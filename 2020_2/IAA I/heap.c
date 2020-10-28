#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void MAX_HEAPIFY(int A[], int m, int i){
	int e, d, maior, temp;

	e = 2*i;
	d = 2*i + 1;
	if ( e <= d && A[e] > A[i] ) maior = e;
	else maior = d;

	if ( d <= m && A[d] > A[maior] ) maior = d;

	if (maior != i){
		temp = A[i];
		A[i] = A[maior];
		A[maior] = temp;

		MAX_HEAPIFY(A, m, maior);
	}
}

void BUILD_MAX_HEAP(int A[], int n){
	printf("entrou\n");
	for(int i = n/2; i >= 1; i--){
		MAX_HEAPIFY(A, n, i);
	}
}

void HEAP_SORT(int A[], int n){
	int m, temp, i;

	BUILD_MAX_HEAP(A, n); // pre-processamento

	m = n;
	for(i = n; i >= 2; i--){
		temp = A[1];
		A[1] = A[i];
		A[i] = temp;

		m--;
		MAX_HEAPIFY(A, m, 1);
	}
}

int HEAP_EXTRACT_MAX(int A[], int m){
	int max;

	max = A[1];
	A[1] = A[m];

	m--;
	MAX_HEAPIFY(A, m, 1);
	return max;
}

void IMPRIME_HEAP(int A[], int tam){
	int j;

    for(int i = 1; i <= tam; i++){
        for(int j = 0; j < pow(2, i) && j+pow(2, i) <= tam; j++){
            printf("%d ",  A[j+(int)pow(2,i)-1]);
        }
        printf("\n");
    }


}


int main(){
	int A[] = {-1, 1, 6, 9, 6, 3, 12, 13, 83, 1, 0, 5};
	int tam = sizeof(A) / sizeof(A[0]);


	IMPRIME_HEAP(A, tam);
	printf("\n");

	BUILD_MAX_HEAP(A, tam);
	IMPRIME_HEAP(A, tam);
	printf("\n");

	printf("max : %d\n", HEAP_EXTRACT_MAX(A, tam));

	printf("\n");
	HEAP_SORT(A, tam);
	IMPRIME_HEAP(A, tam);
	return 0;
}