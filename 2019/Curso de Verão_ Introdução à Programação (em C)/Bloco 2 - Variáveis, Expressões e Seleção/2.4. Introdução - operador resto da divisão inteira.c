#include <stdio.h>
int main(){
  int num;

  scanf("%d", &num);
  if (num % 2 == 0){
    printf("1\n");
  } else {
    printf("0\n");
  }

  return 0;
}
