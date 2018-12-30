#include <stdio.h>
#include <windows.h>
#include <stdbool.h>

#define DEFAULT 15
#define SELECT	2

#define IAK47 0
#define IM4A4 1

	void Navigation();
	void Switch(int index);
	void UpdateMenu();
	void MouseMove(int x, int y, int px, float t);
	void RCS_AK47();
	void RCS_M4A4();

int M_Index = 0;

bool ak47 = false;
bool m4a4 = false;

char bools[2][3] = {{"ON"},{"OFF"}};

int main(){
	UpdateMenu();
	Navigation();
}

void Navigation(){

	while (true){

		if (GetAsyncKeyState(VK_UP)){
			if (M_Index > 0){
				M_Index--;
				UpdateMenu();
			}
		}
		if (GetAsyncKeyState(VK_DOWN)){
			if (M_Index < 1){
				M_Index++;
				UpdateMenu();
			}

		}
		if (GetAsyncKeyState(VK_RIGHT)){
			Switch(M_Index);
			UpdateMenu();
		}
		if (GetAsyncKeyState(VK_LEFT)){
			Switch(M_Index);
			UpdateMenu();
		}

		if (ak47){
			RCS_AK47();
		}
		if (m4a4){
			RCS_M4A4();
		}
		
		Sleep(150);
	}

}

void Switch(int index){

	switch(index){
		case IAK47:
			ak47 = !ak47;
			if (m4a4){
				m4a4 = !m4a4;
			}
		break;

		case IM4A4:
			m4a4 = !m4a4;
			if (ak47){
				ak47 = !ak47;
			}
		break;
	}

}


void UpdateMenu(){
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

	system("cls");

	SetConsoleTextAttribute(hConsole, DEFAULT);

	printf("--------R.C.S--------\n");
	printf("1.1(jogo) | 900(dpi)\n");
	printf("---------------------\n");
	if (M_Index == IAK47){
		SetConsoleTextAttribute(hConsole, SELECT);
		printf("AK-47\t\t[%s]\n", bools[!ak47]);
	}else{
		SetConsoleTextAttribute(hConsole, DEFAULT);
		printf("AK-47\t\t[%s]\n", bools[!ak47]);
	}

	if (M_Index == IM4A4){
		SetConsoleTextAttribute(hConsole, SELECT);
		printf("M4A4\t\t[%s]\n", bools[!m4a4]);
	}else{
		SetConsoleTextAttribute(hConsole, DEFAULT);
		printf("M4A4\t\t[%s]\n", bools[!m4a4]);
	}

}

void MouseMove(int x, int y, int px, float t){
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

void RCS_AK47(){
	MouseMove( 0,	 1, 500, 1);
	MouseMove(-3,	 1, 28, 17.85);
	MouseMove( 5,  1, 30, 16.66);
	MouseMove( 0,  1, 31, 16.12);
	MouseMove(-4,	-1, 66, 7.57);	
}

void RCS_M4A4(){
	MouseMove( 0,	 1, 300, 2);
	MouseMove(-3,	 1, 34, 23.52);
	MouseMove(3, 1, 34, 23.52);
}