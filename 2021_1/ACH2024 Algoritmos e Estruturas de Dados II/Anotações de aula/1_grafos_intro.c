/* 
    2021.04.14 AED II
    https://youtu.be/1bNHNG0s7ug 
*/

#include <stdio.h>
#include <stdlib.h>
#define true 1
#define false 0
typedef int bool;
typedef int TIPOPESO;

typedef struct adjacente {
    int vertice;
    TIPOPESO peso;
    struct adjacente *prox;
} ADJACENCIA;

typedef struct vertice {
    /* Dados armazenados vao aqui */
    ADJACENCIA *cab;
} VERTICE;

typedef struct grafo {
    int vertices;
    int arestas;
    VERTICE *adj;
} GRAFO;



// Numero fixo de vertice, grafo sem aresta
GRAFO *criaGrafo(int v) {

    GRAFO *g = (GRAFO *) malloc (sizeof(GRAFO));
    g->vertices = v;
    g->arestas = 0;
    g->adj = (VERTICE *) malloc (v*sizeof(VERTICE));
    
    for (int i = 0; i < v; i++){
        g->adj[i].cab = NULL;
    }

    return g;
}


ADJACENCIA *criaAdj(int v, int peso){

    ADJACENCIA *temp = (ADJACENCIA *) malloc (sizeof(ADJACENCIA));
    temp->vertice = v;
    temp->peso = peso;
    temp->prox = NULL;

    return temp;
}


// Dirigido
bool criaAresta (GRAFO *gr, int vi, int vf, TIPOPESO p){
   
    if (!gr) return false;
    if ( (vf < 0) || vf >= gr->vertices ) return false;
    if ( (vi < 0) || vi >= gr->vertices ) return false;

    ADJACENCIA *novo = criaAdj(vf, p);
    novo->prox = gr->adj[vi].cab;
    gr->adj[vi].cab = novo;

    gr->arestas++;
    
    return true;
}


// *gr NULL은 안됨
void imprime (GRAFO *gr){

    printf("Vertices : %d; Arestas : %d\n", gr->vertices, gr->arestas);

    for (int i = 0; i < gr->vertices; i++){
        printf("v%d : ", i);
        ADJACENCIA *ad = gr->adj[i].cab;
        while (ad){
            printf("v%d(%d) ", ad->vertice, ad->peso);
            ad = ad->prox;
        }
        printf("\n");
    }
}


int main (){

    GRAFO *gr = criaGrafo(5);

    criaAresta(gr, 0, 1, 2);
    criaAresta(gr, 1, 2, 4);
    criaAresta(gr, 2, 0, 12);
    criaAresta(gr, 2, 4, 40);
    criaAresta(gr, 3, 1, 3);
    criaAresta(gr, 4, 3, 8);

    imprime(gr);

    return 0;
}/* 
    2021.04.14 AED II
    https://youtu.be/1bNHNG0s7ug 
*/

#include <stdio.h>
#include <stdlib.h>
#define true 1
#define false 0
typedef int bool;
typedef int TIPOPESO;

typedef struct adjacente {
    int vertice;
    TIPOPESO peso;
    struct adjacente *prox;
} ADJACENCIA;

typedef struct vertice {
    /* Dados armazenados vao aqui */
    ADJACENCIA *cab;
} VERTICE;

typedef struct grafo {
    int vertices;
    int arestas;
    VERTICE *adj;
} GRAFO;



// Numero fixo de vertice, grafo sem aresta
GRAFO *criaGrafo(int v) {

    GRAFO *g = (GRAFO *) malloc (sizeof(GRAFO));
    g->vertices = v;
    g->arestas = 0;
    g->adj = (VERTICE *) malloc (v*sizeof(VERTICE));
    
    for (int i = 0; i < v; i++){
        g->adj[i].cab = NULL;
    }

    return g;
}


ADJACENCIA *criaAdj(int v, int peso){

    ADJACENCIA *temp = (ADJACENCIA *) malloc (sizeof(ADJACENCIA));
    temp->vertice = v;
    temp->peso = peso;
    temp->prox = NULL;

    return temp;
}


// Dirigido
bool criaAresta (GRAFO *gr, int vi, int vf, TIPOPESO p){
   
    if (!gr) return false;
    if ( (vf < 0) || vf >= gr->vertices ) return false;
    if ( (vi < 0) || vi >= gr->vertices ) return false;

    ADJACENCIA *novo = criaAdj(vf, p);
    novo->prox = gr->adj[vi].cab;
    gr->adj[vi].cab = novo;

    gr->arestas++;
    
    return true;
}


// *gr NULL은 안됨
void imprime (GRAFO *gr){

    printf("Vertices : %d; Arestas : %d\n", gr->vertices, gr->arestas);

    for (int i = 0; i < gr->vertices; i++){
        printf("v%d : ", i);
        ADJACENCIA *ad = gr->adj[i].cab;
        while (ad){
            printf("v%d(%d) ", ad->vertice, ad->peso);
            ad = ad->prox;
        }
        printf("\n");
    }
}


int main (){

    GRAFO *gr = criaGrafo(5);

    criaAresta(gr, 0, 1, 2);
    criaAresta(gr, 1, 2, 4);
    criaAresta(gr, 2, 0, 12);
    criaAresta(gr, 2, 4, 40);
    criaAresta(gr, 3, 1, 3);
    criaAresta(gr, 4, 3, 8);

    imprime(gr);

    return 0;
}
