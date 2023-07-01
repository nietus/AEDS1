#include <stdio.h>

const int n = 4;
const int m = 4;

void leMatriz(int mat[][n], int m);
void imprimeMatriz(int mat[][n], int m, int n);
void matrizTransposta(int mat[m][n], int matt[n][m]);
void inverteDiagonaisMat(int mat[][n], int m);

int main()
{
    int mat[m][n];
    int matt[m][n];
    leMatriz(mat, m);
    printf("\nmatriz original:\n");
    imprimeMatriz(mat, m, n);
    printf("matriz transposta:\n");
    matrizTransposta(mat, matt);
    imprimeMatriz(matt, m, n);
    printf("matriz com diagonais invertidas:\n");
    inverteDiagonaisMat(mat, m);
    imprimeMatriz(mat, m, n);
}

void leMatriz(int mat[][n], int m)
{
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            scanf("%d", &mat[i][j]);
        }
    }
}

void imprimeMatriz(int mat[][n], int m, int n)
{
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("%d ", mat[i][j]);
        }
        printf("\n");
    }
}

void matrizTransposta(int mat[m][n], int matt[n][m])
{
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            matt[i][j] = mat[j][i];
        }
    }
}

void inverteDiagonaisMat(int mat[][n], int m)
{
    int aux;
    for (int i = 0; i < n; i++)
    {
        aux = mat[i][i];
        mat[i][i] = mat[i][m - 1 - i];
        mat[i][n - 1 - i] = aux;
    }
}