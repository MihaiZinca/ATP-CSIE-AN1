#define _CRt_SECURE_NO_WARNINGS
#include <stdio.h>

typedef struct {
	char c;
	char s;
}at;
typedef struct {
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
	student s;
	FILE* g;
	int i,n=0;
	char nume[30];
	printf("\nFisierul rezultat: ");gets(nume);
	g = fopen(nume, "W");
	fprintf(g, "\nNr.   NrMatricol    Nume   Grupa An  Absente", "");
	fread(&s, sizeof(student), 1, f);
	while (!feof(f))
	{
		if (s.is == 1)
		{
			fprintf(g, "%4d %4d %-30s %4d %4d", ++n, s.nrm, s.nume, s.grupa, s.an);
			for (i = 0; i< 15;i++)
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
	int n, i, nra;
	FILE* f;
	printf("\nFisieru: ");gets(nume);
	f = fopen(nume, "rb+");
	if (!f)printf("Fisierul %s nu poate fi deschis.", nume);
	else 
	{
		list_stud(f);
		printf("\nNumarul matricol: ");scanf("%d", &n);
		while (!feof(stdin))
		{
			nra = 0;
			if (n >= nrart(f, sizeof(student)))printf("\nStudentul nu exista");
			else
			{
				fseek(f, n * sizeof(student), 0);
				fread(&s, sizeof(student), 1, f);
				if (s.is == 0)printf("Studentul nu exista");
				else
				{	
					for (i = 0;i < 15;i++)
					{
						nra = nra + s.abs[i].c + s.abs[i].s;
					}
					printf("Studentul are %d absente", nra);
					
				}
			}
			printf("\nNumarul matricol: ");scanf("%d", &n);
		}
		fclose(f);
	}
}