#include <windows.h>
#include <stdio.h>

int main()
{
    FARPROC pGetPixel;

    HINSTANCE _hGDI = LoadLibrary("gdi32.dll");
    if(_hGDI)
    {
        pGetPixel = GetProcAddress(_hGDI, "GetPixel");
        HDC _hdc = GetDC(NULL);
        if(_hdc)
        {
            while(1){
                POINT _cursor;
                GetCursorPos(&_cursor);
                COLORREF _color = (*pGetPixel) (_hdc, _cursor.x+326, _cursor.y+157);
                int _red = GetRValue(_color);
                int _green = GetGValue(_color);
                int _blue = GetBValue(_color);

                printf("Red:%d\n", _red);
                printf("Green: %d\n", _green);
                printf("Blue: %d\n\n", _blue);

                Sleep(100);

            }
            
        }
        FreeLibrary(_hGDI);
    }
    return 0;
}