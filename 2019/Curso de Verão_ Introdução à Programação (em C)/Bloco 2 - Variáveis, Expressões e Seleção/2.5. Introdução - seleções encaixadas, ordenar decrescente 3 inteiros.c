#include <stdio.h>
int main(){
  int num1, num2, num3;

  scanf("%d %d %d", &num1, &num2, &num3);
  if (num1 < num2){
    num1 = num1 + num2;
    num2 = num1 - num2;
    num1 = num1 - num2;
  }
  if (num1 < num3){
    num1 = num1 + num3;
    num3 = num1 - num3;
    num1 = num1 - num3;
  }
  if (num2 < num3){
    num2 = num2 + num3;
    num3 = num2 - num3;
    num2 = num2 - num3;
  }

  printf("%d %d %d", num1, num2, num3);

  return 0;
}
