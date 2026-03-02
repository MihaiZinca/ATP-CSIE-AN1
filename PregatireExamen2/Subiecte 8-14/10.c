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

void list_stud(FILE* f)
{
	char nume[30];
	FILE* g;
	student s;
	int i;
	printf("\n Fisierul rezultat ");gets(nume);
	g = fopen(nume, "w");
	fprintf(g,"\n Nr Matricol   Nume       Grupa PP     Puncte teme             Pe", " ");
	fread(&s, sizeof(student), 1, f);
	while (!feof(f))
	{
		fprintf(g, "%4d %-30s %4d %2c", s.nrm, s.nume, s.grupa, s.pp);
		for (i = 0;i < 10;i++)
			fprintf(g, "%2c", s.pt[i]);
		fprintf(g, "%2c", s.pe);
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
	printf("\nFisierul");gets(nume);
	f = fopen(nume, "rb+");
	if (!f)printf("Fisierul %s nu poate fi deschis ", nume);
	else 
	{
		list_stud(f);
		printf("Nr matricol: ");scanf("%d", &n);
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
					printf("Punctajul obtinut la examen");scanf("%d", pun);
					s.pe = pun;
					fseek(f, ftell(f) - sizeof(student), 0);
					fwrite(&s, sizeof(student), 1, f);
				}
				else fread(&s, sizeof(student), 1, f);
			}
			if (ok == 0)printf("Nu s-a gasit");
			printf("Nr matricol: ");scanf("%d", &n);
		}
		fclose(f);
	}

}