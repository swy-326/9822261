#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <malloc.h>
#include <stdbool.h>

// nos das listas de adjacencias
typedef struct adj {
	int v;
	struct adj* prox;
} NO;

// vertices
typedef struct {
	NO* inicio;
} VERTICE;


// [ 0 | 1 | 2 ]   총 3칸, 사용되는 건 2칸 
/*

    Faltan : 
        testar varios casos

    ???? :
        repeticao e flag de vertice_y    =>    deletar as saidas de vertice_y ????
            Tinha um caso de teste que estava ultrapassadno o y (1,3,5,4,3)
            mas aparentemente agora esta certo
        
    Terminado :
        비어있는데 맘대로 감 -> vertice y nao estava sendo retirado da seqP ao backtracking
        self-loop -> flag eh 1, portanto, nao visita de novo

*/

// funcao principal
VERTICE* criaGrafo (int n);
NO* criaAdjacente (int v);
void criaAresta (VERTICE* g, int i, int v);
void imprime (VERTICE* g, int n);

NO* criaNovoNo (int v);
void adicionaSequenciaParcial (NO** seqP, int v);
void retiraSequenciaParcial (NO** seqP);
void adicionaSequenciaFinal (NO** seqP, NO** seqF);

NO* caminhos_max_d (VERTICE* g, int n, int x, int y, int d);
void buscaProfundidade (VERTICE* g, int x, int y, int d, int count, int flag[], NO** seqP, NO** seqF);




VERTICE* criaGrafo (int n){

	VERTICE* g = (VERTICE *) malloc (n * sizeof(VERTICE));
	
	for (int i = 0; i < n; i++){
		g[i].inicio = NULL; 
	}

	return g;
}

NO* criaAdjacente (int v){

	NO* temp = (NO *) malloc (sizeof(NO));
	temp->v = v;
	temp->prox = NULL;

	return temp;

}

void criaAresta (VERTICE* g, int i, int v){

	NO* novo = criaAdjacente(v);
	novo->prox = g[i].inicio;

	g[i].inicio = novo;

}

void imprime (VERTICE* g, int n){

	if (g){
		
		for (int i = 1; i <= n; i++){
			printf("v%d : ", i);
			NO* temp = g[i].inicio;

			while(temp){
				printf("v%d  ", temp->v);
				temp = temp->prox;
			}
			printf("\n");
		}
	}
	printf("\n\n");

}

NO* criaNovoNo (int v){
    NO* novo = (NO *) malloc (sizeof(NO));
    novo->v = v;
    return novo;
}


void adicionaSequenciaParcial (NO** seqP, int v){

    NO* novo = (NO *) malloc (sizeof(NO));
    novo->v = v;


    printf("\tadicionaSequenciaParcial\n");

    if (*seqP == NULL){
        novo->prox = NULL;
        *seqP = novo;
        printf("\t\tsequencia parcial vazia\n");
    }
    else {
        novo->prox = *seqP;
        *seqP = novo;
        printf("\t\tsequencia parcial nao vazia\n");
    }

    NO* temp = *seqP;

    printf("\t\t**Sequencia atual : ");
    while(temp){
        printf("%d ", temp->v);
        temp = temp->prox;
    }
    printf("\n");

    // ordem de seq : 1 - 2 - 3
    // adicionado sempre no inicio, portanto, ordem : 3 - 2 - 1

}

void retiraSequenciaParcial (NO** seqP){

    printf("\tretiraSequenciaParcial\n");

    NO* temp = *seqP;
    *seqP = (*seqP)->prox;
    
    printf("\t\tretirando : %d\n", temp->v);

    free(temp);

    printf("\tretirado\n");

    // seqP ordem : 3 - 2 - 1
    // retirar do inicio (free)

}

void adicionaSequenciaFinal (NO** seqP, NO** seqF){

    printf("\tadicionaSequenciaFinal\n");
    
    NO* temp = *seqP;
    printf("\t\t**Seq a adicionar inverso : ");
    while(temp){
        printf("%d ", temp->v);
        temp = temp->prox;
    }
    printf("\n");


    if (*seqF == NULL) printf("\t\tprimeira sequencia viavel\n");
    else printf("\t\tja existe outra sequencia\n");


    // cria semi-lista
    temp = *seqP;
    while(temp){
        NO* nuevo = criaNovoNo(temp->v);
        nuevo->prox = *seqF;
        *seqF = nuevo;
        temp = temp->prox;
    }


    temp = *seqF;
    printf("\t\t**Sequencia Final final : ");
    while(temp){
        printf("%d ", temp->v);
        temp = temp->prox;
    }
    printf("\n");

    // seqP ordem : 3 - 2 - 1
    // ordem a ser colocado : reverter a ordem : 1 - 2 - 3

}




