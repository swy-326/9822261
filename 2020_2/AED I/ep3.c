#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

// ######### ESCREVA O NROUSP AQUI
const char* nroUSP() {
    return("9822261");
}


// no da arvore
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


// retorna o endereco do no errado
bool ehValido(NO* *raiz, NO* *errado){
	NO* p = (*raiz);
	return true;
}


// raiz sempre eh != NULL
NO* acharpai(NO* raiz, int valor){

	NO* p = raiz;

	NO* esquerda = p->esq;
	NO* direita = p->dir;

	if (esquerda != NULL && esquerda->chave == valor || direita != NULL && direita->chave == valor) return p;
	
	else {
		if (valor < p->chave && esquerda != NULL) acharpai(esquerda, valor);
		else acharpai(direita, valor);
	} 
}


// usado apenas para testes
NO* acharNo(NO* raiz, int valor){

	NO* p = raiz;

	if (p->chave == valor) return p;

	if( valor < p->chave ) acharNo(p->esq, valor);
	else acharNo(p->dir, valor);

}


NO* menorChave(NO* p){

	if(p){

		if (p->esq == NULL && p->dir == NULL) return p;

		NO* esquerda = menorChave(p->esq);
		NO* direita = menorChave(p->dir);

		return (esquerda->chave < direita->chave) ? esquerda : direita;

	}

}


void exlcuirNo(NO* raiz, NO* errado){

	int chaveErrado = errado->chave;
	printf("chave a ser excluido :  %d\n", chaveErrado);
	NO* pai = NULL;

	// no errado nao tem filhos
	if ( errado->esq == NULL && errado->dir == NULL ){
		printf("case : nao tem filhos\n");
		pai = acharpai(raiz, chaveErrado);
		printf("achou o pai %d\n", pai->chave);
		
		if (pai->esq == errado) pai->esq = NULL;
		else if (pai->dir == errado) pai->dir = NULL;

		free(errado);
	}

	// no errado so tem filho esquerdo
	else if ( errado->esq == NULL && errado->dir != NULL ) {
		printf("case : apenas filho esquerdo");
		pai = acharpai(raiz, chaveErrado);

		if (pai->esq == errado) pai->esq = errado->esq;
		else if (pai->dir == errado) pai->dir = errado->esq;

		free(errado);
	}

	// no errado so tem filho direito
	else if ( errado->esq != NULL && errado->dir == NULL ){
		printf("case : apenas filho direito");
		pai = acharpai(raiz, chaveErrado);

		if (pai->esq == errado) pai->esq = errado->dir;
		else if (pai->dir == errado) pai->dir = errado->dir;

		free(errado);		
	}

	// tem ambos os filhos direito e esquerdo
	else {
		printf("case : ambos os filhos");

		NO* menorValor = menorChave(errado->dir);
		NO* paiDoMenorValor = acharpai(raiz, menorValor->chave);
		paiDoMenorValor->esq = NULL;

		NO* paiDoErrado = acharpai(raiz, errado->chave);
		paiDoErrado->dir = menorValor;
		menorValor->dir = errado->dir;

		free(errado);
	}

}

/*
void organizar(NO* *raiz) {
	
	NO* errado = NULL;
	NO* p = (*raiz);

	if ( p != NULL ){
		if( !ehValido(p, &errado) ) exlcuirNo(errado);
	}

}
*/





int main() {

	NO* arv = NULL;

	inicializarArvore(&arv);

	inserirNo(&arv, 50);
	inserirNo(&arv, 17);
	inserirNo(&arv, 72);
	inserirNo(&arv, 12);
	inserirNo(&arv, 23);
	inserirNo(&arv, 54);
	inserirNo(&arv, 76);
	inserirNo(&arv, 9);
	inserirNo(&arv, 14);
	inserirNo(&arv, 67);
	inserirNo(&arv, 15);

	imprimirArvore(arv, 0);
	printf("\n\n\n");


	NO* noAExcluir = acharNo(arv, 15);
	exlcuirNo(arv, noAExcluir);

	imprimirArvore(arv, 0);


	// serao realizadas chamadas como esta:
	// organizar(&arv);

}