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
	printf("\nFisierul rezultat: ");gets(nume);
	FILE* g;
	g = fopen(nume, "w");
	int n, i;
	fprintf(g, "\nNr.  NrMatricol  Nume   Grupa PP PunctajTeme         PunctExamen", "");
	fread(&s, sizeof(student), 1, f);
	while (!feof(f))
	{
		fprintf(g, "%2d %4d %-30s %8d %4d %2d", ++n, s.nrm, s.nume, s.grupa, s.pp);
		for (i = 0;i < 10;i++)
			fprintf(g, "%2d", s.pt[i]);
		fprintf(g, "%2d", s.pe);
		fread(&s, sizeof(student), 1, f);
	}
	fclose(g);
}
void main()
{
	char nume[30];
	student s;
	FILE* f;
	int n,ok,pun;
	printf("\nFisierul: ");gets(nume);
	f = fopen(nume, "rb+");
	if (!f)printf("Fisierul %s nu poate fi deschis", nume)
	else
	{
		list_stud(f);
		printf("\nNr matricol:");scanf("%d", &n);
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
					printf("Introduceti punctajul la PP: ");scanf("%d", &pun);
					s.pp = pun;
					fseek(f, ftell(f) - sizeof(student), 0);
					fwrite(&s, sizeof(student), 1, f);
				}
				else fread(&s, sizeof(student), 1, f);

			}
			if (ok == 0)printf("nu s-a putut gasi");
			printf("\nNr matricol:");scanf("%d", &n);
		}
		fclose(f);
	}
}