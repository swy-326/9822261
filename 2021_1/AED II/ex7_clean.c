#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


// struct do arquivo binario
typedef struct { 
	int v1;
	int v2;
	int custo;
} REGISTRO;


// struct do grafo reconstruido
typedef struct adj {
	int v;
	int peso;
	struct adj* prox;
} NO;

typedef struct {
	NO* inicio;
} VERTICE;



VERTICE* criaGrafo (int n){

	VERTICE* g = (VERTICE *) malloc (n * sizeof(VERTICE));
	
	for (int i = 0; i <= n; i++){
		g[i].inicio = NULL; 
	}

	return g;
}


NO* criaAdjacente (int v, int peso){

	NO* temp = (NO *) malloc (sizeof(NO));
	temp->v = v;
	temp->prox = NULL;

	temp->peso = peso;

	return temp;

}

void criaAresta (VERTICE* g, int i, int v, int peso){

	NO* novo = criaAdjacente(v, peso);
	novo->prox = g[i].inicio;

	g[i].inicio = novo;

}


VERTICE* leArquivo (char *nome){

	FILE *fp = fopen(nome, "rb");
	if (fp == NULL) exit(1);


	rewind(fp); fseek(fp, 0, SEEK_SET);

	// qntde de vertices (no inicio do arquivo)
	int n; fread(&n, sizeof(int), 1, fp);


	// cria novo grafo
	VERTICE *grafo = criaGrafo(n);

	REGISTRO tempReg;
	while (fread(&tempReg, sizeof(REGISTRO), 1, fp) == 1)
		criaAresta(grafo, tempReg.v1, tempReg.v2, tempReg.custo);

	fclose(fp);


	return grafo;
}




int main(){

	char nome[20];
	VERTICE* g1 = leArquivo(gets(nome));

	return 0;
}