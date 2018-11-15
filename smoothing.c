#include <stdio.h>
#include <windows.h>

int main()
{
	int x[] = {0,-1,3,-2,-4,-6,-7,2,111,-82,15,11,11,6,-2,-15,-19,-19,-19,-12,-4,2,2,-1,-3,2,13,22,27,26};
	int i, aux, count;

	for (i = 0; i < 30; ++i)
	{
		printf("%d, ", x[i]);
		count = abs(x[i] - x[i+1]);
		if (count > 1)
		{
			aux = x[i];
			if ((x[i] - x[i+1]) < 0){
				while (aux < count-1)
				{
					aux++;
					printf("%d| ", aux);
				}
			}else{
				while (aux > count-1)
				{
					aux--;
					printf("%d| ", aux);
				}
			}
		}
	}


	return 0;
}