#include <stdio.h>
void ordenacao_fusao(int vetor[], int aux[], int inicio, int fim);
void intercala(int vetor[], int aux[], int inicio, int meio, int fim);
void imprimir(int vetor[], int tamanho);

void main(void)
{

    // int i = 0;
    // printf("\ni:%d\n", i++);
    // printf("\ni:%d\n", i++);

    int vetor[] = {1, 4, 6, 2, 3, 5, 9, 8, 7, 0, -1};

    // int vetor[] = {1, 5, 6, 4, 2, 3, 2};

    int tamanho = sizeof(vetor) / sizeof(int);
    int aux[tamanho];

    printf("Vetor original\n");
    imprimir(vetor, tamanho);

    ordenacao_fusao(vetor, aux, 0, tamanho - 1);

    printf("\nVetor ordenado\n");
    imprimir(vetor, tamanho);
}

void ordenacao_fusao(int vetor[], int aux[], int inicio, int fim)
{

    // caso base
    if (inicio >= fim)
        return;

    // divide conjunto no meio
    int meio = (inicio + fim) / 2;

    // merge sort para metade 1 do inicio ao meio
    ordenacao_fusao(vetor, aux, inicio, meio);
    // fim do precsso conquista

    // merge sort para metade 2 do meio + 1 ao fim
    ordenacao_fusao(vetor, aux, meio + 1, fim);
    // fim do precsso conquista

    // intercala
    intercala(vetor, aux, inicio, meio, fim);
    // fim do processo combina
}

void intercala(int vetor[], int aux[], int inicio, int meio, int fim)
{

    // cria copia do vetor original
    for (int k = inicio; k <= fim; k++)
        aux[k] = vetor[k];

    // i recebe inicio
    int i = inicio;

    // j recebe meio
    int j = meio + 1;

    for (int k = inicio; k <= fim; k++)
    {
        // se a primeira "pilha" ainda tiver elementos
        if (j > fim)
            vetor[k] = aux[i++];
        // se a segunda "pilha" ainda tiver elementos
        else if (i > meio)
            vetor[k] = aux[j++];
        // valida o topo das duas pilhas
        else if (aux[i] < aux[j])
            vetor[k] = aux[i++];
        else
            vetor[k] = aux[j++];
    }
}

void imprimir(int vetor[], int tamanho)
{
    printf("\n[ ");

    for (int i = 0; i < tamanho; i++)
        printf(" %d ", vetor[i]);

    printf(" ]\n");
}