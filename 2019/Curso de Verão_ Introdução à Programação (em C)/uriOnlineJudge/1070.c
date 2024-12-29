#include <stdio.h>
int main(){
  int valor;

  scanf("%d", &valor);
  if (valor % 2 == 0){
    printf("%d\n", valor + 1);
    printf("%d\n", valor + 3);
    printf("%d\n", valor + 5);
    printf("%d\n", valor + 7);
    printf("%d\n", valor + 9);
    printf("%d\n", valor + 11);
  } else {
    printf("%d\n", valor + 2);
    printf("%d\n", valor + 4);
    printf("%d\n", valor + 6);
    printf("%d\n", valor + 8);
    printf("%d\n", valor + 10);
    printf("%d\n", valor + 12);
  }

  return 0;
}
