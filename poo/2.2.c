#include <stdio.h>
const int MAX_CONTAS = 2;
typedef struct
{
    int agencia;
    int num_conta;
    char cliente[50];
} conta_bancaria;

int checar_duplicado(conta_bancaria conta[], int tam, int agencia, int numero)
{
    for (int i = 0; i < tam; i++)
    {
        if (conta[i].agencia == agencia && conta[i].num_conta == numero)
        {
            return 1;
        }
    }
    return 0;
}

void cadastro(conta_bancaria conta[])
{
    for (int i = 0; i < MAX_CONTAS;)
    {
        printf("Num da agencia %d : ", i + 1);
        scanf("%d", &conta[i].agencia);
        printf("Num da conta %d : ", i + 1);
        scanf("%d", &conta[i].num_conta);
        if (checar_duplicado(conta, i, conta[i].agencia, conta[i].num_conta))
        {
            printf("Conta duplicada. Tente novamente.\n");
        }
        else
        {
            getchar();
            printf("Nome do cliente %d : ", i + 1);
            scanf("%[^\n]", conta[i].cliente);
            i++;
        }
    }
}

void display(conta_bancaria conta[])
{
    for (int i = 0; i < MAX_CONTAS; i++)
    {
        printf("Agencia %d: %d\n", i + 1, conta[i].agencia);
        printf("Numero da conta %d: %d\n", i + 1, conta[i].num_conta);
        printf("Cliente %d: %s\n", i + 1, conta[i].cliente);
    }
}

int main()
{
    conta_bancaria conta[MAX_CONTAS];
    cadastro(conta);
    display(conta);
    return 0;
}