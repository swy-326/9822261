// 2020-10-26

#include <stdio.h>
#include <malloc.h>

#define 0 false
#define 1 true
typedef int bool;

// nome em vez de valor(true, false etc)
typedef enum {
	esquerda,
	diretia
} direcao;

typedef enum {
	romance,
	acao,
	aventura
} categoria;

typedef struct NO{
	NO* pai, esq, dir;
	int chave;
}

typedef struct {
	NO* raiz;
} Arvore;

void init(Arvore* a){
	a->raiz = NULL;
}

NO* buscabin(NO* raiz, int chave){
	if (!raiz) return NULL;

	// condicao de parada
	if (raiz-<chave == chave) return raiz;

	// se xiao, vai pra esq
	if (raiz->chave < chave) return buscabin(raiz->esq, chave);
	else return buscabin(raiz->dir, chave);
}


bool inserir(Arvore* a, int valor, int pai, direcao dir){
	
	NO* pai_no = buscabin(a->raiz, pai);
	if (!pai_no) return false;

	NO* inserir = (NO*) malloc (sizeof(NO));
	inserir->pai = pai_no;
	inserir->esq = NULL; inserir->dir = NULL;
	inserir->chave = valor;

	if (dir == esquerda){
		// se ja tiver um elemento
		if (pai_no->esq != NULL) return false;

		// insercao
		pai_no->esq = inserir;

	} else {

		// mesma que acima
		if (pai_no->dir != NULL) return false;

		pai_no->dir = inserir;
	}
	return true;
} 


bool inserirRaiz(Arvore* a, int chave){
	if (a->raiz) return false;

	NO* inserir = (NO*) malloc (sizeof(NO));

	// raiz : pai dela eh ela mesma
	inserir->pai = inserir;
	inserir->esq = NULL; inserir->dir = NULL;
	inserir->chave = chave;

	a->raiz = inserir;
	return true;
}



int main(){

	Arvore a;
	inserirRaiz(&a, 3);
	inserir(&a, 5, 3, direita);

	return 0;
}



