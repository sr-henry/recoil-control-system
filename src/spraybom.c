/*
* Desligar RAW INPUT no jogo
*/
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include "config.h"

#define True 1
#define Time 40

int main()
{

	int i = 0;
	
	puts("--Insert--");

	printf("%d\n", x_ak47[10]);

	POINT mouse;

	while (True)
	{ 
		while (GetAsyncKeyState(VK_LBUTTON) && GetKeyState(VK_INSERT))
		{
			GetCursorPos(&mouse);
			SetCursorPos((mouse.x - spray[0][i]), (mouse.y - spray[1][i]));
			Sleep(Time);
			i++;
			if (i == 30){break;}
		}
		i = 0; 
	}

return 0;
}
