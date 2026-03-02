#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

typedef struct
{
	char c;
	char s;
}as;
typedef struct
{
	char is;
	int nrm;
	char nume[25];
	int grupa;
	char an;
	as abs[10];
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
void lista_stud(FILE* f)
{
	char nume[30];
	student s;
	FILE* g;
	int i, n = 0;
	printf("Fisierul rezultat: ");gets(nume);
	g = fopen(nume, "w");
	fprintf(g, "\nNr. NrMatricol  Nume  Grupa  An  Absente", "");
	fread(&s, sizeof(student), 1, f);
	while (!feof(f))
	{
		if (s.is == 1)
		{
			fprintf(g, "\n%2d %4d %-30s %4d %2d %2d", ++n, s.nrm, s.nume, s.grupa, s.an);
			for (i = 0;i < 15;i++)
				fprintf(g, "\n%-2d %-2d", s.abs[i].c, s.abs[i].s);
		}
		fread(&s, sizeof(student), 1, f);
	}
	fclose(g);
}
void main()
{
	FILE* f;
	student s;
	int n;
	char nume[30];
	printf("\n Fisierul: ");gets(nume);
	f = fopen(nume, "rb+");
	char t;
	if (!f)printf("nu exista");
	else
	{
		lista_stud(f);
		printf("\nNr matricol: ");scanf("%d", &n);
		while (!feof(stdin))
		{
			if (n >= nrart(f, sizeof(student)))printf("Studentul nu exista");
			else
			{
				fseek(f, n * sizeof(student), 0);
				fread(&s, sizeof(student), 1, f);
				if (s.is == 0)printf("Studentul nu exista");
				else
				{
					printf("Tip activitate: (C/S)");scanf("%c", &t);
					if (t == 'C')s.abs[0].c++;
					if (t == 'S')s.abs[0].s++;
					fseek(f, n * sizeof(student), 0);
					fwrite(&s, sizeof(student), 1, f);
					printf("Absenta a fost adaugata");
				}
			}
			printf("\nNr matricol: ");scanf("%d", &n);
		}

	fclose(f);
	}
}
