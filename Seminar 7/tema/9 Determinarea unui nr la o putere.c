#include <stdio.h>

int putere(double x,int n)
{
	if (n == 0)return 1;
	else
		if (n > 0)return x * putere(x, n - 1);
		else
			return 1 / (putere(x, -n));
}
void main() 
{   
    double x;
    int n;

    printf("Introdu valoarea lui x: ");
    scanf("%lf", &x);

    printf("Introdu valoarea lui n: ");
    scanf("%d", &n);

    printf("%.2lf ^ %d = %.5lf\n", x, n, putere(x, n));

}