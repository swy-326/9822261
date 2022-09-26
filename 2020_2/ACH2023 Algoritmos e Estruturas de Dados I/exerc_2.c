#include <stdio.h>
#include <stdbool.h>

/*
Ex1 Dada uma lista sequencial l não ordenada que admite repetição de chaves, e um valor de chave x, retorne o número de vezes que x aparece na lista.

int ocorrencias(LISTA* l, int x)

 
Ex2 Verifique se duas listas sequenciais l1 e l2 são idênticas (i.e., com as mesmas chaves, na mesma ordem e com o mesmo tamanho), retornando true/false conforme o caso.

bool identicas(LISTA* l1, LISTA *l2) 
*/

#define MAX 50

typedef struct {
    int chave;
} REGISTRO;

typedef struct {
    REGISTRO A[MAX];
    int nroElem;
} LISTA;

void inicializarLista1(LISTA* l){
	l->A[0].chave = 2;
	l->A[1].chave = 6;
	l->A[2].chave = 3;
	l->A[3].chave = 3;
	l->A[4].chave = 0;
    l->nroElem = 5;
}

void inicializarLista2(LISTA* l){
	l->A[0].chave = 2;
	l->A[1].chave = 6;
	l->A[2].chave = 3;
	l->A[3].chave = 3;
	l->A[4].chave = 0;
    l->nroElem = 5;
}

int exibirLista(LISTA* l){
    for (int i = 0; i < l->nroElem; i++){
        printf("%d ", l->A[i].chave);
    }
}

int ocorrencias(LISTA* l, int x){
	int num = 0;

	for (int i = 0; i < l->nroElem; i++){
		if (x == l->A[i].chave) num++;
	}

	return num;
}

bool identicas (LISTA* l1, LISTA* l2){
	if (l1->nroElem != l2->nroElem) return false;

	for (int i = 0; i < l1->nroElem; i++){
		if (l1->A[i].chave != l2->A[i].chave) return false;
	}

	return true;
}

int main(){

	LISTA l1;
	LISTA l2;

	inicializarLista1(&l1);
	inicializarLista2(&l2);

	exibirLista(&l1);	printf("\n");
	exibirLista(&l2);	printf("\n");

	printf("%d\n", ocorrencias(&l1, 3));
	printf("%d\n", identicas(&l1, &l2));

	return 0;
}