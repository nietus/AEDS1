#include<stdio.h>
#include<math.h>

int main(){
    int N,M,aux;
    scanf("%d",&N);
    scanf("%d",&M);
    int diferenca_novo = M - N;
    for(int i = 40;i >= 0;i--){
        if (diferenca_novo == i - M)
            aux = i;
    }
    printf("%d\n",aux);
    return 0;
}