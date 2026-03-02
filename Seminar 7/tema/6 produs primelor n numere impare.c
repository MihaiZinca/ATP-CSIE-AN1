#include <stdio.h>

int produs(int n)
{
	int r;
	if (n == 1)r = 1;
	else
		r = (2 * n - 1) * produs(n - 1);
	retun r;
}
void main()
{
	int n;
	printf("n=");scanf("%d", &n);
	printf("Produsul primelor %d nr impare este %d", n, produs(n));
}

