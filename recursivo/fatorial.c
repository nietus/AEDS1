#include<stdio.h>

int fat(int);
int fat_recursivo(int);
void imprime_seq_fat(int n);
int validacao(int num);
void entrada(int *e);

int main(){
    int e,seq;
    entrada(&e);
    imprime_seq_fat(e);
    return 0;
}

void entrada(int *e){
    int valida;
    do{
        printf("Fatorial de qual num? > ");
        scanf("%d",e);
        valida = validacao(*e);
    }while(valida == 1);
}

int validacao(int num){
    if (num <= 1 || num >= 20) {
        return 1;
    }
    else {
        return 0;
    }
}

int fat(int f){//nao-recursiva
    int resultado = 1;
    for (f;f > 1;f--){
        resultado *= f;
    }
    return resultado;
    }

void imprime_seq_fat(int n){
    for (n;n > 1;n--){
        printf("Fat de %d eh %d \n",n, fat(n));
    }
}

int fat_recursivo(int f){//recursiva
    if ( f > 1 )
        return f * fat(f - 1);
    else{
       return 1;
    }
}
