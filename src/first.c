#include <stdio.h>
#include <string.h>
#include <windows.h>


int main () 
{

	POINT mouse;
	int i = 0;

	puts("Press Insert ON | OFF");
 
	while (1){

		if (GetAsyncKeyState(VK_HOME)){ return 0; }

		while (GetAsyncKeyState(VK_LBUTTON) && GetKeyState(VK_INSERT)){
			GetCursorPos(&mouse);
			SetCursorPos(mouse.x, mouse.y + 1);
			Sleep(1);
			printf("%d\n", i);
			i++;
		}

		i = 0;

	}//400

	return 0;
}
