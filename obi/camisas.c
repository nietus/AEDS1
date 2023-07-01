#include <stdio.h>

int main(void) {
  int x,y,cont1 = 0,cont2 = 0;
  scanf("%d",&x);
  for(int i = 0; i < x; i++){
    scanf("%d",&y);
    if (y == 1){
      cont1++;
    }
    else{
      cont2++;
    }
  }
  int peq,med;
  scanf("%d",&peq);
  scanf("%d",&med);
  if (peq == cont1 && med == cont2){
    printf("S");
  }
  else{
    printf("N");
  }
  return 0;
}