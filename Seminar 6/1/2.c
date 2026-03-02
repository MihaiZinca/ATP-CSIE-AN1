#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

typedef struct
{
	int nrm;
	char nume[30];
	int grupa;
	char pp;
	char pt[10];
	char pe;
}student;

void list_stud(FILE* f)
{
	char nume[30];
	FILE* g;
	int n,i;
	student s;
	printf("\nFisier: ");gets(nume);
	g = fopen(nume, "w");
	fprintf(g, "\nNr  Nr.Matricol   Nume   Grupa  PP  PunctajTeme   PuncteExamen", "");
	fread(&s, sizeof(student), 1, f);
	n = 0;
	while (!feof(f))
	{
		fprintf(g, "%3d  %6d  %-30s  %4d %4d", ++n, s.nrm, s.nume, s.grupa, s.pp);
		for (i = 0;i < 10;i++)
			fprintf(g, "%2d", s.pt[i]);
		fprintf(g, "%2d", s.pe);
		fread(&s, sizeof(student), 1, f);
	}
	fclose(g);
}
void main()
{
	char nume[30];
	FILE* f;
	student s;
	int n, i;
	printf("\nFisier: ");gets(nume);
	f = fopen(nume, "rb+");
	if (!f)printf("Fisierul %s nu paote fi deschis", nume);
	else
	{
		list_stud(f);
		fseek(f, 0, 2);
		printf("\nNr.Matricol: ");scanf("%d", &s.nrm);
		while (!feof(stdin))
		{
			printf("Nume:"); scanf("%s", s.nume);
			printf("Grupa:");scanf("%d", &s.grupa);
			s.pp = 0;
			for (i = 0;i < 10;i++)
				s.pt[i] = 0;
			s.pe = 0;
			fwrite(&s, sizeof(student), 1, f);
		}
		fclose(f);
	}
}