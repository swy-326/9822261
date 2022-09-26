- Acesso direto a arquivos usando hashing externo


# INDEXACAO E ARVORES B

- Uso de indice quase transparente
- Acesso log_k(N)
- Hashing sem overflow = 1 seek; com overflow eh tipicamente pior que arvore B
- Arquivos dinamicos nao podem se beneficia de hashing estatico


# HASHING ESTATICO EM MEMORIA PRINCIPAL

- Idealmente O(1)
- Tratamento de colisoes
	Enderecamento aberto (sequencia de tentativas ate achar a chave)
	Enderecamento externo (listas ligadas associadas a cada registro)
- Em disco, ambos sao caras e nao pode haver tantas seeks assim


# SOLUCOES A CONSIDERAR

- Modificar a uncao de hashing? (Colisao)

	hashing perfeito ?!
	boa funcao de espalhamento, evitando agrupamentos

- Modificar a forma de armazenamento?

	gastar mais espaco com maior espalhamento
	mais registros por endereco = buckets (mas ha fragmentacao interna) <-

- Nenhuma das duas estrategias isoladamente seria o bastante para aplicacoes verdadeiramente dinamicas


# HASHING EXTENSIVEL

- Arvore trie (Retrieval) ou arvore de recuperacao de dados
- Mais aleatoria possivel (maximo espalhamento)
- Segunda funcao que transforma h(k) em uma sequencia de bits que corresponde a localizacao da chave na estrutura trie
- Somente os bits menos significativos (e possivelmente mais diferentes entre si) sao usados


# ARVORE TRIE

- Arvore cujas ramificacoes correspondem aos simbolos que constituem a chave
- Capacidade de usar uma porcao variavel de chave para enderacamento (e portanto tem grau de profundidade variavel)


# ARVORE TRIE EM HASHING EXTENSIVEL

- sequencia de bits 0 e 1 - arvore binaria
	isso n eh arvore B?


# REPRESENTACAO DA ARVORE TRIE

- Para evitar profundidade, cria-se arvore completa, que eh entao colapsada em uma tabela de diretorio
- Arvore completa : analisa toda a profundidade => ha ligacao redundante
- Diretorio: lista de ponteiros (com base nos bits)


# IMPLEMENTACAO DO DIRETORIO 

- Um diretorio usado como arvore trie eh apenas uma tabela de ponterios para buckets
- Representacao conveniente para armazenamento secundario


# OBJETIVOS DO HASHING EXTENSIVEL

- Solucao para underflow e overflow de buckets usadno um espaco de Enderecamento que se expande/contrai conforme populacao de chaves existentes em um dado momento
	(ex: jogar fora capitulos de livros diminui o indice de capitulos)

- estrutura de enderacamento (arvore trie ou diretorio) sofre momentos de expansao e reducao qnd necessario


# 50:50