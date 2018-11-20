#include <stdlib.h>
#include <windows.h>
#include <stdio.h>
#define MenuInicio 1     
#define MenuFim 7
#define LinhaDeInicio 3 
#define TAM 30
#define PX 35


/*PROTOTIPOS DAS FUNÇOES*/
int menu();
void goy(int y);
void Linha_Menu();
void Linha_Menu_2();
void Menu_Principal(char str[]);
void Menu_Item(char str[]);
void Linha_Menu_3();
void Monta_Menu();
void limpar();
void graph(int sizex,int sizey,int X[],int Y[]);
void gotoxy( int x, int y );
void sub_menu(int i);


int i; /*variavel global*/

/*FUNÇÕES*/
int menu(){
	system("cls");
	int Menu; 
	
	Monta_Menu();/*cria o layout*/
	
	Menu = 1;
	
	goy(LinhaDeInicio);/*posiciona o cursor na coordenada Y desejada*/
	printf("%c%c",186,175);
	
	system("color 0");/*muda a cor do programa*/
	
	
	while(1){
	
	Sleep(100);/*serve para retardar o laço, tipo assim ele le (11111111111), ja com o sleep ele le (1 1 1 1 1 1 1 1)*/
	
		if (GetAsyncKeyState(VK_UP)){/*verifica se a tecla foi precionada*/
			Menu=Menu==MenuInicio?MenuFim:--Menu;/*essa parte pode ficar meio confusa mas é só uma operação ternaria, o "?" é um operador ternario
			funciona basicamente assim: <condição> ? <operação 1> : <operação 2>;*/
			printf("\r%c    ",186);/*printa a >*/
			goy(LinhaDeInicio+Menu-1);/*muda de linha*/
			printf("%c%c",186,175);/*printa a lateral*/} 
		
		else if (GetAsyncKeyState(VK_DOWN)){/*o mesmo q o de cima*/
			Menu=Menu==MenuFim?MenuInicio:++Menu;
			printf("\r%c    ",186);
			goy(LinhaDeInicio+Menu-1);
			printf("%c%c",186,175);} 
	
		else if (GetAsyncKeyState(VK_RIGHT)){break;}

		}/*aqui é pra selecionar a opção, no caso a tecla é o F1*/
		
		
		goy(11);/*e muda de linha*/
		
return Menu;/*retornando a opção*/}


void goy(int y){
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD pos;
	pos.X = 0;
	pos.Y = y;
	SetConsoleCursorPosition(hConsole,pos);}
	
void Monta_Menu(){	
	Linha_Menu();

	Menu_Principal("MENU");
	Linha_Menu_3();
	Menu_Item("     1.REGISTRAR");
	Menu_Item("     2.ESTOQUE");
	Menu_Item("     3.SALVAR");
	Menu_Item("     4.CARREGAR");
	Menu_Item("     5.PEDIDO");
	Menu_Item("     6.RELATORIO");
	Menu_Item("     7.SAIR");
	Linha_Menu_2();}
	
/*MENU DESENVOLVIMENTO*/	
void Linha_Menu(){
	printf("%c",201);
	for(i=0;i<TAM;i++){
	printf("%c",205);}
	printf("%c\n",187);}

void Linha_Menu_2(){
	printf("%c",200);
	for(i=0;i<TAM;i++){
	printf("%c",205);}
	printf("%c\n",188);}

void Menu_Principal(char str[]){
	printf("%c",186);
	printf("%*s",17,str);
	printf("%14c\n",186);}
	
void Menu_Item(char str[]){
	printf("%c",186);
	printf("%-*s",TAM,str);
	printf("%c\n",186);}
	
void Linha_Menu_3(){
	printf("%c",204);
	for(i=0;i<TAM;i++)
	printf("%c",205);
	printf("%c\n",185);}
	
	
void limpar(){char c;while((c=getchar())!='\n' && c != EOF);}


void graph(int sizex,int sizey,int X[],int Y[]){
	
	char plano[1000][1000];
	int k,j,xy=sizey,y,n=0,PY=3;
	y=sizey;
		
	/*inicializa*/
	for(k=0;k<sizey;k++){/*sizey*/
		for(j=0;j<sizex;j++){/*sizex*/
			plano[k][j]=32;}}
			
	/*monta o grafico*/
	while(n<(sizex-2)){
	for(k=0;k<sizey;k++){
		if(Y[n]==y){
			plano[k][X[n]]=178; Y[n]--;
		}y--;}		
		n++;y=sizey;}
			
	/*mostra o grafico*/
	for(k=0;k<sizey;k++){gotoxy(PX,PY);
		printf("%02d%c",xy,179); xy--;
		for(j=0;j<sizex;j++){
			printf("%c",plano[k][j]);
		}printf("\n");PY++;}gotoxy(PX,PY);printf("  %c",192);
	for(k=0;k<sizex;k++){printf("%c",196);}printf("\n");PY++;
	
	gotoxy((PX+4),PY);
	for(k=1;k<=(sizex-2);k++){
		printf("%d",k);
	}printf("\n\n");
	
}

void gotoxy( int x, int y ){
	COORD coord;
	coord.X = (short)x;
	coord.Y = (short)y;
SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);}

void sub_menu(int i){
	system("cls");
	
	Linha_Menu();
	
	switch(i){
		case 1:
			Menu_Principal("[1]CADASTRO");
		break;
		
		case 2:
			Menu_Principal("[2]ESTOQUE");
		break;
		
		case 3:
			Menu_Principal("[3]SALVANDO");
		break;
		
		case 4:
			Menu_Principal("[4]LOAD");
		break;
		
		case 5:
			Menu_Principal("[5]PEDIDO");
		break;
		
		case 6:
			Menu_Principal("[6]RELATORIO");
		break;
	}
	
	Linha_Menu_2();
}

















