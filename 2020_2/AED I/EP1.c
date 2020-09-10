#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

typedef struct estr {
        int valor;
        struct estr* prox;
} NO;

void imprime(NO *p){
	NO * pp;
	for (pp = p; pp != NULL; pp = pp->prox){
		printf("%d %d %d\n",pp, pp->valor, pp->prox);
	}
	printf("\n");
}

void adiciona(int x, NO* p){
	NO *pp = p;
	NO *novo = (NO*) malloc (sizeof(NO));
	novo->valor = x;
	novo->prox = NULL;

	while(pp->prox){
		pp = pp->prox;
	}
	pp->prox = novo;

	printf("Adicionado %d em %d, anterior %d e prox como %d\n", x, novo, pp, novo->prox);
}


NO* uniao(NO* p1, NO* p2){
	printf("\n\n\n");
	NO *p11 = p1;
	NO *p22 = p2;

	NO *p111 = p11->prox;
	NO *p222 = p22->prox;

	NO *nuevo = (NO*) malloc (sizeof(NO));

	// se tamanho dos dois forem 0, return head
	// se apenas um tamanho for zero, recorre ao caso embaixo
	// se os dois forem nao vazia:

	// primeira insercao
	nuevo->prox = NULL;

	while(p11 && p22) {
		// verificar e pular repeticoes


		if (p11->valor < p22->valor){
			adiciona(p11->valor, nuevo);
			p11 = p11->prox;
		}
		else if (p11->valor == p22->valor){
			adiciona(p11->valor, nuevo);
			p11 = p11->prox;
			p22 = p22->prox;
		}
		// if (p11->valor > p22->valor)
		else {
			adiciona(p22->valor, nuevo);
			p22 = p22->prox;
		}
	}

	// tem q verificar repeticao
	while (p11){
		adiciona(p11->valor, nuevo);
		p11 = p11->prox;
	}
	while (p22){
		adiciona(p22->valor, nuevo);
		p22 = p22->prox;
	}

	return nuevo;
}


int main() {

	NO* p1 = (NO *)malloc(sizeof(NO));
	NO* p2 = (NO *)malloc(sizeof(NO));

	p1->valor = 1;
	p1->prox = NULL;
	p2->valor = 2;
	p2->prox = NULL;

	adiciona(2, p2);
	adiciona(2, p2);
	adiciona(2, p2);
	adiciona(8, p2);

 
	NO* teste = uniao(p1,p2);
	printf("\n");
	imprime(teste);
}
