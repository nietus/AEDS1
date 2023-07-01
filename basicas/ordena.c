#include<stdio.h>

//prototipos

void entrada(float *,float *, float *);
void troca(float *, float *);
void imprime (float,float,float);
float calc_media (float,float,float);
void ordena(float *,float *, float *);

int main(){
    float a,b,c;
    entrada(&a,&b,&c);
    ordena(&a,&b,&c);
    imprime(a,b,c);
}

void entrada(float *a,float *b, float *c) {
    printf("Valor de a: ");
    scanf("%f",a);
    printf("Valor de b: ");
    scanf("%f",b);
    printf("Valor de c: ");
    scanf("%f",c);
}
void troca(float *a, float *b){
    float aux;
    aux = *a;
    *a = *b;
    *b = aux;
}
void imprime (float n1,float n2,float n3){
    float media = calc_media(n1,n2,n3);
    printf("Na ordem crescente: %.2f,%.2f,%.2f\nA média eh: %.2f",n1,n2,n3,media);
}
float calc_media (float n1,float n2,float n3){
    return (n1 + n2 + n3) / 3;
}

void ordena(float *a, float *b, float *c){
    if (*b < *a){
        troca(b,a);
    } // b a c
    if (*c < *a){
        troca(c,a);
    } // b c a
    if (*c < *b){
        troca(c,b);
    }
}