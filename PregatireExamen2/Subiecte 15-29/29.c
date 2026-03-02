#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

typedef struct
{
	int nrm;
	char nume[30];
	int grupa;
	char pp;
	char pt[i];
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
	fprintf(g, "\nNr. Nr.Matricol  Nume          Grupa  PP  PuncteTeme     PP", "");
	fread(&s, sizeof(student), 1, f);
	while (!feof(f))
	{
		if (s.is == 1)
		{
			fprintf(g, "%4d %4d %-15s %4d %4d", ++n, s.nrm, s.nume, s.grupa, s.pp);
			for (i = 0;i < 10;i++)
				fprintf(g, "%-2d", s.pt[i]);
			fprintf(g, "%2d", s.pe);
		}
		fread(&s, sizeof(student), 1, f);
	}
	fclose(g);
}

void main()
{
	student s;
	char nume[30];
	FILE* f;
	int n;
	printf("\nFisierul: ");gets(nume);
	f = fopen(nume, "rb+");
	if (!f)printf("Fisierul %s nu poate fi deschis", nume);
	else
	{
		list_stud(f);
		printf("\nNr.Matricol:");scanf("%d", &n);
		while (!feof(stdin))
		{
			if (n >= mrart(f, sizeof(student)))printf("Studentul nu exista");
			else
			{
				fseek(f, n * sizeof(student), 0);
				fread(&s, sizeof(student), 1, f);
				if (s.is == 0)printf("Studentul nu exista");
				else
				{
					sum = s.pp + s.pe + 10;
					for (i = 0;i < 10;i++)
						sum = sum + s.pt[i];
					if (sum / (10.0) > 8)printf("Studentul %s a obinut note peste 8", s.nume);

				}
			}
			printf("\nNr.Matricol: ");scanf("%d", &n);
		}
		fclose(f);
	}
}