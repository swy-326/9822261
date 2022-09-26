#include <stdio.h>
#include <stdbool.h>

#define MAX 50

typedef struct {
	int chave;
} REGISTRO;

typedef struct {
	REGISTRO A[MAX];
	int topo;
} PILHA;

void inicializa(PILHA *p){
	p->topo = -1;
}

int quantidade(PILHA *p){
	return (p->topo + 1);
}

void exibir(PILHA *p){
	printf("PILHA :  ")
	for (int i = 0; i < topo; i++){
		printf("%d ", p->A[i].chave);
	}
}

// insere
bool push(PILHA *p, REGISTRO reg){
	if(p->topo == MAX-1) return false;
	p->topo = p->topo+1;
	p->A[p->topo] = reg;
	return true;
}

bool pop(){
	if(p->topo == -1) return false;
	p->topo--;
}

void reinicializa(){
	p->topo = -1;
}