void buscaProfundidade (VERTICE* g, int x, int y, int d, int count, int flag[], NO** seqP, NO** seqF){

    printf("\nbuscaProfundidade\n");

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

        printf("\tchegou no destino\n");

        adicionaSequenciaFinal(seqP, seqF);
        retiraSequenciaParcial(seqP);
        count -= 1;
        flag[x] = 0;

        printf("\tdestino registrado\n");

    }

    else {

        // marca como visitado
        // se count < d, procura outros vertices nao visitados
        // marca como explorado, tira da sequencia parcial, diminui count

        printf("\tno meio do caminho\n");

    	flag[x] = 1;

        NO* p = g[x].inicio;

        printf("\tcount : %d\n", count);
        while (p && count < d){
            printf("\t\tadicionando os proximos\n");
            if (flag[p->v] == 0) buscaProfundidade(g, p->v, y, d, count, flag, seqP, seqF);
            p = p->prox;
        }

        printf("\tbacktracking\n");

        count -= 1;
        flag[x] = 0;

        retiraSequenciaParcial(seqP);

    }

}


// busca em largura pq distancia
NO* caminhos_max_d (VERTICE* g, int n, int x, int y, int d){

    printf("caminhos_max_d\n");

	if (g[x].inicio == NULL) return NULL;

    printf("\tnot null\n");

	NO* sequenciaFinal = NULL;
	NO* sequenciaParcial = NULL;
    int count = 0;

	int flag[n]; // 0 nao visitado - 1 visitado - 2 explorado
	for (int i = 0; i <= n; i++) flag[i] = 0;

    printf("\tflag resetado\n\n");

    NO* temp = g[y].inicio;
    g[y].inicio = NULL;
    printf("\tarestas saindo de %d desconexos\n", y);

	buscaProfundidade(g, x, y, d, count, flag, &sequenciaParcial, &sequenciaFinal);
    
    printf("terminado a busca profundidade\n");

    g[y].inicio = temp;
    printf("retomando a conexao\n");
    
    return sequenciaFinal;

}




int main(){
	
	int n = 5; // v1 v2 v3 v4 v5

	VERTICE *g = criaGrafo(n+1);
/*
	criaAresta(g, 1, 2);
	criaAresta(g, 1, 3);
	criaAresta(g, 2, 4);
	criaAresta(g, 3, 5);
	criaAresta(g, 3, 6);
	criaAresta(g, 4, 5);
	criaAresta(g, 4, 7);
	criaAresta(g, 5, 7);
	criaAresta(g, 6, 7);

	criaAresta(g, 1, 1);
	criaAresta(g, 2, 2);
	criaAresta(g, 3, 3);
	criaAresta(g, 4, 4);
	criaAresta(g, 5, 5);
	criaAresta(g, 6, 6);
	criaAresta(g, 7, 7);

	criaAresta(g, 2, 1);
	criaAresta(g, 3, 1);
	criaAresta(g, 4, 2);
	criaAresta(g, 5, 3);
	criaAresta(g, 6, 3);
	criaAresta(g, 5, 4);
	criaAresta(g, 7, 4);
	criaAresta(g, 7, 5);
	criaAresta(g, 7, 6);

*/

/*
	criaAresta(g, 1, 3);
	criaAresta(g, 1, 2);
	criaAresta(g, 3, 2);
	criaAresta(g, 3, 5);
	criaAresta(g, 4, 2);
	criaAresta(g, 4, 3);
	criaAresta(g, 5, 4);

    criaAresta(g, 3, 1);
	criaAresta(g, 2, 1);
	criaAresta(g, 2, 3);
	criaAresta(g, 5, 3);
	criaAresta(g, 2, 4);
	criaAresta(g, 3, 4);
	criaAresta(g, 4, 5);
*/

	criaAresta(g, 1, 2);
	criaAresta(g, 2, 3);
	criaAresta(g, 2, 5);
	criaAresta(g, 3, 4);
	criaAresta(g, 4, 2);
	criaAresta(g, 4, 5);

	imprime(g, n);

	NO* temp = caminhos_max_d(g, n, 1, 5, 10);

    printf("[");
    while(temp){
        printf(" %d ", temp->v);
        temp = temp->prox;
    }
    printf("]");
}

