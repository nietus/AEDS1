#include <stdio.h>
#include <string.h>
const int tam = 2;
typedef struct
{
    char nome[50];
    int idade;
    float h;
    int frequenta;
} Crianca;

void leVetorCrianca(Crianca v[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("\nEntrada crianca %d\n", i + 1);
        printf("===================\n");
        printf("Nome: ");
        scanf("%[^\n]", v[i].nome);
        printf("Idade: ");
        scanf("%d", &v[i].idade);
        printf("Altura: ");
        scanf("%f", &v[i].h);
        printf("Frequenta? (0/1): ");
        scanf("%d", &v[i].frequenta);
        getchar();
    }
}

void imprimeVetorCrianca(Crianca v[], int n)
{
    for (int i = 0; i < n; i++)
    {
        char x;
        if (v[i].frequenta == 0)
            x = 'n';
        else
            x = 's';
        printf("\nNome: %s | Idade: %d | Altura: %.2f | Frequenta: %c\n", v[i].nome, v[i].idade, v[i].h, x);
    }
}

void imprimeCrianca(Crianca c)
{
    char x;
    if (c.frequenta == 0)
        x = 'n';
    else
        x = 's';
    printf("\nNome: %s | Idade: %d | Altura: %.2f | Frequenta: %c\n", c.nome, c.idade, c.h, x);
}

double mediaAlturaCrianca(Crianca v[], int n)
{
    double media = 0;
    for (int i = 0; i < n; i++)
    {
        media += v[i].idade;
    }
    return media / n;
}

int pesquisaCrianca(Crianca v[], int n, char nome[81])
{
    for (int i = 0; i < n; i++)
    {
        if (strcmp(v[i].nome, nome) == 0)
            return i;
    }
    return -1;
}

void intervaloIdadeCrianca(Crianca v[], int n, int menor, int maior)
{
    for (int i = 0; i < n; i++)
    {
        if (v[i].idade >= menor && v[i].idade <= maior)
            printf("\n%s esta no intervalo\n", v[i].nome);
    }
}

int escolaCrianca(Crianca v[], int n)
{
    int contador = 0;
    for (int i = 0; i < n; i++)
    {
        if (v[i].frequenta != 0)
            contador++;
    }
    return contador;
}

int main()
{
    Crianca v[tam];
    char nome[81];
    leVetorCrianca(v, tam);
    double h = mediaAlturaCrianca(v, tam);
    intervaloIdadeCrianca(v, tam, 5, 10);
    printf("Pesquise o nome da crianca: ");
    scanf("%[^\n]", nome);
    int existe = pesquisaCrianca(v, tam, nome);
    if (existe != -1)
        imprimeCrianca(v[existe]);
    int n = escolaCrianca(v, tam);
    printf("\nFrequentam: %d", n);
    return 0;
}