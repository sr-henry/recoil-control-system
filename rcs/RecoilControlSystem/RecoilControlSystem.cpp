#include "pch.h"
#include <iostream>
#include <Windows.h>

using namespace std;

int main()
{

	//partner
	long recoil[30][2] = {  {0, 0},{-1,27},{1,38},{2,49},{10,55},
							{ 15,60},{13,49},{0,37},{-23,21},{-38,10},
							{-35,7},{-23,9},{-23,6},{-12,1},{7,8},
							{32,5},{44,13},{45,5},{41,5},{30,-7},
							{8,-2},{-3,8},{-4,6},{4,10},{6,6},
							{-2,3},{-27,-4},{-51,-10},{-58,-14},{-57,-16} };
	
	//len
	int len = (sizeof(recoil) / sizeof(long)) / 2;

	//dpi
	int dpi = 900;

	//game sensi 0.95
	float sensi = 1;
	
	//multiplier
	double k = (900 * 1.5) / (dpi*sensi);

	//rounds per minute
	DWORD rpm = 600;

	//weapon delay
	DWORD delay = 1000 / (rpm / 60);

	//shot index
	int index = 0;

	cout << "Configs:\ndpi: " << dpi << "\nsensi: " << sensi << "\nmultiplier: " << k;

	while (true) {
		while (GetAsyncKeyState(VK_LBUTTON) && index < len) {
			mouse_event(MOUSEEVENTF_MOVE, long(recoil[index][0]*k) , long(recoil[index][1]*k), 0, 0);
			Sleep(delay);
			index++;
		}
		index = 0;
	}
	

	return 0;
}


