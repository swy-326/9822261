#include <stdio.h>

void insercao(int n, int arr[]);
void imprime(int tam, int arr[]);

int main(){
	int arr[] = {4,6,2,10,9,8,15,18,12,5};
	int tam = 10;

	imprime(tam, arr);
	insercao(tam, arr);

	return 0;
}

void insercao(int tam, int arr[]){
	int chave, i;

	for (int j = 1; j < tam; j++){
		chave = arr[j];
		i = j - 1;
		while (i >= 0 && arr[i] > chave){
			//printf("heelo\n");
			arr[i+1] = arr[i];
			i--;
		}
		arr[i+1] = chave;
		imprime(tam, arr);
	}

}

void imprime(int tam, int arr[]){
	for (int i = 0; i < tam; i++){
		printf("%d  ", arr[i]);
	}
	printf("\n");
}