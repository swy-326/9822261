/* Enunciado do exercício:
https://www.urionlinejudge.com.br/judge/pt/problems/view/1021
*/

#include<stdio.h>
int main(){
  float n;
  int q, resto;
  scanf("%f", &n);  
  resto = (int)(100*n);
  printf("NOTAS:\n");
  q = resto / 10000;
  resto = resto % 10000;
  printf("%d nota(s) de R$ 100.00\n", q);
  q = resto / 5000;
  resto = resto % 5000;
  printf("%d nota(s) de R$ 50.00\n", q);
  q = resto / 2000;
  resto = resto % 2000;
  printf("%d nota(s) de R$ 20.00\n", q);
  q = resto / 1000;
  resto = resto % 1000;
  printf("%d nota(s) de R$ 10.00\n", q);
  q = resto / 500;
  resto = resto % 500;
  printf("%d nota(s) de R$ 5.00\n", q);
  q = resto / 200;
  resto = resto % 200;
  printf("%d nota(s) de R$ 2.00\n", q);
  printf("MOEDAS:\n");
  q = resto / 100;
  resto = resto % 100;
  printf("%d moeda(s) de R$ 1.00\n", q);
  q = resto / 50;
  resto = resto % 50;
  printf("%d moeda(s) de R$ 0.50\n", q);
  q = resto / 25;
  resto = resto % 25;
  printf("%d moeda(s) de R$ 0.25\n", q);
  q = resto / 10;
  resto = resto % 10;
  printf("%d moeda(s) de R$ 0.10\n", q);
  q = resto / 5;
  resto = resto % 5;
  printf("%d moeda(s) de R$ 0.05\n", q);
  printf("%d moeda(s) de R$ 0.01\n", resto);

  return 0;
}