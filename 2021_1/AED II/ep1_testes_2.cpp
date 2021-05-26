#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

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

VERTICE *criarGrafo(int vertices) {
    // Aloco memoria para o grafo
    VERTICE *grafo = (VERTICE*) malloc((vertices + 1) * sizeof(VERTICE));

    int i;

    for (i = 0; i <= vertices; i++) {
        grafo[i].inicio = NULL; // definimos o no inicio como null
    }

    return grafo;
}

NO *criarAdjacencia(int vertice) {
    NO *adjacencia = (NO*) malloc(sizeof(NO));

    adjacencia->v = vertice;
    adjacencia->prox = NULL;

    return adjacencia;
}

bool criarAresta(VERTICE *grafo, int verticeInicial, int verticeFinal) {
    if (!grafo) return false;

    NO* novaAdjacencia = criarAdjacencia(verticeFinal);
    novaAdjacencia->prox = grafo[verticeInicial].inicio;
    grafo[verticeInicial].inicio = novaAdjacencia;

    return true;
}

void imprimirLista(NO* inicio) {
    NO* p = inicio;
    if (!p)
        return;

    int x = p->v;
    while (p) {
        if (p->v == x)
            printf(" ");
        printf("%i", p->v);

        p = p->prox;
    }
}

// funcao principal
NO* caminhos_max_d(VERTICE* g, int n, int x, int y, int d);

