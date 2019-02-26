#include "pch.h"
#include <Windows.h>
#include <iostream>

using namespace std;

float recoil[30][2] = {
	{0,0},
	{-1,8},
	{1,32},
	{1,21},
	{1,6.85714},
	{1,4},
	{1,4.66667},
	{-1,15.5},
	{-1.11765,1},
	{-3.88889,1},
	{-7.75,1},
	{-2.44444,1},
	{-19,1},
	{-4,1},
	{2.33333,1},
	{3.85714,1},
	{5.14286,1},
	{7.4,1},
	{34,1},
	{5,-1},
	{6,-1},
	{-1,1.5},
	{-1,3},
	{1,2.5},
	{1.2,1},
	{-6,1},
	{-4.6,-1},
	{-4.88889,-1},
	{-3.53333,-1},
	{-4.09091,-1},
}; 

int multiplier[30] = { 0, 3, 1, 2, 7, 12, 9, 2, 17, 9, 4, 9, 1, 3, 3, 7, 7, 5, 1, 5, 1, 2, 3, 2, 5, 1, 5, 9, 15, 11, };

void MouseMove(int Dx, int Dy, int M, float T) {
	int count = 0;
	while (count != M) {
		mouse_event(MOUSEEVENTF_MOVE, Dx, Dy, 0, 0);
		Sleep(T);
		count++;
	}
}

int main()
{
	int shot_i = 0;

	Sleep(1500);

	while (shot_i < 30) {

		MouseMove(recoil[shot_i][0], recoil[shot_i][1], multiplier[shot_i], 10);

		shot_i++;
	}

}