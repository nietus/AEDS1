#include<stdio.h>

float celsius(float x);
float fahrenheit(float y);

int main(){
    float cels,fah;
    printf("Temperatura em celsius: ");
    scanf("%f",&cels);
    printf("\nTemperatura em fahrenheit: ");
    scanf("%f",&fah);
    float conversaoUm = fahrenheit(cels);
    float conversaoDois = celsius(fah);
    printf("\n%f celsius em fahrenheit eh %f f, %f f em celsius eh %f c",cels,conversaoUm,fah,conversaoDois);
    return 0;
}


float celsius(float x){
    return (x - 32) * (9/5);
}
float fahrenheit(float y){
    return (y * 9 / 5) + 32;
}