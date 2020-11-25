#include <stdio.h>
#include <stdlib.h>


// https://www.codesdope.com/blog/article/priority-queue-using-heap/


typedef struct {
	int id; 
	float prior; 
} ELEMENTO;

typedef struct {
	ELEMENTO* A[4001]; 
	//ta dando erro, n sei pq
	//int maxElementos = 4000; 
	int m; 
} FILAPRIORIDADE;	


// funcoes adicionais
void init(FILAPRIORIDADE* fila){
	printf("Init\n\n");
	fila->m = 0;
}

ELEMENTO* criarNo(int valor, float prior){
	printf("\tcriarNo\n");
	ELEMENTO* novo = (ELEMENTO*) malloc (sizeof(ELEMENTO));
	novo->id = valor;
	novo->prior = prior;

	return novo;
}

void swap (ELEMENTO** a, ELEMENTO** b){
	printf("\tswap\n");
	ELEMENTO* temp = *a;
	*a = *b;
	*b = temp;
}

int indexRightChild(ELEMENTO* A[], int i){
	return (((2*i)+1) <= 4000) ?  ((2*i)+1) : -1;
}

int indexLeftChild(ELEMENTO* A[], int i){
	return ((2*i) <= 4000) ?  (2*i) : -1;
}

int indexParent(ELEMENTO* A[], int i){
	return ( i > 1 && i <= 4000 ) ? i/2 : -1;
}



// case 1
ELEMENTO* heapMax(ELEMENTO* A[], int *m){
	printf("\theapMax\n");
	return A[1];
}

ELEMENTO* maximum(FILAPRIORIDADE* fila){

	printf("Procurando maximum...\n");

	if ( fila->m == 0 ) return NULL;
	else {
		ELEMENTO* elem = heapMax(fila->A, &(fila->m));
		//printf("%d %.1f")
		return elem;
	}

	// retorna o elemento de S que possui a maior prioridade
}




// case 2
void maxHeapify(ELEMENTO* A[], int i, int m){

	printf("\tmaxHeapify\n");

	int max = i;
	int leftIndex = indexLeftChild(A, i);
	printf("\t\tpassou\n");
	int rightIndex = indexRightChild(A, i);

	if ( leftIndex <= m && leftIndex >= 1 ){
		printf("\t\tcondicao 1\n");
		if ( A[leftIndex]->prior > A[max]->prior ) max = leftIndex;
		printf("\t\tcondicao 1 depois de if\n");
	}

	if ( rightIndex <= m && rightIndex >= 1 ){
		printf("\t\tcondicao 2\n");
		if ( A[rightIndex]->prior > A[max]->prior ) max = rightIndex;
	}

	if (max != i){
		printf("\t\tif diferente\n");
		swap( &A[i], &A[max] );
		printf("\t\trealizou swap\n");
		maxHeapify(A, max, m);
	}

	printf("\t\tterminou\n");

}

ELEMENTO* heapExtractMax(ELEMENTO* A[], int* m){
	printf("\theapExtractMax\n");
	ELEMENTO* elem = A[1];
	A[1] = A[*m];
	*m -= 1;
	maxHeapify(A, 1, *m);
	return elem;	
}

ELEMENTO* extractMax(FILAPRIORIDADE* fila){

	printf("Extraindo o maximo...\n");

	if (fila->m == 0) return NULL;

	fila->m -= 1;
	return heapExtractMax(fila->A, &(fila->m));

	// remove e devolve o elemento de S que possui a maior prioridade
}



// case 3
// copiado, no se q pio hace
void heapIncreaseKey(ELEMENTO* A[], int i){

	printf("\theapIncreaseKey\n");

	while( i > 1 &&  A[indexParent(A, i)]->prior < A[i]->prior ){
		swap( &A[i], &A[indexParent(A, i)] );
		i = indexParent(A, i);
	} 
	
}

char heapInsert(ELEMENTO* A[], ELEMENTO* novo, float prior, int m){

	printf("\theapInsert\n");

	A[m] = novo;
	heapIncreaseKey(A, m);

	return 'T';
}

char insert(FILAPRIORIDADE* fila, int valor, float prior){

	printf("Inserindo %d...\n", valor);

	if ( fila->m > 4000 ) return 'F';

	ELEMENTO* novo = criarNo(valor, prior);
	fila->m += 1;
	return heapInsert(fila->A, novo, prior, fila->m);

}




// case 4
void heapPrint(FILAPRIORIDADE* fila){

	printf("Imprimindo... %d quantidades\n", fila->m);

	for (int i = 1; i <= fila->m; i++){
		printf("%d %.1f ", fila->A[i]->id, fila->A[i]->prior);
	}
	printf("\n");
}



int main(){

	FILAPRIORIDADE fila;
	init(&fila);

	ELEMENTO* elem; 
	int valor; float prior; char sucesso;

	int Q; scanf("%d", &Q); // numero de operacoes
	for (int i = 0; i < Q; i++){

		int caso; scanf("%d", &caso);
		
		switch(caso){
			case 1 : 
				elem = maximum(&fila);
				if (elem)
					printf("CASE 1 - Elem com max prioridade : %d %.1f\n", elem->id, elem->prior);
				else printf("-1 -1,0\n");
				printf("\n\n");
				break;

			case 2 : 
				elem = extractMax(&fila);
				if (elem)
					printf("CASE 2 - Extraido elem com max prioridade : %d %.1f\n", elem->id, elem->prior);
				else printf("-1 -1,0\n");
				printf("\n\n");
				break;

			case 3 : 
				scanf("%d", &valor); scanf("%f", &prior);
				if (insert(&fila, valor, prior) == 'T')
					printf("CASE 3 - Inserido %d tal vez com sucesso\n", valor);
				else printf("CASE 3 - Nao inserido %d\n", valor);
				printf("\n\n");
				break;

			case 4 : 
				heapPrint(&fila);
				printf("\n\n");
				break;

			default : 
				printf("nao eh aqui\n");
				printf("\n\n");
				break;
		} 
	}

	return 0;
}