#include <stdio.h>
#include <math.h>

float delta(float a, float b, float c);
float bhaskara(float a,float b, float d);


float main(){
    float a,b,c;
    printf("ax**2 + bx + c\n");
    printf("\nDigite o valor de a:");
    scanf("%f",&a);
    printf("\nDigite o valor de b:");
    scanf("%f",&b);
    printf("\nDigite o valor de c:");
    scanf("%f",&c);
    float d = delta(a,b,c);
    bhaskara(a,b,d);
    return 0;
}

float delta(float a, float b, float c){
    return pow(b,2) - (4 * a * c);
}

float bhaskara(float a,float b, float d){
    printf("%f\n",(-b - sqrt(d)) / (2 * a));
    printf("%f",(-b + sqrt(d)) / (2 * a));
}