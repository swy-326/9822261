2021.06.11 ~ 12


Uma chave para cada registros

KeySort()
	cria tabela de memoria (lista sequencial, ligada, arvore balanceada etcetc)
	ordena a tabela por chave (qq ordenacao)
	reescrever os registros -> custo computacional alto




tabela eh uma arvore balanceada, ou vetor etc
registros de tabela possuem dois campos:
	int chave eh a chave do registro
	int end eh o endereco (i.e., nro do registro) no arquivo (tipicamente longint)

bool inserirIndice (tabela, chave, end) // em qq estrutura desejada
int buscarEndereco (tabela, chave) // retorna end no arquivo, ou -1 se nao achou
int excluirIndice (tabela, chave) // exclui indice e retorna endereco para exclusao no arquivo ou -1


// Criacao de tabela de indices (de memoria principal)
int prox = 0
REGISTRO r
FILE *fp = fopen("dados.bin", "rb");
while (1 == fread(&r, sizeof(REGISTRO), 1, fp)){
	inserirIndice(tabela, r.chave,  prox);
	prox++;
}




Operacoes de arquivo
- insercao de um novo registro
- leitura de um registro dada a sua chave
- exclusao (logica)
- atualizacao de um campo nao chave
- atualizacao do campo chave

Insercao de um registro r
	fseek (arq, 0, SEEK_END);
	fwrite(&r, sizeof(REGISTRO), 1, arq)
	inserirIndice(tabela, r.chave, prox)
	prox++;

Leitura de um registro r dada sua chave
	int end = buscarEndereco(tabela, chave)
	if (end > -1)
		fssek(arq, end*sizeof(REGISTRO), SEEK_SET);
		int lidos = fread(&r, sizeof(REGISTRO), 1, arq)
		if (lidos < 1) // nao encontrado
	else	// registro nao encontrado - erro no indice ou nao existe


Exclusao logica do registro contendo chave (requer limpeza periodica do arquivo)
	REGISTRO rvazio;
	rvazio.valido = false;
	int end = excluirIndice(tabela, r.chave)
	if (end > -1)
		fseek(arq, end*sizeof(REGISTRO), SEEK_SET)
		fwrite(&rvazio, sizeof(REGISTRO), 1, arq)
		// atencao : nao mudou prox pq eh so exclusao logica
	else // registro nao encontrado - erro no indice


Exclusao => gerenciar posicoes livres

Atualizacao do campo nao chave
	// Assum-se que os dados estao em r
	int end = buscarIndice(tabela, r.chave)
	fseek(arq, end*sizeof(REGISTRO), SEEK_SET)
	fwrite(&r, sizeof(REGISTRO), 1, arq)


Atualizacao do campo chave chave1 para nova chave
	
	// corrige indice
	end = excluirIndice(tabela, chave)
	chave = novachave
	inserirIndice(tabela, chave, end)

	// le registro
	fseek(arq, end*sizeof(REGISTRO), SEEK_SET)
	int lidos = fread(&r, sizeof(REGISTRO), 1, arq)
	if (lidos == 0) // ERRO exit(1)

	// modifica e reescreve registros
	r.chave = novachave
	fseek(arq, -sizeof(REGISTRO), SEEK_SET) // bixu
	fwrite(&r, sizeof(REGISTRO), 1, arq)


// ------------------------------------------------------- //


INDICES SECUNDARIOS
- acesso ao arquivo nao eh feito com base na chave primaria (normalmente nao eh)
- tem q atualizar todas as tabelas (multiplicidade de tabelas)
- tabela invertida => chave secundaria e varias chaves primarias associadas
- meoria principal : 
	indice primario ordenado por chave primaria 
	indices secundarios para as chaves artista e ano - ordenado por chave secundaria \
		e apontado para listas de chaves primarias
	[cd.id | end] [artista | todos os cd.id] [ano | todos os cd.id]
- o resto eh a mesma


Operacoes
- Insercao :
	criar registro fisico no arquivo
	criar indice primario
	cirar / atualizar todos indices secundarios

- Exclusao : 
	excluir registro no arquivo
	excluir indice primario
	~opcionalmente~ atualizar indices secundarios
		// └ eh muito caro acessar e nao precisa pq nao esta no indice primario

- Alteracao
	tres casos a alterar : 
	- alteracao de campo nao chave (basta alterar conteudo do arquivo)
	- alteracao de chave secundaria (altera arquivo e reordena indice secundario afetado)
	- alteracao de chave primaria (altera arquivo, reordena indice primario e todos os indices secundarios \
		-- custo elevado e por vezes nao permitido)