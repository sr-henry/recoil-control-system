#include <stdio.h>
#include <windows.h>

#define AK 3000

int main()
{

	float t[] = {100,4,8,13,13,2,2,12,8,11,5,21,2,12,11,8,40,2,5,2,4,2,2,3,5,13,25,17};

	int len = sizeof(t)/sizeof(float);

	int i;

	float result, tempo = AK/len;

	for (i = 0; i < len; ++i){
		result = tempo/t[i];
		printf("Sleep(%.3f);\n", result);
	}
	
	system("pause");
	return 0;
}