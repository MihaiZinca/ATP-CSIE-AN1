#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

// I: capacitate totala (q), nr. obiecte (n), capacitate ocupata (c),
// E: solutia x
void rucsac_con(float q int n, float* c, float* x)
{
	float qr;
	int i, j;
	qr = q;
	for (i = 0;i < n && qr>0;i++)
	{
		if (qr >= c[i]) {
			x[i] = 1;
			qr = qr - c[i];
		}
		else
		{
			x[i] = qr / c[i];
			qr = 0;
			for (j = i + 1;j < n;j++)
				x[j] = 0;
		}
	}
}

void main()
{
	float ct, c[30], v[30], sol[30], a, castig;
	int i, j, n;
	printf("Capacitate toala a rucs:");scanf("%f", &ct);
	printf("Nr obiecte: ");scanf("%d", &n);
	for (i = 0;i < n;i++)
	{
		printf("Capacitatea obiectului %d: ", i+1);
		scanf("%f", &c[i]);
		printf("Venitul obiectului %d; ", i+1);
		scanf("%f", &v[i]);
	}
	//sortare desc
	for (i = 0;i < n - 1;i++)
		for (j = i + 1;j < n;j++)
			if (v[i] / c[i] < v[j] / c[j])
			{
				a = v[i];v[i] = v[j];v[j] = a;
				a = c[i];c[i] = c[j];c[j] = a;
			}
	rucsac_con(ct, n, c, sol);
	castig = 0;
	for (i = 0;i < n;i++)
	{
		printf("\n%2d: c=%5.2f v=%5.2f %2f, castig=%5.2f", i + 1, c[i], v[i], sol[i], castig += v[i] * sol[i]);
	}

}