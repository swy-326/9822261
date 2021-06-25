INDICES NO RESIDENTES EM MEMORIA PRINCIPAL

- nem as chaves cabem na memoria
- os proprios indices sao um arquivo
- FILE STRUCTURES / Michael J. Folk


// youtube-dl --write-srt --sub-lang ko --skip-download https://youtube.com/playlist?list=PLIsLFZTOf0vjAlkppNYNh1Blr_0v2P8Ye


# O Problema
- Acesso direto a registro do arquivo com base em uma chave de interesse requer uma estrutura intermediaria que relaciona as chaves e os enderecos fisicos do arquivo ao qual elas se relacionam
- Memoria secundaria
- A propria estrutura de indices se transforma em um arquivo que precisa ser acessado de modo a acessar o arquivo principal 


# Requisitos necessarios da estrutura de indices externos
(1) Precisa ser ordenada por chave
(2) Precisa permitir atualizacoes localizadas (porque reorganizar a estrutura em memoria externa seria proibitivo)
	- Lista linear nao serve, nem vetor nem lista ligada -- arvores nao lineares
(3) Precisa localizar chaves rapidamente
	- Arvores sem balanceamento tb nao servem


# 1a tentativa : AVL
(+) atualizacao tem efeito local
(+) registros nao precisam estar fisicamente ordenados
(-) busca ainda exige muitos acessos (seeks) pra uma estrutura intermediaria
(-) balanceamento e rotacoes


# Percurso em arvore binaria em arquivo
- ABB completa tem pior caso de busca		=>		log2(N+1)
- AVL (culpa da rotacao)					=>		1.44*log2(N+2)
- 1 milhao de chaves em ABB completa = 20 niveis de altura
- Em AVL seriam 28 niveis => os dois sao inaceitaveis
- 10 seeks ja eh inaceitavel


# Como reduzir o numero de seeks?
- Acessar cada um dos elemento da arvore em memoria secundaria exige um seek, cujo custo eh elevado
- No entanto, uma vez que o acesso foi realizado, nao faz sentido recuperar apenas uma chave
- Ao inves disso, tiramos proveito do acesso realizado para comandar a transferencia de um bloco de chaves
- Os elementos (paginas) de arvores de armazenamento externo devem assim conter um grande numero (possivelmente milhares) de chaves


# Paginacao
- Uma pagina contem muitas chaves (associadas a enderecos de registros do arquivo real)
- Ao acessar um registro, a pagina inteira eh lida
- Se a chave a ser acessada estiver na pagina residente, nenhum outro acesso ao disco eh necessario


# Exemplo
- Em uma arvore :
	Cada pagina armazena k=511 pares chave-referencia
	Cada pagina contem uma arvore completa perfeitamente balanceada
- Entao a capacidade total em 3 niveis (3 seeks) sera
	N = 511 + (512*511) + (5122*511) = 134217727 chaves
	=> arvore grande pros lados
- ABB511		log_k+1(N) => log_512 (134217727) = 3 seeks
  ABB2			log_2(N) => log_2 (134217727) = 27 seeks


# Balanceamento
- Se as chaves sao conhecidas de antemao, inicia-se a insercao pela chave mediana (top-down)


# Problemas 
- Tem paginas com baixa ocupacao, sempre vai ter
- Operacoes de rotacao complexas, podendo envolver varias paginas -- mtos seek 
- Chaves proximas podem ficar em paginas muito distantes (problema qnd acesso sequencial)
- Chaves que nao deveriam estar juntas estao na mesma pagina


# Consideracoes
- Para preservar o balanceamento, tudo depende de definirmos boas chaves separadoras entre paginas
	Mas isso nao reslve todos os problemas (ex : rotacao)
- Aspectos importantes : 
	Arvore ordenada (atualizacao local)
	Organizada em paginas (poucos seeks = acesso rapido) <= CONDICAO ABSOLUTA
	Balanceada com bons separadores
	Operacoes de balanceamento de baixa complexidade
- COMO ???????





# ARVORES B
- AVL (1962)
- Arvore B (1972/1979)
- Arvore B, arvore B*, arvore B+ sao tudo diferentes, mast erminologia tudo misturado
- Referencia livro : Folk & Zoelick


# Visao geral
- Objetivo : armazenar colecoes imensas de chavevs (e seus respectivos ponteiros de registro) para uso como indice de acesso ao arquivo (tb imenso) de aplicacao
- Somente uma pequena porcao da estrutura de indice fica residente em memoria. O resto esta no arquivo de arvore B 
- Arvore cresce pra cima
- Desempenho da ordem de log_k(i) onde k eh a capacidade da pagina e i eh o tamanho do indice (ou qntde de resitros do arquivo-alvo)
- A arvore eh um indice de armazenamento em memoria secundaria, para acesso a outro arquivo 
- Eh uma arvore ordenada por chave, mas nao eh binaria
- Nao possui paginas vazias ou folhas com alturas diferentes
- esq = menor; meio = entre; dir = maior


# Exemplo : paginas de ate k=2 chaves cada
- Cada pagina eh um vetor de ate k chaves ordenadas e k+1 links para as paginas inferiores (e portanto paginas nao contem arvores)
- Haveria ainda os ponteiros para registros do arquivo
- Uma pagina contendo n chaves possui obrigatoriamente n+1 links para seus filhos (ou -1 se for folha)
- O numero m de links (descendencias) possiveis (ou k+1) eh a ordem da arvore.


# Implementacao da pagina
- A pagina eh composta minimamente de dois vetores : o vetor de chaves, e do vetor de links, ambos numerados de 1...k
- Um link[i] eh, por definicao, o caminho a direita da chave[i] correspondente, ou seja, eh o que leva aas chaves maiores do que chave[i]
- O link esquerdo de uma chave ch[i] eh na verdade o link[i-1], o que exige a criacao de uma posicao (0) sem chave, contendo apenas o link mais aa esquerda da chave [1]


# Exemplo : m = 4 (ou seja, 4 links)
-  chave[0]  |  link[0]  |  chave[1]  |  link[1]  |  chave[2]  |  link[2]  |  link[3]
					|						|
			chaves < chave[1]				|
							chaves > chave[1] e < chave[2]
- A posicao zero do vetor so eh usada para link -- nao contem chave


# Busca em arvore B 
- A chave de busca eh comparada co todas as chaves da pagina atual 
- Se encontrou, fim
- Se for menor do que a chave encontrada na pagina, segue o link esquerdo 
- Caso contrario, segue o link direito


# Insercao
- A arvore B eh construida sempre da folha para raiz (de baixo para cima), estando assim permanentemente balanceada
	Evitando a necessidade de rotacoes complexas
	Resolvendo o problema de escolha de separadores otimos
- Procedimento geral : 
	Buscar a pagina, e se houver espaco, inserir e fim
	Quando necessario (overflow), pagina pode ser dividida em duas (divisao, ou split) promovendo-se em um separador (a chave mediana e seu link direito) para a pagina pai 
	Se houver promocao de separador, a chave em questao eh reinserida (recursivamente) na pagina pai


# Exemplo : m = 3 (3 links, 2 chaves)
(1) Inserir 10, 20 -> [10 20]
(2) Inserir 30 -> overflow
				
				[10 __ ] [30 __ ]
			A chave mediana 20 eh promovida ao nivel superior
(3) A promocao de 20 ao nivel superior, que nao existe, leva a criacao de uma nova pagina pai

					[20 __ ]
				[10 __ ] [30 __ ]