#include <stdio.h>

double pol(int a[],int n,double x)
{
	if (n == 0) return a[0];
	return a[n] * pow(x, n) + pol(a, n - 1, x);
}
void main() 
{
    int a[100], n, i;
    double x;

    printf("Introdu gradul polinomului: "); scanf("%d", &n);

    printf("Introdu coeficien?ii de la a0 la an%d:\n", n);
    for (i = 0; i <= n; i++) 
        printf("a[%d] = ", i); scanf("%d", &a[i]);


    printf("Introdu valoarea lui x: ");scanf("%lf", &x);

    double rezultat = pol(a, n, x);
    printf("Valoarea polinomului în x = %.2lf este: %.4lf\n", x, rezultat);

}
