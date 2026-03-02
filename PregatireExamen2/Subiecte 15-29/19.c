#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>


typedef struct
{
	char c, s;
}at;
typedef struct
{
	char is;
	int nrm;
	char nume[25];
	int grupa;
	char an;
	at abs[15];
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
	fprintf(g, "\nNr.  Nr.Matricol  Nume   Grupa   An", "");
	fread(&s, sizeof(student), 1, f);
	while (!feof(f))
	{
		if (s.is == 1)
		{
			fprintf(g, "%4d %4d %-30s %4d %4d", ++n, s.nrm, s.nume, s.grupa, s.an);
			for (i = 0;i < 15;i++)
				fprintf(g, "%-2d %-2d ", s.abs[i].c, s.abs[i].s);
		}
		fread(&s, sizeof(student), 1, f);
	}
	fclose(g);
}

void main()
{
	FILE* f;
	student s;
	char nume[30];
	int n;
	printf("\nFisierul: ");gets(nume);
	f = fopen(nume, "rb+");
	if (!f)printf("\nFisierul %s nu poate fi deschis", nume);
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
					fseek(f, n * sizeof(student), 0);
					s.is = 0;
					printf("Studentul cu nr matricol %d a fost exmatriculat", s.nrm);
					fwrite(&s, sizeof(student), 1, f);
				}
			}
			printf("\nNr.Matricol: ");scanf("%d", &n);
		}
		fclose(f);
	}

}