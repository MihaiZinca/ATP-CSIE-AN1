#include <stdio.h>

int cmmdc(int a, int b)
{
	int r;
	if (a % b == 0)r = b;
	else
		r = cmmdc(b, a % b);
	return r;
}
int cv(int x[], int n)
{
	int r;
	if (n == 1)r = x[0];
	else
		r = cmmdc(cv(x, n - 1), x[n - 1]);
	return r;
}
void main()
{
	int x[100], cmm, n, i;
	printf("n=");scanf("%d", &n);
	for (i = 0;i < n;i++)
		printf("x[%d]=", i);scanf("%d", &x[i]);
	cmm = cv(x, n);
	printf("Cmmdc este :%d", cmm);
}