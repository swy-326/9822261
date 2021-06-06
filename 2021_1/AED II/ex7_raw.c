/*

	Suponha um arquivo de registros de tamanho fixo (binário) em que cada registro é um par de arestas (v1,v2) e um custo, ou seja:

	typedef struc { 
		int v1;
		int v2;
		int custo;
	} REGISTRO;

	Escreva um algoritmo para ler um arquivo deste tipo e construir o grafo correspondente, retornando a respectiva ED de listas de adjacências. Por simplicidade, considere que os vértices possíveis são numerados de 0 a 9. 

*/

// https://stackoverflow.com/questions/5431941/why-is-while-feof-file-always-wrong
// https://stackoverflow.com/questions/40182893/output-struct-objects-to-binary-file-and-input-from-it-back-in-c


#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


typedef struct { 
	int v1;
	int v2;
	int custo;
} REGISTRO;


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

void imprime (VERTICE* g, int n){

	if (g){
		
		for (int i = 0; i <= n; i++){
			printf("v%d : ", i);
			NO* temp = g[i].inicio;

			while(temp){
				printf("v%d(%d)  ", temp->v, temp->peso);
				temp = temp->prox;
			}
			printf("\n");
		}
	}
	printf("\n\n");

}



void criaArquivo (int n, VERTICE* g){

	int sss = remove("aaa.txt");
	FILE *fp = fopen("aaa.txt", "w");

	if (fp == NULL) exit(1);

	fwrite(&n , sizeof(int), 1, fp);

	n = 9;
	REGISTRO tempReg;


	for (int i = 0; i <= n; i++){

		NO* temp = g[i].inicio;

		while (temp){

			
			tempReg.v1 = i;
			tempReg.v2 = temp->v;
			tempReg.custo = temp->peso;

			//printf("tempReg->v1 : %d\n", tempReg.v1);

			fwrite(&tempReg, sizeof(REGISTRO), 1, fp);

			temp = temp->prox;
		}
	}

	//fwrite(&tempReg, sizeof(REGISTRO), 1, fp);

	fclose(fp);

}


VERTICE* leArquivo (){

	int n;

	FILE *fp = fopen("aaa.txt", "rb");
	if (fp == NULL) exit(1);

	rewind(fp);

	fseek(fp, 0, SEEK_SET);
	fread(&n, sizeof(int), 1, fp);

	printf("n : %d\n", n);


	VERTICE *grafo = criaGrafo(n);


//	printf("\n\n=============================\n");
	REGISTRO tempReg;
	while (fread(&tempReg, sizeof(REGISTRO), 1, fp) == 1){

		

//		printf("tempReg.v1 : %d\n", tempReg.v1);
//		printf("tempReg.v2 : %d\n", tempReg.v2);
//		printf("tempReg.custo : %d\n", tempReg.custo);
//		printf("=============================\n");

		criaAresta(grafo, tempReg.v1, tempReg.v2, tempReg.custo);
	}



	fclose(fp);

	return grafo;
}




int main(){

	int n = 9;

	VERTICE *g = criaGrafo(n); // 0~9
	criaAresta(g, 0, 1, 0);
	criaAresta(g, 0, 2, 0);
	criaAresta(g, 0, 3, 0);
	criaAresta(g, 0, 4, 0);
	criaAresta(g, 0, 5, 0);
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
	criaAresta(g, 9, 0, 900);*/

	imprime(g, n);
		

	// cria arquivo binario de grafo
	criaArquivo(n, g);
	VERTICE* g2 = leArquivo();
	imprime(g2, n);
}



