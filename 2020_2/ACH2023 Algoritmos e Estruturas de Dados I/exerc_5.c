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

void ExcluirOcorrencias(LISTA* l, int x){
	NO* anterior = NULL;
	NO* p = l->inicio;
	NO* proximo;
	NO* temp;

	// primeiro elemento da lista
	while(p != NULL && anterior == NULL && p->chave == x){
		temp = p->prox;
		l->inicio = temp;
		//printf("a. Excluido %d com prox apontando para %d\n\n", proximo->chave);
		free(p);
		p = l->inicio;
	}

	// anterior 이미 있는 상태임
	while(p != NULL){
		//printf("valor atual : %d em %d com prox %d\n", p->chave, p, p->prox);
		if(p->chave == x){
			anterior->prox = p->prox;
			//printf("b. Excluido %d com prox apontando para %d\n\n", p->chave, anterior->prox->chave);
			free(p);
			p = anterior->prox;
		}
		else {
			anterior = p;
			if (p->prox == NULL) break;
			else p = p->prox;
			//printf("c. Estou em %d, %d e indo para %d, %d\n\n", anterior->chave, anterior, p->chave, p);
		}
	}
}

void imprime(LISTA* l){
	NO *p = l->inicio;
	NO *pp = l->inicio;

	while(p){
		printf("%d %d %d\n", p, p->chave, p->prox);
		p = p->prox;
	}

	printf("\n");
}

void imprimir(NO* p){
	while(p){
		printf("%d \n", p->chave);
		p = p->prox;
	}
}


NO* copia(NO* p){
	NO* anterior = NULL;
	NO* temp;

	NO* novo = (NO*)malloc(sizeof(NO));
	novo->chave = p->chave;
	novo->prox = NULL;

	anterior = novo;
	p = p->prox;

	while(p){
		temp = (NO*)malloc(sizeof(NO));
		temp->chave= p->chave;
		temp->prox = NULL;

		anterior->prox = temp;

		printf("adicionado %d situado em %d a %d\n", temp->chave, temp, anterior->prox);

		anterior = temp;
		p = p->prox;
	}

	return novo;
}


int main(){
	LISTA* l = (LISTA*) malloc (sizeof(LISTA));
	l->inicio = NULL;

	adiciona(2, l); 
	adiciona(2, l);	
	adiciona(3, l);	
	adiciona(4, l);	
	adiciona(8, l);	
	adiciona(6, l);
	imprime(l);

	//ExcluirOcorrencias(l, 2);
	//imprime(l);

	NO* test = copia(l->inicio);
	imprimir(test);

	return 0;
}