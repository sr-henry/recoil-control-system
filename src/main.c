#include <stdio.h>
#include <string.h>
#include <windows.h>



void trivela(int x, int y, int px, float t){
	POINT mouse;
	int i = 1;
	while (GetAsyncKeyState(VK_LBUTTON) && GetKeyState(VK_INSERT)){
		GetCursorPos(&mouse);
		SetCursorPos(mouse.x + x, mouse.y + y);
		Sleep(t);
		i++;
		if (i == px){break;}
	}
}


int main () 
{

	puts("--Press Insert ON/OFF--");
 
	while (1){

		if (GetAsyncKeyState(VK_HOME)){ return 0; }

		while (GetAsyncKeyState(VK_LBUTTON) && GetKeyState(VK_INSERT)){

				trivela( 0,	 1, 500, 1);
				trivela(-3,	 1, 28, 17.85);
				trivela( 5,  1, 30, 16.66);
				trivela( 0,  1, 31, 16.12);
				trivela(-4,	-1, 66, 7.57);

		}
	}

	return 0;
}
