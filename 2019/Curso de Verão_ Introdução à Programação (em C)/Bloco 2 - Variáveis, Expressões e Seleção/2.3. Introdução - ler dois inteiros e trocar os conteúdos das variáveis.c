#include <stdio.h>
int main(){
  int aux, a, b;

  scanf("%d %d", &a, &b);
  aux = a;
  a = b;
  b = aux;
  printf("%d %d", a, b);

  return 0;
}
