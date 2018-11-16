/*
 * Desligar RAW INPUT no jogo
*/
#include <windows.h>
#include <stdio.h>

#define True 1
#define Time 40

int main()
{
    int i = 0, fx, fy;

    int spray[2][30] = {{0,0,0,-2,-4,-6,-6,1,1,18,16,11,10,6,-2,-14,-20,-19,-19,-12,-4,2,2,-1,-2,1,14,22,26,27},
                        {0,-19,-16,-22,-24,-26,-22,-16,-9,-5,-3,-4,-2,0,-1,-4,-4,-3,0,1,2,-1,-4,-4,-2,-1,2,5,8,6}};

    puts("--Insert--");

    POINT mouse;

    while (True)
    { 
        while (GetAsyncKeyState(VK_LBUTTON) && GetKeyState(VK_INSERT))
        {
            GetCursorPos(&mouse);
            SetCursorPos((mouse.x - spray[0][i]), (mouse.y - spray[1][i]));
            Sleep(Time);
            i++;
            if (i == 30){break;}
        }
        i = 0; 
    }
    
    return 0;
}

