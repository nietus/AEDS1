#include<stdio.h>

int main(){
    int num, multiplo;
    printf("Digite um numero entre 3 e 99: ");
    scanf("%d",&num);
    for(int i = 2;i < 100;i++) {
        if (num % 3 == 0){
            multiplo = 1;
        }
    }
    if (multiplo == 1){
        printf("Entrada validada com sucesso: %d",num);
    }
    else {
        printf("Entrada invalidada: %d",num);
    }
    return 0;
}