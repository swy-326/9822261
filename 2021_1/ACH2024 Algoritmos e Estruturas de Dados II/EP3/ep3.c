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



void inicializarArvore(NO* *raiz);
NO* inserirNo(NO* *raiz, int ch);
NO* inserirDadoPai(NO* *raiz, NO* pai, int ch, int pos);
void imprimirArvore(NO* p, int d);
NO* acharpai(NO* raiz, int valor);
NO* acharNo(NO* raiz, int valor);
NO* menorChave(NO* p);
NO* maiorChave(NO* p);
void exlcuirNo(NO** raiz, NO* errado);
NO* ehValido(NO* *raiz);
void printInOrder(NO* raiz);
void organizar(NO* *raiz);




void inicializarArvore(NO* *raiz){
	*raiz = NULL;
}


NO* inserirNo(NO* *raiz, int ch){
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
	return novo;
}

// Inserção de um nó em árvore comum (sem ordem) esq:pos=1 dir:pos=2 
NO* inserirDadoPai(NO* *raiz, NO* pai, int ch, int pos) {
	NO* novo;
	novo = (NO *) malloc(sizeof(NO));
	novo->chave = ch;
	novo->esq = NULL;
	novo->dir = NULL;
	
	if(pos == 1) pai->esq = novo;
	else pai->dir = novo;

	return novo;
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


NO* maiorChave(NO* p){

	while (p->dir != NULL) p = p->dir;
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

		if (errado != (*raiz)){

			// procura o menor valor e pai do errado
			NO* menorValor = menorChave(errado->dir);
			NO* paiDoErrado = acharpai(*raiz, errado->chave);
			printf("menor valor : %d\n", menorValor->chave);

			// pai do menor valor
			NO* paiDoMenorValor = acharpai(*raiz, menorValor->chave);

			// se o menor valor esta logo abaixo do errado (sempre lado direito)
			if(paiDoMenorValor == errado) {
				printf("esta abajo");
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
		}
		else {

			// procura o menor valor e pai do errado
			NO* menorValor = menorChave(errado->dir);
			printf("menor valor : %d\n", menorValor->chave);

			// pai do menor valor
			NO* paiDoMenorValor = acharpai(*raiz, menorValor->chave);

			// se o menor valor esta logo abaixo do errado (sempre lado direito)
			if(paiDoMenorValor == errado) {
				printf("esta abajo");
				(*raiz) = menorValor;

				menorValor->esq = errado->esq;
			}
			else {
				printf("esta lejo");
				paiDoMenorValor->esq = NULL;
	
				(*raiz) = menorValor;


				menorValor->esq = errado->esq;
				menorValor->dir = errado->dir;
			}

		}

		free(errado);

	}

}


// retorna o endereco do no errado
NO* ehValido(NO* *raiz){

	NO* p = (*raiz);
	
	if ( p == NULL ) return NULL;

	if ( p->esq != NULL && (maiorChave(p->esq))->chave > p->chave ) return p;
	if ( p->dir != NULL && (menorChave(p->dir))->chave < p->chave ) return p;

	if ( ehValido(&(p->esq)) || ehValido(&(p->dir)) ) return p;

	return NULL;
}


void printInOrder(NO* raiz){
	if(raiz != NULL){
		printInOrder(raiz->esq);
		printf("%d  ", raiz->chave);
		printInOrder(raiz->dir);
	}
	
}


// arvore com apenas dois elementos
void organizar(NO* *raiz) {

	if( (*raiz) != NULL ){

		NO* temp = ehValido(raiz);
		if (temp != NULL){ 
			printf("no errado : %d\n\n\n", temp->chave);
			NO* noAExcluir = acharNo(*raiz, temp->chave);
			exlcuirNo(raiz, noAExcluir);
		}
		else printf("correto\n");

	}
}






int main() {

	NO* arv = NULL;

	NO* ershiyi = inserirNo(&arv, 21);
	NO* yi = inserirDadoPai(&arv, ershiyi, 39, 2);



/*
	NO* ershiyi = inserirNo(&arv, 21);
	NO* ershi = inserirNo(&arv, 20);
	NO* liushi = inserirNo(&arv, 60);

	NO* wu = inserirDadoPai(&arv, ershi, 5, 1);
	NO* sanshiwu = inserirDadoPai(&arv, ershi, 35, 2);
	NO* ershier = inserirDadoPai(&arv, sanshiwu, 22, 1);

	NO* wushi = inserirDadoPai(&arv, liushi, 50, 1);
	NO* bai = inserirDadoPai(&arv, liushi, 100, 2);
	NO* yibaiyi = inserirDadoPai(&arv, bai, 101, 2);

*/

/*
	inserirNo(&arv, 50);
	inserirNo(&arv, 17);
	inserirNo(&arv, 72);
	inserirNo(&arv, 12);
	inserirNo(&arv, 23);
	inserirNo(&arv, 54);
	inserirNo(&arv, 76);
	inserirNo(&arv, 14);
	inserirNo(&arv, 53);
	inserirNo(&arv, 100);
	inserirDadoPai(&arv, 100, 102, 1);
*/

	imprimirArvore(arv, 0);


	//printf("\n==============\n\n\n");
	//printInOrder(arv);

	organizar(&arv);


	printf("\n\n\n\n");
	imprimirArvore(arv, 0);


	// serao realizadas chamadas como esta:
	// organizar(&arv);

}