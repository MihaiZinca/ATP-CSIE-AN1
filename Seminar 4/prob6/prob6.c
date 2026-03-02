#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int nr, an, grupa, n, note[15], nAtp[15];
    char nume[30];
} Student;

void main() {
    FILE* f;
    char s1[20];
    Student s;
    int grupaCautata, i;

    printf("\n Numele fisierului: "); gets(s1);

    f = fopen(s1, "rb+"); 
    if (!f) 
        printf("\n Fisierul %s nu poate fi deschis. ", s1);
    else {

        printf("\n Introduceti grupa pentru care se adauga punctul din oficiu: ");
        scanf("%d", &grupaCautata);

        while (fread(&s, sizeof(Student), 1, f)) {
            if (s.grupa == grupaCautata)
            {
                printf("\n Modificari pentru studentul: %s\n", s.nume);
                for (i = 0; i < s.n; i++)
                {
                    s.nAtp[i] += 1;
                    if (s.nAtp[i] > 10) s.nAtp[i] = 10;
                }

                fseek(f, -sizeof(Student), SEEK_CUR);
                fwrite(&s, sizeof(Student), 1, f);
            }
        }

        fclose(f);
    }
}
