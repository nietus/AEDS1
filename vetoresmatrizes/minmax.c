#include <stdio.h>

int main()
{
    int m, n, elemento, minmaxi = 0, minmaxj = 0;
    scanf("%d %d", &m, &n);
    int matriz[m][n];
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            scanf("%d", &matriz[i][j]);
            if (i == 0 && j == 0)
                elemento = matriz[i][j];
            if (elemento > matriz[i][j])
            {
                elemento = matriz[i][j];
                minmaxi = i;
            }
        }
    }
    for (int i = 0; i < m; i++)
    {
        if (i == 0)
            elemento = matriz[minmaxi][0];
        if (matriz[minmaxi][i] > elemento)
        {
            elemento = matriz[minmaxi][i];
            minmaxj = i;
        }
    }

    printf("%d\n", elemento);
    printf("%d %d", minmaxi, minmaxj);
    return 0;
}
