#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
typedef struct {
	char zi;
	char luna;
	char an;
}datai;
typedef struct
{
	char ora;
	char minu;
}oraii;
typedef struct
{
	char ora;
	char minut;
}oraiee;
typedef struct {
	int nrmatricol;
	char nume[30];
	char an;
	int grupa;
	char tip;
	datai data;
	oraii orai;
	oraiee oraie;
	
}student;


void lista_studenti(FILE* f)
{
	char nume[30];
	student s;
	FILE* g;
	int i, n;
	printf("\n Fisierul rezultat: ");gets(nume);
	g = fopen(nume, "w");
	fprintf(g, "\n Nr. Matricol   Nume    An   Grupa  Tip   Data              Ora intrare     Ora Iesire ", " ");
	fread(&s, sizeof(student), 1, f);
	n = 0;
	while (!feof(f))
	{
		fprintf(g, "\n %3d %8d %-30s %2c %2d %2c %2c %2c %2c %2c %2c %2c %2c", ++n, s.nrmatricol, s.nume, s.an, s.grupa, s.tip, s.data.zi, s.data.luna, s.data.an, s.orai.ora, s.orai.minu, s.oraie.ora, s.oraie.minut);
		fread(&s, sizeof(student), 1, f);
	}
	fclose(g);

}
void main()
{
	FILE* f;
	char nume[30];
	student s;
	int n, ok;
	printf("\nFisier: ");gets(nume);
	f = fopen(nume, "rb+");
	if (!f)printf("\n Fifisrul %s nu poate fi deschis", nume);
	else
	{
		lista_studenti(f);
		printf("\n Nr.Matricol: ");scanf("%d", &n);
		while (!feof(stdin))
		{
			rewind(f);
			fread(&s, sizeof(student), 1, f);
			ok = 0;
			while (!feof(f) && (ok == 0))
			{
				if (n == s.nrmatricol)
				{
					ok = 1;
					s.orai.ora = s.oraie.ora = 0;
					s.orai.minu = s.oraie.minut = 0;
					printf(" Nr. Matricol      Nume An Grupa  Tip   Data      Ora intrare     Ora Iesire ", s.nrmatricol, s.nume, s.an, s.grupa, s.tip, s.data.zi, s.data.luna, s.data.an, s.orai.ora, s.orai.minu, s.oraie.ora, s.oraie.minut);
					fseek(f,ftell(f)-sizeof(student), 0);
					fwrite(&s, sizeof(student), 1, f);

				}
				else fread(&s, sizeof(student), 1, f);
			
			}
			if (ok == 0)printf("Nu a fost gasit");
			printf("\n Nr matricol: ");scanf("%d", &n);

		}
		fclose(f);
	}

}