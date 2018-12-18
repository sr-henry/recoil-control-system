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
					SetCursorPos(mouse.x, mouse.y + 1);
					for (x = 0; x < 3; ++x){
						SetCursorPos(mouse.x - 1, mouse.y);
						Sleep(1);
					}
					Sleep(1);
					GetCursorPos(&mouse);
				}

				puts("$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$");
				Sleep(2000);
				break;
			}
			printf("%d\n", i);	
		}

		i = 0; 
	}

	return 0;
}


