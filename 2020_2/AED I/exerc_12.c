#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct estrutura {
	int chave;
	struct estrutura *esq;
	struct estrutura *dir;
} NO;

/*

1. Escreva um algoritmo que, dado um nó p em árvore binária, retorne a sua altura.
 
int altura(NO* p)
 
2. Dada uma árvore comum (não ordenada) contendo apenas chaves entre 0 e 100 sem repetição, escreva um algoritmo que retorne a menor chave da estrutura. Se a árvore esteja vazia, retorne um valor fora do intervalo válido.
 
int menorChave(NO* p)

*/

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

void niveldado(NO* raiz, int level){
	if (level == 1) printf("%d   ", (raiz)->chave);
	else{
		niveldado((raiz)->esq, level-1);
		niveldado((raiz)->dir, level-1);
	}
}

void emOrdem(NO* p){
	if(p) {
		emOrdem(p->esq);
		printf("%d ", p->chave);
		emOrdem(p->dir);
	}
}

int altura(NO* p){

	if(p == NULL) return 0;

	return altura(p->esq) > altura(p->dir) ? altura(p->esq)+1 : altura(p->dir)+1;
}



int menorChave(NO* p){

	if(p){

		if (p->esq == NULL && p->dir == NULL) return p->chave;

		int esquerda = menorChave(p->esq);
		int direita = menorChave(p->dir);

		return (esquerda < direita) ? esquerda : direita;

	}

}



int mmenorChave(NO* p){

	int dir, esq;
	printf("valor atual : %d\n", p->chave);

	if (p == NULL) return 999;

	else{

		esq = menorChave(p->esq);
		dir = menorChave(p->dir);

		if(p != NULL) return p->chave;

		return (esq < dir) ? esq : dir;	
	}

}

NO* buscaNo (NO* raiz, int ch, NO* *pai){
	NO* atual = raiz;
	*pai = NULL;
	while(atual){
		if (atual->chave == ch) printf("n\n");
	}
}

int main(){

	NO* raiz;
	inicializarArvore(&raiz);

	inserirNo(&raiz, 6);
	inserirNo(&raiz, 4);
	inserirNo(&raiz, 8);
	inserirNo(&raiz, 3);
	inserirNo(&raiz, 5);
	inserirNo(&raiz, 7);
	inserirNo(&raiz, 9);
	inserirNo(&raiz, 1);
	inserirNo(&raiz, -4);
	inserirNo(&raiz, 89);


	printf("altura eh : %d\n", altura(raiz));
	printf("menor chave : %d\n", menorChave(raiz));

	emOrdem(raiz); printf("\n");

/*

	niveldado(raiz, 1); printf("\n");
	niveldado(raiz, 2); printf("\n");
	niveldado(raiz, 3); printf("\n");
	niveldado(raiz, 4); printf("\n");
*/

	return 0;
}