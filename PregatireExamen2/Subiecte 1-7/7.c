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

void lista_studenti(FILE* f)
{
	char nume[30];
	FILE* g;
	printf("\nFisierul rezultat: ");gets(nume);
	g = fopen(nume, "w");
	int n, i;
	fprintf(g, "\n Nr.crt  Nr.Matricol    Nume     Grupa    PP   Punctaj teme                                   Puncte examen", " ");
	fread(&s, sizeof(student), 1, f);
	n = 0;
	while (!feof(f))
	{
		fprintf(g, "\n%3d %8d %-30s %4d %4c ", ++n, s.nrm, s.nume, s.grupa, s.pp);
		for (i = 0;i < 10;i++)
			fprintf(g, "%2d", s.pt[i]);
		fprintf(g, "%2s", s.pe);
		fread(&s, sizeof(student), 1, f);
	}
	fclose(g);
}
void main()
{
	char nume[30];
	student s;
	FILE* f;
	int i,n;
	printf("\nFisierul ");gets(nume);
	f = fopen(nume, "rb+");
	if (!f)printf("Fisi %s nu poate fi deschis", nume);
	else
	{
		lista_studenti(f);
		fseekf(f, 0, 2);
		printf("Nr matricol: ");scanf("%d", &s.rnm);
		while (!feof(stdin))
		{
			printf("Nume: "); getchar(); scanf("%s", s.nume);
			printf("Grupa: ");scanf("%d",& s.grupa);
			s.pp = 0;
			for (i = 0;i < 10;i++)
				s.pt[i] = 0;
			s.pe = 0;
			fwrite(&s, sizeof(student), 1, f);
			printf("Nr matricol: ");scanf("%d", &s.nrm);

		}

		fclose(f);
	}
}