//#define _CRT_SECURE_NO_WARNINGS
//#include <stdio.h>
//
//typedef struct 
//{
//	int nrm;
//	char nume[30];
//	int grupa;
//	char pcp;
//	char pt[10];
//	char pce;
//}student;
//
//void lista_studenti(FILE* f)
//{
//	char nume[30];
//	student s;
//	FILE* g;
//	int n, i;
//	printf("\nFisier rezultat: ");gets(nume);
//	g = fopen(nume, "w");
//	fprintf(g, "\nNr.   Nr.Mat Nume %15s     Grupa PP     Punctaj teme       Examen", "");
//	fread(&s, sizeof(student), 1, f);
//	n = 0;
//	while (!feof(f))
//	{
//		fprintf(g, "\n%3d %8d %-30s %2d %2d", ++n, s.nrm, s.nume, s.grupa, s.pcp);
//		for (i = 0;i < 10;i++)
//			fprintf(g, "%2d", s.pt[i]);
//		fprintf(g, "%6d", s.pce);
//		fread(&s, sizeof(student), 1, f);
//	}
//	fclose(g);
//}
//void main()
//{
//	FILE* f;
//	student s;
//	char nume[30];
//	int ok, n, j;
//	printf("\nFisier: ");gets(nume);
//	f = fopen(nume, "rb+");
//	if (!f)printf("Fisierul %s nu poate fi deschis", nume);
//	else
//	{
//		lista_studenti(f);
//		printf("\nNr Matricol: ");scanf("%d", &n);
//		while (!feof(stdin))
//		{
//			rewind(f);
//			fread(&s, sizeof(student), 1, f);
//			ok = 0;
//			while (!feof(f) && (ok == 0))
//			{
//				if (n == s.nrm)
//				{
//					ok = 1;
//					printf("\nNr Matricol:%3d Nume: %-30s Grupa: %4d Punctaj pp: %2d\n", s.nrm, s.nume, s.grupa, s.pcp);
//					for (j = 0;j < 10;j++)
//						printf("%2d", s.pt[j]);
//					printf("Punctaj examen: %2d", s.pce);
//					printf("Introduceti punctajul la examen: "); scanf("%d", &s.pce);
//					fseek(f,- sizeof(student), 0);
//					fwrite(&s, sizeof(student), 1, f);
//
//				}
//				else fread(&s, sizeof(student), 1, f);
//			}
//			if (ok == 0)printf("\nNu a fost gasit");
//			printf("\nNr Matricol: ");scanf("%d", &n);
//		}
//		fclose(f);
//	}
//}