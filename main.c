/*
*
*	NORecoil.WinAPI
*
*/

#include <windows.h>
#include <stdio.h>

#define True 1
#define Time 105

int main()
{
    POINT mouse;

    int cX, cY;
    int i = 0;

        int x[] = {0,-1,3,-2,-4,-6,-7,2,111,-82,15,11,11,6,-2,-15,-19,-19,-19,-12,-4,2,2,-1,-3,2,13,22,27,26};
        int y[] = {0,-17,-17,-21,-26,-26,-22,-14,-10,-4,-3,-5,-1,-1,0,-4,-5,-2,-1,2,1,0,-5,-3,-2,-2,3,4,7,8};

    puts("--Insert--");

    while(True)
    {
        if (GetKeyState(VK_INSERT))
        {
            while (GetAsyncKeyState(VK_LBUTTON))
            {
                GetCursorPos(&mouse);
                cX = mouse.x - x[i];
                cY = mouse.y - y[i];
                SetCursorPos(cX, cY);
                Sleep(Time);
                i++;
                if (i == 30){ break; }
            }
            i = 0;
        }   
    }
    return 0;
}