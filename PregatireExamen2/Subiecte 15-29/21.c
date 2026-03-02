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
	char nume[30];
	student s;
	FILE* g;
	int n = 0, i;
	printf("\nFisierul rezultat: ");gets(nume);
	g = fopen(nume, "w");
	fprintf(g, "\nNr.  NrMatricol    Nume      Grupa PP  PunctajTeme     Pe", "");
	fread(&s, sizeof(student), 1, f);
	while (!feof(f))
	{
		if (s.is == 1)
		{
			fprintf(g, "%4d %4d %-30s %4d %4d", ++n, s.nrm, s.nume, s.grupa, s.pp);
			for (i = 0;i < 10;i++)
				fprintf(g, "%-2d ", s.pt[i]);
			fprintf(g, "%2d", s.pe);
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
	int n;
	printf("\nFisierul:");gets(nume);
	f = fopen(nume, "rb+");
	if (!f)printf("Fisierul %s nu poate fi deschis", nume);
	else 
	{
		list_stud(f);
		printf("\nNr matricol: ");scanf("%d", &n);
		while (!feof(stdin))
		{
			if (n >= nrart(f, sizeof(student)))printf("Studentul nu s-a gasit");
			else 
			{
				fseek(f, n * sizeof(student), 0);
				fread(&s, sizeof(student), 1, f);
				if (s.is == 1)printf("Studentul exista deja");
				else
				{
					s.is = 0;
					fseek(f, n * sizeof(student), 0);
					printf("\nNume: ");getchar();gets(s.nume);
					printf("Grupa: ");scanf("%d", s.grupa);
					s.pp = 0;
					for (i = 0;i < 10;i++)
						s.pt[i] = 0;
					s.pe = 0;
					fwrite(&s, sizeof(student), 1, f);
					printf("Studentul a fost inmatriculat");

				}
			}
			printf("\nNumar matricol: ");scanf("%d", &n);
		}
		fclose(f);

	}
}