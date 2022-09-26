# Referencia / terminologia

- Khuth, D. The art of computer programming


# ARVORE B*

- tem ocupacao media maior q arvore b (85% > 69%)

## MELHORIAS EM RELACAO A ARVORE B COMUM

- redistribuicao eh eficiente mas eh utilizada apenas na inclusao
- divisao (que eh cara) eh invocada com muita frequencia, sempre que uma pagina e suas irmas estao cheias
- uso da redistribuicao na insercao e adiamento da divisao

## INSERCAO EM ARVORE B*

- cada pagina tem no minimo 2/3 da capacidade
- divisao eh adiada ate que duas paginas irmas fiquem cheias
- divisao simultanea de 2 para 3 paginas

- pagina raiz nao da pra redistribuir => caso especial -> utiliza um tamanho maior para evitar overflow

## USO DE MEMORIA VIRTUAL

- arvore b so funciona com uso de memoria virtual
- raiz / topo na memoria
- ocupar a memoria com tantas paginas quanto possivel, e so acessar disco qnd ha page fault (como em um buffer)
- busca a pagina substitui em regime LRU (Least Recently Used) ou equivalente


# ARVORE B+

- acesso direto e sequencial

- solucao hibrida de arvore de separadores minimos
- capacidade (ou ordem m) das paginas de separadores != capacidade dos blocos
- insercao e exclusao (com possivel over/underflow) afetam a lista de blocos e a estrutura de separadores
- tamanho da pagina de indice = tamanho do bloco de dados
- pode usar um mesmo arquivo para indices e blocos

## ACESSO DIRETO

- estrutura de indicies (separador) para referenciar blocos de chavevs ordenados

## ACESSO SEQUENCIAL

- blocos ordenados formam uma lista ligada

## CONSIDERACOES

- operacoes de divisao qnd ha overflow nos blocos
- operacoes de concatenacao qnd ha underflow
- fragmentacao interna: blocos ocupam mais espaco que o arquivo ordenado comum
- ordem fisica nao eh necessariamente sequencial

## SEPARADORES

- arvore de separadores (que podem ou nao coincidir com as chaves nos blocos)
- separadores minimos (ou seja, contendo a sequencia minima de simbolos necessaria para distinguir um bloco do outro)

	void achaSeparador (char k1[], char k2[], char sep[]){
		while ( (*sep++= *k2++) == *k1++ );
		*sep = '\0';
	}

## ESTRATEGIA GERAL DE INSERCAO E REMOCAO

1. operar no bloco de dados sequenciais fazendo divisao, concatenacao e redistribuicao conforme necessario
2. se dividir, adiciona separador
3. se concatenar, remove separador (deleta pq n eh chave)
4. se redistribuir, muda separador