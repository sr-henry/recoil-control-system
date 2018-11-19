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

int main () 
{

	WEAPON input;

	FILE *fp = fopen("ak47.dat", "r");

	if (fp == NULL){
		printf("Erro ao abrir um arquivo!\n");
		return 0;
	}

	fread(&input, sizeof(WEAPON), 1, fp);

	fclose(fp);

	int i;

	for (i = 0; i < input.nBullets; ++i){
		printf("%d/", input.xSpray[i]);
	}
	printf("\n");
	for (i = 0; i < input.nBullets; ++i){
		printf("%d/", input.ySpray[i]);
	}

	printf("\n");
	puts("Config Loaded!");

//==========================================================

	puts("--Press Insert--");

	POINT mouse;
	int j = 0;
	while (1){ 
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