/*
 * Desligar RAW INPUT no jogo
*/
#include <windows.h>
#include <stdio.h>

#define True 1

int macro(int cSpray[2][30], int nBullets, int tSpray)
{
	POINT mouse;
	int i = 0;

	while (True)
    { 
        while (GetAsyncKeyState(VK_LBUTTON) && GetKeyState(VK_INSERT))
        {
            GetCursorPos(&mouse);
            SetCursorPos((mouse.x - cSpray[0][i]), (mouse.y - cSpray[1][i]));
            Sleep(tSpray);
            i++;
            if (i == nBullets){break;}
        }
        i = 0; 
    }

	return 0;
}


int main()
{
    

    int ak47[2][30] = {{0,0,0,-2,-4,-6,-6,1,1,18,16,11,10,6,-2,-14,-20,-19,-19,-12,-4,2,2,-1,-2,1,14,22,26,27},
                       {0,-19,-16,-22,-24,-26,-22,-16,-9,-5,-3,-4,-2,0,-1,-4,-4,-3,0,1,2,-1,-4,-4,-2,-1,2,5,8,6}};

    int ump45[2][30] = {{0,-1,1,4,0,1,-3,-8,-11,-6,1,14,19,21,17,8,4,4,2,-7,-14,-17,-16,-12,-7,-1,-1,-2,-3,-3},
                        {0,-9,-12,-13,-19,-19,-20,-16,-13,-7,-6,-3,0,0,2,-1,-2,0,0,-1,-3,-3,-1,-3,-1,-2,-2,-2,-2,0}};

    puts("--Insert--");

    macro(ak47, 30, 40);

    return 0;
}

