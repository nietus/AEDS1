// 2.3 Media
// Antonio Soares Couto Neto, 1368777
// 20/05/2023

#include <stdio.h>
#include <math.h>

void lerVetor(float v[], int n);
void imprimeVetor(float v[], int n);
float calcula_media(float v[], int n);

int main()
{
    int n;
    printf("Tamanho do vetor: ");
    scanf("%d", &n);
    float v[n], soma;
    lerVetor(v, n);
    float media = calcula_media(v, n);
    printf("Media eh: %f", media);
    return 0;
}

void lerVetor(float v[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("Nota da prova [%d]:", i + 1);
        scanf("%f", &v[i]);
    }
}
void imprimeVetor(float v[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%.2f ", v[i]);
    }
}
float calcula_media(float v[], int n)
{
    int soma = 0;
    for (int i = 0; i < n; i++)
    {
        soma += v[i];
    }
    return soma / n;
}