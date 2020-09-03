#include <stdio.h>
#include <stdbool.h>
#define MAX 50

/*

Exercicio 3

(a) Escreva um algoritmo que troque de lugar a primeira e a última chave da estrutura. 
Se a lista possuir menos de dois elementos, não há nada a executar.
 
void trocar(LISTA* l)
 
(b) Escreva um algoritmo que copie uma chave em posição i para a posição seguinte, 
ou seja, sobrescrevendo seu sucessor na ordem da lista. 
Se i já for a última posição da lista, não há nada a executar.
 
void sobrescrever(LISTA* l, int i)

*/

typedef struct {
	int chave;
	int prox;
}REGISTRO;

typedef struct {
	REGISTRO A[MAX];
	int inicio;
	int dispo; 
	// inicio do vetor vazio. a chave contino nao importa
	// apenas o prox que queremos saber
}LISTA;

void inicializar(LISTA* l);
void imprimeLista(LISTA* l);
void trocar (LISTA* l);
void sobrescrever (LISTA* l, int i);

int main(){

	LISTA l;

	inicializar(&l);
	imprimeLista(&l);
	trocar(&l);
	imprimeLista(&l);
	sobrescrever(&l, 1);
	imprimeLista(&l);

	return 0;
}


void inicializar(LISTA* l){
	l->inicio = 0;

	l->A[0].chave = 100;
	l->A[0].prox = 1;

	l->A[1].chave = 101;
	l->A[1].prox = 2;

	l->A[2].chave = 102;
	l->A[2].prox = -1;
/*
	l->A[3].chave = 103;
	l->A[3].prox = 4;

	l->A[4].chave = 104;
	l->A[4].prox = 5;

	l->A[5].chave = 105;
	l->A[5].prox = -1;
	*/

}

void imprimeLista(LISTA* l){
	int i = l->inicio;
	while (i != -1){
		printf("%d   ", l->A[i].chave);
		i = l->A[i].prox;
	}
	printf("\n\n\n");
}

void trocar (LISTA* l){

    /* i para percorrer a lista, ini apenas para visualizacao melhor */
    int i = l->inicio, ini = l->inicio;
    int tam = 0;

    /* achar a ultima posicao */
    while (i != -1) {
        tam++;
        if (l->A[i].prox == -1) break;
        i = l->A[i].prox;
    }

    /* se houver dois ou mais elementos, troca de posicao */
    if (tam > 1){
        int aux = l->A[ini].chave;
        l->A[ini].chave = l->A[i].chave;
        l->A[i].chave = aux;
    }
}

/* Se nao for ultimo elemento, copia o anterior ao proximo  */
void sobrescrever (LISTA* l, int i){
    if (l->A[i].prox != -1) l->A[l->A[i].prox].chave = l->A[i].chave;
}