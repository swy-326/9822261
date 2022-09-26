#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

typedef struct estrutura {
	int lin;
	int col;
	int info;
	struct estrutura *prox;
} NO;

typedef struct {
	NO* inicio;
	int maxlin;
	int maxcol;
} MATRIZ;


// retorna o valor da célula [i,j] da matriz
int valor(MATRIZ* m, int i, int j){

	NO* p = m->inicio;

	while(p->prox != NULL && p->lin < i){
		p = p->prox;
	}
	while(p->prox != NULL && p->col < j){
		p = p->prox;
	}

	if (p != NULL && p->lin == i && p->col == j) return p->info;
	else return 0;
	
}


// exibe todos os valores da linha i fornecida, inclusive zeros.
void exibirLinha(MATRIZ* m, int i){

	if (m->inicio != NULL){

		printf("linha %d : ", i);


		NO* p = m->inicio;
		int j;

		while( p->prox != NULL && p->lin < i ){
			p = p->prox;
		}	


		if (p->lin == i){
			j = 1;
			do{
				while(j < p->col){
					printf("0 ");
					j++;
				}
				printf("%d ", p->info);
				j++;
			
				if(p->prox) p = p->prox;
				else break;

			} while(j <= m->maxcol && p->lin == i );

			while(j <= m->maxcol){
				printf("0 ");
				j++;
			}

		} else {
			for(j = 0; j < m->maxcol; j++){
				printf("0 ");
			}
		}

		printf("\n");
	}

}


// Escreva um algoritmo para zerar a diagonal principal da matriz.
void zerarDiagonal(MATRIZ* m){
	NO* p = m->inicio;
	NO* ant = p; NO* aux; 

	while(p != NULL && p->lin <= m->maxlin && p->col <= m->maxcol){
		if (p->lin == p->col){
			printf("diagonal p[%d][%d], valor : %d\n", p->lin, p->col, p->info);
			
			ant->prox = p->prox;
			aux = p;
			p = p->prox;
			free(aux);

			printf("anterior = [%d][%d]\n\n", ant->lin, ant->col);
		} else {
			ant = p;
			p = p->prox;
		}
	}

}


void novoNo(MATRIZ* m, int lin, int col){

	NO* novo = (NO*)malloc(sizeof(NO));
	novo->lin = lin;
	novo->col = col;
	novo->info = 1;
	novo->prox = NULL;

	if(m->inicio == NULL) m->inicio = novo;
	else {
		NO* p = m->inicio;

		while(p->prox) {
			p = p->prox;
		}

		p->prox = novo;
	}
}

void inicializaMatriz(MATRIZ* m){
	m->inicio = NULL;
	m->maxcol = 5;
	m->maxlin = 5;
}

int main(){

	MATRIZ* m = (MATRIZ*)malloc(sizeof(MATRIZ));
	inicializaMatriz(m);

	novoNo(m, 1, 1);
	novoNo(m, 2, 2);
	novoNo(m, 3, 3);
	novoNo(m, 4, 4);
	novoNo(m, 5, 5);

	zerarDiagonal(m); printf("\n"); printf("\n");

	exibirLinha(m, 1);
	exibirLinha(m, 2);
	exibirLinha(m, 3);
	exibirLinha(m, 4);
	exibirLinha(m, 5);

	printf("m->inicio : [%d][%d]\n", m->inicio->lin, m->inicio->col);


/*
	printf("valor de [%d][%d] : %d", 1, 1, valor(m, 1, 1)); printf("\n"); printf("\n");
	printf("valor de [%d][%d] : %d", 1, 4, valor(m, 1, 4)); printf("\n"); printf("\n");
	printf("valor de [%d][%d] : %d", 1, 5, valor(m, 1, 5)); printf("\n"); printf("\n");
	printf("valor de [%d][%d] : %d", 2, 2, valor(m, 2, 2)); printf("\n"); printf("\n");
	printf("valor de [%d][%d] : %d", 4, 3, valor(m, 4, 3)); printf("\n"); printf("\n");
	printf("valor de [%d][%d] : %d", 5, 5, valor(m, 5, 5)); printf("\n"); printf("\n");
*/


	return 0;
}