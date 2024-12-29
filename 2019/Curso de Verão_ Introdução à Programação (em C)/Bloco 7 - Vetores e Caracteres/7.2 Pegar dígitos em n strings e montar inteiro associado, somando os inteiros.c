#include <stdio.h>
int main(){
	char matriz[100][200];
	int numeros[200];
	int i, j, n, numLinha = 0, soma = 0;

	scanf("%d", &n);

	for (i=0; i<n; i++){
		scanf(" %[^\n]", matriz[i]);
	}

	for (i = 0; i < n; i++){
		for (j = 0; matriz[i][j] != '\0'; j++){
			if (matriz[i][j] >= '0' && matriz[i][j] <= '9'){
				numLinha += matriz[i][j]-48;
				numLinha *= 10;
			}
		}
		numLinha /= 10;
		soma += numLinha;

		numeros[i] = numLinha;

		numLinha = 0;
	}


	printf("%d\n", soma);

	for (i=0; i < n; i++){
		printf("%d\n", numeros[i]);
	}


	return 0;
}