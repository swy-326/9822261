#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>


/*

https://blog.csdn.net/xiaofei0859/article/details/77284951
https://www.jianshu.com/p/5c92720206e9
https://labuladong.gitbook.io/algo/shu-ju-jie-gou-xi-lie/2.3-shou-ba-shou-shua-er-cha-shu-xun-lian-di-gui-si-wei/er-cha-sou-suo-shu-cao-zuo-ji-jin
https://www.jianshu.com/p/998e0162db31
https://blog.csdn.net/sinat_35261315/article/details/78885322

*/



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
NO* ehValido(NO* *raiz, NO* *queueue);
void printInOrder(NO* raiz);
void organizar(NO* *raiz);
int altura(NO* p);



// inicializa a arvore
void inicializarArvore(NO* *raiz){
	*raiz = NULL;
}


// inserir novo no
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


// Iserir no dado a posicao do pai ( esq=1   dir=2 )
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


// imprimir horizontal
void imprimirArvore(NO* p, int d){
	int i;
	if(p) {
		imprimirArvore(p->dir, d+1);
		for(i = 1; i <= d; i++) printf("     ");
		printf("%d\n", p->chave);
		imprimirArvore(p->esq, d+1);
	}
}


// imprimir crescente
void printInOrder(NO* raiz){
	if(raiz != NULL){
		printInOrder(raiz->esq);
		printf("%d  ", raiz->chave);
		printInOrder(raiz->dir);
	}
}


// achar pai, raiz sempre eh valida
NO* acharpai(NO* raiz, int valor){

	if (raiz != NULL){

		NO* p = raiz;
		NO* temp = NULL;

		NO* esquerda = p->esq;
		NO* direita = p->dir;

		if (esquerda != NULL && esquerda->chave == valor || direita != NULL && direita->chave == valor) return p;
	
		else {
			if (esquerda != NULL){
				temp = acharpai(esquerda, valor);
			}  
			if (temp == NULL && direita != NULL){
				return acharpai(direita, valor); 
			}
		}
	}

}


// achar o endereco, dado a chave
NO* acharNo(NO* raiz, int valor){

	NO* p = raiz;

	if (p->chave == valor) return p;

	if( valor < p->chave ) acharNo(p->esq, valor);
	else acharNo(p->dir, valor);

}


// achar menor valor da (sub)arvore
NO* menorChave(NO* p){

	while (p->esq != NULL) p = p->esq;
	return p;

}


// achar maior valor da (sub)arvore
NO* maiorChave(NO* p){

	while (p->dir != NULL) p = p->dir;
	return p;

}


