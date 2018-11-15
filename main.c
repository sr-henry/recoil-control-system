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

    int cX, cY, bx, by;
    int i = 0;

        int x[] = {0,0,0,-2,-4,-6,-6,1,1,18,16,11,10,6,-2,-14,-20,-19,-19,-12,-4,2,2,-1,-2,1,14,22,26,27};
        int y[] = {0,-19,-16,-22,-24,-26,-22,-16,-9,-5,-3,-4,-2,0,-1,-4,-4,-3,0,1,2,-1,-4,-4,-2,-1,2,5,8,6};

    puts("--Insert--");

    while(True)
    {
        if (GetKeyState(VK_INSERT))
        {
            GetCursorPos(&mouse);
            bx = mouse.x;
            by = mouse.y;
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
            SetCursorPos(bx, by);
            i = 0;
        }   
    }
    return 0;
}