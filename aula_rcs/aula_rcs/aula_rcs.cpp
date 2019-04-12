#include <iostream>
#include <string>
#include <Windows.h>
#include "patterns.h"

#define getLen(x) (sizeof(x)/sizeof(x[0]))

using namespace std;

typedef struct $ {
	string	name;
	long	**pattner;
	int		len;
	int		rpm;
}weapon_t;

	weapon_t *LoadWeapon(string name, long recoil[][2], int len, int rpm);
	float GetK(float dpi, float sensi);
	DWORD GetTime(float rpm);
	void ExecControl(weapon_t gun);

	float K;

int main()
{

	K = GetK(800, 0.95);

	weapon_t *ak47 = LoadWeapon("AK-47", ak47_pattern, getLen(ak47_pattern), 600);
	weapon_t *m4a4 = LoadWeapon("M4A4", m4a4_pattern, getLen(m4a4_pattern), 666);
	weapon_t *ump45 = LoadWeapon("UMP-45", ump45_pattern, getLen(ump45_pattern), 666);

	while (true) {
		if (GetAsyncKeyState(VK_F1)) {
			ExecControl(*ak47);
		}
		if (GetAsyncKeyState(VK_F2)) {
			ExecControl(*m4a4);
		}
		if (GetAsyncKeyState(VK_F3)) {
			ExecControl(*ump45);
		}
		Sleep(150);
	}

	return 0;
}

void ExecControl(weapon_t gun) {

	cout <<"CurrentWeapon:\t" << gun.name <<"\nMagazineSize:\t" << gun.len << "\nRPM:\t" << gun.rpm << "\n\n[INSERT]\n";

	DWORD delay = GetTime(gun.rpm);

	int index = 0;

	while (true) {

		if (GetAsyncKeyState(VK_HOME)) {
			system("cls");
			break;
		}

		while (GetAsyncKeyState(VK_LBUTTON) && index != gun.len) {
			mouse_event(MOUSEEVENTF_MOVE, long(gun.pattner [index][0] * K), long(gun.pattner[index][1] * K), 0, 0);
			index++;
			Sleep(delay);
		}

		index = 0;
	}

}

weapon_t *LoadWeapon(string name, long recoil[][2], int len, int rpm) {
	
	int i;

	weapon_t *gun = new weapon_t();

	gun->name = name;
	gun->len = len;
	gun->rpm = rpm;

	gun->pattner = new long*[len];
	for (i = 0; i < len; i++) {
		gun->pattner[i] = new long[2];
	}
	
	for (i = 0; i < len; i++) {
		gun->pattner[i][0] = recoil[i][0];
		gun->pattner[i][1] = recoil[i][1];
	}

	return gun;
}

float GetK(float dpi, float sensi) {
	return (1140 / (dpi*sensi));
}

DWORD GetTime(float rpm) {
	return DWORD((60 / rpm) * 1000);
}