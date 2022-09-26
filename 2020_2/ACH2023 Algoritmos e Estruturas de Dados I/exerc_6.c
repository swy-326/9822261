/*

Dada uma lista ligada de elementos inteiros *p, escreva um algoritmo que retorne uma cópia invertida da lista utilizando uma pilha dinâmica como estrutura auxiliar. 
 
Dica: use a função PUSH da apostila para empilhar, e depois use POP com a função de cópia do exercício anterior para obter a lista invertida.
 
NO* copiaInvertida(NO* p) 

*/

#include <stdio.h>
#include <stdlib.h>

typedef struct estrutura {
	int chave;
	struct estrutura *prox;
} NO;

typedef struct {
	NO* topo;
} PDINAM;

void imprime(NO* p){
	while(p){
		printf("%d em %d\n", p->chave, p);
		p = p->prox;
	}
	printf("\n");
}

void adiciona(int x, NO* p){
	NO *pp = p;

	NO *novo = (NO*) malloc (sizeof(NO));
	novo->chave = x;
	novo->prox = NULL;

	while(pp->prox){
		pp = pp->prox;
	}
	pp->prox = novo;
}

void push(int ch, PDINAM* p) {
	NO* novo = (NO*) malloc(sizeof(NO));
	novo->chave = ch;
	if (p->topo == NULL) novo->prox = NULL;
	else novo->prox = p->topo;
	p->topo = novo;
}

int pop(PDINAM* p) {
	NO* aux;
	int ch;

	if(!p->topo) return(-1);

	aux = p->topo;
	ch = aux->chave;
	p->topo = p->topo->prox;
	free(aux);
	
	return(ch);
}

NO* copiaInvertida(NO* p) {
	NO* runner = p;

	PDINAM* tempPilha = (PDINAM*)malloc(sizeof(PDINAM));
	tempPilha->topo = NULL;

	while(runner){
		push(runner->chave, tempPilha);
		runner = runner->prox;
	}

	NO* copiaInv = (NO*)malloc(sizeof(NO));
	copiaInv->chave = pop(tempPilha);
	copiaInv->prox = NULL;

	while(tempPilha->topo){
		adiciona(pop(tempPilha), copiaInv);
	}

	return copiaInv;
}




int main(){

	NO* head = (NO*) malloc (sizeof(NO));
	head->chave = 1;
	head->prox = NULL;
	
	for (int i = 2; i < 7; i++){
		adiciona(i, head);
	}

	imprime(head);
	imprime( copiaInvertida(head) );

	return 0;
}
