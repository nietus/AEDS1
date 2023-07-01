#include <stdio.h>
typedef struct
{
    int agencia;
    int num_conta;
    char cliente[50];
} conta_bancaria;

void cadastro(conta_bancaria *conta)
{
    printf("Num da agencia : ");
    scanf("%d", &conta->agencia);
    printf("\n");
    printf("Num da conta: ");
    scanf("%d", &conta->num_conta);
    printf("\n");
    getchar();
    printf("Nome do cliente: ");
    scanf("%[^\n]", conta->cliente);
}

void display(conta_bancaria conta)
{
    printf("Agencia: %d\n", conta.agencia);
    printf("Numero da conta: %d\n", conta.num_conta);
    printf("Cliente: %s\n", conta.cliente);
}

int main()
{
    conta_bancaria conta;
    cadastro(&conta);
    display(conta);
    return 0;
}