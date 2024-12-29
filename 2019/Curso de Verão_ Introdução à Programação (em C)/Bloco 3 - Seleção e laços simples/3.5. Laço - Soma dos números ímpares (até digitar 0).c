#include <stdio.h>
int main(){
	int num, soma = 0;


	do{
		scanf("%d", &num);
		if (num %2 == 1){
			soma += num;
		}
	} while (num != 0);

	printf("%d", soma);

	return 0;
}