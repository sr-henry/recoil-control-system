#include <windows.h>
#include <stdio.h>
#include <stdbool.h>

#define AK 3000

	void 	MouseMove		(int Dx, int Dy, int M, float T);
	float 	CalculateDelay	(int gunTime, int len, float M);

int main()
{

	int dx[] = {0,1,1,1,1,-1,-1,-3,-5,-2,-4,-1,2,3,4,5,1,13,1,2,-1,-1,1,1,-6,-4,-2,-4};
	int dy[] = {1,16,9,6,5,22,9,1,1,1,1,0,1,1,1,1,0,-1,-1,-1,2,5,4,3,-1,-1,-1,-1};
	int  M[] = {100,4,8,13,13,2,2,12,8,11,5,21,2,12,11,8,40,2,5,2,4,2,2,3,5,13,25,17};

	int len = sizeof(dx)/sizeof(dx[0]);

	int i = 0;

	while(true){
		while(GetAsyncKeyState(VK_LBUTTON) && GetKeyState(VK_HOME)){
			MouseMove(dx[i], dy[i], M[i], CalculateDelay(AK, len, M[i]));
			i++;
			if (i == len){break;}
		}
		i = 0;
	}

	return 0;
}


void MouseMove(int Dx, int Dy, int M, float T){
	POINT mouse;
	int count = 0;
	while (GetAsyncKeyState(VK_LBUTTON)){
		GetCursorPos(&mouse);
		SetCursorPos(mouse.x + Dx, mouse.y + Dy);
		Sleep(T);
		count++;
		if (count == M){break;}
	}
}

float CalculateDelay(int gunTime, int len, float M){
	float result = (gunTime/len)/M;
	return result;
}


