#include <stdio.h>
#include <math.h>

void lerVetor(float v[], int n);
void imprimeVetor(float v[], int n);
void imprime_elemento_impar(float v[], int n);
void imprime_elemento_par(float v[], int n);
float calcula_media(float v[], int n, float *soma);
void imprime_maior_menor(float v[], int n);
void imprime_potencia(float v[], int n);
void imprime_vetor_invertido(float v[], int n);

int main()
{
    int n;
    printf("Tamanho do vetor: ");
    scanf("%d", &n);
    float v[n], soma;
    lerVetor(v, n);
    printf("\nVetor original:\n");
    imprimeVetor(v, n);
    printf("\nElementos impares:\n");
    imprime_elemento_impar(v, n);
    printf("\nElementos pares:\n");
    imprime_elemento_par(v, n);
    float media = calcula_media(v, n, &soma);
    printf("\nMedia: %f, Soma: %f\n", media, soma);
    imprime_maior_menor(v, n);
    printf("\nPotencias:\n");
    imprime_potencia(v, n);
    printf("\nVetor invertido:\n");
    imprime_vetor_invertido(v, n);
    return 0;
}

void lerVetor(float v[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("Valor [%d]:", i);
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
void imprime_elemento_impar(float v[], int n)
{
    for (int i = 0; i < n; i++)
    {
        int a = v[i]; // ou (int)v[i]
        if (a % 2 == 0)
        {
            continue;
        }
        else
        {
            printf("%.2f ", v[i]);
        }
    }
}

void imprime_elemento_par(float v[], int n)
{
    for (int i = 0; i < n; i++)
    {
        int a = v[i]; // ou (int)v[i]
        if (a % 2 == 0)
        {
            printf("%.2f ", v[i]);
        }
        else
        {
            continue;
        }
    }
}

float calcula_media(float v[], int n, float *soma)
{
    for (int i = 0; i < n; i++)
    {
        *soma += v[i];
    }
    return *soma / n;
}

void imprime_maior_menor(float v[], int n)
{
    float maior = v[0], menor = v[0];
    int maior_i = 0, menor_i = 0;
    for (int i = 1; i < n; i++)
    {
        if (v[i] > maior)
        {
            maior = v[i];
            maior_i = i;
        }
        if (v[i] < menor)
        {
            menor = v[i];
            menor_i = i;
        }
    }
    printf("Maior: %f de indice %d, Menor: %f de indice %d", maior, maior_i, menor, menor_i);
}

void imprime_potencia(float v[], int n)
{
    float a[n];
    for (int i = 0; i < n; i++)
    {
        int b = v[i];
        if (b % 2 == 0)
        {
            a[i] = pow(b, 2);
        }
        else
        {
            a[i] = pow(b, 3);
        }
    }
    for (int i = 0; i < n; i++)
    {
        printf("%.2f ", a[i]);
    }
}

void imprime_vetor_invertido(float v[], int n)
{
    float inv[n];
    for (int i = 0; i < n; i++)
    {
        inv[i] = v[n - 1 - i];
        printf("%.2f ", inv[i]);
    }
}
