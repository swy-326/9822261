#include <stdio.h>
int main(){
	int num1, num2, num3, total;

	scanf("%d", &num1);
	scanf("%d", &num2);
	scanf("%d", &num3);

	if (num1 + num2 + num3 == 180){
		printf("Sim %d %d %d\n", num1, num2, num3);
	} else {
		printf("NAO %d\n", num1 + num2 + num3);
	}


	return 0;
}