#include <stdio.h>
int main(){
	int *pt;
	int x;

	pt = &x;
	scanf("%d", pt);

	printf("%d\n", x);
	printf("%d\n", *pt);

	return 0;

}