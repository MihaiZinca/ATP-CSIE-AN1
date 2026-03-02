#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

typedef struct
{
	char c, s;
}as;
typedef struct
{
	char is;
	int nrm;
	char nume[25];
	int grupa;
	char an;
	as abs[15];
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
	int n=0, i;
	FILE* g;
	printf("\nFisierul rezultat: ");gets(nume);
	g = fopen(nume, "w");
	fprintf(g, "\nNr.   NrMatricol    Nume     Grupa  An  Absente   ", "");
	fread(&s, sizeof(student), 1, f);
	while (!feof(f))
	{
		if (s.is == 1)
		{
			fprintf(g, "%4d %4d %-30s %4d %4d", ++n, s.nrm, s.nume, s.grupa, s.an);
			for (i = 0;i < 15;i++)
				fprintf(g, "%-2d %-2d", s.abs[i].c, s.abs[i].s);
		}
		fread(&s, sizeof(student), 1, f);
	}
	fclose(g);
}
// Funcție pentru a crea un fișier binar cu datele studenților
void create_binary_file() {
	char nume_fisier[30];
	student s;
	FILE* f;
	int n, i, j;

	printf("\nIntroduceti numele fisierului binar: ");
	scanf("%s", nume_fisier);
	f = fopen(nume_fisier, "wb");
	if (!f) {
		printf("Eroare la crearea fisierului %s!\n", nume_fisier);
		return;
	}

	printf("\nNumar de studenti: ");
	scanf("%d", &n);
	for (i = 0; i < n; i++) {
		printf("\nIntroduceti datele pentru studentul %d:\n", i + 1);
		s.is = 1;
		printf("Numar matricol: "); scanf("%d", &s.nrm);
		printf("Nume: "); scanf("%s", s.nume);
		printf("Grupa: "); scanf("%d", &s.grupa);
		printf("An: "); scanf(" %c", &s.an);

		printf("Introduceti absentele pentru cele 15 discipline (curs, seminar):\n");
		for (j = 0; j < 15; j++) {
			printf("Disciplina %d: ", j + 1);
			scanf(" %hhd %hhd", &s.abs[j].c, &s.abs[j].s);
		}
		fwrite(&s, sizeof(student), 1, f);
	}
	fclose(f);
	printf("\nFisierul binar %s a fost creat cu succes!\n", nume_fisier);
}

void main()
{
	char nume[30];
	student s;
	FILE* f;
	int n, i,maxi=0;
	// Creare fisier binar
	//create_binary_file();
	printf("\nFisierul: ");gets(nume);
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
					if (s.abs[0].s > maxi) maxi = s.abs[0].s;

				}
			}
			printf("\nNr matricol: ");scanf("%d", &n);
		}
		fseek(f, 0, 0);
		fread(&s, sizeof(student), 1, f);
		while (!feof(f))
		{
			if (s.is == 1)
					if(s.abs[0].s == maxi) printf("\n %s", s.nume);
			fread(&s, sizeof(student), 1, f);
		}
		fclose(f);
	}

}