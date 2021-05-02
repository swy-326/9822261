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

typedef struct no {
    int vertice;
    struct no *prox;
} NO;


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


void criaListaLigada(int i, NO** *caminho){

    printf("inserindo %d\n", i);

    NO* pCaminho = (**caminho);

    NO* novo = (NO*) malloc (sizeof(NO));
    novo->vertice = i;
    novo->prox = NULL;

    if (pCaminho == NULL) pCaminho = novo;
    else {
        novo->prox = pCaminho;
        pCaminho = novo;
    }

}


void buscaChave(VERTICE* g, int i, int* visitado, NO* *caminho){

    visitado[i] = 1;

    ARESTA *v = g[i].inicio;
    printf("visitando %d com chave %d\n", i, g[i].chave);

    if (g[i].chave == 1){
        NO* novo = (NO*) malloc (sizeof(NO));
        novo->vertice = i;
        novo->prox = NULL;

        if ((*caminho) == NULL) (*caminho) = novo;
        else {
            novo->prox = (*caminho);
            (*caminho) = novo;
        }

    }

    while(v){
        if (visitado[v->vertice] == 0) buscaChave(g, v->vertice, visitado, caminho);
        v = v->prox;
    }

    visitado[i] = 2;

}


void salasComChaves(VERTICE* g, int i, int qntde){

    int visitado[qntde];
    NO* caminho = NULL;

    for (int i = 1; i < qntde; i++){
        visitado[i] = 0;
    }

    buscaChave(g, i, visitado, &caminho);

    printf("\n\nTerminado\n");

    if (caminho == NULL) printf("Caminho NULL");
    
    NO* pCaminho = caminho;
    while(pCaminho){
        printf("%d ", pCaminho->vertice);
        pCaminho = pCaminho->prox;
    }

} 





int main (){

    int n = 6;
    GRAFO *gr = criaGrafo(n);

    for (int i = 1; i < n; i++) gr->adj[i].chave = 0;
    gr->adj[2].chave = 1;
    gr->adj[5].chave = 1;

    criaAresta(gr, 1, 3, 0, 0);
    criaAresta(gr, 1, 2, 0, 0);
    criaAresta(gr, 3, 2, 0, 0);
    criaAresta(gr, 3, 5, 0, 0);
    criaAresta(gr, 4, 2, 0, 0);
    criaAresta(gr, 4, 3, 0, 0);
    criaAresta(gr, 5, 4, 0, 0);

    imprime(gr);

    salasComChaves(gr->adj, 5, gr->vertices);

    return 0;
}
