/*
    Estrutura de Dados - Aula 28 - Grafos - Algoritmo de Dijkstra /'daik.stra/
    https://youtu.be/ovkITlgyJ2s

    Busca em largura - menor caminho (num de arestas) entre dois vertices
    Dijkstra - peso total das arestas

    Os pesos nao podem ser negativos
    A velocidade de existeAberto e menorDist eh lenta
        ㄴ Pode ser resolvido com fila de prioridade

    · Para cada vertice V do grafo, mantemos um atributo d[v] que eh um limite superior \
        para o peso do caminho mais curto do no inicial s a v
    · Dizemos que d[v] eh uma estimativa de caminho mais curto, inicialmente feito infinito
    · Tambem armazenamos o vertice que precede v (p[v] - precedente de v) no caminho mais curto de s a v



    Faca a estimativa de distancia de s a qualquer vertice ser infinita
        Exceto, claro, a distancia de s a s, que eh 0
        Ou seja, d[s] = 0 e d[v] = ∞    para todo v != s
    Faca os precedentes dos nos serem um valor qualquer
        Na pratica, podemos fazer p[v] = -1 ja que nao temos vertice de indice -1 na estrutura GRAFO
    Marque todos os vertives como "abertos"

    Enquanto tiver vertice aberto:
        Escolha o vertice aberto u cuja estimativa seja a menor entre os demais abertos
        Feche u
        Para todo no aberto v na adjacencia de u:
            Some d[u] ao peso da aresta (u, v)                                  ____\ Procedimento de 
            Caso a soma seja menor que d[v], atualize d[v] e faca p[v] = u      ----/ relaxamento da aresta (u, v)



    Inicialize o grafo com d[s] = 0, d[v] = ∞, para todo v != s e p[v] = -1 para todo v
    Faca baerto[v] = true para todo v no grafo
    Enquanto houver vertice aberto:
        Escolha u cuja estimativa seja a menor dentre os abertos
        Feche u
        Para todo no aberto v na adjacencia de u:
            Relaxe a aresta (u, v)

*/


#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>


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

void inicializaD (GRAFO *g, int *d, int *p, int s){

    printf("inicializaD\n");
    for (int v = 1; v < g->vertices; v++){
        d[v] = 56 / 2;
        p[v] = -1;
    }
    d[s] = 0;

    printf("\tfim\n\n");
}

void relaxa (GRAFO *g, int *d, int *p, int u, int v){

    printf("relaxa\n");

    ARESTA *ad = g->adj[u].inicio;

    while (ad && ad->vertice != v) ad = ad->prox;

    if (ad){
        if (d[v] > d[u] + ad->peso){ // distancia estimada eh maior?
            d[v] = d[u] + ad->peso;
            p[v] = u;
        }
    }
    printf("\tfim\n\n");
}

bool existeAberto (GRAFO *g, bool *aberto){

    printf("existeAberto\n");

    for (int i = 0; i < g->vertices; i++)
        if (aberto[i]) return true;

    printf("\tfim\n\n");
    return false;
}

int menorDist (GRAFO *g, bool *aberto, int *d){

    printf("menorDist\n");

    int i;
    for (i = 0; i < g->vertices; i++)
        if (aberto[i]) break;

    if (i == g->vertices) {
        printf("\tfim\n\n");
        return -1;
    }

    int menor = i;
    for (i = menor + 1; i < g->vertices; i++){
        if (aberto[i] && d[menor] > d[i]) menor = i;
    }
    printf("\tfim\n\n");
    return menor;
}

int *dijkstra (GRAFO *g, int s){

    printf("*dijkstra\n");

    int *d = (int *) malloc (g->vertices * sizeof(int));
    int p[g->vertices];
    bool aberto[g->vertices];

    inicializaD(g, d, p, s);

    for (int i = 0; i < g->vertices; i++){
        aberto[i] = true;
    }

    while (existeAberto(g, aberto)){
        int u = menorDist(g, aberto, d);
        aberto[u] = false;

        ARESTA *ad = g->adj[u].inicio;
        while (ad){
            relaxa(g, d, p, u, ad->vertice);
            ad = ad->prox;
        }
    }
    printf("\tfim\n\n");
    return d;
}

int main (){

    GRAFO *gr = criaGrafo(6);
    gr->adj[2].chave = 1;

    criaAresta(gr, 1, 3, 3, 0);
    criaAresta(gr, 1, 2, 8, 0);
    criaAresta(gr, 3, 2, 4, 0);
    criaAresta(gr, 3, 5, 1, 0);
    criaAresta(gr, 4, 2, 3, 0);
    criaAresta(gr, 4, 3, 0, 0);
    criaAresta(gr, 5, 4, 8, 0);

    imprime(gr);

    int *r = dijkstra(gr, 1);
    printf("sucess\n");

    for (int i = 1; i < gr->vertices; i++){
        printf("D(v1 -> V%d) = %d\n", i, r[i]);
    }

    return 0;
}
