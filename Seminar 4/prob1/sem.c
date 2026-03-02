#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

typedef struct
{
	int nr, an, grupa, n, note[15];
	char nume[30];
}Student;
void main()
{
	char s1[20];
	FILE* f;
	Student s;
	int i;
	printf("\n Introduceti numele fisierului pe care doriti sa l creati: "); gets(s1);
	f = fopen(s1, "wb");
	printf("Nr matricol: ");scanf("%d", &s.nr);
	while (!feof(stdin)) // citeste de la tastatura datele pana cand se ajunge la sfarsitul fisierului
	{ 
		printf("Numele Studentului: ");
		getchar();  // cingetline in c++ ne pune spatiu adc
		gets(s.nume);
		printf("An: ");scanf("%d", &s.an);
		printf("Grupa: "); scanf("%d", &s.grupa);
		printf("Nr.de note: (<15)");scanf("%d", &s.n);
		for (i = 0;i < s.n;i++)
		{
			printf("Note %d: ", i + 1);
			scanf("%d", &s.note[i]);

		}
		fwrite(&s, sizeof(Student), 1, f);
		printf("Nr matricol: ");scanf("%d", &s.nr);

	}
	fclose(f);
}
