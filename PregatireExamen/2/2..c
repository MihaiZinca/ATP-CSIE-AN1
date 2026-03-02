#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

typedef struct
{
	int nrm;
	char nume[30];
	int grupa;
	char pp;
	char pt[10];
	char pe;
}student;

void listastud(FILE* f)
{	
	FILE* g;
	student s;
	char nume[30];
	int i;
	printf("\nFisier rezultat: ");gets(nume);
	g = fopen(nume, "w");
	fprintf(g,"\n Nr.Matricol		Nume %15	Grupa	PP	Punctaj teme  PE","");
	fread(&s, sizeof(student), 1, f);
	while (!feof(f))
	{
		fprintf(g, "\n%8d %-30s %2d %2d", s.nrm, s.nume, s.grupa, s.pp);
			for (i = 0;i < 10;i++)
				fprintf(g, "%2d", s.pt[i]);
		fprintf(g, "%6d", s.pe);
		fread(&s, sizeof(student), 1, f);
	}
	fclose(g);
}
void main()
{
	FILE* f;
	student s;
	char nume[30];
	int i;
	printf("\n Fisier: "); gets(nume);
	f = fopen(nume, "rb+");
	if (!f)printf("\nFisierul %s nu poate fi gasit!");
	else {
		listastud(f);
		fseek(f, 0,2);
		printf("Nr.Matricol: ");scanf("%d", &s.nrm);
		while(!feof(stdin))
		{
			printf("\nNume: ");getchar();gets(s.nume);
			printf("\nGrupa: ");scanf("%d", s.grupa);
			s.pp = 0;
			for (i = 0;i < 10;i++)
				s.pt[i] = 0;
			s.pe = 0;
			fwrite(&s, sizeof(student), 1, f);
			printf("\nNr matricol: ");scanf("%d", &s.nrm);
		}
		fclose(f);
	}
}