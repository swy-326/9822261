#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>


const char* nroUSP() {
    return("9822261");
}


typedef struct estr {
    int chave;
    struct estr *esq;
	struct estr *dir;
} NO;


void inicializarArvore(NO* *raiz);
NO* inserirNo(NO* *raiz, int ch);
NO* inserirDadoPai(NO* *raiz, NO* pai, int ch, int pos);
void imprimirArvore(NO* p, int d);
void imprimirFila(NO* raiz);
NO* acharpai(NO* raiz, int valor);
NO* ehValido(NO* *raiz, NO* *queueue);
NO* acharNo(NO* raiz, int valor);
NO* menorChave(NO* p);
NO* maiorChave(NO* p);
void excluirNo(NO** raiz, NO* errado);
int altura(NO* p);
void montarQueueue(NO* *queueue, NO* atual);
NO* copiar(NO* raiz);
bool ehDecrescente(NO* p);
void ordemDecrescente(NO* p, NO* *queueue);
NO* percorrer(NO* raiz, NO* descrescente);
void organizar(NO* *raiz);
NO* copiarFila(NO* raiz);




// inicializa a arvore
void inicializarArvore(NO* *raiz){
	*raiz = NULL;
}


// inserir novo no
NO* inserirNo(NO* *raiz, int ch){
	NO* pai;
	NO* atual;

	NO* novo = (NO*) malloc (sizeof(NO));
	novo->chave = ch;
	novo->esq = NULL; novo->dir = NULL;


	if (*raiz == NULL){
		(*raiz) = novo;
	}

	else {
		atual = (*raiz);
		pai = NULL;

		while(atual != NULL){

			pai = atual;

			if (ch < pai->chave){
				atual = atual->esq;
				if(atual == NULL) pai->esq = novo;
			}

			else { 
				atual = atual->dir;
				if (atual == NULL) pai->dir = novo;
			}
		}
	}
	return novo;
}


// Iserir no dado a posicao do pai ( esq=1   dir=2 )
NO* inserirDadoPai(NO* *raiz, NO* pai, int ch, int pos) {
	NO* novo;
	novo = (NO *) malloc(sizeof(NO));
	novo->chave = ch;
	novo->esq = NULL;
	novo->dir = NULL;
	
	if(pos == 1) pai->esq = novo;
	else pai->dir = novo;

	return novo;
}


// imprimir horizontal
void imprimirArvore(NO* p, int d){
	int i;
	if(p) {
		imprimirArvore(p->dir, d+1);
		for(i = 1; i <= d; i++) printf("     ");
		printf("%d\n", p->chave);
		imprimirArvore(p->esq, d+1);
	}
}


// achar pai, raiz sempre eh valida
NO* acharpai(NO* raiz, int valor){

	if (raiz != NULL){

		NO* p = raiz;
		NO* temp = NULL;

		NO* esquerda = p->esq;
		NO* direita = p->dir;

		if (esquerda != NULL && esquerda->chave == valor || direita != NULL && direita->chave == valor) return p;
	
		else {
			if (esquerda != NULL){
				temp = acharpai(esquerda, valor);
			}  
			if (temp == NULL && direita != NULL){
				return acharpai(direita, valor); 
			}
		}
	}

}


// achar o endereco, dado a chave
NO* acharNo(NO* raiz, int valor){

	NO* p = raiz;

	if (p){

		if (p->chave == valor) {
			return p;
		}

		NO* esq = acharNo(p->esq, valor);
		if (esq) {if(esq->chave == valor) return esq;}
		else {
			NO* dir = acharNo(p->dir, valor);
			if (dir) if(dir->chave == valor) return dir;
		}

	}

}


