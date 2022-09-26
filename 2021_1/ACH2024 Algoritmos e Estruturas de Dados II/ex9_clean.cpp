#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define ARESTA_MAX 100 // 100 arestas
#define VERTICE_MAX 10 // 0~9

// arquivo binario
typedef struct { 
	int v1;
	int v2;
	int custo;
} REGISTRO;

// tabela
typedef struct {
	int v1;
	int v2;
	int nroReg;
} TAB;



// Reseta tabela de indice
void inicializaTabela(TAB* tabela[VERTICE_MAX][ARESTA_MAX]){

	for (int i = 0; i < VERTICE_MAX; i++){
		for (int j = 0; j < ARESTA_MAX; j++){
			tabela[i][j] = NULL;
		}
	}
}


// Insere uma indice na tabela
void inserirIndice (TAB* tabela[VERTICE_MAX][ARESTA_MAX], int v1, int v2, int end){

	TAB* novo = (TAB*) malloc (sizeof(TAB));
	novo->v1 = v1;
	novo->v2 = v2;
	novo->nroReg = end;

	tabela[v1][v2] = novo;
}



void criaTabelaIndice(FILE* fp, TAB* tabela[VERTICE_MAX][ARESTA_MAX]){

	inicializaTabela(tabela);

	// quantidade de vertices no inicio do arquivo
	rewind(fp); fseek(fp, 0, SEEK_SET);
	int n; fread(&n, sizeof(int), 1, fp);

	// cria tabela
	REGISTRO temp; int prox = 0;
	while (1 == fread(&temp, sizeof(REGISTRO), 1, fp)){
		inserirIndice(tabela, temp.v1, temp.v2, prox);
		prox++;
	}

}





int main(){

	// o arquivo contem no inicio a quantidade de vertices 
	FILE *fp = fopen("aaa.txt", "rb"); if (fp == NULL) exit(1);

	TAB* tabela[VERTICE_MAX][ARESTA_MAX];
	criaTabelaIndice(fp, tabela);
	fclose(fp);


	return 0;
}