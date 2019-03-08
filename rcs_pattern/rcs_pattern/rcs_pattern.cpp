#include "pch.h"
#include <windows.h>
#include <iostream>

using namespace std;

void Tracking() {

	cout << "[!] Lendo entradas do mouse\n\n";

	FILE *fp;

	fopen_s(&fp, "recoil.txt", "w");

	int old_dx = 0, old_dy = 0;
	int dx = 0, dy = 0;
	int shots = 0;

	POINT mouse;

	while (true) {

		Sleep(100);

		if (GetAsyncKeyState(VK_LBUTTON)) {

			Beep(2000, 100);

			GetCursorPos(&mouse);

			if (old_dx == 0 && old_dy == 0) {
				old_dx = mouse.x;
				old_dy = mouse.y;
			}
			else {
				dx = (mouse.x - old_dx)+1;
				dy = (mouse.y - old_dy)+1;
				old_dx = mouse.x;
				old_dy = mouse.y;
			}

			cout << dx << "|" << dy << "\n";

			fprintf_s(fp, "{%d,%d},\n", dx, dy);

			shots++;
		}

		if (!GetKeyState(VK_F4)) {
			break;
		}

	}

	fclose(fp);

	cout << "\n[+] Padrao Detectado\n";

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