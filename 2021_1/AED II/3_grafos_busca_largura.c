/*
    Estrutura de Dados - Aula 27 - Grafos - Busca em largura
    https://youtu.be/9J3Sz6K--8c

    BFS - Breadth First Search
    Distancia em numero de arestas de cada vertice atingivel do grafo a s
    Caminho mais curto para atingir do no inicial a qq vertice do grafo

    Enfilerar os filhos


    Defina um no inicial, marcando como explorado
    Enfileire-o
    Enquanto a fila nao estiver vazia:
        Remova o 1o no da fila, u
        Para cada vizinho v de u:
            Se v nao explorado:
                Marque v como explorado
                Coloque v no fim da fila
    Repita de outro no inicial, se houver

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
    ARESTA *inicio;
} VERTICE;

typedef struct grafo {
    int vertices;
    int arestas;
    VERTICE *adj;
} GRAFO;


// Fila
typedef struct {
    int chave;
} REGISTRO;

typedef struct aux {
    REGISTRO reg;
    struct aux *prox;
} ELEMENTO, *PONT; // *PONT == ELEMENTO* 

typedef struct {
    PONT inicio;
    PONT fim;
} FILA;

void inicializarFila(FILA* f){
    f->inicio = NULL;
    f->fim = NULL;
}

bool excluirDaFila(FILA* f, REGISTRO* reg) {

    if (f->inicio==NULL) return false;                     

    *reg = f->inicio->reg;
    PONT apagar = f->inicio;
    f->inicio = f->inicio->prox;
    free(apagar);

    if (f->inicio == NULL) f->fim = NULL;

    return true;
}

bool inserirNaFila(FILA* f, REGISTRO reg) {

    PONT novo = (PONT) malloc (sizeof(ELEMENTO));
    novo->reg = reg;
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

void visitaL (GRAFO *g, int s, bool *expl){

    FILA f; inicializarFila(&f); // Aula 12
    expl[s] = true;

    REGISTRO *u = (REGISTRO*) malloc (sizeof(int));
    u->chave = s;
    inserirNaFila(&f, *u);

    printf("%d ", u->chave);

    while (f.inicio){

        excluirDaFila(&f, u);
        ARESTA *v = g->adj[u->chave].inicio;

        while(v) {
            if (!expl[v->vertice]){
                expl[v->vertice] = true;
                u->chave = v->vertice; // u 재사용
                printf("%d ", u->chave);

                inserirNaFila(&f, *u);
            }
            v = v->prox;
        }
    }
    free(u);
}


void largura (GRAFO *g){

    bool expl[g->vertices];

    for (int u = 0; u < g->vertices; u++){
        expl[u] = false;
    }

    for (int u = 0; u < g->vertices; u++){
        if (!expl[u]) visitaL(g, u, expl);
    }

}





int main (){

    GRAFO *gr = criaGrafo(6);
    gr->adj[2].chave = 1;

    criaAresta(gr, 1, 3, 0, 0);
    criaAresta(gr, 1, 2, 0, 0);
    criaAresta(gr, 3, 2, 0, 0);
    criaAresta(gr, 3, 5, 0, 0);
    criaAresta(gr, 4, 2, 0, 0);
    criaAresta(gr, 4, 3, 0, 0);
    criaAresta(gr, 5, 4, 0, 0);

    imprime(gr);

    largura(gr);


    return 0;
}