NO* acharFila(NO* raiz, int valor){


    NO* p = raiz; NO* pp = p;

    printf("percorrendo : ");
	
    while(p){
        printf("%d    ", p->esq->chave);
        if ( p->esq->chave == valor && ( pp->esq->chave <= p->esq->chave || ( p->dir != NULL && p->dir->esq->chave >= p->esq->chave) ) ) {
            return p;
        }
        pp = p;
        p = p->dir;
    }
	
/*
	while(p->dir){
		printf("%d  ", p->esq->chave);
		if ( p->esq->chave == valor ) {
			printf("\n\nretornando %d do endereco %d\n", p->esq->chave, p);
			return p;
		}
		p = p->dir;
	}
*/
	printf("\n\n");

}


// achar menor valor da (sub)arvore
NO* menorChave(NO* p){

	while (p->esq != NULL) p = p->esq;
	return p;

}


// achar maior valor da (sub)arvore
NO* maiorChave(NO* p){

	while (p->dir != NULL) p = p->dir;
	return p;

}


// excluir no
void excluirNo(NO** raiz, NO* errado){

	int chaveErrado = errado->chave;
	printf("\n\n\n\n\n\n=-=- chave a ser excluido :  %d -=-=\n", chaveErrado);
	NO* pai = NULL;

	// no errado nao tem filhos
	if ( errado->esq == NULL && errado->dir == NULL ){
		printf("case : nao tem filhos\n");

		if (errado != *raiz) {
			pai = acharpai(*raiz, chaveErrado);
		
			if (pai->esq == errado) pai->esq = NULL;
			else if (pai->dir == errado) pai->dir = NULL;
		}
		else (*raiz) = NULL;

		free(errado);
	}

	// no errado so tem filho esquerdo
	else if ( errado->esq != NULL && errado->dir == NULL ) {
		printf("case : apenas filho esquerdo");

		if (errado != (*raiz)){
			pai = acharpai(*raiz, chaveErrado);

			if (pai->esq == errado) pai->esq = errado->esq;
			else if (pai->dir == errado) pai->dir = errado->esq;
		}

		else (*raiz) = errado->esq;

		free(errado);
	}

	// no errado so tem filho direito
	else if ( errado->esq == NULL && errado->dir != NULL ){
		printf("case : apenas filho direito");

		if (errado != (*raiz)){
			pai = acharpai(*raiz, errado->chave);

			if (pai->esq == errado) pai->esq = errado->dir;
			else pai->dir = errado->dir;
		}
		else (*raiz) = errado->dir;

		free(errado);		
	}

	// tem ambos os filhos direito e esquerdo
	else {
		printf("case : ambos os filhos\n");

		if (errado != (*raiz)){

			// procura o menor valor e pai do errado
			NO* menorValor = menorChave(errado->dir);
			NO* paiDoErrado = acharpai(*raiz, errado->chave);
			printf("menor valor : %d\n", menorValor->chave);

			// pai do menor valor
			NO* paiDoMenorValor = acharpai(*raiz, menorValor->chave);
			printf("paiDoMenorValor : %d\n", paiDoMenorValor->chave);

			// se o menor valor esta logo abaixo do errado (sempre lado direito)
			if(paiDoMenorValor->chave == errado->chave) {
				printf("esta abajo\n");
				if(paiDoErrado->dir == errado) paiDoErrado->dir = menorValor;
				else paiDoErrado->esq = menorValor;

				menorValor->esq = errado->esq;
			}
			else {
				printf("esta lejo\n");
				paiDoMenorValor->esq = NULL;
	
				if(paiDoErrado->dir == errado) paiDoErrado->dir = menorValor;
				else paiDoErrado->esq = menorValor;

				menorValor->esq = errado->esq;
				menorValor->dir = errado->dir;
			}
		}
		else {

			// procura o menor valor e pai do errado
			NO* menorValor = menorChave(errado->dir);
			printf("menor valor : %d\n", menorValor->chave);

			// pai do menor valor
			NO* paiDoMenorValor = acharpai(*raiz, menorValor->chave);

			// se o menor valor esta logo abaixo do errado (sempre lado direito)
			if(paiDoMenorValor == errado) {
				printf("esta abajo\n");
				(*raiz) = menorValor;

				menorValor->esq = errado->esq;
			}
			else {
				printf("esta lejo\n");
				paiDoMenorValor->esq = NULL;
	
				(*raiz) = menorValor;


				menorValor->esq = errado->esq;
				menorValor->dir = errado->dir;
			}

		}

		free(errado);

	}

}


