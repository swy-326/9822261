/*
Suponha o mesmo arquivo de registros de tamanho fixo (binário) da semana anterior, em que cada registro é um par de arestas (v1,v2) e um custo.

Escreva um algoritmo que, dado um arquivo deste tipo, crie uma tabela de índices em memória usando um vetor estático comum do tipo struct de 3 campos (v1, v2 e o nro. do registro no arquivo).

Por simplicidade, considere que o número máximo de arestas possível é 100, e observe que o acesso a uma aresta precisa ser feito por duas chaves simultaneamente, e não por uma chave única como nos exemplos vistos em aula. 
*/


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

// =========================================================== //


void inicializaTabela(TAB* tabela[VERTICE_MAX][ARESTA_MAX]){

	printf("\tINICIALIZAR TABELA\n");

	for (int i = 0; i < VERTICE_MAX; i++){
		for (int j = 0; j < ARESTA_MAX; j++){
			tabela[i][j] = NULL;
		}
	}

	printf("\t\ttabela iniciao\n");
}

void inserirIndice (TAB* tabela[VERTICE_MAX][ARESTA_MAX], int v1, int v2, int end){

	printf("\tINSERIR INDICE\n");

	TAB* novo = (TAB*) malloc (sizeof(TAB));
	novo->v1 = v1;
	novo->v2 = v2;
	novo->nroReg = end;

	tabela[v1][v2] = novo;
	printf("\t\tindice inserido na tabela\n");
}

void criaTabelaIndice(FILE* fp, TAB* tabela[VERTICE_MAX][ARESTA_MAX]){

	printf("CRIA TABELA INDICE\n");

	inicializaTabela(tabela);

	// quantidade de vertices no inicio do arquivo
	rewind(fp); fseek(fp, 0, SEEK_SET);
	int n; fread(&n, sizeof(int), 1, fp);


	printf("\tcriando tabela...\n");
	// cria tabela
	REGISTRO temp; int prox = 0;
	while (1 == fread(&temp, sizeof(REGISTRO), 1, fp)){
		inserirIndice(tabela, temp.v1, temp.v2, prox);
		prox++;
	}

}



// =========================================================== //


int buscarIndice(TAB* tabela[VERTICE_MAX][ARESTA_MAX], int v1, int v2){

	printf("\tBUSCAR INDICE\n");

	if (tabela[v1][v2] != NULL){
		int end = tabela[v1][v2]->nroReg;
		printf("\t\tendereco : %d\n", end);
		return end;
	}

	return -1;
}

int leituraTabelaIndice(FILE* fp, TAB* tabela[VERTICE_MAX][ARESTA_MAX], int v1, int v2){

	printf("LEITURA TABELA INDICE\n");

	int end = buscarIndice(tabela, v1, v2);


	if (end > -1){
		printf("\tindice encontrado na tabela\n");

		REGISTRO temp;
		fseek (fp, sizeof(int) + end*sizeof(REGISTRO), SEEK_SET);
		int lidos = fread(&temp, sizeof(REGISTRO), 1, fp);
		if (lidos < 1) {
			printf("\tindice nao encontrado no arquivo\n");
			return -1; // nao encontrado
		}
		printf("\tindice encontrado no arquivo\n");
		return temp.custo;
	}

	else {
		printf("\tindice nao encontrado na tabela\n");
		return -1;
	} 
}



// =========================================================== //



int main(){

	printf("MAIN\n");

	// o arquivo contem no inicio a quantidade de vertices 
	FILE *fp = fopen("aaa.txt", "rb"); if (fp == NULL) exit(1);

	TAB* tabela[VERTICE_MAX][ARESTA_MAX];

	// vertice a buscar
	int v1 = 9; int v2 = 0;

	criaTabelaIndice(fp, tabela);
	int custo = leituraTabelaIndice(fp, tabela, v1, v2);
	fclose(fp);


	printf("\n\ncusto : %d\n", custo);


	return 0;
}


/*

    criaAresta(g, 1, 3, 900);
    criaAresta(g, 1, 2, 900);
    criaAresta(g, 3, 2, 900);
    criaAresta(g, 3, 5, 900);
    criaAresta(g, 4, 2, 900);
    criaAresta(g, 4, 3, 900);
    criaAresta(g, 5, 4, 900);
	criaAresta(g, 6, 7, 900);
	criaAresta(g, 7, 8, 900);
	criaAresta(g, 8, 9, 900);
	criaAresta(g, 9, 0, 900);

*/









/*
		VERSAO RASCUNHO   ||
		VERSAO RASCUNHO	  ||
		VERSAO RASCUNHO	  ||
		VERSAO RASCUNHO	  ||
		VERSAO RASCUNHO	  ||
		VERSAO RASCUNHO  \  /
		VERSAO RASCUNHO	  \/
*/









/*
Suponha o mesmo arquivo de registros de tamanho fixo (binário) da semana anterior, em que cada registro é um par de arestas (v1,v2) e um custo.

Escreva um algoritmo que, dado um arquivo deste tipo, crie uma tabela de índices em memória usando um vetor estático comum do tipo struct de 3 campos (v1, v2 e o nro. do registro no arquivo).

Por simplicidade, considere que o número máximo de arestas possível é 100, e observe que o acesso a uma aresta precisa ser feito por duas chaves simultaneamente, e não por uma chave única como nos exemplos vistos em aula. 
*/


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


// =========================================================== //


void inserirIndice (TAB* tabela[][], int v1, int v2, int end){

	TAB novo = (TAV*) malloc (sizeof(TAB));
	novo.v1 = v1;
	novo.v2 = v2;
	novo.nroReg = end;

	tabela[v1][v2] = novo;
}


int criaTabelaIndices (int v1, int v2){

	FILE *fp = fopen("aaa.txt", "rb"); if (fp == NULL) exit(1);

	// variaveis
	int n, prox = 0;

	TAB* tabela[VERTICE_MAX][ARESTA_MAX]; 
	for (int i = 0; i < VERTICE_MAX; i++) 
		for (int j = 0; j < ARESTA_MAX; j++)
			tabela[i][j] = NULL;


	// quantidade total de vertices no inicio do arquivo
	rewind(fp);	fseek(fp, 0, SEEK_SET); 
	fread(&n, sizeof(int), 1, fp); printf("n : %d\n", n);


	// cria tabela
	REGISTRO tempReg;
	while (1 == fread(&tempReg, sizeof(REGISTRO), 1, fp)){
		inserirIndice(tabela, tempReg.v1, tempReg.v2, prox);
		prox++;
	}

	fclose(fp);

}


// =========================================================== //


int buscarIndice(tabela, v1, v2){

	int end = tabela[v1][v2].nroReg;
	end >= 0 ? return end : return -1 ;
}



int leituraTabela (int chave1, chave2){

	int end = buscarIndice(tabela, chave1, chave2);
	if (end > -1){
		fseek (arq, end*sizeof(REGISTRO), SEEK_SET);
		int lidos = fread(&r, sizeof(REGISTRO), 1, arq);
		if (lidos < 1) return -1; // nao encontrado
		return lidos
	}
	else return -1;

}



// =========================================================== //


	void tabelaDeIndice(){

		

	}

		//TABELA MAIN FUNCTION// 



// =========================================================== //




int main(){

	return 0;
}