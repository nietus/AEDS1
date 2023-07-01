#include <stdio.h>
#include <math.h>

void lerTemperaturas(float vetor[], int tamanho);
void imprimirTemperaturas(float vetor[], int tamanho);
float calcularMedia(float vetor[], int tamanho);
float calcularDesvioPadrao(float vetor[], int tamanho, float media);

int main()
{
    int n;
    printf("Digite a quantidade de dias: ");
    scanf("%d", &n);

    float temperaturas[n];
    lerTemperaturas(temperaturas, n);

    printf("\nTemperaturas inseridas:\n");
    imprimirTemperaturas(temperaturas, n);

    float media = calcularMedia(temperaturas, n);
    float desvioPadrao = calcularDesvioPadrao(temperaturas, n, media);

    printf("\nTemperatura media: %.2f\n", media);
    printf("Desvio padrão da media: %.2f\n", desvioPadrao);

    return 0;
}

void lerTemperaturas(float vetor[], int tamanho)
{
    for (int i = 0; i < tamanho; i++)
    {
        printf("Insira a temperatura do dia %d: ", i + 1);
        scanf("%f", &vetor[i]);
    }
}

void imprimirTemperaturas(float vetor[], int tamanho)
{
    for (int i = 0; i < tamanho; i++)
    {
        printf("Temperatura do dia %d: %.2f\n", i + 1, vetor[i]);
    }
}

float calcularMedia(float vetor[], int tamanho)
{
    float soma = 0.0;

    for (int i = 0; i < tamanho; i++)
    {
        soma += vetor[i];
    }

    return soma / tamanho;
}

float calcularDesvioPadrao(float vetor[], int tamanho, float media)
{
    float soma = 0.0;

    for (int i = 0; i < tamanho; i++)
    {
        soma += pow(vetor[i] - media, 2);
    }

    return sqrt(soma / tamanho);
}