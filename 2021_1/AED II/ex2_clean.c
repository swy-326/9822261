/*
    Nao entendi muito bem em que contexto a funcao eh chamada,
    nem como a funcao deveria devolver a lista ligada NO*.
    Em vez de criar campo flag, utilizei vetor visitado = []
    Estou apenas imprimindo os vetices que contem a chave dentro da funcao.
*/

/*

Contexto: no mesmo grafo de salas do exemplo a ser visto em aula, suponha que pode existir chaves simultaneamente em várias salas, e não apenas em uma.

Objetivo: dado um ponto de partida i, escreva um algoritmo que retorne uma lista ligada contendo todas as salas alcançáveis a partir de i que possuem chave, em qualquer ordem.

A assinatura da função é deixada incompleta para ser modificada a seu critério:

       void salasComChaves(VERTICE* g, int i.......

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

void buscaChave(VERTICE* g, int i, int* visitado, NO* *caminho){

    visitado[i] = 1;

    ARESTA *v = g[i].inicio;

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
    gr->adj[3].chave = 1;
    gr->adj[5].chave = 1;

    criaAresta(gr, 1, 3, 0, 0);
    criaAresta(gr, 1, 2, 0, 0);
    criaAresta(gr, 3, 2, 0, 0);
    criaAresta(gr, 3, 5, 0, 0);
    criaAresta(gr, 4, 2, 0, 0);
    criaAresta(gr, 4, 3, 0, 0);
    criaAresta(gr, 5, 4, 0, 0);

    salasComChaves(gr->adj, 1, gr->vertices);

    return 0;

}
