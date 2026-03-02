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
	int n, i;
	printf("\nFisierul:");gets(nume);
	g = fopen(nume, "w");
	fprintf(g, "\nNr.  Nr.Matricol  Nume   Grupa PP Puncte_teme       Puncte_examen", "");
	fread(&s, sizeof(student), 1, f);
	while (!feof(f))
	{
		fprintf(g, "%2d %4d %-30s %4d %4d", ++n, s.nrm, s.nume, s.grupa, s.pp);
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
	float med,maxi;
	int i, sum;
	printf("\nFisierul rezultat: ");gets(nume);
	f = fopen(nume, "rb+");
	if (!f)printf("Produsul %s nu poate fi deschis.", nume);
	else 
	{
		list_stud(f);
		fread(&s, sizeof(student), 1, f);
		while (!feof(f))
		{
			sum = s.pp;
			for (i = 0;i < 10;i++)
				sum = sum + s.pt[i];
			sum = sum + s.pe;
			sum = sum + 10;
			med = sum / 10.0;
			if (med > maxi)maxi = med;		
			fread(&s, sizeof(student), 1, f);
		}
		printf("Cea mai mare medie a fost %.2f, obtinuta de :\n", maxi);
		rewind(f); // poz la inceputul fisierului
		fread(&s, sizeof(student), 1, f);
		while (!feof(f))
		{
			sum = s.pp;
			for (i = 0;i < 10;i++)
				sum = sum + s.pt[i];
			sum = sum + s.pe;
			sum = sum + 10;
			med = sum / 10.0;
			if (med == maxi)printf("%d %s %d\n", s.nrm, s.nume, s.grupa);
			fread(&s, sizeof(student), 1, f);
		}
		fclose(f);
	}
}