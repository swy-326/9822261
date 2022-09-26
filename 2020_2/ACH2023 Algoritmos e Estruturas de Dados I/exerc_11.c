#include <stdio.h>
#include <stdlib.h>

/*

(1) Escreva a ordem de visita das chaves da árvore da imagem anexa (ou ver slides da aula sobre percursos em árvore, ao final), nos percursos pré-ordem, em ordem, pós ordem e em nível. 

(2) Escreva um algoritmo que, dada uma chave ch garantidamente existente em uma posição folha (ou seja, 3,9,2,13,6 ou 5 no exemplo), efetue a sua exclusão.

18 17 12 3 9 15 2 13 16 6 5

3 12 9 17 2 15 13 18 6 16 5        

3 9 12 2 13 15 17 6 5 16 18                                                    

18 17 16 12 15 6 5 3 9 2 13 
*/

typedef struct estrutura {
	int chave;
	struct estrutura *esq;
	struct estrutura *dir;
} NO;

// Inicialização da árvore vazia
void inicializarArvore(NO* *raiz) {
	*raiz = NULL;
}


void preOrdem(NO* p){
	if(p) {
		printf("%d ", p->chave);
		preOrdem(p->esq);
		preOrdem(p->dir);
	}
}

void emOrdem(NO* p){
	if(p) {
		emOrdem(p->esq);
		printf("%d ", p->chave);
		emOrdem(p->dir);
	}
}

void posOrdem(NO* p){
	if(p) {
		posOrdem(p->esq);
		posOrdem(p->dir);
		printf("%d ", p->chave);
	}
}

void niveldado(NO* raiz, int level){
	if (level == 1) printf("%d, esq : %d   ", (raiz)->chave, raiz->esq->chave);
	else{
		niveldado((raiz)->esq, level-1);
		niveldado((raiz)->dir, level-1);
	}
}


void excluirFolha(NO* *raiz, int ch){

	if((*raiz) != NULL){

		printf("atual : %d\n", (*raiz)->chave);

		NO* esquerda = (*raiz)->esq; 
		NO* direita = (*raiz)->dir;

	
		if ( esquerda != NULL && esquerda->chave == ch ) {
			(*raiz)->esq = NULL;
			free(esquerda);
		}

		else if( direita != NULL && (*raiz)->dir->chave == ch ) {
			(*raiz)->dir = NULL;
			free(direita);
		}

		else {
			if (esquerda != NULL) {
				excluirFolha(&esquerda, ch);
			}
			if (direita != NULL) {
				excluirFolha(&direita, ch);
			}
		}

	}

}


// Inserção de um nó em árvore comum (sem ordem) esq:pos=1 dir:pos=2
NO* inserirNo(NO* *raiz, NO* pai, int ch, int pos) {
	NO* novo;

	novo = (NO *) malloc(sizeof(NO));
	novo->chave = ch;
	novo->esq = NULL;
	novo->dir = NULL;
	
	if(!pai) *raiz = novo;
	else {
		if(pos==1) pai->esq = novo;
		else pai->dir = novo;
	}
	return novo;
}






int main(){
	NO* raiz, *onde, *onde1, *onde2;
	inicializarArvore(&raiz);

	onde = inserirNo(&raiz, NULL, 18, 1);

	onde = inserirNo(&raiz, raiz, 17, 1);
	onde1 = onde;
	onde = inserirNo(&raiz, onde, 12, 1);
	onde2 = onde;
	onde = inserirNo(&raiz, onde, 3, 1);
	onde = inserirNo(&raiz, onde2, 9, 2);

	onde = inserirNo(&raiz, onde1, 15, 2);
	onde1 = onde;
	onde = inserirNo(&raiz, onde, 2, 1);
	onde = inserirNo(&raiz, onde1, 13, 2);

	onde = inserirNo(&raiz, raiz, 16, 2);
	onde1 = onde;
	onde = inserirNo(&raiz, onde, 6, 1);
	onde = inserirNo(&raiz, onde1, 5, 2);


	excluirFolha(&raiz, 3);

	
	preOrdem(raiz); printf("\n");
	//emOrdem(raiz); printf("\n");
	//posOrdem(raiz); printf("\n");
	
/*
	niveldado(raiz, 1); printf("\n");
	niveldado(raiz, 2); printf("\n");
	niveldado(raiz, 3); printf("\n");
	niveldado(raiz, 4); printf("\n");
*/
}