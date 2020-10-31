#include <stdio.h>
#include <stdlib.h>

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

	if(m != NULL){
	
		NO* p = m->inicio;
		while(p->lin <= i && p->col <= j){
			if ( p->lin == i && p->col ) return p->info;
			p = p->prox;
		}

		return 0;

	}
}

// exibe todos os valores da linha i fornecida, inclusive zeros.
void exibirLinha(MATRIZ* m, int i){
	NO* p = m->inicio;

	if (m != NULL){
		while( p->lin != i ){
			p = p->prox;
		}

		if( p->lin == i){
			for (int k = 0; k < m->coluna; k++){
				if ()
			}
		}
	}
}

// Escreva um algoritmo para zerar a diagonal principal da matriz.
void zerarDiagonal(MATRIZ* m){
	NO* p = m->inicio;
	NO* pp, aux;

	if (p)

	while(p){
		if (p->lin == p->col){
			aux = p;
			p = p->prox;
			free(aux);

			if( m->inicio == NULL ) m->inicio = p;

		}
	}
}

int main(){

	int A[] = {3,4,6,8,4,4,6,7,1,5,3};

	int x = preprocessa(A, sizeof(A)/sizeof(A[0]), 8);
	printf("ha %d elementos\n", consulta(x, 3, 5));

	return 0;
}