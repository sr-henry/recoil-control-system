#include "pch.h"
#include <windows.h>
#include <fstream>
#include <iostream>
#include <list>

#pragma warning (disable : C4244)

using namespace std;

void SavePattern(float **pattern, int *multiplier, int len) {

	cout << "\n[+] Salvando\n";

	ofstream recoil_pattern;
	recoil_pattern.open("config.txt");

	recoil_pattern << "float recoil[" << len << "]" << "[2] = {\n";

	for (int i = 0; i < len; i++) {
		recoil_pattern <<"\t{" << pattern[i][0] << "," << pattern[i][1] <<"},\n";
	}

	recoil_pattern << "};";

	recoil_pattern << "float recoil[" << len << "] = {";

	for (int i = 0; i < len; i++) {
		recoil_pattern << multiplier[i] << ", ";
	}

	recoil_pattern << "};";


	recoil_pattern.close();
	
	free(pattern);
	free(multiplier);

}

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

void CalculateSmooth(float *x, float *y, int *multiplier, int index) {

	float smt;

	float mod_x = abs(*x);
	float mod_y = abs(*y);

	float ret_x, ret_y;

	if (*x == 0 && *y == 0) {
		multiplier[index] = 0;
		*x = 0;
		*y = 0;
	}

	if (*x == 0 && *y > 0) {
		multiplier[index] = mod_y;
		*x = 0;
		*y = 1;
	}

	if (*x == 0 && *y < 0) {
		multiplier[index] = mod_y;
		*x = 0;
		*y = -1;
	}

	if (*x > 0 && *y == 0) {
		multiplier[index] = mod_x;
		*x = 1;
		*y = 0;
	}

	if (*x < 0 && *y == 0) {
		multiplier[index] = mod_x;
		*x = -1;
		*y = 0;
	}

	if (mod_x >= mod_y && mod_y != 0) {

		smt = mod_x / mod_y;

		if (*x < 0) {
			*x = -smt;
		}
		else {
			*x = smt;
		}

		if (*y < 0) {
			*y = -1;
		}
		else {
			*y = 1;
		}

		multiplier[index] = mod_y;

	}

	if (mod_y >= mod_x && mod_x != 0) {

		smt = mod_y / mod_x;

		if (*x < 0) {
			*x = -1;
		}
		else {
			*x = 1;
		}
		if (*y < 0) {
			*y = -smt;
		}
		else {
			*y = smt;
		}

		multiplier[index] = mod_x;

	}
}

void Smoothing(float **toSmooth, int len) {

	cout << "\n[+] Smoothing\n";

	int *multiplier = (int *)malloc(len * sizeof(int));

	for (int i = 0; i < len; i++) {

		CalculateSmooth(&toSmooth[i][0], &toSmooth[i][1], multiplier, i);

	}

	SavePattern(toSmooth, multiplier, len);

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

	cout << "\n[+] Padrao Detectado\n";

	BuildPattern(x, y);
}

int main()
{
	cout << "[*] Pattern Generator for Recoil Control System\n\n";
	cout << "[?] Como usar:\n";
	cout << "\t1. Abra uma img do padrao do recoil.\n\t2. Ative o programa (F4).\n\t3. Clique nos pontos dos tiros.\n\n";
	cout << "F4 - Ativa & Desativa rastreamento\n\n";

	while (true) {
		if (GetKeyState(VK_F4)) {
			Tracking();
		}
	}

	return 0;
}