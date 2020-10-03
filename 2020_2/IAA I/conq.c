/*
	// 포기함
    https://www.ime.usp.br/~pf/analise_de_algoritmos/aulas/divide-and-conquer.html
    divisao e conquista

*/


#include <stdio.h>

int somaRec(int A[], int l, int r){
    int s = (l+r)/2;                    // Θ(1)
    int m1, m2, soma;

    if(l == r) return A[l];             // Θ(1)
    if(l < r){                          // Θ(1)
        m1 = somaRec(A, l, s);          // T(n/2)
        m2 = somaRec(A, s+1, r);        // T(n/2)
        soma = m1+m2;                   // Θ(1)
    }
}

void intercala(int A[], int ini, int med, int fim){
    int B[fim];
    int i = ini, j = med, k = ini;

    while (i < med && j < fim){
        if (A[i] < A[j]) {
            B[k] = A[i];
            k++;
            i++;
        } else {
            B[k] = A[j];
            k++;
            j++;
        }
    }

    while(i < med){
        B[k] = A[i];
        i++;
        k++;
    }

    while(j < fim){
        B[k] = A[i];
        k++;
        j++;
    }

    for(i = 0; i < fim; i++){
        A[i] = B[i];
    }

}

void selection(int A[], int ini, int fim){
    int temp, i, j, min;

    for(i = ini; i < fim-1; i++){
        min = i;
        for(j = i+1; j < fim; j++){
            if (A[j] < A[min]) min = j;
        }
        temp = A[min];
        A[min] = A[i];
        A[i] = temp;
    }
    
}


void merge_sort(int A[], int ini, int fim){
    int med, q1, q3;
    int n = (ini + fim) / 2;

    if (n >= 4){

        med = (ini + fim) / 2;
        q1 = (ini + med) / 2;
        q3 = (med + fim) / 2;
    
        printf("here\n");

        merge_sort(A, ini, q1);
        merge_sort(A, q1+1, med);
        merge_sort(A, med+1, q3);
        merge_sort(A, q3+1, fim);

        printf("there\n");

        intercala(A, ini, q1, med);
        intercala(A, med, q3, fim);
        intercala(A, ini, med, fim);
    }   
    else selection(A, ini, fim);
}
/*
| ... | ... | ... | ... |
i     1     m     3     f
*/
int main(){

    int A[] = {2,7,6,3,1,9,9,8,0};
    int tam = sizeof(A) / sizeof(A[0]);


    merge_sort(A, 0, tam-1);


    for(int i = 0; i < tam; i++){
        printf("%d ", A[i]);
    }

    return 0;
}