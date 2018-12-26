#include <stdio.h>
#include <string.h>
#include <windows.h>


void trivela(int x, int y, int px, float t){
	POINT mouse;
	int i = 1;
	while (GetAsyncKeyState(VK_LBUTTON)){
		GetCursorPos(&mouse);
		SetCursorPos(mouse.x + x, mouse.y + y);
		Sleep(t);
		i++;
		if (i == px){break;}
	}
}

void ak47(){
	trivela( 0,	 1, 500, 1);
	trivela(-3,	 1, 28, 17.85);
	trivela( 5,  1, 30, 16.66);
	trivela( 0,  1, 31, 16.12);
	trivela(-4,	-1, 66, 7.57);	
}

void m4a4(){
	trivela( 0,	 1, 300, 2);
	trivela(-3,	 1, 34, 23.52);
	trivela(3, 1, 34, 23.52);
}

int exec(int opc){

	puts("Press Insert ON | OFF");

	while (1){

		if (GetAsyncKeyState(VK_HOME)){ return 0; }

			switch(opc){
				case 1:
					ak47();
				break;

				case 2:
					m4a4();
				break;

				default:
    				printf ("Valor invalido!\n");
    				return 1;
    			
			}
	}
}

void menu(){
	printf("________Weapons______\n");
	printf("1_______________AK-47\n");
	printf("2________________M4A4\n");
}

int main () {

	while(1){
		if (GetAsyncKeyState(VK_PRIOR)){
			exec(1);
		}
		if (GetAsyncKeyState(VK_NEXT)){
			exec(2);
		}
	}
	return 0;
}
