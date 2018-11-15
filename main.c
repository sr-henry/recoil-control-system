/*
*
*	NORecoil.WinAPI
*
*/

#include <windows.h>
#include <stdio.h>

#define True 1
#define Time 105

typedef struct $
{
    int nBullets;
    int spray[2][30];
    int time;   
}weapon;

int main()
{
    POINT mouse;

    int cX, cY;
    int i = 0;

    weapon ak;

    ak.nBullets = 30;
    ak.time = 105;

    FILE *cfg = fopen("config.txt", "r");
    for (i = 0; i < 30; ++i)
    {
        fscanf(cfg,"%d", &ak.spray[0][i]);
    }

    for (i = 0; i < 30; ++i)
    {
        fscanf(cfg,"%d", &ak.spray[1][i]);
    }  

    fclose(cfg);

    puts("--Insert--");

    while(True)
    {
        while (GetKeyState(VK_INSERT))
        {
            while (GetAsyncKeyState(VK_LBUTTON))
            {
                GetCursorPos(&mouse);
                cX = mouse.x - ak.spray[0][i];
                cY = mouse.y - ak.spray[1][i];
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