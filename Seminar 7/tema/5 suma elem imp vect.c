#include <stdio.h>

// metoda reducerii

int suma(int* v, int n)
{
	int s;
	if (n == 0)s = 0;
	else
		s = suma(v, n - 1) + (v[n - 1] % 2 == 1) * v[n - 1];
	return s;
}

//metoda descoumperii

int sum2(int* v, int* ls, int* ld)
{
	int s;
	if (ls == ld)s = (v[ls] % 2 == 1) * v[ls];
	else
		s = sum2(v, ls, (ls + ld) / 2) + sum2(v, (ls + ld) / 2 +1, ld);
	return s;
}

void main()
{
	int x[50], s, n, i;
	printf("n=");scanf("%d", &n);
	for (i = 0;i < n;i++)
		printf("x[%d]=", i);scanf("%d", &x[i]);
	s = suma(x, n);
	printf("Met reducerii suma nr impare este = %d", s);
	s = sum2(x, 0, n - 1);
	printf("Met descompunerii suma nr impare este =%d", s);
}