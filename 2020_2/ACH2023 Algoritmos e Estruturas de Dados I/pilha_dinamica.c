// 본인 밑에 있는 애 위치를 담고있어야됨

#include <stdio.h>
#include <stdlib.h>

typedef struct {
	int chave;
} REGISTRO;

typedef struct aux {
	REGISTRO reg;
	struct aux* prox;
} ELEMENTO;

typedef struct{
	ELEMENTO* topo;
} PILHA;


void inicializa(PILHA *p){
	p->topo = NULL;
}

int quantidade(PILHA *p){
	ELEMENTO* end = p->topo;
	int tam = 0;
	while(end != NULL){
		tam++;
		end = end->prox;
	}
	return tam;
}

void imprime(PILHA *p){
	ELEMENTO* end = p->topo;
	while(end != NULL){
		printf("%d  ", end->reg.chave);
		end = end->prox;
	}
	printf("\n");	
}

bool estaVazia(PILHA *p){
	if(p->topo == NULL) return true;
	return false;
}

bool push(PILHA *p, REGISTRO reg){
	ELEMENTO* novo = (ELEMENTO*) malloc(sizeof(ELEMENTO));
	novo->reg = reg;
	novo->prox = p->topo;
	p->topo = novo;
	return true;
}


void pop(PILHA *p){
	if(p->topo == NULL) return false;
	ELEMENTO* apagar = p->topo;
	p->topo = p->topo->prox;
	free(apagar);
	return true;
}

void reinicializa(PILHA *p){
	ELEMENTO* apagar;
	ELEMENTO* posicao = p->topo;
	while(posicao != NULL){
		apagar = posicao;
		posicao = posicao->prox;
		free(apagar);
	}
	p->topo = NULL;
}