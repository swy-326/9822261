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

	while (p->esq != NULL) p = p->esq;
	return p;

}


void exlcuirNo(NO** raiz, NO* errado){

	int chaveErrado = errado->chave;
	printf("chave a ser excluido :  %d\n", chaveErrado);
	NO* pai = NULL;

	// no errado nao tem filhos
	if ( errado->esq == NULL && errado->dir == NULL ){
		printf("case : nao tem filhos\n");

		if (errado != *raiz) {
			pai = acharpai(*raiz, chaveErrado);
		
			if (pai->esq == errado) pai->esq = NULL;
			else if (pai->dir == errado) pai->dir = NULL;
		}
		else (*raiz) = NULL;

		free(errado);
	}

	// no errado so tem filho esquerdo
	else if ( errado->esq != NULL && errado->dir == NULL ) {
		printf("case : apenas filho esquerdo");

		if (errado != (*raiz)){
			pai = acharpai(*raiz, chaveErrado);

			if (pai->esq == errado) pai->esq = errado->esq;
			else if (pai->dir == errado) pai->dir = errado->esq;
		}

		else (*raiz) = errado->esq;

		free(errado);
	}

	// no errado so tem filho direito
	else if ( errado->esq == NULL && errado->dir != NULL ){
		printf("case : apenas filho direito");

		if (errado != (*raiz)){
			pai = acharpai(*raiz, chaveErrado);

			if (pai->esq == errado) pai->esq = errado->dir;
			else if (pai->dir == errado) pai->dir = errado->dir;
		}
		else (*raiz) = errado->dir;


		if (errado == *raiz) *raiz = pai;

		free(errado);		
	}

	// tem ambos os filhos direito e esquerdo
	else {
		printf("case : ambos os filhos\n");

		// procura o menor valor e pai do errado
		NO* menorValor = menorChave(errado->dir);
		NO* paiDoErrado = acharpai(*raiz, errado->chave);
		printf("menor valor : %d\n", menorValor->chave);

		// pai do menor valor
		NO* paiDoMenorValor = acharpai(*raiz, menorValor->chave);

		// se o menor valor esta logo abaixo do errado (sempre lado direito)
		if(paiDoMenorValor == errado) {
			printf("esta abajo");
			paiDoMenorValor->esq = NULL;
			if(paiDoErrado->dir == errado) paiDoErrado->dir = menorValor;
			else paiDoErrado->esq = menorValor;
		}
		else {
			printf("esta lejo");
			paiDoMenorValor->esq = NULL;
	
			if(paiDoErrado->dir == errado) paiDoErrado->dir = menorValor;
			else paiDoErrado->esq = menorValor;

			menorValor->esq = errado->esq;
			menorValor->dir = errado->dir;

		}

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
	inserirNo(&arv, 53);
	inserirNo(&arv, 67);
	inserirNo(&arv, 66);
	inserirNo(&arv, 100);
	inserirNo(&arv, 8);
	inserirNo(&arv, 13);


	imprimirArvore(arv, 72);
	printf("\n\n\n");


	NO* noAExcluir = acharNo(arv, 50);
	exlcuirNo(&arv, noAExcluir);

	printf("\n\n");
	imprimirArvore(arv, 0);


	// serao realizadas chamadas como esta:
	// organizar(&arv);

}