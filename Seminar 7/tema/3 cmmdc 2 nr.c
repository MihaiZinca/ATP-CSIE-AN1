#include <stdio.h>
int cmmdc(int a, int b)
{
	int r;
	if (a % b == 0)r = b;
	else
		r = cmmdc(b, a % b);
	return r;
}
void main()
{
	int a, b, cm;
	printf("a=");scanf("%d", &a);
	printf("b=");scanf("%d",&b);
	cm = cmmdc(a, b);
	printf("Cmmdc este: ", cm);
}