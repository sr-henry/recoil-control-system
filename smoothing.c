#include <stdio.h>
#include <windows.h>

int main()
{
	int x[] = {0,-1,3,-2,-4,-6,-7,2,111,-82,15,11,11,6,-2,-15,-19,-19,-19,-12,-4,2,2,-1,-3,2,13,22,27,26};
	int i, aux, nElementos;

	for (i = 0; i < 30; i++)
	{
		nElementos = abs(abs(x[i]-x[i+1])-1);
		if (nElementos == 0){
			printf("%d. ", x[i]);
		}
		else if (nElementos > 0)
		{
			//printf("Smoothing:");
			aux = x[i];
			if (x[i] > x[i+1])
			{
				while (aux > x[i+1])
				{
					printf("%d, ", aux);
					aux--;
				}
			}
			if (x[i] < x[i+1])
			{
				while (aux < x[i+1])
				{
					printf("%d, ", aux);
					aux++;
				}
			}
		}
	}
	return 0;
}