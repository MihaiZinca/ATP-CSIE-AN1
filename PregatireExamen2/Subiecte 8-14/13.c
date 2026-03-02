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
	student s;
	FILE* g;
	printf("\nFisierul rezultat :");gets(nume);
	g = fopen(nume, "w");
	fprintf(g, "\nNr   NrMat  Nume   Grupa PP  Punctaj teme        Punctaj Examen", "");
	fread(&s, sizeof(student), 1, f);
	int n = 0;
	while (!feof(f))
	{
		fprintf(g, "%4d %8d %-30s %4d %4d", ++n, s.nrm, s.nume, s.grupa, s.pp);
		for (int i = 0;i < 10;i++)
			fprintf(g, "%2d", s.pt[i]);
		fprintf(g, "%2d", s.pe);
		fread(&s, sizeof(student), 1, f);
	}
	fclose(g);
}
void maine()
{
	char nume[30];
	student s;
	FILE* f;
	int n,ok,pun;
	printf("\nFisierul:");gets(nume);
	f = fopen(nume, "rb+");
	if (!f)printf("Fisierul %s nu poate fi deschis", nume);
	else
	{
		list_stud(f);
		printf("Numar Matricol: ");scanf("%d", &n);
		while (!feof(stdin))
		{
			rewind(f);
			fread(&s, sizeof(student), 1, f);
			ok = 0;
			while (!feof(f) && (ok == 0))
			{
				if (n == s.nrm)
				{
					ok = 1;
					printf("Punctajul modificat la pe este: ");scanf("%d", &pun);
					s.pe = pun;
					fseek(f, ftell(f) - sizeof(student), 0);
					fwrite(&s, sizeof(student), 1, f);
				}
				else fread(&s, sizeof(student), 1, f);
			}
			if (ok == 0)printf("nu s-a gasit");
			printf("Numar Matricol:");scanf("%d", &n);
		}
		fclose(f);
	}
}