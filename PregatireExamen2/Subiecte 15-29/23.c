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
	char is;
}student;

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
void list_stud(FILE* f)
{
	FILE* g;
	student s;
	int n = 0, i;
	char nume[30];
	printf("\nFisierul rezultat: ");gets(nume);
	g = fopen(nume, "w");
	fprintf(g, "\nNr. NrMatricol   Nume   Grupa  PP PuncteTeme   PE","");
	fread(&s, sizeof(student), 1, f);
	while (!feof(f))
	{
		if (s.is == 1)
		{
			fprintf(g, "%4d %4d %-30s %4d %4d", ++n, s.nrm, s.nume, s.grupa, s.pp);
			for (i = 0;i < 10;i++)
				fprintf(g, "%-2d", s.pt[i]);
			fprintf(g, "-2d", s.pe);
		}
		fread(&s, sizeof(student), 1, f);
	}
	fclose(g);
}
void main()
{
	char nume[30];
	student s;
	FILE* f;
	int n, pun;
	printf("Fisierul rezultat: ");gets(nume);
	f = fopen(nume, "rb+");
	if (!f)printf("Fisierul %s nu poate fi deschis", nume);
	else 
	{
		list_stud(f);
		printf("\nNr.Matricol: ");scanf("%d", &n);
		while (!feof(stdin))
		{
			if (n >= nrart(f, sizeof(student)))printf("Studentul nu s-a gasit");
			else
			{
				fseek(f, n * sizeof(student), 0);
				fread(&s, sizeof(student), 1, f);
				if (s.is == 0)printf("Studentul nu s-a gasit");
				else
				{
					printf("Punctajul obtinut de student la proba practica este: ");scanf("%d", &pun);
					s.pp = pun;
					fseek(f, n * sizeof(student),0);
					fwrite(&s, sizeof(student), 1, f);
				}
			}
			printf("\nNr matricol: ");scanf("%d", &n);
		}
		fclose(f);
	}
}
