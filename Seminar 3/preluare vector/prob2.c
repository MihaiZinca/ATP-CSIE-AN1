#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void preluare_vector_1(char* nume, float v[], int* n) {
	FILE* f;
	float x;
	f = fopen(nume, "r");
	if (f)
	{
		*n = 0;
		fscanf(f, "%f", &x);
		while (!feof(f))
		{
			v[(*n)++] = x;
			fscanf(f, "%f", &x);
		}
		fclose(f);
	}
	else printf("nu se poate");
}
void main()
{
	float a[100];
	int n;
	char numef[20];
	printf("Introduceti numele fisierului: ");
	scanf("%s", numef);
	preluare_vector_1(numef, a, &n);
	for (int i = 0; i < n; i++)
		printf("%4.1f , ", a[i]);

}