#include <windows.h>
#include <stdbool.h>
#include <stdio.h>
#include "config.h"

	void	ExecConfig		(int *dx, int *dy, int *M, int T, int len);
	void	MouseMove		(int Dx, int Dy, int M, float T);
	float	CalculateDelay	(int gunTime, int len, float M);
	void	Menu			();

int main()
{	
	int op;

	Menu();
	scanf("%d", &op);
	switch(op){
		case 1:
			ExecConfig(ak_dx, ak_dy, ak_M, AK47, ak_len);
		break;
		case 2:
			ExecConfig(m4_dx, m4_dy, m4_M, M4A4, m4_len);
		break;
		default:
			printf("Erro!\n");
	}
	
	return 0;
}

void ExecConfig(int *dx, int *dy, int *M, int T, int len){

	int i = 0;

	while(true){
		while(GetAsyncKeyState(VK_LBUTTON) && GetKeyState(VK_HOME)){
			MouseMove(dx[i], dy[i], M[i], CalculateDelay(T, len, M[i]));
			i++;
			if (i == len){break;}
		}
		i = 0;
	}
}

void MouseMove(int Dx, int Dy, int M, float T){
	POINT mouse;
	int count = 0;
	while(GetAsyncKeyState(VK_LBUTTON)){
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

void Menu(){
	printf("___EXTERNAL_RCS_CSGO___\n");
	printf("Configuration:_________\n");
	printf("900 dpi_____1.1 in game\n");
	printf("Weapons:_______________\n");
	printf("1.________________AK-47\n");
	printf("2._________________M4A4\n");
	printf("$: ");
}