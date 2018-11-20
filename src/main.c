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

	int StartMacro(WEAPON input);
	void MenuLayout();

int main () 
{

	WEAPON ak47 = {30, x_ak47, y_ak47, 40};
	WEAPON m4a4 = {30, x_m4a4, y_m4a4, 40};
	WEAPON m4a1 = {20, x_m4a1, y_m4a1, 40};
	WEAPON ump45 = {25, x_ump45, y_ump45, 40};

	int op;

	while (1){

		MenuLayout();
		scanf("%d", &op);

		switch(op){
			case 1:
				StartMacro(ak47);
				break;
			case 2:
				StartMacro(m4a4);
				break;
			case 3:
				StartMacro(m4a1);
				break;
			case 4:
				StartMacro(ump45);
				break; 
			default:
				puts("Opcao Invalida!");
				system("pause");
		}
		
	}

	return 0;
}

int StartMacro(WEAPON input)
{
	puts("--Press Insert ON/OFF--");

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

void MenuLayout()
{
	system("cls");
	printf("___Weapons___\n");
	printf("1.AK-47______\n");
	printf("2.M4A4_______\n");
	printf("3.M4A1-S_____\n");
	printf("4.UMP45______\n");
	printf("$: ");
}