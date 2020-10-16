#include <stdio.h>
#include <malloc.h>
#include <stdbool.h>

/*
Ex1: Dado um inteiro n > 0, criar uma lista duplamente ligada sem cabeça e sem circularidade de n elementos numerados de 1..n, retornando o ponteiro para o seu início.
 
NO* listaNumerada(int n)
 
 
 
Ex2: Dada uma lista do tipo anterior e um ponteiro p garantidamente válido, mover o elemento p para o fim da lista. Se p já for o último elemento dda lista, não há nada a fazer.
 
void moverParaFim(LISTA* l, NO* p)
*/

typedef struct estrutura {
	struct estrutura *ant;
	struct estrutura *prox;
	int valor;
} NO;

typedef struct {
    NO* inicio;
} LISTA;


void inserirFinal(LISTA* l, int ch){
	// 맨 뒤에 추가
	NO* novo = (NO*) malloc (sizeof(NO));
	NO* anterior = l->inicio;

	novo->valor = ch;

	if(l->inicio == NULL){
		novo->prox = novo;
		novo->ant = novo;
		l->inicio = novo;
		printf("inserido %d em %d\n", ch, novo);

	}
	else {
		while(anterior->prox) anterior = anterior->prox;

		novo->prox = l->inicio;
		novo->ant = anterior;

		anterior->prox = novo;
		
		l->inicio->ant = novo;
		printf("inserido %d em %d\n", ch, novo);

	}
}

void moverParaFim(LISTA* l, NO* p){
    NO* runner = p;

    while(runner->prox) runner = runner->prox;

    if(p->prox){
        if (p!= l->inicio) p->ant->prox = p->prox;
        else l->inicio = p->prox;
    
        runner->prox = p;
        p->prox = NULL;
    }
}

NO* listaNumerada(int n){
    NO* head;

    int i = 1;
    NO* novo = (NO*) malloc (sizeof(NO));
        head = novo;
        novo->valor = i;
        novo->ant = NULL;
        novo->prox = NULL;
        i++;
        printf("inserido %d em %d\n", i-1, novo);


    NO* anterior = head;
    while(i <= n){

        NO* novo = (NO*) malloc (sizeof(NO));

        novo->valor = i;

        anterior->prox = novo;
        novo->ant = anterior;
        novo->prox = NULL;
        
        printf("inserido %d em %d\n", i, novo);

        anterior = novo;
        i++;
    }

    return head;
}

NO* getAdress(int n, LISTA* l){
    NO* runner = l->inicio;
    while(runner->valor != n){
        runner = runner->prox;
    }
    return runner;
}

void imprime(NO* p){
	while(p){
		printf("%d ", p->valor, p);
		p = p->prox;
	}
	printf("\n");
}


int main(){

	//NO* l = NULL;
    //l = listaNumerada(10);
    //imprime(l);

    LISTA* l = (LISTA*)malloc(sizeof(LISTA));
    l->inicio = listaNumerada(10);
    /*
    inserirFinal(l, 1);
    inserirFinal(l, 2);
    inserirFinal(l, 3);
    inserirFinal(l, 4);
    inserirFinal(l, 5);
    inserirFinal(l, 6);
    inserirFinal(l, 7);
    inserirFinal(l, 8);
*/

    NO* ad = getAdress(9, l);
    moverParaFim(l,  ad);

    imprime(l->inicio);

	return 0;
}
