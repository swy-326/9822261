#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include "atrapalha.h"


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
NO* validaaa(NO* p, NO* *queueue);
NO* ehValido(NO* *raiz, NO* *queueue);
NO* menorChave(NO* p);
NO* maiorChave(NO* p);
void exlcuirNo(NO** raiz, NO* errado);
int altura(NO* p);
void montarQueueue(NO* *queueue, NO* atual);


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


// 사실상 void
NO* validaaa(NO* p, NO* *queueue){

	if (!p) return NULL;
    
	NO* esq = validaaa(p->esq, queueue);
	montarQueueue(queueue, p);
	NO* dir = validaaa(p->dir, queueue);

	return *queueue;

}


// usado para teste
NO* ehValido(NO* *raiz, NO* *queueue){

	NO* filaa = validaaa(*raiz, queueue);
	if (filaa == NULL) return NULL;
	return filaa;

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
			if(paiDoMenorValor->chave == errado->chave) {
				printf("esta abajo\n");
				if(paiDoErrado->dir == errado) paiDoErrado->dir = menorValor;
				else paiDoErrado->esq = menorValor;

				menorValor->esq = errado->esq;
			}
			else {
				printf("esta lejo\n");
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
				printf("esta abajo\n");
				(*raiz) = menorValor;

				menorValor->esq = errado->esq;
			}
			else {
				printf("esta lejo\n");
				paiDoMenorValor->esq = NULL;
	
				(*raiz) = menorValor;


				menorValor->esq = errado->esq;
				menorValor->dir = errado->dir;
			}

		}

		free(errado);

	}

}


int altura(NO* p){

	if(p == NULL) return 0;

	return altura(p->esq) > altura(p->dir) ? altura(p->esq)+1 : altura(p->dir)+1;
}


// dir = prox; esq = ponteiro a guardar
void montarQueueue(NO* *queueue, NO* atual){

	if ((*queueue) == NULL) {
		printf("aaadicionado a queue : %d\n", atual->chave);
		NO* novo = (NO*) malloc (sizeof(NO));
		novo->esq = atual;
		novo->dir = NULL;
		(*queueue) = novo; 
	}
	else {
		NO* novo = (NO*) malloc (sizeof(NO));
		novo->esq = atual;
		novo->dir = (*queueue);
        (*queueue) = novo;
    	
        printf("aaadicionado a queue : %d\n", (*queueue)->esq->chave);
	}
}


NO* copiar(NO* raiz){
    NO* novo, *esq, *dir;
    novo = NULL;
    if(raiz){
        esq = copiar(raiz->esq);
        dir = copiar(raiz->dir);
        novo = (NO*) malloc (sizeof(NO));
        novo->chave = raiz->chave;
        novo->esq = esq;
        novo->dir = dir;
        printf("errrrrrooooooo : %d\n", novo->chave);
    }
    return novo;
}




// 사실상 void
NO* validaaa_v2(NO* p, NO* *queueue){

	if (!p) return NULL;
    
	NO* esq = validaaa(p->esq, queueue);
	montarQueueue(queueue, p);
	NO* dir = validaaa(p->dir, queueue);

	return *queueue;

}



bool percorrer_v2(NO* p, NO* raiz){

	NO* pp = p;
    NO* ppp = p;

	printf("\n\n---------------buscando erro---------------n");
    NO* outraFila = NULL;
	while ( pp->dir ){
        if (pp->esq->chave < pp->dir->esq->chave){ 
                            printf("now where is\n");

            return false;
        }
		pp = pp->dir;

	}

    return true;

}






NO* percorrer(NO* p, NO* raiz){

	NO* pp = p;
    NO* ppp = p;

	printf("\n\n=======buscando erro======\n");
    NO* outraFila = NULL;
	while ( pp->dir ){
        if (pp->esq->chave < pp->dir->esq->chave){ 
            montarQueueue(&outraFila, pp->dir->esq);
            montarQueueue(&outraFila, pp->esq);
        }
        printf("%d  ", pp->esq->chave);
		pp = pp->dir;
	}

    NO* pOutra = outraFila;
    while ( pOutra ){
	    
        printf("\n\n=======verificando se esta certo======\n");
        NO* tempPilha = NULL;

        NO* teste = NULL;
        teste = copiar(raiz);

        printf("No copiado\n");
        exlcuirNo(&teste, outraFila->esq);
        printf("\ndeletado\n");

        imprimirArvore(teste, 0);
        NO* temptemp = validaaa_v2(teste, &tempPilha);
        
        if ( percorrer_v2(tempPilha, teste) == true ) return outraFila->esq;
        else {
            free(teste);
            free(tempPilha);
            printf("bkppbkpppbkpbpkbpkb\n");
            pOutra = pOutra->dir;
        }
    }

    return NULL;

}



void organizar(NO* *raiz){

	if( (*raiz) != NULL ){

		NO* queueue = NULL;
		NO* temp = validaaa(*raiz, &queueue);

		NO* errado = percorrer(queueue, *raiz);

        if (errado != NULL) printf("corrigido");
		else printf("correto\n");

	}
}






int main() {

	NO* arv = NULL;

	NO* ershiwu = inserirNo(&arv, 25);
	
	NO* ershi = inserirDadoPai(&arv, ershiwu, 20, 1);
	NO* shi = inserirDadoPai(&arv, ershi, 10, 1);
	NO* wu = inserirDadoPai(&arv, shi, 79, 1);
	NO* shier = inserirDadoPai(&arv, shi, 12, 2);
	NO* ershier = inserirDadoPai(&arv, ershi, 22, 2);

	NO* sanshiliu = inserirDadoPai(&arv, ershiwu, 36, 2);
	NO* sanshi = inserirDadoPai(&arv, sanshiliu, 30, 1);
	NO* ershiba = inserirDadoPai(&arv, sanshi, 28, 1);
	NO* sishi = inserirDadoPai(&arv, sanshiliu, 40, 2);
	NO* sanshiba = inserirDadoPai(&arv, sishi, 38, 1);
	NO* sishiba = inserirDadoPai(&arv, sishi, 48, 2);



	imprimirArvore(arv, 0);
	printf("\n\n\n\n");


    organizar(&arv);


	printf("\n\n\n\n");
	imprimirArvore(arv, 0);


	NO* queueue = NULL;
    NO* temp = ehValido(&arv, &queueue);

    NO* errado = percorrer(queueue, arv);
	if (errado != NULL) printf("errado\n");
    else printf("certo\n");

}