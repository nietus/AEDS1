#include<stdio.h>

int verifica_intervalo(float ini, float fim, float valor);

int main(){
    float x,y,numero;
    printf("Digite um numero: ");
    scanf("%f",&numero);
    printf("Entre o valor menor x do intervalo [x,y]: ");
    scanf("%f",&x);
    printf("Entre o valor maior y do intervalo [%f,y]: ",x);
    scanf("%f",&y);
    int verificado = verifica_intervalo(x,y,numero);
    if (verificado == 1){
        printf("No intervalo!");
    }
    else {
        printf("Fora do intervalo!");
    }
}

int verifica_intervalo(float ini, float fim, float valor){
    if (valor > ini && valor < fim){
        return 1;
    }
    else {
        return 0;
    }
}