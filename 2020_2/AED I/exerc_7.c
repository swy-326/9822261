#include <stdio.h>
#include <malloc.h>
#include <stdbool.h>

/*

(1) Dada uma lista ligada duplamente ligada *l com nó cabeça e circularidade, escreva um algoritmo que exiba as chaves existentes em ordem reversa. 
 
NO* exibirInvertida(LISTA* l) 
 
(2) Para a mesma lista, escreva um algoritmo para inserir uma nova chave ch (que pode ser repetida) antes da posição *atual fornecida, criando um novo nó.
 
void inserirAntes(LISTA* l, int ch, NO* atual)

*/

typedef struct estrutura {
	struct estrutura *ant;
	struct estrutura *prox;
	int valor;
} NO;

typedef struct {
	NO* head;
} LISTA;


void inicializa(LISTA* l){
	l->head = NULL;
}


NO* acharTopo(LISTA* l){
	NO* runner = l->head;
	NO* anterior = runner;

	runner = runner->prox;

	while(runner != l->head && runner != NULL) {
		anterior = runner;
		runner = runner->prox;
	}

	return anterior;
}

void inserirFinal(LISTA* l, int ch){
	// 맨 뒤에 추가
	NO* novo = (NO*) malloc (sizeof(NO));
	NO* anterior;

	novo->valor = ch;

	if(l->head == NULL){
		novo->prox = novo;
		novo->ant = novo;
		l->head = novo;

		printf("inserido %d em %d com ant %d e com prox %d\n", ch, novo, novo->ant, novo->prox);
	}
	else {
		anterior = acharTopo(l);
		novo->prox = l->head;
		novo->ant = anterior;

		anterior->prox = novo;
		
		l->head->ant = novo;
		printf("inserido %d em %d com ant %d e com prox %d\n", ch, novo, novo->ant, novo->prox);
	}
}

// nunca eh vazia
void inserirAntes(LISTA* l, int ch, NO* atual){

	// achar posicao do atual
        // 이거 필요 없음 이미 주소가 주어졌는데
	NO* runner = l->head;
	NO* anterior = runner;

	if (runner->prox != l->head){
		while(runner != atual){
			anterior = runner;
			runner = runner->prox;
		}
	}

	// novo NO
	NO* novo = (NO*)malloc(sizeof(NO));
	novo->valor = ch;
	novo->ant = anterior;
	novo->prox = runner;

	anterior->prox = novo;
	runner->ant = novo;

	printf("inserido %d em %d com ant %d e com prox %d\n", ch, novo, novo->ant, novo->prox);


}



NO* exibirInvertida(LISTA* l){
	NO* runner = l->head->ant;

	while( runner != l->head ) {
		printf("%d  ", runner->valor);
		runner = runner->ant;
	}
	printf("%d  \n", runner->valor); // head NO

	return NULL;
}

int main(){

	LISTA* l = (LISTA*)malloc(sizeof(LISTA));
	inicializa(l);
	inserirFinal(l, 1);

	NO* no = acharTopo(l);
	inserirAntes(l, 7, no);

	inserirFinal(l, 2);
	inserirFinal(l, 3);
	inserirFinal(l, 4);
	inserirFinal(l, 5);



	NO* temp = exibirInvertida(l);


	return 0;
}
