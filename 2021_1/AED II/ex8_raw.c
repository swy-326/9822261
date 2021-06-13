/*

Suponha o mesmo arquivo de registros de tamanho fixo (binário) da semana anterior, em que cada registro é um par de arestas (v1,v2) e um custo, ou seja:

typedef struc { 
	int v1;
	int v2;
	int custo;
} REGISTRO;

Escreva um algoritmo que, dado um par de vértices v1,v2 e um arquivo de grafo do tipo acima, retorne o seu custo ou, se a aresta não existir, retorne -1. Por simplicidade, considere que os vértices possíveis são numerados de 0 a 9. 

*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct { 
	int v1;
	int v2;
	int custo;
} REGISTRO;



int leArquivo (int v1, int v2){

	int n;

	FILE *fp = fopen("aaa", "rb");
	if (fp == NULL) exit(1);

	rewind(fp);

	fseek(fp, 0, SEEK_SET);
	fread(&n, sizeof(int), 1, fp);

	printf("n : %d\n", n);

	REGISTRO tempReg;
	while (fread(&tempReg, sizeof(REGISTRO), 1, fp) == 1){
		if (tempReg.v1 == v1)
			if (tempReg.v2 == v2)
				return tempReg.custo;
	}


	fclose(fp);
	return -1;
}




int main(){

	int v1 = 9;
	int v2 = 7;

	printf("custo : %d", leArquivo(v1, v2));

	return 0;
}
