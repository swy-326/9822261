#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>


// https://stackoverflow.com/questions/46697901/linked-list-initialize-head-with-function
// 참고하기


typedef struct estr {
    int valor;
    struct estr* prox;
} NO;

void imprime(NO **p){
	NO *atual = *p;

	if(*p) {
		while(atual){
			printf("%d  ", atual->valor);
			atual = atual->prox;
		}
		printf("\n");
	}
	else {
		printf("A lista esta vazia");
	}

	printf("\n");
}

void adiciona(int x, NO **p){
	NO* atual;
	NO* anterior;

	NO* novo = (NO*)malloc(sizeof(NO));	
	novo->valor = x;
	novo->prox = NULL;

	if(*p == NULL) {
		printf("\n\nPrimeira vez\n");
		*p = novo;
	}
	else {
		anterior = NULL;
		atual = *p;
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
	NO *atual = p;
	NO *anterior = NULL;

	while(atual){
		if (atual->valor == x){
			anterior = atual;
			atual = atual->prox;
		}
		else break;
	}

	return anterior;
}

NO* uniao(NO* p1, NO* p2){

	NO *ptr1 = p1;
	NO *ptr2 = p2;

	NO *novo = NULL;

	if (ptr1 && ptr2){
		while(ptr1 && ptr2) {
			ptr1 = pulaRepeticao(ptr1);
			ptr2 = pulaRepeticao(ptr2);

			if (ptr1->valor < ptr2->valor){
				adiciona(ptr1->valor, &novo);
				ptr1 = ptr1->prox;
			}
			else if (ptr1->valor == ptr2->valor){
				adiciona(ptr1->valor, &novo);
				ptr1 = ptr1->prox;
				ptr2 = ptr2->prox;
			}
			// if (ptr1->valor > ptr2->valor)
			else {
				adiciona(ptr2->valor, &novo);
				ptr2 = ptr2->prox;
			}
		}
	}

	while (ptr1){
		ptr1 = pulaRepeticao(ptr1);
		adiciona(ptr1->valor, &novo);
		ptr1 = ptr1->prox;
	}
	while (ptr2){
		ptr2 = pulaRepeticao(ptr2);
		adiciona(ptr2->valor, &novo);
		ptr2 = ptr2->prox;
	}

	return novo;
}


int main() {

	NO* p1 = NULL;
	NO* p2 = NULL;

	adiciona(2, &p1);
	adiciona(2, &p1);
	adiciona(2, &p1);
	adiciona(2, &p1);
	adiciona(2, &p1);
	adiciona(2, &p1);

	adiciona(2, &p2);
	adiciona(2, &p2);
	adiciona(2, &p2);
	adiciona(2, &p2);
	adiciona(2, &p2);
	adiciona(2, &p2);
	adiciona(2, &p2);

	NO* teste = uniao(p1, p2);

	printf("\nP1 : "); imprime(&p1);
	printf("\nP2 : "); imprime(&p2);
	printf("\nTeste : "); imprime(&teste);

}