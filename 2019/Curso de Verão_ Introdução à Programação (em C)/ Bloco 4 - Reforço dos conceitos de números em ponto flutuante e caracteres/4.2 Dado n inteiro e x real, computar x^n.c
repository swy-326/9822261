#include <stdio.h>
int main(){
  int n, i;
  float x, resultado = 1;

  scanf("%d %f", &n, &x);

  for (i=1; i<=n; i++){
    resultado *= x;
  }

  printf("%f\n", resultado);

  return 0;
}