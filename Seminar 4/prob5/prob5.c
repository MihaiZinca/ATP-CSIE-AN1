#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

typedef struct {
    int nr, an, grupa, n, note[15], nAtp[15];
    char nume[30];
} Student;

void main() {
    FILE* f;
    char s1[20];
    Student s;
    int i, n, j, nt[15], x, gasit;

    printf("\n Fisier: ");gets(s1);
    f = fopen(s1, "rb+");
    if (!f) 
        printf("\n Fisierul %s nu poate fi deschis.", s1);
    else {
        printf("\n Nr matricol: ");scanf("%d", &n);

        printf("\n Cate note doriti sa adaugati la ATP? ");
        scanf("%d", &x);

        if (x > 15) printf("\n Nu se pot introduce mai mult de 15 note.");
        else {
            for (i = 0; i < x; i++) 
            {
                printf("\n Introduceti nota %d la ATP: ", i + 1);
                scanf("%d", &nt[i]);
            }
            rewind(f);
            fread(&s, sizeof(Student), 1, f);
            gasit = 0;
            while ((!feof(stdin)) && (!gasit))
            {
                if (n == s.nr) 
                {
                    gasit = 1;

                    if (s.n + x > 15) {
                        printf("\n Nu se pot adauga toate notele, depaseste limita de 15");
                        break;
                    }

                    printf("\n Notele actualizate la ATP sunt: ");
                    for (j = 0; j < x; j++) {
                        s.nAtp[s.n++] = nt[j];
                        printf("%2d ", nt[j]);
                    }

                    fseek(f, -sizeof(Student), SEEK_CUR);
                    fwrite(&s, sizeof(Student), 1, f);
                }
            }
        
            if (!gasit) printf("\n Studentul cu nr. matricol %d nu a fost gasit.", n);
        }
        fclose(f);
    }
}