#include <stdio.h>
//Daca p=1 => A  Daca p=0 => I
// A^p=A * A^(p-1)
void inmultiremat(int a[10][10], int b[10][10], int c[10][10], int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            c[i][j] = 0;
            for (int k = 0; k < n; k++)
                c[i][j] += a[i][k] * b[k][j];

        }
    }
}
void mIden(int a[10][10], int n)
{
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            a[i][j] = (i == j) ? 1 : 0;
}
void cop(int s[10][10], int d[10][10], int n)
{
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            d[i][j] = s[i][j];
}
void puterem(int a[10][10], int rez[10][10], int n, int p)
{
    if (p == 0) 
       return mIden(rez, n);
    if (p == 1) 
     return cop(a, rez, n);
     
    int temp[10][10];
    puterem(a, temp, n, p - 1);
    inmultiremat(a, temp, rez, n);
}
