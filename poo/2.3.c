#include <stdio.h>
#include <stdlib.h>
const int MAX_CONTAS = 100;
typedef struct
{
    int agencia;
    int num_conta;
    char cliente[50];
    float saldo;
} conta_bancaria;

int checar_duplicado(conta_bancaria **conta, int tam, int numero, int id)
{
    for (int i = 0; i < tam; i++)
    {
        if (i == id)
        {
            break;
        }
        if (conta[i]->num_conta == numero)
        {
            printf("\nJa existe!\n");
            return 1;
        }
    }
    return 0;
}

void cadastro(conta_bancaria **conta, int *id, int tam)
{
    do
    {
        printf("Num da conta %d : ", *id + 1);
        scanf("%d", &conta[*id]->num_conta);
    } while (checar_duplicado(conta, tam, conta[*id]->num_conta, *id));
    getchar();
    printf("Nome do cliente %d : ", *id + 1);
    scanf("%[^\n]", conta[*id]->cliente);
    printf("Saldo do cliente %d : ", *id + 1);
    scanf("%f", &conta[*id]->saldo);
    printf("Num da agencia %d : ", *id + 1);
    scanf("%d", &conta[*id]->agencia);
    (*id)++;
}

void display(conta_bancaria **conta, int tam)
{
    for (int i = 0; i < tam; i++)
    {
        printf("\nCliente: %s | Saldo: %.2f | Agencia: %d | Conta: %d\n", conta[i]->cliente, conta[i]->saldo, conta[i]->agencia, conta[i]->num_conta);
    }
}

void maior_saldo(conta_bancaria **conta, int tam)
{
    float maior = conta[0]->saldo;
    int idx = 0;
    for (int i = 1; i < tam; i++)
    {
        if (maior < conta[i]->saldo)
        {
            maior = conta[i]->saldo;
            idx = i;
        }
    }
    printf("\nCliente: %s | Saldo: %.2f | Agencia: %d | Conta: %d\n", conta[idx]->cliente, conta[idx]->saldo, conta[idx]->agencia, conta[idx]->num_conta);
}

void menor_saldo(conta_bancaria **conta, int tam)
{
    float menor = conta[0]->saldo;
    int idx = 0;
    for (int i = 1; i < tam; i++)
    {
        if (menor > conta[i]->saldo)
        {
            menor = conta[i]->saldo;
            idx = i;
        }
    }
    printf("\nCliente: %s | Saldo: %.2f | Agencia: %d | Conta: %d\n", conta[idx]->cliente, conta[idx]->saldo, conta[idx]->agencia, conta[idx]->num_conta);
}

void media(conta_bancaria **conta, int tam)
{
    float total = 0;
    for (int i = 0; i < tam; i++)
    {
        total += conta[i]->saldo;
    }
    printf("%.2f", total / tam);
}

void excluir_conta(conta_bancaria **conta, int *id)
{
    int num;
    printf("Qual o numero da conta a ser excluida >> ");
    scanf("%d", &num);
    for (int i = 0; i < *id; i++)
    {
        if (conta[i]->num_conta == num)
        {
            free(conta[i]);
            (*id)--;
            for (int j = i; j < *id; j++)
            {
                conta[j] = conta[j + 1];
            }
        }
    }
}

int main()
{
    int id = 0;
    char v;
    conta_bancaria **conta;
    conta = malloc(MAX_CONTAS * sizeof(conta_bancaria *));
    for (int i = 0; i < MAX_CONTAS; i++)
        conta[i] = malloc(MAX_CONTAS * sizeof(conta_bancaria));
    do
    {
        printf("\na. Sair;\nb. Cadastrar uma conta;\nc. Visualizar todas as contas;\nd. Mostrar informacoes da conta que possui o maior saldo;\ne. Mostrar informacoes da conta com menor saldo;\nf. Calcular a media dos saldos dos correntistas;\ng. Excluir uma conta.\n >> ");
        scanf(" %c", &v);
        switch (v)
        {
        case 'a':
            break;
        case 'b':
            cadastro(conta, &id, MAX_CONTAS);
            break;
        case 'c':
            display(conta, id);
            break;
        case 'd':
            maior_saldo(conta, id);
            break;
        case 'e':
            menor_saldo(conta, id);
            break;
        case 'f':
            media(conta, id);
            break;
        case 'g':
            excluir_conta(conta, &id);
            break;
        }
    } while (v != 'a');
    free(conta);
    return 0;
}