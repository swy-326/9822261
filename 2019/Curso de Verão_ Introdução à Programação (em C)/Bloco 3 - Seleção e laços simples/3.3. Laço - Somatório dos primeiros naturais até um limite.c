#include <stdio.h>
int main(){
	int total, i = 1, soma = 0;
	scanf("%d", &total);

	while (soma <= total){
		soma += i;
		i++;
	}

	if (soma >= total) soma -= i - 1;
	printf("%d\n", soma);

	return 0;
}