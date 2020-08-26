/*

19/08/2020 12:00 ~ 26/08/2020 09:00


Escreva uma função C que recebe como entrada um vetor de inteiros de N elementos possivelmente repetidos, e verifica a ordenação dos elementos.
 
int verificarOrdem(int vetor[], int N)
 
O retorno da função é um inteiro -1, +1, 0 ou 99 como segue:
 
+1 se os elementos seguem uma ordem crescente, ou no mínimo não decrescente{1 2 3 4 10 20 20 20 20 33 44 55 66}
 
-1 se os elementos seguem uma ordem decrescente, ou no mínimo não crescente{99 88 77 77 77 77 77 66 50 30 20 10 1 1 1 1 1 0}
 
0 se os elementos são idênticos ou se a lista é vazia:{1 1 1 1 1 1}
 
99 caso não haja nenhuma ordem (ou seja, nenhuma das anteriores):{1 2 3 2 4 5 6 }

*/


int verificarOrdem (int vetor[], int N){
 
    /* lista vazia */
    if (N == 0) return 0;
 
    /* lista nao vazia */
    int dif = vetor[1] - vetor[0];
 
    for (int i = 2; i < N; i++){
        int dif2 = vetor[i] - vetor[i-1];
 
        // se a dif2 for 0, ignora essa diferenca
 
        // em casos como [1,1,1,2,3] atualiza dif
        if (dif == 0 && dif2 != 0) dif = dif2;
 
        // vetor[1] - [0] eh crescente mas os proximos sao decrescentes
        else if ( dif > 0 && dif2 < 0 ) return 99; 
 
        // vetor[1] - [0] eh decrescente mas os proximos sao crescentes
        else if ( dif < 0 && dif2 > 0) return 99;
    }
 
    if (dif < 0) return -1;
    if (dif == 0) return 0;
    if (dif > 0) return 1;
}