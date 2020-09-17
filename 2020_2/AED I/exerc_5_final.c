#include <stdio.h>
#include <stdlib.h>

typedef struct estrutura {
	int chave;
	struct estrutura *prox;
} NO;

typedef struct {
	NO *inicio;
} LISTA;


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
}

// Codigos escritos assumindo que a lista eh nao-vazia
void ExcluirOcorrencias(LISTA* l, int x){
	NO* anterior = NULL;
	NO* p = l->inicio;
	NO* temp;

	// ocorrencias no inicio da lista
	while(p != NULL && anterior == NULL && p->chave == x){
		temp = p->prox;
		l->inicio = temp;
		free(p);
		p = l->inicio;
	}

	// ocorrencias no meio ou final da lista
	while(p != NULL){
		if(p->chave == x){
			anterior->prox = p->prox;
			free(p);
			p = anterior->prox;
		}
		else {
			anterior = p;
			if (p->prox == NULL) break;
			else p = p->prox;
		}
	}
}

void imprime(LISTA* l){
	NO *p = l->inicio;
	NO *pp = l->inicio;

	while(p){
		printf("%d em %d\n", p->chave, p);
		p = p->prox;
	}

	printf("\n");
}

void imprimir(NO* p){
	while(p){
		printf("%d em %d\n", p->chave, p);
		p = p->prox;
	}
	printf("\n");
}


NO* copia(NO* p){
	NO* anterior = NULL;
	NO* temp;

	// copiar primeiro elemento
	NO* novo = (NO*)malloc(sizeof(NO));
	novo->chave = p->chave;
	novo->prox = NULL;

	anterior = novo;
	p = p->prox;

	// elementos seguidos
	while(p){
		temp = (NO*)malloc(sizeof(NO));
		temp->chave= p->chave;
		temp->prox = NULL;

		anterior->prox = temp;
		anterior = temp;
		p = p->prox;
	}

	return novo;
}


int main(){
	LISTA* l = (LISTA*) malloc (sizeof(LISTA));
	l->inicio = NULL;

	adiciona(1, l); 
	adiciona(1, l);	
	adiciona(3, l);	
	adiciona(2, l);	
	adiciona(2, l);	
	adiciona(2, l);
	adiciona(1, l);
	imprime(l);

	ExcluirOcorrencias(l, 0);
	imprime(l);

	NO* test = copia(l->inicio);
	imprimir(test);

	return 0;
}