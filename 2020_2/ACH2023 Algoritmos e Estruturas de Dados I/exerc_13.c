#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>


/*

1. Exibir todas as folhas de uma árvore, em qualquer ordem.
void exibirFolhas(NO* p)
 
2. Em ABB, exibir os ancestrais de uma chave x, do seu pai até a raiz.
void exibeAncestrais(NO* p, int x)

*/

typedef struct estr {
    int chave;
    struct estr *esq;
	struct estr *dir;
} NO;


void inicializarArvore(NO* *raiz){
	*raiz = NULL;
}


void inserirNo(NO* *raiz, int ch){
	NO* pai;
	NO* atual;

	NO* novo = (NO*) malloc (sizeof(NO));
	novo->chave = ch;
	novo->esq = NULL; novo->dir = NULL;


	if (*raiz == NULL){
		(*raiz) = novo;
	}

	else {
		atual = (*raiz);
		pai = NULL;

		while(atual != NULL){

			pai = atual;

			if (ch < pai->chave){
				atual = atual->esq;
				if(atual == NULL) pai->esq = novo;
			}

			else { 
				atual = atual->dir;
				if (atual == NULL) pai->dir = novo;
			}
		}
	}
}


void imprimirArvore(NO* p, int d){
	int i;
	if(p) {
		imprimirArvore(p->dir, d+1);
		for(i = 1; i <= d; i++) printf("     ");
		printf("%d\n", p->chave);
		imprimirArvore(p->esq, d+1);
	}
}


void exibirFolhas(NO* p){
	if(p) {
		if(p->esq == NULL && p->dir == NULL) printf("%d ", p->chave);
		exibirFolhas(p->esq);
		exibirFolhas(p->dir);
	}
}


// so funciona se a chave existir, se nao fosse void, teria outro jeito
void exibeAncestrais(NO* p, int x){
	if(p->esq == NULL && p->dir == NULL && p->chave != x){
		printf("nao encontrado\n");
		exit();
	}
	else if(p->chave != x && p != NULL){
		if(x < p->chave) exibeAncestrais(p->esq, x);
		else exibeAncestrais(p->dir, x); 
		printf("%d ", p->chave);
	}
}


int main(){

	NO* raiz;
	inicializarArvore(&raiz);

	inserirNo(&raiz, 50);
	inserirNo(&raiz, 17);
	inserirNo(&raiz, 72);
	inserirNo(&raiz, 12);
	inserirNo(&raiz, 23);
	inserirNo(&raiz, 54);
	inserirNo(&raiz, 76);
	inserirNo(&raiz, 9);
	inserirNo(&raiz, 14);
	inserirNo(&raiz, 67);
	inserirNo(&raiz, 15);
	//inserirNo(&raiz, 16);

	imprimirArvore(raiz, 0);
	exibeAncestrais(raiz, 15);
	//exibirFolhas(raiz);

	printf("teste\n");

	return 0;
}