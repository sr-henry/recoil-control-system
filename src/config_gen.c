#include <stdio.h>
#include <string.h>
#include "config.h"

typedef struct $ {
	int nBullets;
	int *xSpray;
	int *ySpray;
	int time;
}WEAPON;

int main () 
{

	WEAPON ak47 = {30, x_ak47, y_ak47, 40};

	FILE *fp = fopen("ak47.dat", "w");

	if (fp == NULL){
		printf("Erro ao abrir um arquivo!\n");
		return 0;
	}

	fwrite (&ak47, sizeof(WEAPON), 1, fp);

	fclose(fp);

	return 0;
}