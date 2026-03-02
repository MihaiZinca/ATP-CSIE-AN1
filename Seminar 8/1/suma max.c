#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void suma_max(float* a, int n, float* b, int* nr)
{
	int i;
	*nr = 0;
	for (i = 0;i < n;i++)
		if (a[i] >= 0) b[(*nr)++] = a[i];
}
void main()
{
	float a[100], b[100];
	int n, i, nr;
	printf("n= ");scanf("%d", &n);
	for (i = 0;i < n;i++)
	{
		printf("a[%d]= ", i);scanf("%f", &a[i]);
	}
	suma_max(a, n, b, &nr);
	if (nr == 0)printf("Nu exista nr pozitive");
	else
	{
		printf("Solutia este: ");
		for (i = 0;i < nr;i++)
			printf("%3.1f", b[i]);
	}
}