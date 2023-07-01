#include<stdio.h>

int primo(int numero);

int main() {
    int num;
    printf("Entre com um inteiro: ");
    scanf("%d",&num);
    int validador = primo(num);
    if (validador == 1) {
        printf("\nPrimo!");
    }
    else {
        printf("\nNao eh primo!");
    }
    return 0;
}
int primo(int numero){
    for (int i = 2;i < numero-1;i++){
            if (numero % i != 0){
                    return 1;
            }
            else {
                return 0;
            }
}
}