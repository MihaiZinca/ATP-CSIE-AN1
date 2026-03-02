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

void lista_stud(FILE* f)
{
	char nume[30];
	student s;
	FILE* g;
	int n,i;
	printf("\nFisierul rezultat: ");gets(nume);
	g = fopen(nume, "w");
	fprintf(g, "\nNr.  Nr.Matricol   Nume    Grupa  PP    PunctajTeme   Puncte Examen", "");
	fread(&s, sizeof(student), 1, f);
	n = 0;
	while (!feof(f))
	{
		fprintf(g, "\n%3d  %10d %-30s %2d %2d", ++n, s.nrm, s.nume, s.grupa, s.pp);
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
	int n, ok,pun,i;
	printf("\nFisier: ");gets(nume);
	f = fopen(nume, "rb+");
	if (!f)printf("Fisierul %s nu poate fi deschis", nume);
	else
	{
		lista_stud(f);
		printf("\nNr.Matricol: ");scanf("%d", &n);
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
					printf("\n Nr.mat: %3d Nume:  %-30s Grupa: %4d PP: %2d Punctaj examen:", s.nrm, s.nume, s.grupa, s.pp);
					for (i = 0;i < 10;i++)
						printf("%2d", s.pt[i]);
					printf("Punctaj examen: %2d ", s.pe);
					printf("Punctajul obtinut la examen este: ");scanf("%d", &pun);
					s.pe = pun;
					fseek(f, ftell(f) - sizeof(student), 0);
					fwrite(&s, sizeof(student), 1, f);
				}
				else fread(&s, sizeof(student), 1, f);
	
			}
			if (ok == 0)printf("Nu s-a gasit");
			printf("\nNr.Matricol: ");scanf("%d", &n);

		}
		fclose(f);
	}
}