/*

Contexto: no mesmo grafo de salas visto em aula, suponha que as arestas são associadas a um valor representando o custo do deslocamento de uma sala para outra.

Objetivo: dado um ponto de partida i, escreva um algoritmo que retorne o custo total (i.e., a soma dos pesos das arestas) para ir do ponto inicial i até a chave mais próxima (em número de arestas, sem considerar seu peso). Se duas ou mais chaves estiverem à mesma distância de i, retorne o resultado da primeira que encontrar.

A assinatura da função é deixada incompleta para ser modificada a seu critério:

void custoChaveMaisProxima(VERTICE* g, int i...

*/


#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct aresta {
    int vertice; 
    int peso; 
    struct aresta *prox; 
} ARESTA;

typedef struct vertice {
    int chave; // 1-tem 0-ntem 
    int flag;
    ARESTA *inicio;
} VERTICE;

typedef struct grafo {
    int vertices;
    int arestas;
    VERTICE *adj;
} GRAFO;


// Fila
typedef struct aux {
    int chave;
    struct aux *prox;
} ELEMENTO;

typedef struct {
    ELEMENTO *inicio;
    ELEMENTO *fim;
} FILA;


void inicializarFila(FILA* f);
int excluirDaFila(FILA* f);
bool inserirNaFila(FILA* f, int reg);
GRAFO *criaGrafo(int v);
ARESTA *criaAdj(int v, int peso);
bool criaAresta (GRAFO *gr, int vi, int vf, int p, int ch);
void imprime (GRAFO *gr);
int custoChaveMaisProxima(VERTICE* g, int i);

int n = 6;

void inicializarFila(FILA* f){
    f->inicio = NULL;
    f->fim = NULL;
}

int excluirDaFila(FILA* f) {

    if (f->inicio==NULL) return false;                     

    int valor = f->inicio->chave;
    ELEMENTO* apagar = f->inicio;
    f->inicio = f->inicio->prox;
    free(apagar);

    if (f->inicio == NULL) f->fim = NULL;

    return valor;
}

bool inserirNaFila(FILA* f, int reg) {

    ELEMENTO* novo = (ELEMENTO*) malloc (sizeof(ELEMENTO));
    novo->chave = reg;
    novo->prox = NULL;
    
    if (f->inicio==NULL) f->inicio = novo;
    else f->fim->prox = novo;

    f->fim = novo;

    return true;
}

GRAFO *criaGrafo(int v) {

    GRAFO *g = (GRAFO *) malloc (sizeof(GRAFO));
    g->vertices = v;
    g->arestas = 0;
    g->adj = (VERTICE *) malloc (v*sizeof(VERTICE));
    
    for (int i = 0; i < v; i++){
        g->adj[i].inicio = NULL;
        g->adj[i].chave = 0;
    }

    return g;
}

ARESTA *criaAdj(int v, int peso){

    ARESTA *temp = (ARESTA *) malloc (sizeof(ARESTA));
    temp->vertice = v;
    temp->peso = peso;
    temp->prox = NULL;

    return temp;
}

bool criaAresta (GRAFO *gr, int vi, int vf, int p, int ch){
   
    if (!gr) return false;
    if ( (vf < 0) || vf >= gr->vertices ) return false;
    if ( (vi < 0) || vi >= gr->vertices ) return false;

    ARESTA *novo = criaAdj(vf, p);
    novo->prox = gr->adj[vi].inicio;
    gr->adj[vi].inicio = novo;

    gr->arestas++;
    
    return true;
}

void imprime (GRAFO *gr){

    if (gr != NULL){
        printf("\n\n\nVertices : %d; Arestas : %d\n", gr->vertices, gr->arestas);

        for (int i = 1; i < gr->vertices; i++){

            printf("v%d(%d) : ", i, gr->adj[i].chave);
            ARESTA *ad = gr->adj[i].inicio;

            while (ad){
                printf("v%d(%d)  ", ad->vertice, ad);
                ad = ad->prox;
            }
            printf("\n");
        }
        printf("\n\n\n");
    }
}

int custoChaveMaisProxima (VERTICE* g, int i){

    for (int i = 1; i < n; i++)
        g[i].flag = 0;

    FILA f; inicializarFila(&f);
    g[i].flag = 1;
    inserirNaFila(&f, i);

    int soma = 0;

    while (f.inicio){

        i = excluirDaFila(&f);
        ARESTA *p = g[i].inicio;

        if (g[i].chave == 1) break;
        else {
        	if (p) soma += p->peso;
	        while (p){
	            if (g[p->vertice].flag == 0){
	                g[p->vertice].flag = 1;
	                inserirNaFila(&f, p->vertice);
	            }
	            p = p->prox;
	        }
	        g[i].flag = 2;
        }
    }

    printf("soma : %d, chave em : ", soma);

    return i;
}






int main (){

    GRAFO *gr = criaGrafo(n);
    gr->adj[2].chave = 1;
    gr->adj[3].chave = 1;
    gr->adj[5].chave = 1;

    criaAresta(gr, 1, 3, 3, 0);
    criaAresta(gr, 1, 2, 8, 0);
    criaAresta(gr, 3, 2, 4, 0);
    criaAresta(gr, 3, 5, 1, 0);
    criaAresta(gr, 4, 2, 3, 0);
    criaAresta(gr, 4, 3, 2, 0);
    criaAresta(gr, 5, 4, 8, 0);

    imprime(gr);

    printf("%d\n", custoChaveMaisProxima(gr->adj, 1));
    printf("%d\n", custoChaveMaisProxima(gr->adj, 2));
    printf("%d\n", custoChaveMaisProxima(gr->adj, 3));
    printf("%d\n", custoChaveMaisProxima(gr->adj, 4));
    printf("%d\n", custoChaveMaisProxima(gr->adj, 5));

    return 0;
}
