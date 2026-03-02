#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
void scriere_vector(char* nume)
{
	FILE* f; float x;
	f = fopen(nume, "w");
	if (!f)printf("nu se poate");
	else {
		printf("x=");
		scanf("%f", &x);
		while (!feof(stdin))
		{
			fprintf(f, "%4.2f\n", x);
			printf("x=");
			scanf("%f", &x);
		}
		fclose(f);
	}
}
void main()
{
	char numef[20];
	printf("Introduceti numele fisierului:");
	scanf("%s", numef);
	scriere_vector(numef);
}