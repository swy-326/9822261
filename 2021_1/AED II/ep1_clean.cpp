//--------------------------------------------------------------
// NOME : Sungwon Yoon
//--------------------------------------------------------------

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <malloc.h>

// ######### ESCREVA O NROUSP AQUI
int nroUSP() {
    return 9822261;
}

//-------------------------------------------

// nos das listas de adjacencias
typedef struct adj {
	int v;
	struct adj* prox;
} NO;

// vertices
typedef struct {
	NO* inicio;
} VERTICE;


// funcoes
NO* criaNovoNo (int v);
void adicionaSequenciaParcial (NO** seqP, int v);
void retiraSequenciaParcial (NO** seqP);
void adicionaSequenciaFinal (NO** seqP, NO** seqF);

NO* caminhos_max_d (VERTICE* g, int n, int x, int y, int d);
void buscaProfundidade (VERTICE* g, int x, int y, int d, int count, int flag[], NO** seqP, NO** seqF);


NO* criaNovoNo (int v){

    NO* novo = (NO *) malloc (sizeof(NO));
    novo->v = v;

    return novo;
}


void adicionaSequenciaParcial (NO** seqP, int v){

    NO* novo = (NO *) malloc (sizeof(NO));
    novo->v = v;

    if (*seqP == NULL){
        novo->prox = NULL;
        *seqP = novo;
    }
    else {
        novo->prox = *seqP;
        *seqP = novo;
    }

    // ordem de seq : 1 - 2 - 3
    // adicionado sempre no inicio, portanto, ordem : 3 - 2 - 1

}

void retiraSequenciaParcial (NO** seqP){

    NO* temp = *seqP;
    *seqP = (*seqP)->prox;
    
    free(temp);

    // seqP ordem : 3 - 2 - 1
    // retirar do inicio (free)

}

void adicionaSequenciaFinal (NO** seqP, NO** seqF){

    NO* temp = *seqP;
    while (temp){

        NO* nuevo = criaNovoNo(temp->v);
        nuevo->prox = *seqF;
        *seqF = nuevo;
        temp = temp->prox;

    }

    // seqP ordem : 3 - 2 - 1
    // ordem a ser colocado : reverter a ordem : 1 - 2 - 3

}




void buscaProfundidade (VERTICE* g, int x, int y, int d, int count, int flag[], NO** seqP, NO** seqF){

    // adiciona na sequencia parcial
    // count += 1

    adicionaSequenciaParcial (seqP, x);
    count += 1;

    if (x == y){

        // chegou no vertice destino
        // verificar distancia
        // marca como nao visitado
        // adicionar sequencia parcial a sequencia final
        // buscar outro caminho (desconta o count)

        adicionaSequenciaFinal(seqP, seqF);
        retiraSequenciaParcial(seqP);
        count -= 1;
        flag[x] = 0;

    }

    else {

        // marca como visitado
        // se count < d, procura outros vertices nao visitados
        // marca como explorado, tira da sequencia parcial, diminui count

    	flag[x] = 1;

        NO* p = g[x].inicio;

        while (p && count <= d){
            if (flag[p->v] == 0) buscaProfundidade(g, p->v, y, d, count, flag, seqP, seqF);
            p = p->prox;
        }

        count -= 1;
        flag[x] = 0;

        retiraSequenciaParcial(seqP);

    }

}


NO* caminhos_max_d (VERTICE* g, int n, int x, int y, int d){

	if (g[x].inicio == NULL) return NULL;

	NO* sequenciaFinal = NULL;
	NO* sequenciaParcial = NULL;
    int count = 0;

	int flag[n]; // 0 nao visitado - 1 visitado
	for (int i = 0; i <= n; i++) flag[i] = 0;

    NO* temp = g[y].inicio;
    g[y].inicio = NULL;

	buscaProfundidade(g, x, y, d, count, flag, &sequenciaParcial, &sequenciaFinal);
    
    g[y].inicio = temp;
    
    return sequenciaFinal;

}
