/*
Dada uma chave ch garantidamente existente em uma ABB comum, exiba a chave precedente a ch na sequência de chaves da estrutura, ou seja, o valor de chave mais próximo possível de ch, porém inferior a ch.

A assinatura abaixo deve ser completada/modificada conforme a solução escolhida.
 
void precedente(NO* p, int ch, ...
*/

#include <stdio.h>
#include <stdlib.h>


typedef struct estr {
    int chave;
    struct estr *esq;
	struct estr *dir;
} NO;

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


void imprimirArvore(NO* p, int d){
	int i;
	if(p) {
		imprimirArvore(p->dir, d+1);
		for(i = 1; i <= d; i++) printf("     ");
		printf("%d\n", p->chave);
		imprimirArvore(p->esq, d+1);
	}
}

NO* acharNo(NO* raiz, int valor){

	NO* p = raiz;

	if (p){

		if (p->chave == valor) {
			return p;
		}

		NO* esq = acharNo(p->esq, valor);
		if (esq) {if(esq->chave == valor) return esq;}
		else {
			NO* dir = acharNo(p->dir, valor);
			if (dir) if(dir->chave == valor) return dir;
		}

	}

}

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


// so funciona parcialmente, esta errado
int precedente(NO* raiz, int ch){

	NO* noh = acharNo(raiz, ch);
	if (noh->esq){
		noh = noh->esq;
		while(noh->dir) noh = noh->dir;
		return noh->chave;
	}

	else {

		int valor = ch;
		NO* pai = acharpai(raiz, valor); 

		while( pai->esq->chave == valor ){
			printf("%d  ", pai->chave);
			pai = acharpai(raiz, valor); 
			valor = pai->chave;
		} 

		return pai->chave;

	}

}


int main(){

	NO* arv = NULL;

	NO* ershiwu = inserirNo(&arv, 25);
	
	NO* ershi = inserirDadoPai(&arv, ershiwu, 20, 1);
	NO* shi = inserirDadoPai(&arv, ershi, 10, 1);
	NO* wu = inserirDadoPai(&arv, shi, 5, 1);
	NO* shier = inserirDadoPai(&arv, shi, 12, 2);
	NO* ershier = inserirDadoPai(&arv, ershi, 22, 2);

	NO* sanshiliu = inserirDadoPai(&arv, ershiwu, 36, 2);
	NO* sanshi = inserirDadoPai(&arv, sanshiliu, 30, 1);
	NO* ershiba = inserirDadoPai(&arv, sanshi, 28, 1);
	NO* sishi = inserirDadoPai(&arv, sanshiliu, 40, 2);
	NO* sanshiba = inserirDadoPai(&arv, sishi, 38, 1);
	NO* sishiba = inserirDadoPai(&arv, sishi, 48, 2);

	imprimirArvore(arv, 0);

	int n;
	printf("Digite o numero a ser buscado : "); scanf("%d", &n);


    printf ("menor anterior a %d eh : %d\n", n, precedente(arv, n));

	//exibirFolhas(raiz);

	printf("teste\n");

	return 0;
}