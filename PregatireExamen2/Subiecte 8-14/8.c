#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

typedef struct {
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
	student s;
	FILE* g;
	int i;
	printf("\nFisierul rezultat: ");gets(nume);
	g = fopen(nume, "w");
	fprintf(g,"\n Nr.Matricol   Nume   Grupa   Pp   PTeme         PE", "");
	fread(&s, sizeof(student), 1, f);
	while (!feof(f))
	{
		fprintf(g, "%4d %-30s %2d %2c ", s.nrm, s.nume, s.grupa, s.pp);
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
	FILE* f;
	student s;
	int n,ok,punct;
	printf("\nFisier:");gets(nume);
	f = fopen(nume, "rb+");
	if (!f)printf("Fisierul %s nu poate fi deschis", nume);
	else 
	{
		lista_studenti(f);
		printf("Nr matricol"); scanf("%d", &n);
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
					printf("Punctaj la proba practica:");scanf("%d", &punct);
					s.pp = punct;
					fseek(f, ftell(f) - sizeof(student), 0);
					fwrite(&s, sizeof(student), 1, f);
				}
				else fread(&s, sizeof(student), 1, f);

			}
			if (ok == 0)printf("Nu s-a gasit");
			printf("Nr Matricol"); scanf("%d", &n);
		}
		fclose(f);
	}
}