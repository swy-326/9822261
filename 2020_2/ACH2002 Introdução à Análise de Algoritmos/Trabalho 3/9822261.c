#include <stdio.h>
#include <stdlib.h>


// https://www.codesdope.com/blog/article/priority-queue-using-heap/


typedef struct {
	int id; 
	float prior; 
} ELEMENTO;

typedef struct {
	ELEMENTO* A[4001]; 
	int m; 
	int maxElementos; 
} FILAPRIORIDADE;	


// funcoes adicionais
void init(FILAPRIORIDADE* fila){
	fila->m = 0;
	fila->maxElementos = 4000;
}

ELEMENTO* criarNo(int valor, float prior){
	ELEMENTO* novo = (ELEMENTO*) malloc (sizeof(ELEMENTO));
	novo->id = valor;
	novo->prior = prior;

	return novo;
}

void swap (ELEMENTO** a, ELEMENTO** b){
	ELEMENTO* temp = *a;
	*a = *b;
	*b = temp;
}

int indexRightChild(int i){
	return (((2*i)+1) <= 4000) ?  ((2*i)+1) : -1;
}

int indexLeftChild(int i){
	return ((2*i) <= 4000) ?  (2*i) : -1;
}

int indexParent(int i){
	return i/2;
}



// case 1
ELEMENTO* heapMax(ELEMENTO* A[], int *m){
	return A[1];
}

ELEMENTO* maximum(FILAPRIORIDADE* fila){

	if ( fila->m == 0 ) return NULL;
	else {
		ELEMENTO* elem = heapMax(fila->A, &(fila->m));
		return elem;
	}

	// retorna o elemento de S que possui a maior prioridade
}




// case 2
void maxHeapify(ELEMENTO* A[], int i, int m){

	int max = i;
	int leftIndex = indexLeftChild(i);
	int rightIndex = indexRightChild(i);

	if ( leftIndex <= m && leftIndex >= 1 ){
		if ( A[leftIndex]->prior > A[i]->prior ) max = leftIndex;
	}

	if ( rightIndex <= m && rightIndex >= 1 ){
		if ( A[rightIndex]->prior > A[max]->prior ) max = rightIndex;
	}

	if (max != i){
		swap( &A[i], &A[max] );
		maxHeapify(A, max, m);
	}

}

ELEMENTO* heapExtractMax(ELEMENTO* A[], int* m){

	ELEMENTO* elem = A[1];
	A[1] = A[*m];
	*m -= 1;
	maxHeapify(A, 1, *m);
	return elem;	
}

ELEMENTO* extractMax(FILAPRIORIDADE* fila){

	if (fila->m == 0) return NULL;
	return heapExtractMax(fila->A, &(fila->m));

	// remove e devolve o elemento de S que possui a maior prioridade
}




// case 3
// move para cima o novo elemento adicionado
void heapIncreaseKey(ELEMENTO* A[], int i){
		
	while( i > 1 && A[indexParent(i)]->prior < A[i]->prior ){
		swap( &A[i], &A[indexParent(i)] );
		i = indexParent(i);
	} 
	
}

char heapInsert(ELEMENTO* A[], ELEMENTO* novo, int m){

	A[m] = novo;
	heapIncreaseKey(A, m);

	return 'T';
}

char insert(FILAPRIORIDADE* fila, int valor, float prior){

	if ( fila->m > 4000 || prior < 0 || prior > 900000) return 'F';

	fila->m += 1;
	ELEMENTO* novo = criarNo(valor, prior);
	return heapInsert(fila->A, novo, fila->m);

}





// case 4
void heapPrint(FILAPRIORIDADE* fila){

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
					printf("%d %.1f\n", elem->id, elem->prior);
				else printf("-1 -1.0\n");
				break;

			case 2 : 
				elem = extractMax(&fila);
				if (elem)
					printf("%d %.1f\n", elem->id, elem->prior);
				else printf("-1 -1.0\n");
				break;

			case 3 : 
				scanf("%d", &valor); scanf("%f", &prior);
				if (insert(&fila, valor, prior) == 'T')
					printf("T\n");
				else printf("F\n");
				break;

			case 4 : 
				heapPrint(&fila);
				break;

			default : break;
		} 
	}

	return 0;
}