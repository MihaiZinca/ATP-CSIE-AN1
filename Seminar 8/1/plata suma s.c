#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void ord(float* v, int n)
{
	int i, j,aux;
	for(i=0;i<n-1;i++)
		for(j=i+1;j<n;j++)
			if (v[i] < v[j])
			{
				aux = v[i];
				v[i] = v[j];
				v[j] = aux;
			}
}
int suma(float* a, int n, float s)
{
	int i, ok = 0, si = 0;
	i = 0;
	while (i < n && ok == 0)
	{
		si = si + a[i];
		if (si == s)ok = 1;
		i++;
	}
	if (ok == 1)return 1;
	else return 0;
}
void main()
{
	float a[100];
	int n, i, nr,s;
	printf("n= ");scanf("%d", &n);
	for (i = 0;i < n;i++)
	{
		printf("a[%d]= ", i);scanf("%f", &a[i]);
	}
	printf("S=");scanf("%d", &s);
	ord(a, n);
	if (sum(a, n, s) == 1)printf("Este permisa plata");
	else printf("Nu este permisa");
}