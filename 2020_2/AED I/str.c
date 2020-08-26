#include <stdio.h>
#include <stdbool.h>

#define MAX 50

/* https://youtu.be/g_nbG7L5ou0 
* Funcoes de gerenciamento : 
* Inicializar a estrutura
* Retornar a quantidade de elementos validos
* Exibir os elementos da estrutura
* Inserir elementos na estrutura
* Excluir elementos da estrutura
* Reinicializar a estrutura
*/ 

typedef int TIPOCHAVE;

typedef struct {
    TIPOCHAVE chave;
} REGISTRO;

typedef struct {
    REGISTRO A[MAX];
    int nroElem;
} LISTA;

void inicializarLista(LISTA l){
    // faz copia
    l.nroElem = 0;
}

void inicializarLista(LISTA* l){
    // por referencia
    l->nroElem = 0;
}

int tamanho(LISTA* l){
    return l->nroElem;
}

int exibirLista(LISTA* l){
    for (int i = 0; i < l->nroElem; i++){
        printf("%d ", l->A[i].chave);
    }
}

int buscaSequencial(LISTA* l, TIPOCHAVE ch){
    int i = 0;
    while (i < l->nroElem){
        if (ch == l->A[i].chave) return i;
        else i++;
    }

    return -1;
}

// insercao na posicao indicada pelo usuario
bool inserirElemLista(LISTA* l, REGISTRO reg, int i){
    if ( (l->nroElem) == MAX || (i < 0) || (i > nroElem) ) return false;

    for (int j = i; j <= l->nroElem; j++){
        l->A[j+1].chave = l->A[j].chave;
    }
    l->A[i].chave = reg;
    l->nroElem++;

    return true;
}

bool excluirElemLista(LISTA* l, TIPOCHAVE ch){
    // retornar o indice do elemento
    int pos = buscaSequencial(l, ch);

    if (pos == -1) return false;

    for (int j = pos; j < l->nroElem; j++){
        l->A[j] = l->A[j+1];
    }
    l->nroElem--;

    return true;
}

void reinicializarLista(LISTA* l){
    l->nroElem = 0;
}
