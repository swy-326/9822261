#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

/*


a. Dada uma lista ligada dinâmica l não ordenada que admite repetição de chaves, e um valor de chave x, retorne o número de vezes que x aparece na lista.
 int ocorrencias(LISTA* l, int x)
 
b. Verifique se duas listas ligadas dinâmicas l1 e l2 são idênticas (i.e., com as mesmas chaves, na mesma ordem e com o mesmo tamanho), retornando true/false conforme o caso.
 bool identicas(LISTA* l1, LISTA *l2) 


*/


typedef struct estrutura {
	int chave;
	struct estrutura *prox;
} NO;

typedef struct {
	NO *inicio;
} LISTA;


int ocorrencias (LISTA* l, int x);
bool identicas (LISTA* l1, LISTA *l2);
void adiciona(int x, LISTA* l);

int main(){

	LISTA* l = (LISTA*) malloc (sizeof(LISTA));
	l->inicio = NULL;
	/*
	adiciona(1, l); 
	adiciona(2, l);	
	adiciona(3, l);	
	adiciona(4, l);	
	adiciona(5, l);	
	adiciona(6, l);
*/
	LISTA* ll = (LISTA*) malloc (sizeof(LISTA));
	ll->inicio = NULL;
	adiciona(1, ll);
	adiciona(2, ll);
	adiciona(3, ll);
	adiciona(4, ll);
	adiciona(5, ll);
	adiciona(6, ll);
	adiciona(6, ll);


	printf("%d\n", ocorrencias(l, 3));
	if (identicas(l, ll)) printf("True\n");
	else printf("False");


	return 0;
}

int ocorrencias (LISTA* l, int x){
	NO *p = l->inicio;

	if (p == NULL) return -1;

	int i = 0;
	while (p){
		if (p->chave == x) i++;
		p = p->prox;
	}

	return i;
}

bool identicas (LISTA* l1, LISTA *l2){
	NO *ptrl1 = l1->inicio;
	NO *ptrl2 = l2->inicio;

	while(ptrl1 && ptrl2){
		if (ptrl1->chave != ptrl2->chave) return false;
		ptrl1 = ptrl1->prox;
		ptrl2 = ptrl2->prox;
	}

	if (ptrl1 != NULL || ptrl2 != NULL) return false;

	return true;
}

void adiciona(int x, LISTA* l){
	NO *pp = l->inicio;
	NO *novo = (NO*) malloc (sizeof(NO));

	novo->chave = x;
	novo->prox = NULL;

	if (l->inicio == NULL) l->inicio = novo;
	else {
		while(pp->prox){
			pp = pp->prox;
		}
		pp->prox = novo;
	}

	//printf("Adicionado %d em %d, anterior %d e prox como %d\n", x, novo, pp, novo->prox);
}
