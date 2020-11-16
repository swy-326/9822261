#include <malloc.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

typedef struct aux {
	char valor;
	struct aux * filhos[26];
} No;

typedef struct {
	No * cabecas[26];
} Lista;

void init (Lista *l)
{
	for(int i = 0; i != 26; ++i) l->cabecas[i] = NULL;
}

No * buscaAux(No * n, char* palavra)
{
	if (!n || strlen(palavra) == 0) return n;
	return buscaAux(n->filhos[palavra[0] - 'a'], &palavra[1]);
}

No * busca(Lista * l, char* palavra)
{
	if (strlen(palavra) == 0) return NULL;
	return buscaAux(l->cabecas[palavra[0] - 'a'], &palavra[1]);
}

No* criarNo(char valor)
{
	No* no = (No*)malloc(sizeof(No));
	no->valor = valor;
	for (int i = 0; i != 26; ++i) {
		no->filhos[i] = NULL;
	}
}

bool inserir(Lista* l, char* palavra)
{
	No *aux, *pai;
	pai = NULL;
	aux = l->cabecas[palavra[0] - 'a'];
	while (aux) {
		palavra = &palavra[1];
		pai = aux;
		aux = aux->filhos[palavra[0] - 'a'];
	}
	if (!pai) {
		l->cabecas[palavra[0] - 'a'] = criarNo(palavra[0]);
		pai = l->cabecas[palavra[0] - 'a'];
		palavra = &palavra[1];
	}
	while (strlen(palavra) != 0) {
		pai->filhos[palavra[0] - 'a'] = criarNo(palavra[0]);
		pai = pai->filhos[palavra[0] - 'a'];
		palavra = &palavra[1];
	}
	return true;
}

int main()
{
	Lista l;
	init(&l);

	inserir(&l, "rua");
	inserir(&l, "ruela");

	return 0;
}
