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









// ------------------------------------------------------------- //






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

// tabela de dispersao
typedef struct {
	int chave;
	int indice;
	struct TAB* prox;
} TAB;



void inserirIndice(TAB* tabela[], int chave, int prox){
	REGISTRO novo = (TAB*) malloc (sizeof(TAB));
	novo.chave = chave;
	novo.indice = prox;
	novo.prox = tabela[chave];

	tabela[chave] = novo;
}


int buscarTab(TAB* tabela[], int v1, int v2){

	TAB temp = tabela[v1];
	while (temp->prox){

		if ()
		????????????? chave가 잘못됨. chave는 unico여야 하는데 이건 아님

	}

	return -1;
}


int leArquivo (int v1, int v2){

	FILE *fp = fopen("aaa", "rb");
	if (fp == NULL) exit(1);

	int n, prox = 0;
	TAB* tabela[n+1]; for (int i = 0; i <= n; i++) tabela[i] = NULL;

	rewind(fp);	fseek(fp, 0, SEEK_SET); 
	fread(&n, sizeof(int), 1, fp); printf("n : %d\n", n);

	REGISTRO tempReg;
	while (fread(&tempReg, sizeof(REGISTRO), 1, fp) == 1){
		inserirIndice(tabela, r.v1, prox);
		prox++;
	}

	fclose(fp);


	return buscarTab(v1, v2)
}




int main(){

	int v1 = 9;
	int v2 = 7;

	printf("custo : %d", leArquivo(v1, v2));

	return 0;
}
