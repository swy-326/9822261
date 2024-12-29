#include <stdio.h>
int main(){
  int a, b, c, a1, b1, c1;

  scanf("%d %d %d", &a, &b, &c);

  a1 = a;
  b1 = b;
  c1 = c;

  if (a > b) {
    a1 = a1 + b1;
    b1 = a1 - b1;
    a = a - b;
  }
  if (a1 > c1) {
    a1 = a1 + c1;
    c1 = a1 - c1;
    a1 = a1 - c1;
  }
  if (b1 > c1) {
    b1 = b1 + c1;
    c1 = b1 - c1;
    b1 = b1 - c1;
  }

  printf("%d\n%d\n%d\n\n", a1, b1, c1);
  printf("%d\n%d\n%d\n", a, b, c );
  return 0;
}
