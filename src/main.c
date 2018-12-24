#include <stdio.h>
#include <string.h>
#include <windows.h>

#define T 1

int main () 
{

	puts("--Press Insert ON/OFF--");

	POINT mouse;
	int i = 0;

	int x,y, d = 2;
 
	while (1){

		if (GetAsyncKeyState(VK_HOME)){ return 0; }

		while (GetAsyncKeyState(VK_LBUTTON) && GetKeyState(VK_INSERT)){

			GetCursorPos(&mouse);

			if (i == 4){
				d--;
			}

			SetCursorPos(mouse.x, mouse.y + d);
			Sleep(1);

			i++;

			if (i == 500){
				printf("%d\n", i);
				for (y = 0; y < 28; ++y){
					GetCursorPos(&mouse);
					SetCursorPos(mouse.x - 3, mouse.y + 1);
					Sleep(17.85);
					i++;
				}printf("%d\n", i);

				for (y = 0; y < 30; ++y){
					GetCursorPos(&mouse);
					SetCursorPos(mouse.x + 5, mouse.y + 1);
					Sleep(16.66);
					i++;
				}printf("%d\n", i);

				for (y = 0; y < 31; ++y){
					GetCursorPos(&mouse);
					SetCursorPos(mouse.x, mouse.y + 1);
					Sleep(16.12);
					i++;
				}printf("%d\n", i);

				for (y = 0; y < 66; ++y){
					GetCursorPos(&mouse);
					SetCursorPos(mouse.x - 4, mouse.y - 1);
					Sleep(7.57);
					i++;
				}printf("%d\n", i);

				puts("#####################");
				Sleep(2000);
				break;
			}
			//printf("%d\n", i);	
		}

		i = 0; 
		d = 2;
	}

	return 0;
}
