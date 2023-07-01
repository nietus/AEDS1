#include<stdio.h>

/* Faz a entrada de dados, sem nenhuma validação */
void entrada(float n1, float n2, float n3);
/* Faz a validação dos dados: número precisa estar no intervalo de 0 a 100 */
/* Retorna 0 (inválido) se algum dos números estiver fora do intervalo, ou 1 (válido) caso contrário.*/
int validacao(float n1, float n2, float n3);
/* Retorna o maior número */
float ret_maior(float n1, float n2, float n3);
/* Retorna o menor número */
float ret_menor(float n1, float n2, float n3);

int main(){
    float n1,n2,n3;
    entrada(n1,n2,n3);
}

void entrada(float n1,float n2, float n3){
    printf("Digite o primeiro numero: ");
    scanf("%f",&n1);
    printf("Digite o segundo numero: ");
    scanf("%f",&n2);
    printf("Digite o terceiro numero: ");
    scanf("%f",&n3);
    int valida = validacao(n1,n2,n3);
    if (valida != 0){
        printf("Maior num eh %.2f \n",ret_maior(n1,n2,n3));
        printf("Menor num eh %.2f",ret_menor(n1,n2,n3));
    }
    else {
        printf("Digite um numero entre 0 e 100!");
    }
}

int validacao(float n1, float n2, float n3){
    if (n1 < 0 || n1 > 100 || n2 < 0 || n2 > 100 || n3 < 0 || n3 > 100){
        return 0;
    }
}

float ret_maior(float n1, float n2, float n3){
    if (n1 > n2 && n1 > n3){
        return n1;
    }
    else if(n2 > n1 && n2 > n3){
        return n2;
    }
    else{
        return n3;
    }
}

float ret_menor(float n1, float n2, float n3){
    if (n1 < n2 && n1 < n3){
        return n1;
    }
    else if(n2 < n1 && n2 < n3){
        return n2;
    }
    else{
        return n3;
    }
}
