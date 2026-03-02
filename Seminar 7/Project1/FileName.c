#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void sortare(int* x, int n)
{
	int i,j,a;
	for(i=0;i<n-1;i++)
		for(j=i+1;j<n;j++)
			if (x[i] > x[j])
			{
				a = x[i];
				x[i] = x[j];
				x[j] = a;
			}
}
int greed(int n, int a[])
{
	int i, p;
	p = 1;
	for (i = 1;i < n;i++)
		if (a[i] != a[i - 1] && (a[i] % 2 == 1))
			p = p * a[i];
	return p;
}
void main()
{
	int v[100], i, n;
	printf("n=");scanf("%d", &n);
	for (i = 0;i < n;i++)
	{
		printf("a[%d]=", i);
		scanf("%d", &v[i]);
	}
	sortare(v, n);
	printf("Produsul componentelor impare este: %d", greed(n, v));
}