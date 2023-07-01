#include <stdio.h>
#include <string.h>

typedef struct
{
    char nome[10];
    char sobrenome[10];
    char estado[3];
    int dia, mes, ano;
} Pessoa;

void leVetorPessoa(Pessoa v[], int n)
{
    for (int i = 0; i < n; i++)
    {
        scanf(" %s", v[i].nome);
        scanf(" %s", v[i].sobrenome);
        scanf(" %s", v[i].estado);
        scanf("%d", &v[i].dia);
        scanf("%d", &v[i].mes);
        scanf("%d", &v[i].ano);
        getchar();
    }
}

int pesquisaPessoa(Pessoa v[], int n, char nome[], char sobrenome[])
{
    for (int i = 0; i < n; i++)
    {
        if (strcmp(v[i].nome, nome) == 0 && strcmp(v[i].sobrenome, sobrenome) == 0)
            return i;
    }
    return -1;
}

int main()
{
    int tam;
    scanf("%d", &tam);
    Pessoa v[tam];
    leVetorPessoa(v, tam);
    char nome[10];
    char sobrenome[10];
    scanf(" %s", nome);
    scanf(" %s", sobrenome);
    int existe = pesquisaPessoa(v, tam, nome, sobrenome);
    if (existe != -1)
        printf("%s\n0%d/0%d/%d", v[existe].estado, v[existe].dia, v[existe].mes, v[existe].ano);
    return 0;
}