void excluirFila(NO** raiz, NO* errado){

    NO* p = *raiz;

	printf("excluindo na fila : ");

	printf("endereco do raiz : %d,   endereco do errado : %d", p, errado);

	if (p->esq->chave != errado->esq->chave){
	    while (p->dir != errado){
    	    printf("%d     ", p->esq->chave);
        	p = p->dir;
    	}
		p->dir = errado->dir;
    	free(errado);
	}

	else {
		(*raiz) = errado->dir;
		free(errado);
	}

}


// retorna altura de um no
int altura(NO* p){

	if(p == NULL) return 0;

	return altura(p->esq) > altura(p->dir) ? altura(p->esq)+1 : altura(p->dir)+1;
}


// dir = prox; esq = ponteiro a guardar
void montarQueueue(NO* *queueue, NO* atual){

	if ((*queueue) == NULL) {
		printf("\naaadicionado a queue : %d\n", atual->chave);
		NO* novo = (NO*) malloc (sizeof(NO));
		novo->esq = atual;
		novo->dir = NULL;
		(*queueue) = novo; 
	}
	else {
		NO* novo = (NO*) malloc (sizeof(NO));
		novo->esq = atual;
		novo->dir = (*queueue);
        (*queueue) = novo;
    	
        printf("aaadicionado a queue : %d\n", (*queueue)->esq->chave);
	}
}


NO* copiarFila(NO* raiz){
    
    NO* p = raiz;

    NO* primeiro = (NO*)malloc(sizeof(NO));
    //printf("copia primeiro no : %d\n", p->esq->chave);
    primeiro->esq = p->esq;
    primeiro->dir = NULL;
    p = p->dir;

    NO* anterior = primeiro;
    while(p){
        
        NO* novo = (NO*)malloc(sizeof(NO));
        novo->esq = p->esq;
        novo->dir = NULL;

        anterior->dir = novo;
        anterior = novo;

        p = p->dir;
    }

    printf("fila copiado : ");

    imprimirFila(primeiro);

	printf("\n");

    return primeiro;
}


// copiar uma lista ligada
NO* copiar(NO* raiz){
    if (raiz) printf("you mei you raiz : %d\n", raiz->chave);
    NO* novo, *esq, *dir;
    novo = NULL;
    if(raiz){
        esq = copiar(raiz->esq);
        dir = copiar(raiz->dir);
        novo = (NO*) malloc (sizeof(NO));
        novo->chave = raiz->chave;
        novo->esq = esq;
        novo->dir = dir;
    }
    return novo;
}


// verifica se eh decrescente
bool ehDecrescente(NO* p){

	NO* pp = p;

	printf("\n\n--- eh decrescente ? ---\n");
	while ( pp->dir ){
        if (pp->esq->chave <= pp->dir->esq->chave){ 
            return false;
        }
		pp = pp->dir;

	}

    return true;
}


// cria fila em ordem decrescente
void ordemDecrescente(NO* p, NO* *queueue){

	if (p){
    	ordemDecrescente(p->esq, queueue);
	    montarQueueue(queueue, p);
	    ordemDecrescente(p->dir, queueue);
    }
    
}


void imprimirFila(NO* raiz){
    NO* p = raiz;
    printf("\n\nFila  :  ");
    while(p){
        printf("%d  ", p->esq->chave);
        p = p->dir;
    }
    printf("\n\n");
}


