#include <stdio.h>
int main(){
	char frase[1000], num[1000];
	int i, j;
	long numInt = 0;

	scanf("%[^\n]", frase);

	for (i = 0, j = 0; frase[i] != '\0'; i++){
		if (frase[i] >= '0' && frase[i] <= '9'){
			num[j] = frase[i];
			j++;
		}
	}

	num[i] = '\0';

	for (i = 0; num[i] != '\0'; i++){
		numInt += num[i]-48;
		numInt *= 10;
	}

	numInt /= 10;
	printf("%d\n", numInt);


	for (i = 0; num[i] != '\0'; i++){
		printf("%c :: %d\n", num[i], num[i]);
	}

	return 0;
}