#include <stdio.h>

int fib(int n);
void imprime_seq_fib(int n);
void menu(char *opcao);
void entrada(int *numero);
int validacao(int numero, char opcao);

int main() {
  char op;
  int entry,valida;
  menu(&op);
  entrada(&entry);
  if (op == 'a'){
    imprime_seq_fib(entry);
  }
  if (op == 'b') {
    for (int i = 0; i < entry; i++) {
      printf("%d ", fib(i));
    }
  }
  if (op == 'c'){
    for (int i = 0; i < entry+2; i++) {
      printf("%d,%d ",fib(i),entry);
        if (fib(i) > entry){
          valida = 0;
          break;
        }
        else if (fib(i) == entry){
          valida = 1;
          break;
        }
        else{
          valida = 0;
        }
      }
    if (valida == 1){
      printf("existe!");
    }
    else {
      printf("n existe... :(");
    }
    }
  return 0;
}

void menu(char *op) {
  do {
    printf(
        "Escolha uma opcao: \na: Soma de todos valores até um número na sequencia de fib\nb: "
        "Todos valores ate um numero na sequencia de fibo\nc: Informar um valor para ver se ele se encontra em alguma posicao da sequencia\n> ");
    scanf(" %c", op);
    if (*op != 'a' && *op != 'b' && *op != 'c') {
      printf("Opçao invalida, informe uma das opçoes: a, b, c.");
    }
  } while (*op != 'a' && *op != 'b' && *op != 'c');
}

void entrada(int *entry) {
  printf("Digite um numero: ");
  scanf("%d", entry);
}

int fib(int n) {
  if (n == 0) {
    return 0;
  }
  if (n == 1) {
    return 1;
  } else {
    return fib(n - 1) + fib(n - 2);
  }
}

void imprime_seq_fib(int n){
  int soma = 0;
  for (int i = 0; i < n; i++) {
      soma += fib(i);
    }
  printf("%d",soma);
}