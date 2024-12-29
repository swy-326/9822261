#include <stdio.h>
int main(){
  int n, i, soma = 0;
  scanf("%d", &n);

  for (i=1; i<n*2; i+=2){
    soma += i;
  }

  printf("%d\n", soma);
  return 0;
}