// excluir no
void exlcuirNo(NO** raiz, NO* errado){

	int chaveErrado = errado->chave;
	printf("\n\n\nchave a ser excluido :  %d\n", chaveErrado);
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
			pai = acharpai(*raiz, errado->chave);

			if (pai->esq == errado) pai->esq = errado->dir;
			else pai->dir = errado->dir;
		}
		else (*raiz) = errado->dir;

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
			printf("paiDoMenorValor : %d\n", paiDoMenorValor->chave);

			// se o menor valor esta logo abaixo do errado (sempre lado direito)
			if(paiDoMenorValor == errado) {
				printf("esta abajo");
				if(paiDoErrado->dir == errado) paiDoErrado->dir = menorValor;
				else paiDoErrado->esq = menorValor;

				menorValor->esq = errado->esq;
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


// esq = ponteiro guardado
// falso queue
void montarQueue(NO* *queueue, NO* atual){


	if ((*queueue) == NULL) {
		printf("adicionado a queue : %d\n", atual->chave);
		NO* novo = (NO*) malloc (sizeof(NO));
		novo->esq = atual;
		novo->dir = NULL;
		(*queueue) = novo; 
	}

}


// codigo copiado
NO* ehValido(NO* *raiz, NO* *queueue){

	NO* p = (*raiz);
	
	if ( p == NULL ) return NULL;

	printf("percorrendo : %d\n", p->chave);

	
	if ( ehValido(&(p->esq), queueue) || ehValido(&(p->dir), queueue) ) {
		printf("erro3 : %d\n", p->chave);
		montarQueue(queueue, p);
		return p;
	}

	if ( p->esq != NULL && (maiorChave(p->esq))->chave > p->chave ){ 
		printf("erro1 : %d\n", p->chave);
		montarQueue(queueue, p);
		return p;
	}

	if ( p->dir != NULL && (menorChave(p->dir))->chave < p->chave ) {
		printf("erro2 : %d\n", p->chave);
		montarQueue(queueue, p);
		return p;
	}


	return NULL;

}


// falta tratar arvore com apenas dois elementos
void organizar(NO* *raiz) {

	if( (*raiz) != NULL ){

		NO* queueue = NULL;

		NO* temp = ehValido(raiz, &queueue);
		if (temp != NULL){ 
			exlcuirNo(raiz, queueue->esq);
		}
		else printf("correto\n");

	}
}






int main() {

	NO* arv = NULL;


/*
	NO* sanshi = inserirNo(&arv, 30);

	NO* san = inserirDadoPai(&arv, sanshi, 3, 1);
	NO* wu = inserirDadoPai(&arv, san, 5, 1);
	NO* ershiwu = inserirDadoPai(&arv, san, 20, 2);
	NO* shijiu = inserirDadoPai(&arv, ershiwu, 19, 1);
	NO* ershier = inserirDadoPai(&arv, ershiwu, 22, 2);
	NO* shiba = inserirDadoPai(&arv, shijiu, 18, 1);

	NO* liushi = inserirDadoPai(&arv, sanshi, 60, 2);
	NO* wushi = inserirDadoPai(&arv, liushi, 50, 1);
	NO* yibai = inserirDadoPai(&arv, liushi, 100, 2);
	NO* yibaiyi = inserirDadoPai(&arv, yibai, 101, 2);
*/



//	========= 세개일때 문제남 =============

	NO* sanshi = inserirNo(&arv, 30);
	NO* jiu = inserirDadoPai(&arv, sanshi, 9, 1);
	NO* jiushi = inserirDadoPai(&arv, sanshi, 7, 2);


/*
	NO* sanshi = inserirNo(&arv, 30);
	NO* jiu = inserirDadoPai(&arv, sanshi, 9, 1);
	NO* jiushi = inserirDadoPai(&arv, sanshi, 90, 2);
*/

/*
	NO* sanshi = inserirNo(&arv, 30);
	NO* jiu = inserirDadoPai(&arv, sanshi, 1, 1);
*/

/*
	NO* sanshi = inserirNo(&arv, 30);
	NO* jiu = inserirDadoPai(&arv, sanshi, 78, 1);
*/

/*
	NO* sanshi = inserirNo(&arv, 30);
	NO* jiu = inserirDadoPai(&arv, sanshi, 9, 2);
*/

/*
	NO* sanshi = inserirNo(&arv, 30);

	NO* san = inserirDadoPai(&arv, sanshi, 7, 1);
	NO* wu = inserirDadoPai(&arv, san, 5, 1);
	NO* ershiwu = inserirDadoPai(&arv, san, 6, 2);
	NO* shijiu = inserirDadoPai(&arv, ershiwu, 19, 1);
	NO* ershier = inserirDadoPai(&arv, ershiwu, 22, 2);
	NO* shiba = inserirDadoPai(&arv, shijiu, 18, 1);

	NO* liushi = inserirDadoPai(&arv, sanshi, 60, 2);
	NO* wushi = inserirDadoPai(&arv, liushi, 50, 1);
	NO* yibai = inserirDadoPai(&arv, liushi, 100, 2);
	NO* yibaiyi = inserirDadoPai(&arv, yibai, 101, 2);
*/

/*
	NO* sanshi = inserirNo(&arv, 30);

	NO* ershi = inserirDadoPai(&arv, sanshi, 29, 1);

	NO* bashijiu = inserirDadoPai(&arv, sanshi, 21, 2);
	NO* sanshier = inserirDadoPai(&arv, bashijiu, 90, 2);
*/

/*
	NO* sanshi = inserirNo(&arv, 30);

	NO* ershi = inserirDadoPai(&arv, sanshi, 20, 1);

	NO* bashijiu = inserirDadoPai(&arv, ershi, 89, 2);
	NO* sanshier = inserirDadoPai(&arv, bashijiu, 29, 2);
*/


/*
	NO* sanshi = inserirNo(&arv, 30);

	NO* ershi = inserirDadoPai(&arv, sanshi, 20, 1);
	NO* wu = inserirDadoPai(&arv, ershi, 5, 1);
	NO* ershiwu = inserirDadoPai(&arv, ershi, 35, 2);
	NO* ershier = inserirDadoPai(&arv, ershiwu, 22, 2);

	NO* liushi = inserirDadoPai(&arv, sanshi, 60, 2);
	NO* wushi = inserirDadoPai(&arv, liushi, 50, 1);
	NO* yibai = inserirDadoPai(&arv, liushi, 100, 2);
	NO* yibaiyi = inserirDadoPai(&arv, yibai, 101, 2);
*/


/*
	NO* sanshi = inserirNo(&arv, 30);

	NO* san = inserirDadoPai(&arv, sanshi, 3, 1);
	NO* wu = inserirDadoPai(&arv, san, 5, 1);
	NO* ershiwu = inserirDadoPai(&arv, san, 25, 2);
	NO* shijiu = inserirDadoPai(&arv, ershiwu, 19, 1);
	NO* ershier = inserirDadoPai(&arv, ershiwu, 29, 2);
	NO* shiba = inserirDadoPai(&arv, shijiu, 18, 1);

	NO* liushi = inserirDadoPai(&arv, sanshi, 60, 2);
	NO* wushi = inserirDadoPai(&arv, liushi, 50, 1);
	NO* yibai = inserirDadoPai(&arv, liushi, 100, 2);
	NO* yibaiyi = inserirDadoPai(&arv, yibai, 101, 2);
*/



	imprimirArvore(arv, 0);
	printf("\n\n\n\n");
	organizar(&arv);

	printf("\n\n\n\n");
	imprimirArvore(arv, 0);

		NO* queueue = NULL;


	if ( ehValido(&arv, &queueue) == NULL ) printf("corretissimo");
	else printf("ou errado ou teste errado");
}
