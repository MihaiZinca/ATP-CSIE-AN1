//#define _CRT_SECURE_NO_WARNINGS
//#include <stdio.h>
//
//typedef struct {
//	char denumire[20], is;
//	float pret;
//	int cant;
//}produs;
//
//int nrart(FILE* f, int l)
//{
//	int n;
//	long p;
//	p = ftell(f);
//	fseek(f, 0, 2);
//	n = ftell(f) / l;
//	fseek(f, p, 0);
//	return n;
//}
//void raport(FILE* f)
//{
//	produs p;
//	FILE* g;
//	char nume[40];
//	printf("\nFisier text: "); gets(nume);
//	g = fopen(nume, "w");
//	fprintf(g, "\nDenumirea produsului: ");
//	fread(&p, sizeof(produs), 1, f);
//	while (!feof(f))
//	{
//		fprintf(g, "\n %-30s", p.denumire);
//		fread(&p, sizeof(produs), 1, f);
//	}
//	fclose(g);
//}
//void main()
//{
//	FILE* f;
//	char nume[20];
//	printf("\nFisier: "); gets(nume);
//	f = fopen(nume, "rb");
//	if (!f)printf("\n Fisierul %s nu poate fi deschis", nume);
//	else
//	{
//		raport(f);
//		fclose(f);
//	}
//}