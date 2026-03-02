#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

typedef struct
{
	int nr, an, grupa, n, note[15];
	char nume[30];
}Student;

void main()
{
	FILE* f;
	char s1[20];
	Student s;
	int i, n, j;
	printf("\n Fisier: "); gets(s1);
	f = fopen(s1, "rb");
	if (!f)printf("\n Fisierul %s nu poate fi deschis ", s1);
	else {
		printf("\n Nr matricol: "); scanf("%d", &n);
		while (!feof(stdin))
		{
			rewind(f);
			fread(&s, sizeof(Student), 1, f);
			i = 0;
			while ((!feof(stdin)) && (!i))
			{
				if (n == s.nr)
				{  
					i = 1;
					printf("\n Nr.mat: %3d Nume: %-30s  An:  %2d  Grupa: %4d\n Note: ", s.nr, s.nume, s.an, s.grupa);
					for (j = 0;j < s.n;j++)
						printf("%2d", s.note[j]);
				}
				fread(&s, sizeof(Student), 1, f);
			}
			if (!i)printf("\n Nu a fost gasit.");
			printf("\n Nr matricol: ");
			scanf("%d", &n);
		}
		fclose(f);
	}


}