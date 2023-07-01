#include<stdio.h>

/* Calcula e retorna o IMC */
float calculaIMC(float peso, float altura);
/* Faz a entrada do peso e da altura, sem quaisquer validações */
void entrada(float peso, float altura);
/* Retorna falso caso peso/altura forem inválidos (menor/igual a zero); ou verdadeiro, caso contrário */
int validaEntrada(float peso, float altura);
/* Imprime a classificação de acordo com o IMC */
void exibeClassificacaoIMC(float imc);
/* Imprime a tabela de classificação do IMC */
void exibeTabelaIMC();

int main(){
    float peso, altura;
    entrada(peso,altura);
    //exibeClassificacaoIMC();
}

/* Faz a entrada do peso e da altura, sem quaisquer validações */
void entrada(float peso, float altura){
    printf("Digite o peso: ");
    scanf("%f",&peso);
    printf("Digite a altura: ");
    scanf("%f",&altura);
    int valida = validaEntrada(peso,altura);
    if (valida != 0){
    printf("%f \n",calculaIMC(peso,altura));
    exibeClassificacaoIMC(calculaIMC(peso,altura));
    exibeTabelaIMC();
    }
    else{
        printf("Digite um numero diferente de 0 ! ");
    }
}
/* Retorna falso caso peso/altura forem inválidos (menor/igual a zero); ou verdadeiro, caso contrário */
int validaEntrada(float peso, float altura){
    if(peso == 0 || altura == 0){
        return 0;
    }
}
/* Calcula e retorna o IMC */
float calculaIMC(float peso, float altura) {
    return (peso) / (altura*altura);
}
/* Imprime a classificação de acordo com o IMC */
void exibeClassificacaoIMC(float imc){
    if (imc < 18.5) {
        printf("vc esta abaixo do peso");
    }
    else if (imc > 18.5 && imc < 25){
        printf("vc esta no peso ideal");
    }
    else if (imc > 25 && imc < 30){
        printf("vc esta com sobrepeso");
    }
    else if (imc > 30 && imc < 35){
        printf("vc esta com obesidade grau i");
    }
    else if (imc > 35 && imc < 40){
        printf("vc esta com obesidade grau ii");
    }
    else{
        printf("vc esta com obesidade grau iii");
    }
}
/* Imprime a tabela de classificação do IMC */
void exibeTabelaIMC(){
    printf("\n < 18,5 - Abaixo do peso \n 18,5 a < 25,0 - Peso ideal \n 25,0 a < 30,0 - Sobrepeso \n 30,0 a < 35,0 - Obesidade grau I \n 35,0 a < 40,0 - Obesidade Grau II \n >= 40,0 - Obesidade grau III");
}