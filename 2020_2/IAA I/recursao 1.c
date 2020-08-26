#include <stdio.h>

// https://www.ime.usp.br/~pf/analise_de_algoritmos/aulas/recursao.html

int soma (int n, int A[]);
int somaDirEsq (int k, int n, int A[]);
int max (int A[], int n);
int decide (int A[], int n, int x);
int igualdade (int A[], int B[], int n);
int encontra (int A[], int n, int x);
int buscaBinaria(int A[], int x, int ini, int fim);

int main(){

	int A[] = {1, 2, 3, 4, 5};
	int B[] = {710, 3, 6, 9, 2};
	int tam = 5;

	//printf("soma : %d\n", soma(tam, A));
	//printf("somaDirEsq : %d", somaDirEsq(0, tam, A));
	//printf("max : %d", max(A, tam-1));
	//printf("decide : %d", decide(A, tam-1, 10));
	//printf("igualdade : %d", igualdade(A, B, tam-1));
	//printf("encontra : %d", encontra (A, tam-1, 4));
	printf("buscaBinaria : %d\n", buscaBinaria(A, 3, 0, tam-1));
		printf("buscaBinaria : %d\n", buscaBinaria(A, 2, 0, tam-1));

	printf("buscaBinaria : %d\n", buscaBinaria(A, 1, 0, tam-1));

	printf("buscaBinaria : %d\n", buscaBinaria(A, 4, 0, tam-1));
	printf("buscaBinaria : %d\n", buscaBinaria(A, 5, 0, tam-1));
		printf("buscaBinaria : %d\n", buscaBinaria(A, 7, 0, tam-1));



	return 0;
}

// soma recursiva
int soma (int n, int A[]){
	if (n == 0) return 0;
	else return soma(n-1, A) + A[n-1];
	// 위에서 tamanho를 넘겨줘서 그럼. 여기는 indice인데
}

// soma recursiva
int somaDirEsq (int k, int n, int A[]){
	if (k == n) return 0;
	else return somaDirEsq(k+1, n, A) + A[k];
}

// maximo de um valor
int max (int A[], int n){
	int x;

	if (n == 0) return A[0];
	else {
		x = max(A, n-1);
		if (x < A[n]) return A[n];
		else return x;
	}
}

// busca sequencial
int decide (int A[], int n, int x){
	if (n == -1) return -1; 
	if (A[n] == x) return 0;
	else return decide(A, n-1, x);
}

// exercicio 1
int igualdade (int A[], int B[], int n){
	if (n == -1) return -1;
	if (A[n] == B[n]) return 0;
	else return igualdade(A, B, n-1);
}

// busca em vetor ordenado
int encontra (int A[], int n, int x){
	if (n == -1) return 0;

	if ( x < A[n] ) return encontra(A, n-1, x);
	else return n+1;
}


// exercicio 2 
/* 

buscaBinaria (A, x, e, d)
    meio = (e + d) / 2
    se x == A[meio]:
        return SIM
    se e == d:
        return NAO

    se x > A[meio]:
        buscaBinaria(A, x, e+1, d)
    senao:
        buscaBinaria(A, x, e, d-1)

*/
int buscaBinaria(int A[], int x, int ini, int fim){
	int meio = (ini + fim) / 2;
	if (x == A[meio]) return 0;
	if (ini == fim) return -1;

	if (x > A[meio]) buscaBinaria(A, x, meio+1, fim);
	else buscaBinaria(A, x, ini, meio-1);
}

/*
É falso pois pois a condição de parada é n = 0. Quando for chamada a SomaPositivos(A, 1), ele chamará recursivamente SomaPositivos(A, 1-1), criando espaço de memória para SomaPositivos(A, 0).
É falso pois as funções recursivas são empilhadas no stack até satisfazer a condição de parada, e somente a partir dali a ser executado, enquanto que os algoritmos iterativos executam os comandos na hora que são chamados.
*/
