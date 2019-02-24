#include <windows.h>
#include <stdbool.h>
#include <stdio.h>
#include "config.h"

#define DEFAULT 15
#define SELECT	2

#define IAK47 0
#define IM4A4 1

	void	ExecConfig		(int *dx, int *dy, int *M, int T, int len);
	void	MouseMove		(int Dx, int Dy, int M, float T);
	float	CalculateDelay	(int gunTime, int len, float M);
	void	Navigation		();
	void	Switch 			(int index);
	void	UpdateMenu		();

int M_Index = 0;

bool ak47 = false;
bool m4a4 = false;

char bools[2][3] = {{"ON"},{"OFF"}};

int main()
{	
	UpdateMenu();
	Navigation();
	return 0;
}

void ExecConfig(int *dx, int *dy, int *M, int T, int len){

	int i = 0;

	while(GetAsyncKeyState(VK_LBUTTON)){
		MouseMove(dx[i], dy[i], M[i], CalculateDelay(T, len, M[i]));
		i++;
		if (i == len){break;}
	}
	i = 0;
}

void MouseMove(int Dx, int Dy, int M, float T){
	int count = 0;
	while(GetAsyncKeyState(VK_LBUTTON)){
		mouse_event(MOUSEEVENTF_MOVE, Dx, Dy, 0, 0);
		Sleep(T);
		count++;
		if (count == M){break;}
	}
}

float CalculateDelay(int gunTime, int len, float M){
	float result = (gunTime/len)/M;
	return result;
}

void Navigation(){

	while (true){

		if (GetAsyncKeyState(VK_UP)){
			if (M_Index > 0){
				M_Index--;
				UpdateMenu();
			}
		}
		if (GetAsyncKeyState(VK_DOWN)){
			if (M_Index < 1){
				M_Index++;
				UpdateMenu();
			}

		}
		if (GetAsyncKeyState(VK_RIGHT)){
			Switch(M_Index);
			UpdateMenu();
		}
		if (GetAsyncKeyState(VK_LEFT)){
			Switch(M_Index);
			UpdateMenu();
		}

		if (ak47){
			ExecConfig(ak_dx, ak_dy, ak_M, AK47, ak_len);
		}
		if (m4a4){
			ExecConfig(m4_dx, m4_dy, m4_M, M4A4, m4_len);
		}
		
		Sleep(150);
	}
}

void Switch(int index){

	switch(index){
		case IAK47:
			ak47 = !ak47;
			if (m4a4){m4a4 = !m4a4;}
		break;

		case IM4A4:
			m4a4 = !m4a4;
			if (ak47){ak47 = !ak47;}
		break;
	}

}

void UpdateMenu(){
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

	system("cls");

	SetConsoleTextAttribute(hConsole, DEFAULT);

	printf("________EXTERNAL_RCS________\n");
	printf("900dpi______________1.1 game\n");
	printf("____________________________\n");

	if (M_Index == IAK47){
		SetConsoleTextAttribute(hConsole, SELECT);
		printf("AK-47\t\t\t[%s]\n", bools[!ak47]);
	}else{
		SetConsoleTextAttribute(hConsole, DEFAULT);
		printf("AK-47\t\t\t[%s]\n", bools[!ak47]);
	}

	if (M_Index == IM4A4){
		SetConsoleTextAttribute(hConsole, SELECT);
		printf("M4A4\t\t\t[%s]\n", bools[!m4a4]);
	}else{
		SetConsoleTextAttribute(hConsole, DEFAULT);
		printf("M4A4\t\t\t[%s]\n", bools[!m4a4]);
	}

}