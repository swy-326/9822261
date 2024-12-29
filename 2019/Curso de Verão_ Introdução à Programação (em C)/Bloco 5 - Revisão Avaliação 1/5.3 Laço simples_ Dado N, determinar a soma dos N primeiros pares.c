#include <stdio.h>
int main(){
	int n, soma = 0, i = 0;

	scanf("%d", &n);

	while (i < n){
		soma += i*2;
		i++;

	}

	printf("%d\n", soma);
	return 0;
}