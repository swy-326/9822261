<< Serializacao de estrutura de dados >>

- Lista Sequencial (vetor)

	fwrite(), fread()
	contador de elementos => nao precisa ser recuperado, fread()

	escrita : 
		fwrite(vetor, sizeof(tipo_registro), prox, arq)
	leitura : 
		prox = fread(vetor, sizeof(tipo_registro), MAX, ara)

- Lista Ligada (*prox)

	enquanto (prox) : escreve no arquivo


	typedef struct no_sem_ponteiro {
		int chave;
		int info;
		...
		char nome[20];
	}

	no_sem_pontiero aux;
	NO* p = l->inicio;
	while (p){
		aux.chave = p->chave;
		aux.info = p->info;
		strcpy(aux->nome, p->nome);
		fwrite(&aux, sizeof(no_sem_ponteiro), l, arq);
		p = p->prox;
	}

- Arvore Binaria

	tem varios caminhos
		- preservar a estrutura : converter pra arvore estatica
		- sequencia de chaves : 그냥

- Grafos

	informacoes do vertice
	considerando a necessidade de recria-lo, precisamos da qntde de vertices

	lista de adjacencia		
	arquivo deve armazenar pares de vertices i,j que compoe cada aresta, em sequencia
	se for ponderado, alem dos pares i,j eh preciso armazenar tambem o peso de cada aresta

	escrita : percorre todas as arestas (elementos de todas as listas) e escreve os pares no arquivo
			  mas antes de comecar, pode ser util escrever |V| no inicio do arquivo
	leitura : le |V| se houver, crai o vetor dinamico de vertices, inicializa, e le as arestas i,j
			  uma a uma, invocando a funcao de insercao da aresta (일반 grafo 만드는 알고리즘과 비슷)


	6\1\2\p\1\4\p\2\3\p ...
