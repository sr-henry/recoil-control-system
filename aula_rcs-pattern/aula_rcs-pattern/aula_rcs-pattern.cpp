#include "pch.h"
#include <iostream>
#include <Windows.h>

using namespace std;

void Help() {
	cout << "[#] Pattern Generator for Recoil Control System\n";
	cout << "[?] Como usar :\n";
	cout << "\t1. Abra uma img do padrao do recoil.\n";
	cout << "\t2. Ative o programa(INSERT).\n";
	cout << "\t3. Clique nos pontos dos tiros.\n";
	cout << "\n[:] INSERT : Ativar | Desativar Rastreamento\n\n";
}

void Crosshair(int x, int y) {
	HDC dc = GetDC(0);
	COLORREF green = RGB(0, 255, 0);

	for (int i = 0; i < 10; i++) {
		SetPixel(dc, x + i, y, green);
		SetPixel(dc, x - i, y, green);
		SetPixel(dc, x, y + i, green);
		SetPixel(dc, x, y - i, green);
	}
}

int main()
{
	Help();

	POINT current;
	int oldx = 0, oldy = 0;
	int dx, dy;
	int line = 0;

	FILE *fp = fopen("log.txt", "w");

	bool tracking = false;

	while (true) {

		if (GetAsyncKeyState(VK_INSERT)) {
			if (tracking) {
				tracking = false;
				cout << "[-] Stop Tracking\n";
				Beep(1700, 300);
				cout << "\n[+] Save in [log.txt]\n";
				break;
			}
			else {
				tracking = true;
				Beep(2000, 100);
				cout << "[!] Start Tracking\n";
			}

			Sleep(50);
		}

		if (GetAsyncKeyState(VK_LBUTTON) && tracking) {
			GetCursorPos(&current);

			Crosshair(current.x, current.y);

			if (oldx == 0 && oldy == 0) {
				oldx = current.x;
				oldy = current.y;

				dx = 0;
				dy = 0;
			}
			else {
				dx = (current.x - oldx) + 1;
				dy = (current.y - oldy) + 1;

				oldx = current.x;
				oldy = current.y;
			}

			if (line % 5 == 0 && line != 0) {
				fprintf(fp, "\n");
			}

			fprintf(fp, "{%d,%d},", dx, dy);

			cout << dx << "\t:\t" << dy << "\n";
			
			line++;
		}

		Sleep(100);

	}

	fclose(fp);

	system("pause");

	return 0;
}

