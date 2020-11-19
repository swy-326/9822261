#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

// uri 1401

void swap(char* a, char* b){
	char temp;
	temp = *a;
	*a = *b;
	*b = temp;
}


void insertionSort(char* arr, int tam){
	int i, j;
	char chave;

	for (i = 1; i < tam; i++){
		chave = arr[i];
		for(j = i - 1; j >= 0 && arr[j] > chave; j--){
			arr[j+1] = arr[j];
		}
		arr[j+1] = chave;
	}
}


void permutacao(char* str, int n){

	if (strlen(str) == n) printf("%s\n", str);

	for(int i = n; i < strlen(str); i++){

	if (i >= strlen(str)-1 || str[i] != str[i+1]){
		swap(&str[i], &str[n]);

		for(int j = n+1; j <= i; j++){
			if(str[j] > str[i]) swap(&str[j], &str[i]);
		}

		permutacao(str, n+1);

		for(int j = i; j >= n+1; j--){
			if(str[j] < str[i]) swap(&str[j], &str[i]);
		}

		swap(&str[i], &str[n]);

	}
	}

}



int main(){

	int n; scanf("%d", &n);

	for(int i = 0; i < n; i++){
		char str[11]; scanf("%s", str);
		insertionSort(str, strlen(str));
		permutacao(str, 0);
		printf("\n");
	}

	return 0;
}







// for uri c[deprecated] compiler


/*

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>


// Sungwon Yoon

void swap(char* a, char* b){

	char temp;

	temp = *a;
	*a = *b;
	*b = temp;
}


void insertionSort(char* arr, int tam){

	int i, j;
	char chave;

	for (i = 1; i < tam; i++){
		chave = arr[i];
		for(j = i - 1; j >= 0 && arr[j] > chave; j--){
			arr[j+1] = arr[j];
		}
		arr[j+1] = chave;
	}
}


void permutacao(char* str, int n){

	int i, j;

	if (strlen(str) == n) printf("%s\n", str);

	for(i = n; i < strlen(str); i++){
	if (i > strlen(str) || str[i] != str[i+1]){

		swap(&str[i], &str[n]);

		for(j = n+1; j <= i; j++)
			if(str[j] > str[i]) swap(&str[j], &str[i]);

		permutacao(str, n+1);

		for(j = i; j >= n+1; j--)
			if(str[j] < str[i]) swap(&str[j], &str[i]);

		swap(&str[i], &str[n]);

	}
	}

}



int main(){

	int i;
	int n; scanf("%d", &n);

	for(i = 0; i < n; i++){
		char str[11]; scanf("%s", str);
		insertionSort(str, strlen(str));
		permutacao(str, 0);
		printf("\n");
	}

	return 0;
}



*/
