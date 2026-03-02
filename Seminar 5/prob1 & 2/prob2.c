//#define _CRT_SECURE_NO_WARNINGS
//#include <stdio.h>
//
//typedef struct {
//	char denumire[20], is;
//	float pret;
//	int cant;
//}produs;
//int nrart(FILE* f, int l)
//{
//	long p; int n;
//	p = ftell(f);fseek(f, 0, 2); n = ftell(f) / l;
//	fseek(f, p, 0);
//	return n;
//}
//void raport(FILE* f)
//{
//	produs p;
//	int nrc = 0, cod = 0;
//	char nume[40];
//	FILE* g;
//	printf("\nFisier text: ");gets(nume);
//	g = fopen(nume, "w");
//	fprintf(g, "\n Nr.crt Codul Denumirea produsului           Pret");
//	fread(&p, sizeof(produs), 1, f);
//	while (!feof(f))
//	{
//		if (p.is && p.cant == 0)
//		{
//			nrc++;
//			fprintf(g, "\n %-6d %-5d %-30s %7.2f", nrc, cod, p.denumire, p.pret);
//		}
//		cod++;
//		fread(&p, sizeof(produs), 1, f);
//	}
//	fclose(g);
//}
//void main()
//{
//	FLIE* f;
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