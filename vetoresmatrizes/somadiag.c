#include <stdio.h>

const int n = 2;
const int m = 2;

void leMatriz(float mat[][n], int m);
float somaDiagPrincipal(float M[][n], int m);

int main()
{
    float mat[m][n];
    leMatriz(mat, m);
    float sum = somaDiagPrincipal(mat, m);
    printf("Soma diag principal > %f", sum);
    return 0;
}

void leMatriz(float mat[][n], int m)
{
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            scanf("%f", &mat[i][j]);
        }
    }
}

float somaDiagPrincipal(float mat[][n], int m)
{
    float soma = 0;
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i == j)
                soma += mat[i][j];
        }
    }
    return soma;
}