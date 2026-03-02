#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

typedef struct
{
	char c, s;
}disc;
typedef struct
{
	char is;
	int nrm;
	char nume[25];
	int grupa;
	char an;
	disc abs[15];
}stud;

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
	stud st;
	FILE* g;
	int n, i;
	printf("\nFisier rezultat: ");gets(nume);
	g = fopen(nume, "w");
	fprintf(g, "\n Nr:    Nr.Matricol  Nume				Grupa	An	Absente curs si seminar");
	fread(&st, sizeof(stud), 1, f);
	n = 0;
	while (!feof(f))
	{
		if (st.is == 1)
		{
			fprintf(g, "\n %3d %8d %-30s %6d %4c ++n, st.nrm, st.nume, st.grupa, st.an);
			for (i = 0;i < 15;i++)
				fprintf(g, "%2c,%2c", st.abs[i].c, st.abs[i].s);
		}
		fread(&st, sizeof(stud), 1, f);
	}
	fclose(g);
}
void main()
{
	char nume[30];
	stud s;
	FILE* f;
	int n;
	printf("Fisierul: ");gets(nume);
	f = fopen(nume, "rb+");
	if (!f)printf("\nFisierul %s nu poate fi deschis.",nume);
	else {
		lista_stud(f);
		printf("\nNumar matricol: ");scanf("%d", &n);
		while (!feof(stdin))
		{
			if (n >= nrart(f,sizeof(stud)))printf("Studentul nu exista.");
			else {
				fseek(f, n * sizeof(stud), 0);
				fread(&s, sizeof(stud), 1, f);
				if (s.is == 0)printf("Studentul nu exista.");
				else {
					fseek(f, n * sizeof(stud), 0);
					printf("Studentul %s va fi examatriculat.", s.nume);
					s.is = 0;
					fwrite(&s, sizeof(stud), 1, f);
				}
			}
			printf("\nNumar matricol: ");scanf("%d", &n);

		}
		fclose(f);
	}
}