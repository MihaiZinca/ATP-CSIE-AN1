#include<stdio.h>

//a)) Metoda reducerii unei probleme de grad n la o problema de grad n-1 ?i o problema primitiva (verificarea unui element din vector)
int numara(float v[], int n)
{
	int nr;
	if (n == 0) nr = 0;
	else {
		nr = numara(v, n - 1);
		nr+=(v[n - 1] < 0) ? 1 : 0;
	}
	return nr;
}

void main()
{
	int n, i, rez; float x[100];
	printf("n="); scanf("%d", &n);
	for (i = 0;i < n;i++)
	{
		printf("x[%d]=", i);scanf("%f", &x[i]);
	}
	rez = numara(x, n);
	printf("numarul de elemente negative e

//b) b) Metoda descompunerii unei probleme în dou? subprobleme (doi vectori) cu rezolvare similar? 
// (pân? la probleme primitive – cu rezolvare imediat?, anume vectori cu un singur element)
int numara(float v[], int ls, int ld)
	{
		int nr;
		if (ls == ld) nr = (v[ls] < 0) ? 1 : 0;
		else {
			nr = numara(v, ls, (ls + ld) / 2) + numara(v, (ls + ld) / 2 + 1, ld);
		}
		return nr;
	}

	void main()
	{
		int n, i, rez; float x[100];
		printf("n="); scanf("%d", &n);
		for (i = 0;i < n;i++)
		{
			printf("x[%d]=", i);scanf("%f", &x[i]);
		}
		rez = numara(x, 0, n - 1);
		printf("numarul de elemente negative este %d ", rez);
	}