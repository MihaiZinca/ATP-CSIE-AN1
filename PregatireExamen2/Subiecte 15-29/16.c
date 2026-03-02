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

void list_stud(FILE* f)
{
	char nume[30];
	student s;
	FILE* g;
	int n = 0, i;
	printf("\nFisierul rezultat: ");gets(nume);
	g = fopen(nume, "w");
	fprintf(g, "\nNr. NrMatricol  Nume  Grupa   An  Absente", "");
	fread(&s, sizeof(student), 1, f);
	while (!feof(f))
	{
		if (s.is == 1)
		{
			fprintf(g, "%2d %4d %-30s %4d %4d", ++n, s.nrm, s.nume, s.grupa, s.an);
			for (i = 0;i < 15;i++)
				fprintf(g, "%-2d %-2d", s.abs[i].c, s.abs[i].s);
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
	int n,sem;
	printf("\nFisierul:");gets(nume);
	f = fopen(nume, "rb+");
	if (!f)printf("Fisierul %s nu poate fi deschis", nume);
	else 
	{
		list_stud(f);
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
					printf("Seminar de recuperat: ");scanf("%d", &sem);
					s.abs[sem - 1].s--;
					fseek(f, n * sizeof(student), 0);
					fwrite(&s, sizeof(student), 1, f);
					printf("Seminarul a fost recuperat");
				}
			}
			printf("\nNr matricol: ");scanf("%d", &n);
		}
		fclose(f);
	}
}