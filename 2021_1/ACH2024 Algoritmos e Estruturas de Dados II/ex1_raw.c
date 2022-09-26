/* 
temp folder -> ex1.c 
Contexto: uma forma alternativa de representar um grafo é por meio de uma lista de incidências. Nesta representação, utilizamos o mesmo vetor de vértices da implementação vista; no entanto, ao invés de criarmos uma lista de elementos adjacentes de cada vértice, criamos a lista dos elementos que incidem sobre cada um.

Objetivo: dada uma estrutura de listas de adjacências, transforme-a em uma estrutura de listas de incidências.

       void adjacencia2incidencia(VERTICE* g, int n)

Deposite aqui um arquivo txt, com o codigo da funcao C completa para realizar esta operação.
*/


#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct aresta {
    int vertice; // vertice de destino da aresta
    int peso; // opcional
    struct aresta *prox; // lista니까 다음 
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


// Numero fixo de vertice, grafo sem aresta
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

// Dirigido
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

// *gr NULL은 안됨
void imprime (GRAFO *gr){

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


void adjacencia2incidencia(VERTICE* g, int n){

    ARESTA* ultimoElem[n];
    int restamQnts[n];

    // contabiliza ultimos elementos para comparar e adicionar no final
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


    for (int i = 1; i < n; i++){
        printf("Inicio : %d, termino %d\n", g[i].inicio, ultimoElem[i]);
    }
    printf("\n\n\n");



    for (int i = 1; i < n; i++){

        if (g[i].inicio == NULL || restamQnts[i] == 0) {
            printf("%d : NAO TEM OQ MOVIMENTAR %d\n", i, restamQnts[i]);
        }

        else {

            ARESTA *a = g[i].inicio;

            while (restamQnts[i] > 0) {

                printf("MOVIMENTANDO v%d(%d)\n", a->vertice, a);

                int vDestino = a->vertice;
                a->vertice = i;
                
                ARESTA *aProx = a->prox;
                g[i].inicio = aProx; // 뜯어간 곳 다음 요소랑 이어놓기
                a->prox = NULL;


                if (g[vDestino].inicio == NULL){
                    printf("\t%d to %d NAO EXISTE ELEM NO DESTINO\n", a->vertice, vDestino);
                    g[vDestino].inicio = a;
                    ultimoElem[vDestino] = a;
                }
                else {
                    printf("\t%d to %d JA EXISTE ELEM NO DESTINO\n", a->vertice, vDestino);
                    if (ultimoElem[vDestino] != NULL) ultimoElem[vDestino]->prox = a;
                    ultimoElem[vDestino] = a;
                }



                restamQnts[i]--;
                a = aProx;

                //if (restamQnts[i] == 0) a = NULL;

                if (a != NULL){
                    printf("\trestam : %d, prox eh : %d\n", restamQnts[i], a);
                } else { 
                    printf("\tnao restam nada\n"); 
                }

            }

        }

    }

}







int main (){

    GRAFO *gr = criaGrafo(6);

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
