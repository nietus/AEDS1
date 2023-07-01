// Antonio Soares Couto Neto 1368777
// 20 / 05 / 2023 exe 2.4

#include <stdio.h>

void leVetor(float v[], int n);
float calcMedia(float v[], int n);
float retMaior(float v[], int n, int *indice);
float retMenor(float v[], int n, int *indice);
void imprimeVetor(float v[], int n);
void imprimeResultados(float media, float maior, int idxmaior, float menor, int idxmenor);

int main()
{
    int n;
    do
    {
        printf("Digite o tamanho do vetor: ");
        scanf("%d", &n);
    } while (n == 2);

    float vetor[n];
    int idxmaior, idxmenor;
    float media, maior, menor;

    leVetor(vetor, n);

    media = calcMedia(vetor, n);
    maior = retMaior(vetor, n, &idxmaior);
    menor = retMenor(vetor, n, &idxmenor);

    printf("Valores do vetor: ");
    imprimeVetor(vetor, n);

    imprimeResultados(media, maior, idxmaior, menor, idxmenor);

    return 0;
}

void leVetor(float v[], int n)
{
    int i;

    for (i = 0; i < n; i++)
    {
        printf("Digite o valor para a posicao %d: ", i + 1);
        scanf("%f", &v[i]);
    }
}

float calcMedia(float v[], int n)
{
    int i;
    float soma = 0.0;

    for (i = 0; i < n; i++)
    {
        soma += v[i];
    }

    return soma / n;
}

float retMaior(float v[], int n, int *indice)
{
    int i;
    float maior = v[0];

    *indice = 0;

    for (i = 1; i < n; i++)
    {
        if (v[i] > maior)
        {
            maior = v[i];
            *indice = i;
        }
    }

    return maior;
}

float retMenor(float v[], int n, int *indice)
{
    int i;
    float menor = v[0];

    *indice = 0;

    for (i = 1; i < n; i++)
    {
        if (v[i] < menor)
        {
            menor = v[i];
            *indice = i;
        }
    }

    return menor;
}

void imprimeVetor(float v[], int n)
{
    int i;

    for (i = 0; i < n; i++)
    {
        printf("%.2f ", v[i]);
    }

    printf("\n");
}

void imprimeResultados(float media, float maior, int idxmaior, float menor, int idxmenor)
{
    printf("Media: %.2f\n", media);
    printf("Maior elemento: %.2f (posicao %d)\n", maior, idxmaior);
    printf("Menor elemento: %.2f (posicao %d)\n", menor, idxmenor);
}