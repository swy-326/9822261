#include <stdio.h>
#include <stdlib.h>

struct reg {
	int conteudo;
	struct reg *prox;
};

typedef struct reg celula;

void imprime(celula *le){
	if (le != NULL){
		printf("%d\n", le->conteudo);
		imprime(le->prox);
	}
}

/*
void imprime(celula *le){
	celula *p;
	for (p = le; p != NULL; p = p->prox){
		printf("%d", p->conteudo);
	}
}

int contagem(celula *le, int i){
	if (le != NULL){
		i++;
		contagem(le, i);
	}
	return i;
}
*/

int contagem(celula *le){
	int i = 0;
	for(celula *p = le; p != NULL; p = p->prox){
		i++;
	}
	return i;
}

celula *busca(int x, celula *le){
	celula *p = le;
	while(p != NULL && p->conteudo != x) p = p->prox;
	return p;
}

/*
celula *busca(int x, celula *le){
	if (le->conteudo == x) return le;
	return busca(x, le->prox);
}
*/
void imprima(celula *le){
	for (celula *p = le; p != NULL; p = p->prox){
		printf("%d %d %d\n",p, p->conteudo, p->prox);
	}
}

// inserida entre a celula p e a celula seguinte
void insere(int x, celula *p){
	celula *nova;
	nova = malloc(sizeof(celula));
	nova->conteudo = x;
	nova->prox = p->prox;
	p->prox = nova;
}

void removee(celula *p){
	celula *lixo;
	lixo = p->prox;
	p->prox = lixo->prox;
	free(lixo);
}

void busca_e_remove (int y, celula *le){
   celula *p, *q;
   p = le;
   q = le->prox;

   while (q != NULL && q->conteudo != y) {
      p = q;
      q = q->prox;
   }

   if (q != NULL) {
      p->prox = q->prox;
      free (q);
   }
}

void busca_e_insere (int x, int y, celula *le){
   celula *p, *q, *nova;

   nova = malloc (sizeof (celula));
   nova->conteudo = x;

   p = le;
   q = le->prox;

   while (q != NULL && q->conteudo != y) {
      p = q;
      q = q->prox;
   }

   nova->prox = q;
   p->prox = nova;
}

int main(){

	celula *le;
	le = malloc(sizeof(celula));
	le->conteudo = 12;
	le->prox = NULL;

	insere(456, le);
	insere(32, le);
	insere(46, le);
	insere(71, le);
	insere(0, le);

	imprima(le);

	return 0;
}