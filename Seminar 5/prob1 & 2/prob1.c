#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

typedef struct {
	char denumire[20], is;
	float pret;
	int cant;
}produs;
int nrart(FILE* f, int l)
{
	long p; int n;
	p = ftell(f);fseek(f, 0, 2); n = ftell(f) / l;
	fseek(f, p, 0);
	return n;
}
void main()
{
	FILE* f;
	produs p;
	int i, cod;
	char nume[20];
	printf("\n Fisier: "); gets(nume);
	f = fopen(nume, "wb+");
	printf("\n Cod: ");scanf("%d", &cod);
	while (!feof(stdin))
	{
		if (cod >= nrart(f, sizeof(produs)))
		{
			p.is = 0;
			fseek(f, 0, 2);
			for (i = nrart(f, sizeof(produs));i <= cod;i++)
				fwrite(&p, sizeof(produs), 1, f);

		}
		fseek(f, cod * sizeof(produs), 0);
		fread(&p, sizeof(produs), 1, f);
		if (p.is) printf("\n Exista deja un produs cu acest cod");
		else 
		{
			fseek(f, cod * sizeof(produs), 0);
			printf("Denumire: "); getchar(); gets(p.denumire);
			printf("Pret: "); scanf("%f", &p.pret);
			printf("Cant: "); scanf("%d", &p.cant);
			p.is = 1;
			fwrite(&p, sizeof(produs), 1, f);
		}
		printf("\n Cod: ");scanf("%d", &cod);
	}
	fclose(f);
	
}
