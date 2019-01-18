#include <stdio.h>
#include <windows.h>

int main()
{
	POINT mouse;

	int i, j;

	printf("config\n");


	while(1){
		if (GetKeyState(VK_INSERT)){
				
			for (i = 0; i < 100; ++i){
				GetCursorPos(&mouse);
				SetCursorPos(mouse.x, mouse.y+1);
				Sleep(20);
			}
			/*-----------------------------------------*/
			for (i = 0; i < 4; ++i){
				GetCursorPos(&mouse);
				SetCursorPos(mouse.x + 1, mouse.y+16);
				Sleep(20);
			}
		
			for (i = 0; i < 8; ++i){
				GetCursorPos(&mouse);
				SetCursorPos(mouse.x + 1, mouse.y+9);
				Sleep(20);
			}

			for (i = 0; i < 13; ++i){
				GetCursorPos(&mouse);
				SetCursorPos(mouse.x + 1, mouse.y+6);
				Sleep(20);
			}

			for (i = 0; i < 13; ++i){
				GetCursorPos(&mouse);
				SetCursorPos(mouse.x + 1, mouse.y+5);
				Sleep(20);
			}

			for (i = 0; i < 2; ++i){
				GetCursorPos(&mouse);
				SetCursorPos(mouse.x -1, mouse.y+22);
				Sleep(20);
			}

			for (i = 0; i < 2; ++i){
				GetCursorPos(&mouse);
				SetCursorPos(mouse.x -1, mouse.y+9);
				Sleep(20);
			}
			/*--------------------------------------*/
			for (i = 0; i < 12; ++i){
				GetCursorPos(&mouse);
				SetCursorPos(mouse.x -3, mouse.y+1);
				Sleep(20);
			}

			for (i = 0; i < 8; ++i){
				GetCursorPos(&mouse);
				SetCursorPos(mouse.x -5, mouse.y+1);
				Sleep(20);
			}

			for (i = 0; i < 11; ++i){
				GetCursorPos(&mouse);
				SetCursorPos(mouse.x -2, mouse.y+1);
				Sleep(20);
			}

			for (i = 0; i < 5; ++i){
				GetCursorPos(&mouse);
				SetCursorPos(mouse.x -4, mouse.y+1);
				Sleep(20);
			}

			for (i = 0; i < 21; ++i){
				GetCursorPos(&mouse);
				SetCursorPos(mouse.x - 1, mouse.y);
				Sleep(20);
			}

			for (i = 0; i < 2; ++i){
				GetCursorPos(&mouse);
				SetCursorPos(mouse.x +2, mouse.y+1);
				Sleep(20);
			}

			for (i = 0; i < 12; ++i){
				GetCursorPos(&mouse);
				SetCursorPos(mouse.x +3, mouse.y+1);
				Sleep(20);
			}

			for (i = 0; i < 11; ++i){
				GetCursorPos(&mouse);
				SetCursorPos(mouse.x +4, mouse.y+1);
				Sleep(20);
			}

			for (i = 0; i < 8; ++i){
				GetCursorPos(&mouse);
				SetCursorPos(mouse.x +5, mouse.y+1);
				Sleep(20);
			}

			for (i = 0; i < 40; ++i){
				GetCursorPos(&mouse);
				SetCursorPos(mouse.x +1, mouse.y);
				Sleep(20);
			}

			for (i = 0; i < 2; ++i){
				GetCursorPos(&mouse);
				SetCursorPos(mouse.x +13, mouse.y- 1);
				Sleep(20);
			}

			for (i = 0; i < 5; ++i){
				GetCursorPos(&mouse);
				SetCursorPos(mouse.x +1, mouse.y- 1);
				Sleep(20);
			}

			for (i = 0; i < 2; ++i){
				GetCursorPos(&mouse);
				SetCursorPos(mouse.x + 2, mouse.y - 1);
				Sleep(20);
			}
			/*--------------------------------------*/

			for (i = 0; i < 4; ++i){
				GetCursorPos(&mouse);
				SetCursorPos(mouse.x -1, mouse.y + 2);
				Sleep(20);
			}

			for (i = 0; i < 2; ++i){
				GetCursorPos(&mouse);
				SetCursorPos(mouse.x - 1, mouse.y + 5);
				Sleep(20);
			}

			for (i = 0; i < 2; ++i){
				GetCursorPos(&mouse);
				SetCursorPos(mouse.x + 1, mouse.y + 4);
				Sleep(20);
			}

			for (i = 0; i < 3; ++i){
				GetCursorPos(&mouse);
				SetCursorPos(mouse.x + 1, mouse.y + 3);
				Sleep(20);
			}
			/*---------------------------------------*/

			for (i = 0; i < 5; ++i){
				GetCursorPos(&mouse);
				SetCursorPos(mouse.x - 6, mouse.y -1);
				Sleep(20);
			}

			for (i = 0; i < 13; ++i){
				GetCursorPos(&mouse);
				SetCursorPos(mouse.x - 4, mouse.y -1);
				Sleep(20);
			}

			for (i = 0; i < 25; ++i){
				GetCursorPos(&mouse);
				SetCursorPos(mouse.x - 2, mouse.y -1);
				Sleep(20);
			}

			for (i = 0; i < 17; ++i){
				GetCursorPos(&mouse);
				SetCursorPos(mouse.x - 4, mouse.y -1);
				Sleep(20);
			}

			return 1;
		}
	}

		





	return 0;
}