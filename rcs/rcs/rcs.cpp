#include "pch.h"
#include <Windows.h>
#include <iostream>

using namespace std;

typedef struct {
	int		magazineSize;
	float	**pattern;
	int		*multiplier;
}weapon;


float **StandardPattern(int magazineSize) {

	int i, j;

	float **m = (float**)malloc(magazineSize * sizeof(float*));

	for (i = 0; i < magazineSize; i++) {
		m[i] = (float*)malloc(2 * sizeof(float));
		for (j = 0; j < 2; j++) {
			m[i][j] = 0.0;
		}
	}
	return m;
}

void LoadParttern(weapon *current) {

	FILE *fp;
	
	errno_t err = fopen_s(&fp, "config.rcs", "r");

	if (err != 0) {
		cout << "[-] Pattern not found\n";
		return;
	}

	cout << "[+] Pattern found\n";

	int size, mult;

	float cord;

	fscanf_s(fp, "%d", &size);

	current->magazineSize = size;

	current->pattern = StandardPattern(size);

	current->multiplier = (int *)malloc(size * sizeof(int));

	for (int i = 0; i < size; i++) {
		fscanf_s(fp, "%f", &cord);
		current->pattern[i][0] = cord;
	}

	for (int i = 0; i < size; i++) {
		fscanf_s(fp, "%f", &cord);
		current->pattern[i][1] = cord;
	}

	for (int i = 0; i < size; i++) {
		fscanf_s(fp, "%d", &mult);
		current->multiplier[i] = mult;
	}

	fclose(fp);

}

void MouseMove(float Dx, float Dy, int M, float T) {
	int count = 0;
	while (count != M) {
		mouse_event(MOUSEEVENTF_MOVE, Dx, Dy, 0, 0);
		Sleep(T);
		count++;
	}
}

float CalculateTick(int rpm, int magazineSize, float multiplier) {
	float tick = (((magazineSize * 60 * 1000) / rpm) / magazineSize) / multiplier;
	return tick;
}

DWORD CalculateDelay(int gunTime, int len, float M) {
	DWORD result = (gunTime / len) / M;
	return result;
}

int main()
{

	weapon current;

	LoadParttern(&current);

	cout << "insert to on\n";

	int shot_i = 0;

	while (true) {
		
		while (GetKeyState(VK_INSERT) && GetAsyncKeyState(VK_LBUTTON) && shot_i < current.magazineSize) {

			MouseMove(current.pattern[shot_i][0], current.pattern[shot_i][1], current.multiplier[shot_i], CalculateDelay(3000, current.magazineSize, current.multiplier[shot_i]));

			shot_i++;

		}

		shot_i = 0;

	}

	free(current.pattern);
	free(current.multiplier);

	return 0;
}