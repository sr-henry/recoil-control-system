#include "pch.h"
#include <Windows.h>
#include <iostream>

using namespace std;

float mutiplicador(DWORD dpi, DWORD sensi) {
	return (900 * 1.5) / (dpi*sensi);
}
	

DWORD calculate_time(DWORD rpm) {
	return (60*1000)/rpm;
}


DWORD recoil[30][2] = {
{0,0},
{1,45},
{1,52},
{4,73},
{11,84},
{24,85},
{21,76},
{1,51},
{-34,34},
{-60,17},
{-49,12},
{-27,10},
{-30,7},
{-24,3},
{15,14},
{57,7},
{56,13},
{66,17},
{66,-1},
{40,-2},
{13,-1},
{-6,11},
{0,12},
{7,12},
{11,8},
{-8,5},
{-35,-4},
{-73,-12},
{-86,-23}
};

void Transform(float m) {
	int len = sizeof(recoil) / sizeof(float) / 2;
	for (int i = 0; i < len; i++) {
		recoil[i][0] = recoil[i][0] * m;
		recoil[i][1] = recoil[i][1] * m;
	}
}

int main()
{

	int shot = 0;

	DWORD stick = calculate_time(600);

	//float mult = 1.4855;//mutiplicador(900, 1);

	
	//Sleep(2000);

	while (true) {

		while (GetAsyncKeyState(VK_LBUTTON) && shot < 30) {
			//mouse_event(MOUSEEVENTF_LEFTDOWN, 0, 0, 0, 0);
			//mouse_event(MOUSEEVENTF_LEFTUP, 0, 0, 0, 0);
			mouse_event(MOUSEEVENTF_MOVE, recoil[shot][0], recoil[shot][1], 0, 0);
			Sleep(stick);
			shot++;
		}

		shot = 0;
	}

	return 0;
}