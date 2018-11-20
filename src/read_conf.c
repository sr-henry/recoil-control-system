#include <stdio.h>
#include <string.h>
#include <windows.h>
#include "config.h"

typedef struct $ {
	int nBullets;
	int *xSpray;
	int *ySpray;
	int time;
}WEAPON;

	int StartMacro (WEAPON input);
	void MenuLayout();
	int ActiveMenu();
	void goy(int y);

int main () 
{

	WEAPON ak47 = {30, x_ak47, y_ak47, 40};
	WEAPON m4a4 = {30, x_m4a4, y_m4a4, 40};

	int op;

	while (1){
		
		op = ActiveMenu();

		if (op == 1){
			StartMacro(ak47);
		}else{
			StartMacro(m4a4);
		}
		
	}

	return 0;
}

int StartMacro(WEAPON input)
{
	puts("--Press Insert--");

	POINT mouse;
	int j = 0;

	while (1){

		if (GetAsyncKeyState(VK_HOME)){return 0;}

		while (GetAsyncKeyState(VK_LBUTTON) && GetKeyState(VK_INSERT)){
			GetCursorPos(&mouse);
			SetCursorPos((mouse.x - input.xSpray[j]), (mouse.y - input.ySpray[j]));
			Sleep(input.time);
			j++;
			if (j == input.nBullets){break;}
		}
		j = 0; 
	}

	return 0;
}

int ActiveMenu()
{
	system("cls");
	int op = 1;

	MenuLayout();

	goy(1);

	while(1){
	
	Sleep(160);
	
		if (GetAsyncKeyState(VK_UP)){
			op=op==1?2:--op;
			printf("\r    ");
			goy(1+op-1);
			printf(">");
		} 
		
		else if (GetAsyncKeyState(VK_DOWN)){
			op=op==2?1:++op;
			printf("\r    ");
			goy(1+op-1);
			printf(">");
		} 
	
		else if (GetAsyncKeyState(VK_RIGHT)){break;}

	}

	system("cls");

	return op;
}

void MenuLayout()
{

	printf("___Weapons___\n");
	printf("      1.AK-47\n");
	printf("      2.M4A4");

}

void goy(int y)
{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD pos;
	pos.X = 0;
	pos.Y = y;
	SetConsoleCursorPosition(hConsole,pos);
}