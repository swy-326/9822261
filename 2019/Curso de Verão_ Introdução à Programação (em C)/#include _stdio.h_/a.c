#include <stdio.h>
#define TAM 100

float func_media(float vet[], int n){
	float i, soma = 0;
	for (i = 0; i < n; i++){
		soma += vet[i];
	}
	return (float)soma/n;
}


int main(){
	int m, n, ind, i, j;
	float matriz[TAM][TAM], soma[TAM];

	scanf("%d %d", &m, &n);

	for (i = 0; i < m; i++){
		for (j = 0; j < n; j++){
			scanf("%f", &matriz[i][j]);
			soma[i] += matriz[i][j];
		}
	}

	scanf("%d", &ind);

	printf("%.1f\n", func_media(matriz[ind], n));

	return 0;
}