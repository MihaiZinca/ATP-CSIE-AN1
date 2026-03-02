#include <stdio.h>

//metoda reducerii

float ps(float* x, float* y, int n)
{
	float s;
	if (n == 0)s = 0;
	else s = ps(x, y, n - 1) + x[n - 1] * y[n - 1];
	return s;
}

//metoda descompunerii

float ps1(float* x, float* y, int ls, int ld)
{
	float s;
	if (ls == ld)s = x[ls] * y[ls];
	else
		s = ps1(x, y, ls, (ls + ld) / 2) + ps1(x, y, (ls + ld) / 2 + 1, ld);
	return s;
}

void main()
	{
		int n, i; float x[100], y[100], rez;
		printf("n="); scanf("%d", &n);
		for (i = 0;i < n;i++)
		{
			printf("x[%d]=", i);scanf("%f", &x[i]);
		}
		for (i = 0;i < n;i++)
		{
			printf("y[%d]=", i);scanf("%f", &y[i]);
		}
		rez = ps(x, y, n);
		printf("produsul scalar este %5.2f \n", rez);
		rez = ps1(x, y, 0, n - 1);
		printf("produsul scalar in varianta doi este %5.2f ", rez);
	}
