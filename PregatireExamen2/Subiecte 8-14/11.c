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
	FILE* g;
	printf("\nFisierul rezultat: ");gets(nume);
	g = fopen(nume, "w");
	fprintf(g,"\nNr.  Nr.Matricol   Nume   Grupa  PP   Puncte teme    Puncte examen", "");
	fread(&s, sizeof(student), 1, f);
	int n,i;
	while (!feof(f))
	{
		fprintf(g, "%4d %8d %-30s %4d %2d", ++n;s.nrm, s.nume, s.grupa, s.pp);
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
	printf("\nFisierul: ");gets(nume);
	int sum, i, nr = 0;
	float r;
	f = fopen(nume, "rb+");
	if (!f)printf("Fisierul %s nu poate fi deschis.", nume);
	else
	{
		list_stud(f);
		fread(&s, sizeof(student), 1, f);
		while (!feof(f)) 
		{
			sum = s.pp;
			for (i = 0;i < 10;i++)
				sum = sum + p.pt[i];
			sum = sum + s.pe;
			r = sum / 10.0;
			if (r > 8) 
			{
				nr++;
				printf("%d %s %d %2.f\n", s.nrm, s.nume, s.grupa, r);
			}
			fread(&s, sizeof(student), 1, f);

		}
		if (nr == 0)printf("Niciun student nu indepl cond");
		else printf("%d au obinut note mai mari decat 8", nr);
		fclose(f);
	}
}