#include <malloc.h>

typedef struct aux {
	int valor, pesoDir, pesoEsq;
	struct aux* noEsq;
	struct aux* noDir;
	struct aux* noPai;
} NO;

typedef struct {
	NO* raiz;
} Arvore;

void init(Arvore* arvore)
{
	arvore->raiz = NULL;
}

NO* novoNO(int valor)
{
	NO* no = (NO*)malloc(sizeof(NO));
	no->valor = valor;
	no->pesoDir = 0;
	no->pesoEsq = 0;
	no->noEsq = NULL;
	no->noDir = NULL;
	no->noPai = NULL;
	return no;
}

int max(int x, int y)
{
	return (x > y) ? x : y;
}

int abs(int x)
{
	return (x > 0) ? x : -x;
}

NO* pegarFolhaDir(NO* no)
{
	NO *atual = no;
	while (atual->noDir) {
		atual = atual->noDir;
	}
	return atual;
}

void mudarFilhoDePai(NO* atual, NO* aMudar)
{
	NO* noPai = atual->noPai;
	if (noPai->noEsq == atual) {
		noPai->noEsq = aMudar;
	} else {
		noPai->noDir = aMudar;
	}
	aMudar->noPai = noPai;
}

void atualizarPesosAPartirDoNo(NO* no)
{
	no->pesoEsq = max(no->noEsq->pesoEsq, no->noEsq->pesoDir) + 1;
	no->pesoDir = max(no->noDir->pesoEsq, no->noDir->pesoDir) + 1;

	if (abs(no->pesoEsq - no->pesoDir) > 1) {
		//TODO: Fazer o balanceamento
	}
}

void removerNo(Arvore* arvore, NO* no)
{
	NO* folhaDir = pegarFolhaDir(no->noEsq);
	folhaDir->noDir = no->noDir;
	no->noDir->noPai = folhaDir;
	mudarFilhoDePai(no, no->noEsq);
	no->noPai = NULL;
	no->noEsq = NULL;
	no->noDir = NULL;
	atualizarPesosAPartirDoNo(folhaDir);
}

int main()
{
	Arvore arvore;
}

