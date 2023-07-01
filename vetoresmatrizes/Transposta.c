#include <stdio.h>

const int n = 4;
const int m = 4;

void leMatriz(int mat[][n]);
void imprimeMatriz(int mat[][n]);
void matrizTransposta(int mat[m][n], int matt[n][m]);

int main()
{
    int mat[m][n];
    int matt[m][n];
    leMatriz(mat);
    printf("\nmatriz original:\n");
    imprimeMatriz(mat);
    printf("matriz transposta:\n");
    matrizTransposta(mat, matt);
    imprimeMatriz(matt);
}

void leMatriz(int mat[][n])
{
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            scanf("%d", &mat[i][j]);
        }
    }
}

void imprimeMatriz(int mat[][n])
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