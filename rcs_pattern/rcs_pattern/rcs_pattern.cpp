#include "pch.h"
#include <windows.h>
#include <fstream>
#include <iostream>
#include <list>

#pragma warning disable C4244

using namespace std;

float **StandardTemplate(int Linhas) {

	int i, j;

	float **m = (float**)malloc(Linhas * sizeof(float*));

	for (i = 0; i < Linhas; i++) {
		m[i] = (float*)malloc(2 * sizeof(float));
		for (j = 0; j < 2; j++) {
			m[i][j] = 0.0;
		}
	}
	return m;
}

float CalculateSmooth(float x, float y, int *multiplier, int index) {

	float smt;

	float mod_x = abs(x);
	float mod_y = abs(y);

	float ret_x, ret_y;

	if (x == 0 && y == 0) {
		multiplier[index] = 0;
		return 0, 0;
	}

	if (x == 0 && y > 0) {
		multiplier[index] = mod_y;
		return 0, 1;
	}

	if (x == 0 && y < 0) {
		multiplier[index] = mod_y;
		return 0, -1;
	}

	if (x > 0 && y == 0) {
		multiplier[index] = mod_x;
		return 1, 0;
	}

	if (x < 0 && y == 0) {
		multiplier[index] = mod_x;
		return -1, 0;
	}

	if (mod_x >= mod_y && mod_y != 0) {

		smt = mod_x / mod_y;

		if (x < 0) {
			ret_x = -smt;
		}
		else {
			ret_x = smt;
		}

		if (y < 0) {
			ret_y = -1;
		}
		else {
			ret_y = 1;
		}

		multiplier[index] = mod_y;

		return ret_x, ret_y;
	}

	if (mod_y >= mod_x && mod_x != 0) {

		smt = mod_y / mod_x;

		if (x < 0) {
			ret_x = -1;
		}
		else {
			ret_x = 1;
		}
		if (y < 0) {
			ret_y = -smt;
		}
		else {
			ret_y = smt;
		}

		multiplier[index] = mod_x;

		return ret_x, ret_y;
	}
}

void Smoothing(float **toSmooth, int len) {

	cout << "\n[+] Smoothing...\n";

	int *multiplier = (int *)malloc(len * sizeof(int));

	for (int i = 0; i < len; i++) {

		toSmooth[i][0], toSmooth[i][1] = CalculateSmooth(toSmooth[i][0], toSmooth[i][1], multiplier, i);

		cout << toSmooth[i][0] << "\t" << toSmooth[i][1] << "\t" << multiplier[i] << "\n";
	}

	free(toSmooth);
	free(multiplier);

}

void BuildPattern(list <int> x, list <int> y)
{

	int index = 0;
	int size = x.size();
	float **pattern = StandardTemplate(size);

	list <int> ::iterator i;

	for (i = x.begin(); i != x.end(); i++) {
		pattern[index][0] = *i;
		index++;
	}

	index = 0;

	for (i = y.begin(); i != y.end(); i++) {
		pattern[index][1] = *i;
		index++;
	}

	Smoothing(pattern, size);

}

void Tracking() {

	cout << "[!] Lendo entradas do mouse\n\n";

	int old_dx = 0, old_dy = 0;
	int dx = 0, dy = 0;
	int shots = 0;

	POINT mouse;

	list <int> x, y;

	while (true) {

		if (GetAsyncKeyState(VK_LBUTTON)) {

			GetCursorPos(&mouse);

			if (old_dx == 0 && old_dy == 0) {
				old_dx = mouse.x;
				old_dy = mouse.y;
			}
			else {
				dx = (mouse.x - old_dx);
				dy = (mouse.y - old_dy);
				old_dx = mouse.x;
				old_dy = mouse.y;
			}

			x.push_back(dx);
			y.push_back(dy);

			cout << "[+] Shot_Index[" << shots << "].Status = TRACKED\n";

			shots++;
		}

		if (!GetKeyState(VK_F4)) {
			break;
		}


		Sleep(100);

	}

	cout << "\n[+] Detected Pattern\n";

	BuildPattern(x, y);
}

int main()
{
	cout << "1.Abra uma img do padrao do recoil.\n2.Ative o programa (F4).\n3.Clique nos pontos dos tiros.\n\n";
	cout << "F4 - Ativa & Desativa rastreamento\n\n";

	while (true) {
		if (GetKeyState(VK_F4)) {
			Tracking();
		}
	}

	return 0;
}