NO* percorrer(NO* raiz, NO* descrescente){

	NO* pDescrescente = descrescente;
    NO* filaDeErros = NULL;

    // erro 만 따로 쌓음
	printf("\n\n=======buscando erro======\n");
	while ( pDescrescente->dir ){
        if (pDescrescente->esq->chave <= pDescrescente->dir->esq->chave){ 
            montarQueueue(&filaDeErros, pDescrescente->dir->esq);
            montarQueueue(&filaDeErros, pDescrescente->esq);
        }
        printf("%d  ", pDescrescente->esq->chave);
		pDescrescente = pDescrescente->dir;
	}


    // 제거할 시 true일 경우 그 node 높이 계산. (높이 클수록 뿌리에 가까운 거)
    // 초기 최대 높이 -1 와 비교
    NO* pFilaDeErros = filaDeErros; 
    NO* pertoDaRaiz = NULL; int alturaMax = -1;

    imprimirFila(descrescente);

    while(  pFilaDeErros  ){

        printf("\n\n\n\n\n------------ buscando se %d esta certo ------------\n\n", pFilaDeErros->esq->chave);

        NO* copiaDescrescente = copiarFila(descrescente);

        excluirFila(  &copiaDescrescente,  acharFila( copiaDescrescente,  pFilaDeErros->esq->chave)   );
        printf("\ndepois da exclusao : "); imprimirFila(copiaDescrescente);


        if ( ehDecrescente( copiaDescrescente ) == true ){
            printf("eh descrente\n");
            int alt = altura( acharNo(raiz, pFilaDeErros->esq->chave));
            if ( alt > alturaMax ){
                printf("eh mais perto do raiz\n");
                alturaMax = alt;
                pertoDaRaiz = pFilaDeErros;
            }
        }
                
        else {
            printf("nao eh descrescente\n");
        }

        pFilaDeErros = pFilaDeErros->dir;
        free(copiaDescrescente);
    }

    return (pertoDaRaiz) ? pertoDaRaiz->esq : NULL;
    //return pertoDaRaiz->esq;

}


void organizar(NO* *raiz){

	if( (*raiz) != NULL ){

		NO* descrescente = NULL;
		ordemDecrescente(*raiz, &descrescente);

        // if profundidade menor e true (se excluir, fica em ordem crescente)
		NO* errado = percorrer(*raiz, descrescente);

        if (errado) {
            excluirNo(  raiz, errado ); 
            printf("corrigido");
        }
		else printf("correto\n");

	}
}






int main() {

	NO* arv = NULL;

/*
	NO* ba = inserirNo(&arv, 8);

	NO* san = inserirDadoPai(&arv, ba, 3, 1);
	NO* yi = inserirDadoPai(&arv, san, 1, 1);
	NO* liu = inserirDadoPai(&arv, san, 6, 2);
	NO* si = inserirDadoPai(&arv, liu, 6, 1);
	NO* qi = inserirDadoPai(&arv, liu, 7, 2);

	NO* shi = inserirDadoPai(&arv, ba, 10, 2);
	NO* shisi = inserirDadoPai(&arv, shi, 14, 2);
	NO* shisan = inserirDadoPai(&arv, shisi, 13, 1);
*/



	NO* ershiwu = inserirNo(&arv, 25);
	
	NO* ershi = inserirDadoPai(&arv, ershiwu, 20, 1);
	NO* shi = inserirDadoPai(&arv, ershi, 10, 1);
	NO* wu = inserirDadoPai(&arv, shi, 5, 1);
	NO* shier = inserirDadoPai(&arv, shi, 12, 2);
	NO* ershier = inserirDadoPai(&arv, ershi, 22, 2);

	NO* sanshiliu = inserirDadoPai(&arv, ershiwu, 36, 2);
	NO* sanshi = inserirDadoPai(&arv, sanshiliu, 30, 1);
	NO* ershiba = inserirDadoPai(&arv, sanshi, 0, 1);
	NO* sishi = inserirDadoPai(&arv, sanshiliu, 40, 2);
	NO* sanshiba = inserirDadoPai(&arv, sishi, 38, 1);
	NO* sishiba = inserirDadoPai(&arv, sishi, 48, 2);



	imprimirArvore(arv, 0);
	printf("\n\n\n\n");


    organizar(&arv);

    printf("\n\n\n\n\n\n\n\n\n+++++++++final++++++++\n\n\n");

	imprimirArvore(arv, 0);

}