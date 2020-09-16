#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>


// https://stackoverflow.com/questions/46697901/linked-list-initialize-head-with-function
// 참고하기


typedef struct estr {
    int valor;
    struct estr* prox;
} NO;

void imprime(NO **ptrHead){
	NO *atual = *ptrHead;

	if(*ptrHead == NULL) printf("A lista esta vazia\n");
	else{
		while(atual){
			printf("%d  ", atual->valor);
			atual = atual->prox;
		}
		printf("\n");
	}

	printf("\n");
}

void adiciona(int x, NO **head){
	NO* atual;
	NO* anterior;

	NO* novo = (NO*)malloc(sizeof(NO));	
	novo->valor = x;
	novo->prox = NULL;

	if(*head == NULL) {
		printf("\n\nprimeira vez\n");
		*head = novo;
	}
	else {
		anterior = NULL;
		atual = *head;
		while(atual){
			anterior = atual;
			atual = atual->prox;
		}
		anterior->prox = novo;
	}

	printf("valor adicionado : %d\n", x);
}

NO* pulaRepeticao(NO *p){
	int x = p->valor;
	NO *pp = p;
	NO *ant = NULL;

	while(pp){
		if (pp->valor == x){
			ant = pp;
			pp = pp->prox;
		}
		else break;
	}

	return ant;
}

NO* uniao(NO* p1, NO* p2){

	NO *p11 = p1;
	NO *p22 = p2;

	NO *p111 = p11->prox;
	NO *p222 = p22->prox;

	NO *nuevo = NULL;

	while(p11 && p22) {
		/* verificar e pular repeticoes*/
		p11 = pulaRepeticao(p11);
		p22 = pulaRepeticao(p22);

		if (p11->valor < p22->valor){
			adiciona(p11->valor, &nuevo);
			p11 = p11->prox;
		}
		else if (p11->valor == p22->valor){
			adiciona(p11->valor, &nuevo);
			p11 = p11->prox;
			p22 = p22->prox;
		}
		// if (p11->valor > p22->valor)
		else {
			adiciona(p22->valor, &nuevo);
			p22 = p22->prox;
		}
	}

	// tem q verificar repeticao
	while (p11){
		adiciona(p11->valor, &nuevo);
		p11 = p11->prox;
	}
	while (p22){
		adiciona(p22->valor, &nuevo);
		p22 = p22->prox;
	}

	return nuevo;
}


int main() {

	NO* p1 = NULL;
	NO* p2 = NULL;

	adiciona(1, &p1);
	adiciona(2, &p1);
	adiciona(2, &p1);
	adiciona(6, &p1);
	adiciona(8, &p1);
	adiciona(9, &p1);

	adiciona(1, &p2);
	adiciona(2, &p2);
	adiciona(4, &p2);
	adiciona(5, &p2);
	adiciona(7, &p2);
	adiciona(7, &p2);
	adiciona(9, &p2);

	NO* teste = uniao(p1, p2);
	imprime(&teste);

}