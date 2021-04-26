#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct aresta {
    int vertice; 
    int peso; 
    struct aresta *prox; 
} ARESTA;

typedef struct vertice {
    // Dados do vertice (ex : nome da cidade)
    ARESTA *inicio;
} VERTICE;

typedef struct grafo {
    int vertices; // 그냥 갯수
    int arestas; // 그냥 갯수
    VERTICE *adj;
} GRAFO;



GRAFO *criaGrafo(int v) {

    GRAFO *g = (GRAFO *) malloc (sizeof(GRAFO));
    g->vertices = v;
    g->arestas = 0;
    g->adj = (VERTICE *) malloc (v*sizeof(VERTICE));
    
    for (int i = 0; i < v; i++){
        g->adj[i].inicio = NULL;
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

bool criaAresta (GRAFO *gr, int vi, int vf, int p){
   
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
            printf("v%d : ", i);
            ARESTA *ad = gr->adj[i].inicio;
            while (ad){
                printf("v%d(%d)  ", ad->vertice, ad);
                //printf("v%d(%d) ", ad->vertice, ad->peso);
                ad = ad->prox;
            }
            printf("\n");
        }
        printf("\n\n\n");
    }

}


void adjacencia2incidencia(VERTICE* g, int n){

    ARESTA* ultimoElem[n];
    int restamQnts[n];

    // contabiliza qntde de elementos e guarda o ultimo elem da lista
    for (int i = 1; i < n; i++){
        
        if (g[i].inicio == NULL) {
            ultimoElem[i] = NULL;
            restamQnts[i] = 0;
        }

        else{
            ARESTA *a = g[i].inicio;
            restamQnts[i] = 1;
            while (a->prox != NULL){
                a = a->prox;
                restamQnts[i]++;
            }
            ultimoElem[i] = a;
        }
        
    }

    // "movimenta" os vertices
    for (int i = 1; i < n; i++){

        if (!(g[i].inicio == NULL || restamQnts[i] == 0)) {

            ARESTA *a = g[i].inicio;

            while (restamQnts[i] > 0) {

                int vDestino = a->vertice;
                a->vertice = i;
                
                ARESTA *aProx = a->prox;
                g[i].inicio = aProx;
                a->prox = NULL;


                if (g[vDestino].inicio == NULL){
                    g[vDestino].inicio = a;
                    ultimoElem[vDestino] = a;
                }
                else {
                    if (ultimoElem[vDestino] != NULL) ultimoElem[vDestino]->prox = a;
                    ultimoElem[vDestino] = a;
                }

                restamQnts[i]--;
                a = aProx;
            }

        }

    }

}


int main (){

    GRAFO *gr = criaGrafo(6);
/*
    criaAresta(gr, 3, 1, 0);
    criaAresta(gr, 3, 2, 0);
    criaAresta(gr, 3, 3, 0);
    criaAresta(gr, 3, 4, 0);
    criaAresta(gr, 3, 5, 0);
*/

    criaAresta(gr, 1, 3, 0);
    criaAresta(gr, 1, 2, 0);
    criaAresta(gr, 3, 2, 0);
    criaAresta(gr, 3, 5, 0);
    criaAresta(gr, 4, 2, 0);
    criaAresta(gr, 4, 3, 0);
    criaAresta(gr, 5, 4, 0);

    imprime(gr);

    adjacencia2incidencia(gr->adj, gr->vertices);

    imprime(gr);

    return 0;
}
