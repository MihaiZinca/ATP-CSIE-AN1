#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
struct stud{
    int nrmatricol,anul,grupa;
    char nume[50], prenume[50];
    float note[10];
};

void scriere_vector(char* nume)
{
    FILE* f;
    int i, j, n;
    stud student;
    f = fopen(nume, "w");
    if (!f) printf("Nu s-a putut deschide fisierul\n");
    else
    {
        printf("Numarul de studenti: ");scanf("%d", &n);

        for (i = 0;i < n;i++)
        {
            printf("\nDate pentru studentul %d\n", i + 1);

            printf("Numar matricol: ");
            scanf("%d", &student.nrmatricol);

            printf("Nume: ");
            scanf("%s", student.nume);

            printf("Prenume: ");
            scanf("%s", student.prenume);

            printf("An: ");
            scanf("%d", &student.anul);

            printf("Grupa: ");
            scanf("%d", &student.grupa);

            printf("Introduceti cele 10 note: ");
            for (j = 0;j < 10;j++)
                scanf("%f", &student.note[j]);

            fprintf(f, "%d %s %s %d %d", student.nrmatricol, student.nume, student.prenume, student.anul, student.grupa);
            for (j = 0;j < 10;j++)
                fprintf(f, " %.2f", student.note[j]);

            fprintf(f, "\n");
        }

        fclose(f);
        printf("\nDatele au fost salvate\n");
    }
}
void main()
{
    char numef[20];
    printf("Introduceti numele fisierului: ");
    scanf("%s", numef);
    scriere_vector(numef);
    FILE* fi;
    stud student;
    int i,c=0;
    float smed = 0, maxi = 0;
    fi = fopen(numef, "r");
    if (!fi) printf("Nu s-a putut deschide fisierul\n");
    else
    {
        while (fscanf(fi, "%d %s %s %d %d", &student.nrmatricol, student.nume, student.prenume, &student.anul, &student.grupa) == 5)
        {
            int ok = 1;
            float sn = 0, med = 0;
            for (i = 0;i < 10;i++)
            {
                fscanf(fi, "%f", &student.note[i]);
                if (student.note[i] < 5.0)ok = 0;
                sn = sn + student.note[i];
            }
            
            if (ok)
            {
                med = sn / 10;
                smed = smed + med;
                c++;

            }
            if (med > maxi)maxi = med;

        }
       fclose(fi);
    }
    if (c > 0) {
        printf("Media generala a studentilor integralisti: %2.f\n", smed / c);
        printf("Cea mai mare medie este: %2.f\n", maxi);
    }
    else printf("Nu exista studenti integralisti");
}