//---------------------------------------------------------
// use main() para fazer chamadas de teste ao seu programa
// mas nao entregue o codido de main() nem inclua nada
// abaixo deste ponto
//---------------------------------------------------------
int main()
{
    VERTICE *grafo1 = criarGrafo(5);
    VERTICE *grafo2 = criarGrafo(5);
    VERTICE *grafo3 = criarGrafo(6);
    VERTICE *grafo4 = criarGrafo(7);
    VERTICE *grafo5 = criarGrafo(3);
    VERTICE *grafo6 = criarGrafo(5);

    // GRAFO 1
    criarAresta(grafo1, 1, 3);
    criarAresta(grafo1, 1, 2);
    criarAresta(grafo1, 2, 4);
    criarAresta(grafo1, 3, 4);
    criarAresta(grafo1, 3, 5);
    criarAresta(grafo1, 4, 1);
    criarAresta(grafo1, 4, 5);

    // GRAFO 2
    criarAresta(grafo2, 1, 3);
    criarAresta(grafo2, 1, 2);
    criarAresta(grafo2, 2, 4);
    criarAresta(grafo2, 2, 3);
    criarAresta(grafo2, 4, 3);
    criarAresta(grafo2, 3, 5);
    criarAresta(grafo2, 3, 4);
    criarAresta(grafo2, 5, 4);

    // GRAFO 3
    criarAresta(grafo3, 1, 3);
    criarAresta(grafo3, 2, 5);
    criarAresta(grafo3, 3, 5);
    criarAresta(grafo3, 3, 4);
    criarAresta(grafo3, 4, 1);
    criarAresta(grafo3, 4, 2);
    criarAresta(grafo3, 4, 6);
    criarAresta(grafo3, 5, 6);
    criarAresta(grafo3, 5, 1);
    criarAresta(grafo3, 6, 5);
    criarAresta(grafo3, 6, 3);

    // GRAFO 4
    criarAresta(grafo4, 1, 3);
    criarAresta(grafo4, 1, 2);
    criarAresta(grafo4, 2, 3);
    criarAresta(grafo4, 2, 4);
    criarAresta(grafo4, 3, 4);
    criarAresta(grafo4, 4, 5);
    criarAresta(grafo4, 4, 6);
    criarAresta(grafo4, 5, 3);
    criarAresta(grafo4, 5, 6);
    criarAresta(grafo4, 5, 7);
    criarAresta(grafo4, 7, 6);

    // GRAFO 5
    criarAresta(grafo5, 1, 3);
    criarAresta(grafo5, 1, 2);
    criarAresta(grafo5, 2, 3);
    criarAresta(grafo5, 3, 2);

    // GRAFO 6
    criarAresta(grafo6, 1, 3);
    criarAresta(grafo6, 1, 2);
    criarAresta(grafo6, 2, 4);
    criarAresta(grafo6, 2, 3);
    criarAresta(grafo6, 2, 1);
    criarAresta(grafo6, 4, 3);
    criarAresta(grafo6, 3, 5);
    criarAresta(grafo6, 3, 2);
    criarAresta(grafo6, 3, 1);
    criarAresta(grafo6, 3, 4);
    criarAresta(grafo6, 4, 2);
    criarAresta(grafo6, 4, 5);
    criarAresta(grafo6, 5, 4);
    criarAresta(grafo6, 5, 3);

    // GRAFO 2
    NO* resp1 = caminhos_max_d(grafo2, 5, 1, 5, 5); 
    NO* resp2 = caminhos_max_d(grafo2, 5, 1, 5, 4);
    NO* resp3 = caminhos_max_d(grafo2, 5, 1, 5, 3);
    NO* resp4 = caminhos_max_d(grafo2, 5, 2, 4, 5);
    NO* resp5 = caminhos_max_d(grafo2, 5, 3, 4, 3);
    NO* resp6 = caminhos_max_d(grafo2, 5, 3, 4, 2);
    NO* resp7 = caminhos_max_d(grafo2, 5, 3, 4, 1);
    NO* resp8 = caminhos_max_d(grafo2, 5, 2, 1, 5);

    // GRAFO 3
    NO* resp9 = caminhos_max_d(grafo3, 6, 1, 6, 4);
    NO* resp10 = caminhos_max_d(grafo3, 6, 1, 6, 6);
    NO* resp11 = caminhos_max_d(grafo3, 6, 6, 1, 6);
    NO* resp12 = caminhos_max_d(grafo3, 6, 6, 1, 4);
    NO* resp13 = caminhos_max_d(grafo3, 6, 3, 5, 4);
    NO* resp14 = caminhos_max_d(grafo3, 6, 4, 6, 3);
    NO* resp15 = caminhos_max_d(grafo3, 6, 4, 6, 4);
    NO* resp16 = caminhos_max_d(grafo3, 6, 4, 6, 5);

    // GRAFO 4
    NO* resp17 = caminhos_max_d(grafo4, 7, 1, 5, 4);
    NO* resp18 = caminhos_max_d(grafo4, 7, 1, 5, 3);
    NO* resp19 = caminhos_max_d(grafo4, 7, 7, 6, 5);
    NO* resp20 = caminhos_max_d(grafo4, 7, 3, 7, 4);
    NO* resp21 = caminhos_max_d(grafo4, 7, 1, 6, 5);
    NO* resp22 = caminhos_max_d(grafo4, 7, 1, 6, 4);
    NO* resp23 = caminhos_max_d(grafo4, 7, 1, 6, 3);

    // GRAFO 5
    NO* resp24 = caminhos_max_d(grafo5, 3, 1, 3, 2);
    NO* resp25 = caminhos_max_d(grafo5, 3, 1, 3, 3);
    NO* resp26 = caminhos_max_d(grafo5, 3, 3, 1, 3);
    NO* resp27 = caminhos_max_d(grafo5, 3, 3, 2, 2);
    NO* resp28 = caminhos_max_d(grafo5, 3, 2, 3, 2);

    // GRAFO 1
    NO* resp29 = caminhos_max_d(grafo1, 5, 1, 3, 5);
    NO* resp30 = caminhos_max_d(grafo1, 5, 3, 1, 4);
    NO* resp31 = caminhos_max_d(grafo1, 5, 4, 2, 3);
    NO* resp32 = caminhos_max_d(grafo1, 5, 4, 2, 1);

    // GRAFO 6
    NO* resp33 = caminhos_max_d(grafo6, 5, 1, 5, 5); 
    NO* resp34 = caminhos_max_d(grafo6, 5, 1, 5, 4);
    NO* resp35 = caminhos_max_d(grafo6, 5, 1, 5, 3);
    NO* resp36 = caminhos_max_d(grafo6, 5, 2, 4, 5);
    NO* resp37 = caminhos_max_d(grafo6, 5, 3, 4, 3);
    NO* resp38 = caminhos_max_d(grafo6, 5, 3, 4, 2);
    NO* resp39 = caminhos_max_d(grafo6, 5, 3, 4, 1);
    NO* resp40 = caminhos_max_d(grafo6, 5, 2, 1, 5);

    int tamanho = 40;

    NO* respostasObtidas[tamanho] = {
        resp1, resp2, resp3, resp4, resp5, resp6, resp7, resp8, // grafo 2
        resp9, resp10, resp11, resp12, resp13, resp14, resp15, resp16, // grafo 3
        resp17, resp18, resp19, resp20, resp21, resp22, resp23, // grafo 4
        resp24, resp25, resp26, resp27, resp28, resp29, // grafo 5
        resp30, resp31, resp32, // grafo 1
        resp33, resp34, resp35, resp36, resp37, resp38, resp39, resp40// grafo 6
    }; 

    char respostasEsperadas[tamanho][50] = {
        "135 12435 1235", "135 1235 12435", "135 1235", "24 234 2354", "34 354", "34 354", "34", "", // grafo 2
        "1356 1346", "1356 1346 134256", "651 6341 634251 6351", "651 6341 6351", "35 3465 3425", "46 4256", "46 4256 41356", "46 4256 41356", // grafo 3
        "1245 12345 1345", "1245 1345", "76", "3457", "12456 124576 13456 1246 1346 12456 123456 134576", "1246 1346 12456 12346 13456", "1246 1346", // grafo 4
        "13 123", "123 13", "", "32", "23", // grafo 5
        "13", "341", "412", "", // grafo 1 (errei aq mas ignora, ia dar mt trampo arrumar td dnv kkk)
        "12345 1235 1245 12435 1345 13245 135", "12345 1235 1245 12435 1345 13245 135", "1235 1245 1345 135", "2134 21354 234 2354 24", "34 3124 324 354", "324 34 354", "34", "21 231 24531 2431" // grafo 6
    };

    for (int i = 0; i < tamanho; i++) {
        printf("\nSequencias esperadas: %s", respostasEsperadas[i]);
        printf("\nRespostas obtidas: ");
        imprimirLista(respostasObtidas[i]);
        printf("\n========================================================");
    }

    printf("\n");
}