#include <stdio.h>
#include <math.h>

float delta(float a, float b, float c);
float bhaskara1(float a,float b, float d);
float bhaskara2(float a,float b, float d);


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
    float x1 = bhaskara1(a,b,d);
    float x2 = bhaskara2(a,b,d);
    printf("\nAs raizes sao %f e %f",x1,x2);
    return 0;
}

float delta(float a, float b, float c){
    return pow(b,2) - (4 * a * c);
}

float bhaskara1(float a,float b, float d){
    return (-b - sqrt(d)) / (2 * a);
}
float bhaskara2(float a,float b, float d){
    return (-b + sqrt(d)) / (2 * a);
}