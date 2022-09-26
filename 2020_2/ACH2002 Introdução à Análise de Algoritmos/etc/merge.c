#include <stdio.h>

// 포기함

void intercala(int A[], int inicio, int meio, int fim){
    int aux[fim];
    
    int i = inicio;
    int j = meio;
    int k = inicio;

    printf("inicio : %d, meio : %d, fim : %d\n\n", inicio, meio, fim);

    while(i <= meio && j <= fim){
        if(A[i] < A[j]){
            aux[k] = A[i];
            i++;
            k++;
        }
        else{
            aux[k] = A[j];
            j++;
            k++;
        }
    }

    while(i <= meio){
        aux[k] = A[i];
        i++;
        k++;
    }

    while(j <= fim){
            aux[k] = A[j];
            j++;
            k++;
    }

    for(i = inicio; i <= fim; i++){
        A[i] = aux[i];
    }

}

void selection(int A[], int ini, int fim){
    int temp, i, j, min;

    for(i = ini; i < fim; i++){
        min = i;
        for(j = i+1; j < fim; j++){
            if (A[j] < A[min]) min = j;
        }
        temp = A[min];
        A[min] = A[i];
        A[i] = temp;
    }
    printf("selected");
}


void merge_sort(int A[], int ini, int fim){
    int med, q1, q3;
    int n = fim - ini + 1;

    printf("\nn : %d, ", n);

    if (n >= 4){

        med = (ini + fim) / 2;
        q1 = (ini + med) / 2;
        q3 = (med + fim) / 2;
    
        printf("ini : %d, q1 : %d, med : %d, q3 : %d, fim : %d\n", ini, q1, med, q3, fim);

        printf("here\n");

        merge_sort(A, ini, q1);
        merge_sort(A, q1+1, med);
        merge_sort(A, med+1, q3);
        merge_sort(A, q3+1, fim);

        printf("there\n");

        intercala(A, ini, q1, med);
        intercala(A, med+1, q3, fim);
        intercala(A, ini, med, fim);
    }   
    else selection(A, ini, fim);
}

int main(){

    int A[] = {2,7,6,3,1,9,9,8,0};
    int tam = sizeof(A) / sizeof(A[0]);

    merge_sort(A, 0, tam-1);

    for(int i = 0; i < tam; i++){
        printf("%d ", A[i]);
    }

    return 0;
}