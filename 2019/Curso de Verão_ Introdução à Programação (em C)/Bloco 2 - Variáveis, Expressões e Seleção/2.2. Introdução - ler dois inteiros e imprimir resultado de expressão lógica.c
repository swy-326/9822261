#include <stdio.h>
int main(){
  int num1, num2;

  scanf("%d %d", &num1, &num2);

  if (num1 < num2){
    printf("1\n");
  } else {
    printf("0\n");
  }

  return 0;
}
