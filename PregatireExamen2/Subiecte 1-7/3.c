#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

typedef struct
{
	char zi;
	char luna;
	int an;

}datai;
typedef struct
{
	char ora;
	char minut;
}oraii;
typedef struct
{
	char ora;
	char minut;
}oraiee;
typedef struct
{
	int nrmatricol;
	char nume[30];
	char an;
	int grupa;
	char tip;
	datai data;
	oraii orai;
	oraiee oraie;
}student;

void listare_studenti(FILE* f)
{
	char nume[30];
	student s;
	FILE* g;
	printf("\n Fisierul rezultat: ");gets(nume);
	g = fopen(nume, "w");
	fprintf(g, "\n Nr.crt   Nr.Matricol   Nume %15s  An  Grupa   Tip  Data            OraIntrare        OraIesire ", " ");
	fread(&s, sizeof(student), 1, f);
	n = 0;
	while (!feof(f))
	{
		fprintf(g, "\n %3d %4d  %-30s %4s %8d %4s %2s %2s %2s %3s %3s %3s %3s", ++n, s.nrmatricol, s.nume, s.an, s.grupa, s.tip, s.data.zi, s.data.luna, s.data.an, s.orai.ora, s.orai.minut, s.oraie.ora, s.oraie.minut);
		fread(&s, sizeof(student), 1, f);
	}
	fclose(g);
}
void main()
{	
	FILE* f;
	char nume[30];
	int n, ok;
	printf("\nFisierul: ");gets(nume);
	f = fopen(nume, "rb+");
	if (!f)printf("Fisierul %s nu poate fi deschis",nume);
	else
	{
		listare_studenti(f);
		printf("\n Nr matricol: ");scanf("%d", &n);
		while (!feof(stdin))
		{
			rewind(f);
			fread(&s, sizeof(student), 1, f);
			ok = 0;
			while (!feof(f) && (ok == 0))
			{
				if (n == s.nrmatricol && s.tip == 'L')
				{
					ok = 1;
					if (s.oraie.minut < s.orai.minut) {
						s.oraie.minut += 60;
						s.oraie.ora--;
					}
					min = min + s.oraie.minut - s.orai.minut;
					ora = ora + s.oraie.ora - s.orai.ora;
					if (min >= 60) {
						min -= 60;
						ora++;
					}
					if (ora == 0 && min == 0)printf("Studentul nu a vizitat.");
					else printf("Studentul a fost %d ore si %d minute", ora, min);
				}
				else fread(&s, sizeof(student), 1, f);
			}
			if (ok == 0)printf("Nu a fost gasit");
			printf("\n Nr matricol: "); scanf("%d", &n);

		}
		fclose(f);
	}

}