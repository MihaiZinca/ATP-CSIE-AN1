#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

typedef struct {
	char denumire[20], is;
	float pret;
	int cant, codi;
}produs;

int nrart(FILE* f, int l)
{
	int n;
	long p;
	p = ftell(f);
	fseek(f, 0, 2);
	n = ftell(f) / l;
	fseek(f, p, 0);
	return n;
}
void raport(FILE* f)
{
	produs p;
	FILE* g;
	int cod, cant_noua;
	char nume[40];
	int ok=0;
	printf("\nFisier text: "); gets(nume);
	g = fopen(nume, "w");
	printf("Codul: ");scanf("%d", &cod);
	fread(&p, sizeof(produs), 1, f);
	while (!feof(f) && (ok==0))
	{
		if (p.codi == cod) {
			printf("Produs găsit: %s | Stoc actual: %d\n", p.denumire, p.cant);
			printf("Introdu cantitatea suplimentară: ");
			scanf("%d", &cant_noua);

			p.cant = p.cant + cant_noua;
			fseek(f, sizeof(produs), 0);
			fwrite(&p, sizeof(produs), 1, f);
			printf("Stoc actualizat: %d\n", p.cant);
			ok = 1;
		}
		
	}
	if (ok == 0)print("Codul nu a fost gasit");
	fclose(g);
}
void main()
{
	FILE* f;
	char nume[20];
	printf("\nFisier: "); gets(nume);
	f = fopen(nume, "rb");
	if (!f)printf("\n Fisierul %s nu poate fi deschis", nume);
	else
	{
		raport(f);
		fclose(f);
	}
}