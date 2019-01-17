#include <stdio.h>
#include <string.h>
#include <math.h>
#include <windows.h>

	int nBullets = 30;
	int xSpray[] = {0, 0, 0, 4, 8, 13, 13, -2, -2, -39, -35, -24, -21, -13, 4, 30, 43, 41, 41, 26, 8, -4, -4, 2, 4, -2, -30, -48, -56, -59};
	int ySpray[] = {0, 54, 46, 63, 69, 75, 63, 46, 26, 14, 8, 11, 5, 0, 2, 11, 11, 8, 0, -2, -5, 2, 11, 11, 5, 2, -5, -14, -23, -17};

	int StartMacro();
	void LeftClick();
	

int main () 
{

	StartMacro();

	return 0;
}

int StartMacro(){
	puts("--Press HOME ON/OFF--");
	POINT mouse;
	int j = 0,r;

	while (1){

		while (GetKeyState(VK_HOME)){
			GetCursorPos(&mouse);
			//LeftClick();
			SetCursorPos(mouse.x + xSpray[j], mouse.y + ySpray[j]);
			Sleep(80);
			j++;
			if (j == nBullets){return 1;}
		}
		j = 0; 
	}

	return 0;
}


void LeftClick(){
    puts("LEFT CLICK");
    INPUT    Input= {0};												

    Input.type        = INPUT_MOUSE;									
    Input.mi.dwFlags  = MOUSEEVENTF_LEFTDOWN;							
    SendInput( 1, &Input, sizeof(INPUT) );								

    ZeroMemory(&Input,sizeof(INPUT));									
    Input.type        = INPUT_MOUSE;									
    Input.mi.dwFlags  = MOUSEEVENTF_LEFTUP;								
    SendInput( 1, &Input, sizeof(INPUT) );							
}