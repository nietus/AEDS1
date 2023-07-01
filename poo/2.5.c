#include <stdio.h>

const int t = 2;
const int p = 2;

typedef struct
{
    int cod;
    char desc[100];
    float valor;
} Tit;

typedef struct
{
    int reg;
    char nome[50];
    int num_title;
    int total;
    // Tit titulo;
} Prof;

void leTitVetor(Tit v[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("\nEntrada Titulo %d\n", i + 1);
        printf("=================\n");
        printf("Descricao: ");
        scanf(" %[^\n]", v[i].desc);
        printf("Codigo: ");
        scanf("%d", &v[i].cod);
        printf("Valor hora/aula: ");
        scanf("%f", &v[i].valor);
        getchar();
    }
}

void leProfVetor(Prof v[], int n)
{
    for (int i = 0; i < n; i++)
    {
        // v[i].titulo.desc;
        printf("\nEntrada Profe %d\n", i + 1);
        printf("=================\n");
        printf("Nome: ");
        scanf(" %[^\n]", v[i].nome);
        printf("Registro: ");
        scanf("%d", &v[i].reg);
        printf("Total h/semana: ");
        scanf("%d", &v[i].total);
        printf("Codigo do titulo: ");
        scanf("%d", &v[i].num_title);
        getchar();
    }
}

void imprimeVetor(Prof v[], Tit z[], int n, int t)
{
    for (int i = 0; i < n; i++)
    {
        printf("Registro: %d | Nome: %s | Titulo: %s | Valor h/a: R$%.2f | Total h/semana: %d | Total Geral semanal: R$%.2f\n",
               v[i].reg, v[i].nome, z[v[i].num_title].desc, z[v[i].num_title].valor,
               v[i].total, z[v[i].num_title].valor * v[i].total);
    }
}

int main()
{
    Tit ti[t];
    Prof pr[p];
    leTitVetor(ti, t);
    leProfVetor(pr, p);
    imprimeVetor(pr, ti, p, t);
    return 0;
}