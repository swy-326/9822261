#include <malloc.h>
#include <stdio.h>

typedef struct aux {
	struct aux *pai, *dir, *esq;
	int valor, tamE, tamD;
} no;

typedef struct {
	no *raiz;
} avl;

int max (int x, int y)
{
	return (x > y) ? x : y;
}

int abs (int x)
{
	return (x < 0) ? -x : x;
}

int peso (no *n)
{
	return n->tamD - n->tamE;
}

void init(avl *a)
{
	a->raiz = NULL;
}

no *criar_no(int v)
{
	no *aux = (no*)malloc(sizeof(no));

	aux->pai = NULL;
	aux->dir = NULL;
	aux->esq = NULL;
	aux->valor = v;
	aux->tamE = 0;
	aux->tamD = 0;

	return aux;
}

no *buscar_posicao(no *n, int v)
{
	if (n) {
		if (v > n->valor) {
			if (n->dir) return buscar_posicao(n->dir, v);
		} else {
			if (n->esq) return buscar_posicao(n->esq, v);
		}
	}
	return n;
}

void rotE (avl *a, no *n)
{
	printf("\tFazendo rotação E em %d\n", n->valor);
	no *aux = n->dir;
	n->dir = aux->esq;
	aux->esq = n;

	if (a->raiz == n) {
		n->pai = aux;
		a->raiz = aux;
		aux->pai = aux;
	} else {
		aux->pai = n->pai;
		n->pai = aux;
	}

	n->tamD = (!n->dir) ? 0 : max(n->dir->tamE, n->dir->tamD) + 1;
	aux->tamE = max(aux->esq->tamE, aux->esq->tamD) + 1;
}

void rotD (avl *a, no *n)
{
	printf("\tFazendo rotação D em %d\n", n->valor);
	no *aux = n->esq;
	n->esq = aux->dir;
	aux->dir = n;

	if (a->raiz == n) {
		n->pai = aux;
		a->raiz = aux;
		aux->pai = aux;
	} else {
		aux->pai = n->pai;
		n->pai = aux;
	}

	n->tamE = (!n->esq) ? 0 : max(n->esq->tamE, n->esq->tamD) + 1;
	aux->tamD = max(aux->dir->tamE, aux->dir->tamD) + 1;
}

void atualizar_pesos(avl *a, no *p, no *f)
{
	int tam_max = max(f->tamE, f->tamD) + 1;

	if (f == p->dir) p->tamD = tam_max;
	else p->tamE = tam_max;

	if (abs(peso(p)) > 1) {
		if (peso(p) > 0) {
			if (peso(f) < 0) {
				rotD(a, f);
			}
			rotE(a, p);
		} else {
			if (peso(f) > 0) {
				rotE(a, f);
			}
			rotD(a, p);
		}
	}

	if (p->pai != p) atualizar_pesos(a, p->pai, p);
}

void inserir(avl *a, int v)
{
	printf("Inserindo o valor %d\n", v);
	no *no_para_inserir = criar_no(v);

	no *pai = buscar_posicao(a->raiz, v);

	if (pai) {
		no_para_inserir->pai = pai;

		if (pai->valor > v) {
			pai->esq = no_para_inserir;
		} else {
			pai->dir = no_para_inserir;
		}

		atualizar_pesos(a, pai, no_para_inserir);
	} else {
		no_para_inserir->pai = no_para_inserir;

		a->raiz = no_para_inserir;
	}
	printf("Inserção completa\n");
}

int main()
{
	avl arvoreAVL;
	init(&arvoreAVL);

	inserir(&arvoreAVL, 7);
	inserir(&arvoreAVL, 4);
	inserir(&arvoreAVL, 8);
	inserir(&arvoreAVL, 9);
	inserir(&arvoreAVL, 2);
	inserir(&arvoreAVL, 6);
	inserir(&arvoreAVL, 1);
	inserir(&arvoreAVL, 0);
	inserir(&arvoreAVL, 5);
}

