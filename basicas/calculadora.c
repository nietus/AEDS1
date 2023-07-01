#include<stdio.h>

float soma(float n1, float n2);
float subtracao(float n1, float n2);
float multiplicacao(float n1, float n2);
float divisao(float n1, float n2);

int main(){
    float n1,n2, resultado;
    char selecao;
    printf("Digite o primeiro numero: ");
    scanf("%f", &n1);
    printf("Digite o segundo numero: ");
    scanf("%f", &n2);
    printf("+  -  *  /  : ");
    scanf(" %c",&selecao);

    switch (selecao){
        case '+':
            resultado = soma(n1,n2);
            break;
        case '-':
            resultado = subtracao(n1,n2);
            break;
        case '*':
            resultado = multiplicacao(n1,n2);
            break;
        case '/':
            resultado = divisao(n1,n2);
            break;
    }
    printf("%.2f %c %.2f = %.2f",n1,selecao,n2,resultado);
return 0;
}

float soma(float n1, float n2){
    return n1 + n2;
}
float subtracao(float n1, float n2){
    return n1 - n2;
}
float multiplicacao(float n1, float n2){
    return n1 * n2;
}
float divisao(float n1, float n2){
    return n1 / n2;
}