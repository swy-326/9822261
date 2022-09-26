#include <stdio.h>

#define MAX 50



typedef struct {
    REGISTRO A[MAX];
    int inicio;
    int dispo; // primeiro espaco disponivel
} LISTA;

typedef struct {
    int chave;
    int prox;
} REGISTRO;


int main(){


    return 0;
}

void inicializarLista (LISTA* l){
    for (int i = 0; i < MAX; i++){  // 다음 장소 어딘지 알려주기
        l->A[i].prox = i + 1;
    }
    l->A[MAX-1].prox = -1;
    l->inicio = -1;
    l->dispo = 0;   // i=0에서 시작
}

int tamanho(LISTA* l){  // 일일히 percorre
    int i = l->inicio;
    int tam = 0;
    while (i != -1){
        tam++;
        i = l->A[i].prox;
    }
    return tam;
}

int tamanho(LISTA* l){
    int i = l->inicio;
    int tam = 0;
    while (i != -1){
        printf("%d   ", l->A[i].chave);
        i = l->A[i].prox;
    }
    return tam;
}

int buscaSequencialOrd(LISTA* l, int ch){
    int i = l=>inicio;
    while (i != -1 && l->A[i].chave < ch){   // se a lista estiver ordenada
        i = l->A[i].prox;
    }
    if (i != -1 && l->A[i].chave == ch) return i;
    return -1;
}

int obterNo(LISTA* l){
    int resultado = l->dispo;
    if (l->dispo != -1) l->dispo = l->A[l->dispo].prox;
    return resultado;
}

bool inserirElemListaOrd(LISTA* l, REGISTRO reg){
    if (l->dispo == -1) return false;
    int ant = -1;
    int i = l->inicio;
    int ch  = reg.chave;
    while ( (i != -1) && (l->A[i].reg.chave) ){
        ant = i;
        i = l->A[i].prox;
    }
    if (i != -1 && l->A[i].reg.chave == ch) return false;

    i = obterNo(i);
    l->A[i].reg = reg;
    if (ant == -1){
        l->A[i].prox = l->inicio;
        l->inicio = i;
    } else {
        l->A[i].prox = l->A[ant].prox;
        l->A[ant].prox = i;
    }
}

bool excluirElemLista(LISTA* l, int ch){
    int ant = -1;
    int i = l->inicio;
    while ( (i != -1) && (l->A[i].reg.chave < ch) ){
        ant = i;
        i = l->A[i].prox;
    }
    if (i == -1 || l->A[i].reg.chave != ch) return false;
}

void reinicializarLista(LISTA* l){
    inicializarLista(l);
}