void novoEsquerdo(NO* p){

  	if (p->esq == NULL){

  		int valor = p->chave;

  		NO* novo = (NO*)malloc(sizeof(NO));
  		novo->esq = NULL; novo->dir = NULL;

  		if (p->dir != NULL){
  			chave += p->dir->chave;
  		}

  		pai->esq = novo;
  	}
  	
}
