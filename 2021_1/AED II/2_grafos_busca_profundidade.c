/*
    Estrutura de Dados - Aula 26 - Grafos - Busca em profundidade
    https://youtu.be/doH9o1sO-Cw

    Defina um no inicial
    Enquanto este nao afor um no objetivo ou final (no cuja adjacencia ja tenha sido toda visitada)
        Esolha um de seus adjacentes ainda nao visitados
        Visite-o
    Se no final nao objetivo:
        Volte ao pai deste
        Se houver pai, repita. Senao escolha outro no inicial

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


void visitaP(GRAFO *gr, int i, int *cor){

    cor[i] = 1;

    ARESTA *v = gr->adj[i].inicio;
    while (v){
        if (cor[v->vertice] == 0) visitaP(gr, v->vertice, cor);
        v = v->prox;
    }

    cor[i] = 2;

}


void profundidade(GRAFO *gr){

    int cor[gr->vertices];

    for (int i = 1; i < gr->vertices; i++){
        cor[i] = 0;
    }

    for (int i = 1; i < gr->vertices; i++){
        if (cor[i] == 0) visitaP(gr, i, cor);
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

    profundidade(gr);

    //adjacencia2incidencia(gr->adj, gr->vertices);
    //imprime(gr);

    return 0;
}