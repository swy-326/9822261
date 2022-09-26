#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

// http://data.biancheng.net/view/66.html

int BinarySearch(int arr[], int valor, int inf, int sup){
	int mid;

	while( inf <= sup){
		mid = (inf + sup) / 2;
		if(arr[mid] > valor) sup = mid - 1;
		else inf = mid + 1;
	}
	return inf;
}
void BinaryInsertionSort(int arr[], int tam){
	int i, j, index, chave;

	for(i = 1; i < tam; i++){
		chave = arr[i];
		index = BinarySearch(arr, chave, 0, i-1);
		for(j = i; j > index; j--){
			arr[j] = arr[j-1];
		}
		arr[index] = chave;
	}
}


// https://milib.tistory.com/9

int BinarySearchR(int arr[], int valor, int inf, int sup){
	int mid;

	if(inf <= sup){
		mid = (inf + sup) / 2;

		if (arr[mid] == valor) return mid;

		if (arr[mid] > valor) return BinarySearchR(arr, valor, inf, sup-1);
		return BinarySearchR(arr, valor, mid+1, sup);
	}

	return inf;
}

void BinaryInsertionSortR(int arr[], int tam){
	int i, j, chave, index;

	for(i = 1; i < tam; i++){
		chave = arr[i];
		index = BinarySearchR(arr, chave, 0, i);
		for(j = i; j > index; j--){
			arr[j] = arr[j-1];
		}
		arr[index] = chave;
	}
}


void imprimir(int arr[], int tam){
	for(int i = 0; i < tam; i++){
		printf("%d ", arr[i]);
	}
}
/*

int BinarySearchR(int arr[], int valor, int inf, int sup){
	int meio;

	if (sup <= inf){
		if (valor > arr[inf]) return inf + 1; 
		else return inf;
	} 

	meio = (inf + sup) / 2;

	if (valor == arr[meio]) return meio+1;
	if (valor > arr[meio]) return BinarySearch(arr, valor, meio+1, sup);
	return BinarySearch(arr, valor, inf, meio-1);
}


void BinaryInsertionSortR(int arr[], int tam){
	int chave, index, i, j;

	for (i = 1; i < tam; i++){
		j = i-1;
		chave = arr[i];
		index = BinarySearchR(arr, chave, 0, j);
		for(; j > index; j--){
			arr[j+1] = arr[j];
		}
		arr[j+1] = chave;
	}
}

*/

int main(){

	int arr[] = {1,3,5,7,3,3,2,6,8,9,13216,1,61,36,7};

	int tam = sizeof(arr)/sizeof(arr[0]);

	imprimir(arr, tam);

	printf("\n\n\n");

	BinaryInsertionSortR(arr, tam);
	imprimir(arr, tam);


	return 0;
}


