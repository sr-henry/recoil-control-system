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

	WEAPON input;

	FILE *fp = fopen("ak47.dat", "r");

	if (fp == NULL){
		printf("Erro ao abrir um arquivo!\n");
		return 0;
	}

	fread(&input, sizeof(WEAPON), 1, fp);

	fclose(fp);

	int i;

	for (i = 0; i < input.nBullets; ++i){
		printf("%d/", input.xSpray[i]);
	}

	return 0;
}