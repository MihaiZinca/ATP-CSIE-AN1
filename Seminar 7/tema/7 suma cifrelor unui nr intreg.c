#include <stdio.h>
 
int suma(int n)
{
	int r;
	if (!n)r = 0;
	else
		r = n % 10 + suma(n / 10);
	return r;
}

void main()
{
	int n;
	printf("n=");scanf("%d", &n);
	printf("suma cifrelor este: %d", suma(n));
}