#include <stdio.h>
#include <string.h>

int main () 
{
	FILE *fp;

	int x_ak47[] = {0,0,0,-2,-4,-6,-6,1,1,18,16,11,10,6,-2,-14,-20,-19,-19,-12,-4,2,2,-1,-2,1,14,22,26,27};
	int buffer[100], i;

	fp = fopen("ak47", "wb+");

	fwrite(x_ak47, sizeof (int), sizeof (x_ak47), fp);

	fseek(fp, 0, SEEK_SET);

	fread(buffer, sizeof (int), 30*sizeof(int), fp);

	for (i = 0; i < 30; ++i){
		printf("%d, ", buffer[i]);	
	}

	fclose(fp);

	return 0;
}