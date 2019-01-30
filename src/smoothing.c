#include <stdio.h>
#include <windows.h>

void SetLeftClick(){
    puts("SET LEFT CLICK");

    INPUT    Input= {0};
    Input.type        = INPUT_MOUSE;
    Input.mi.dwFlags  = MOUSEEVENTF_LEFTDOWN;
    SendInput( 1, &Input, sizeof(INPUT) );
}

void UnSetLeftClick(){
    puts("UNSET LEFT CLICK");

    INPUT    Input= {0};
    ZeroMemory(&Input,sizeof(INPUT));
    Input.type        = INPUT_MOUSE;
    Input.mi.dwFlags  = MOUSEEVENTF_LEFTUP;
    SendInput( 1, &Input, sizeof(INPUT) );
}

int main()
{
	POINT mouse;

	int i, j;

	printf("INSERT\n");


	while(1){
		if (GetKeyState(VK_INSERT)){
			
			SetLeftClick();

			for (i = 0; i < 100; ++i){
				GetCursorPos(&mouse);
				SetCursorPos(mouse.x, mouse.y+1);
				Sleep(1.070);
			}
			/*-----------------------------------------
				f(x) = 
			*/
			for (i = 0; i < 4; ++i){
				GetCursorPos(&mouse);
				SetCursorPos(mouse.x + 1, mouse.y+16);
				Sleep(26.750);
			}
		
			for (i = 0; i < 8; ++i){
				GetCursorPos(&mouse);
				SetCursorPos(mouse.x + 1, mouse.y+9);
				Sleep(13.375);
			}

			for (i = 0; i < 13; ++i){
				GetCursorPos(&mouse);
				SetCursorPos(mouse.x + 1, mouse.y+6);
				Sleep(8.231);
			}

			for (i = 0; i < 13; ++i){
				GetCursorPos(&mouse);
				SetCursorPos(mouse.x + 1, mouse.y+5);
				Sleep(8.231);
			}

			for (i = 0; i < 2; ++i){
				GetCursorPos(&mouse);
				SetCursorPos(mouse.x -1, mouse.y+22);
				Sleep(53.500);
			}

			for (i = 0; i < 2; ++i){
				GetCursorPos(&mouse);
				SetCursorPos(mouse.x -1, mouse.y+9);
				Sleep(53.500);
			}
			/*--------------------------------------
				f(y) = 
			*/
			for (i = 0; i < 12; ++i){
				GetCursorPos(&mouse);
				SetCursorPos(mouse.x -3, mouse.y+1);
				Sleep(8.917);
			}

			for (i = 0; i < 8; ++i){
				GetCursorPos(&mouse);
				SetCursorPos(mouse.x -5, mouse.y+1);
				Sleep(13.375);
			}

			for (i = 0; i < 11; ++i){
				GetCursorPos(&mouse);
				SetCursorPos(mouse.x -2, mouse.y+1);
				Sleep(9.727);
			}

			for (i = 0; i < 5; ++i){
				GetCursorPos(&mouse);
				SetCursorPos(mouse.x -4, mouse.y+1);
				Sleep(21.400);
			}

			for (i = 0; i < 21; ++i){
				GetCursorPos(&mouse);
				SetCursorPos(mouse.x - 1, mouse.y);
				Sleep(5.095);
			}

			for (i = 0; i < 2; ++i){
				GetCursorPos(&mouse);
				SetCursorPos(mouse.x +2, mouse.y+1);
				Sleep(53.500);
			}

			for (i = 0; i < 12; ++i){
				GetCursorPos(&mouse);
				SetCursorPos(mouse.x +3, mouse.y+1);
				Sleep(8.917);
			}

			for (i = 0; i < 11; ++i){
				GetCursorPos(&mouse);
				SetCursorPos(mouse.x +4, mouse.y+1);
				Sleep(9.727);
			}

			for (i = 0; i < 8; ++i){
				GetCursorPos(&mouse);
				SetCursorPos(mouse.x +5, mouse.y+1);
				Sleep(13.375);
			}

			for (i = 0; i < 40; ++i){
				GetCursorPos(&mouse);
				SetCursorPos(mouse.x +1, mouse.y);
				Sleep(2.675);
			}

			for (i = 0; i < 2; ++i){
				GetCursorPos(&mouse);
				SetCursorPos(mouse.x +13, mouse.y- 1);
				Sleep(53.500);
			}

			for (i = 0; i < 5; ++i){
				GetCursorPos(&mouse);
				SetCursorPos(mouse.x +1, mouse.y- 1);
				Sleep(21.400);
			}

			for (i = 0; i < 2; ++i){
				GetCursorPos(&mouse);
				SetCursorPos(mouse.x + 2, mouse.y - 1);
				Sleep(53.500);
			}
			/*--------------------------------------
				f(x) = 
			*/

			for (i = 0; i < 4; ++i){
				GetCursorPos(&mouse);
				SetCursorPos(mouse.x -1, mouse.y + 2);
				Sleep(26.750);
			}

			for (i = 0; i < 2; ++i){
				GetCursorPos(&mouse);
				SetCursorPos(mouse.x - 1, mouse.y + 5);
				Sleep(53.500);
			}

			for (i = 0; i < 2; ++i){
				GetCursorPos(&mouse);
				SetCursorPos(mouse.x + 1, mouse.y + 4);
				Sleep(53.500);
			}

			for (i = 0; i < 3; ++i){
				GetCursorPos(&mouse);
				SetCursorPos(mouse.x + 1, mouse.y + 3);
				Sleep(35.667);
			}
			/*---------------------------------------
				f(y) = 
			*/

			for (i = 0; i < 5; ++i){
				GetCursorPos(&mouse);
				SetCursorPos(mouse.x - 6, mouse.y -1);
				Sleep(21.400);
			}

			for (i = 0; i < 13; ++i){
				GetCursorPos(&mouse);
				SetCursorPos(mouse.x - 4, mouse.y -1);
				Sleep(8.231);
			}

			for (i = 0; i < 25; ++i){
				GetCursorPos(&mouse);
				SetCursorPos(mouse.x - 2, mouse.y -1);
				Sleep(4.280);
			}

			for (i = 0; i < 17; ++i){
				GetCursorPos(&mouse);
				SetCursorPos(mouse.x - 4, mouse.y -1);
				Sleep(6.294);
			}

			UnSetLeftClick();
			return 1;
		}
	}
	return 0;
}