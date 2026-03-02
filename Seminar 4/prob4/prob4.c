#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

typedef struct
{
	int nr, an, grupa, n, note[15];
	char nume[30];
}Student;

void main()
{
	FILE* f, *g;
	char s1[20];
	Student s;
	int i, n, j;
	printf("\n Fisier: "); gets(s1);
	f = fopen(s1, "rb");
	if (!f)printf("\n Fisierul %s nu poate fi deschis ", s1);
	else {
		printf("\n Nr grupa: "); scanf("%d", &grupa);
		while (!feof(stdin))
		{
			rewind(f);
			getchar();
			printf("\n Fisier rezultat: ");gets(s1);
		
			g = fopen(s1, "w");
			fprintf(g, "\n Nume %25s Numar_Matricol An Grupa Note ", " ");
			fread(&s, sizeof(Student), 1, f);
			i = 0;
			while (!feof(stdin))
			{
				if (n == s.nr)
				{
					i = 1;
					fprintf(g, "\n  %-30s %2d %4d %3d",  s.nume, s.nr, s.an, s.grupa);
					for (j = 0;j < s.n;j++)
						fprintf(g, "%2d", s.note[j]);
				}
				fread(&s, sizeof(Student), 1, f);
			}
			if (!i)printf("\n Nu a fost gasit.");
			printf("\n Nr grupa: ");
			scanf("%d", &n);
			fclose(g);
		}
		fclose(f);
	}
}