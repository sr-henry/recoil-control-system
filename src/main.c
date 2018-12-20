/*
_____Config_____
+ rawinput [off]
+ sensi	   [1.1]
+ 900 dpi
+ 500 polling
+ 1024 x 768 
_______________
*/

#include <stdio.h>
#include <string.h>
#include <windows.h>

#define T 1

int main () 
{

	puts("--Press Insert ON/OFF--");

	POINT mouse;
	int i = 0;

	int x,y;
 
	while (1){

		if (GetAsyncKeyState(VK_HOME)){ return 0; }

		while (GetAsyncKeyState(VK_LBUTTON) && GetKeyState(VK_INSERT)){

			GetCursorPos(&mouse);
		
			SetCursorPos(mouse.x, mouse.y + 1);
			Sleep(1);
			i++;

			if (i == 515){

				for (y = 0; y < 28; ++y){
					GetCursorPos(&mouse);
					SetCursorPos(mouse.x - 3, mouse.y + 1);
					Sleep(17);
				}

				for (y = 0; y < 33; ++y){
					GetCursorPos(&mouse);
					SetCursorPos(mouse.x + 4, mouse.y + 1);
					Sleep(9.54);
				}

				for (y = 0; y < 7; ++y){
					GetCursorPos(&mouse);
					SetCursorPos(mouse.x + 9, mouse.y - 1);
					Sleep(5.2);
				}

				for (y = 0; y < 31; ++y){
					GetCursorPos(&mouse);
					SetCursorPos(mouse.x, mouse.y + 1);
					Sleep(16);
				}

				for (y = 0; y < 66; ++y){
					GetCursorPos(&mouse);
					SetCursorPos(mouse.x - 4, mouse.y - 1);
					Sleep(7.57);
				}

				puts("~#: Reload!");
				Sleep(2000);
				break;
			}
			//printf("%d\n", i);	
		}

		i = 0; 
	}

	return 0;
}


