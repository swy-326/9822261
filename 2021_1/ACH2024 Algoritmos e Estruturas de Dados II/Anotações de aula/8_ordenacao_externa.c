ORDENACAO EXTERNA POR INTERCALACAO



# ORDENACAO
- ordenar um arquivo maior do que a memoria disponivel
- KeySort() - se a tabela de chaves for maior que a memoria disponivel, n funciona



# ORDENACAO EXTERNA POR INTERCALACAO 
- Ler arquivo em blocos (corrdias) que caiba em memoria, e ordenar
- Escrever cada corrida individualmente em arquivos temporarios
- Ler as corridas ordenadas gradativamente, e iintercalar
- Escrever um arquivo final unico ordenado
	=> processamento cossequencial


	┌     ┐		┌     ┐		┌     ┐
	│ 100 │		│ 020 │		│ 001 │  <= 이 맨 윗줄
	│ 111 │		│ 456 │		│ 390 │
	│ 515 │		│ 952 │		│ 700 │
	└     ┘		└     ┘		└     ┘

	[ 001 | 020 | 100 | ... ]



# INTERCALACAO
- ordenar cada corrida
- selecionar a menor proxChave em memoria, escreve-la na saida e ler uma nova proxChave ate esgotar todas as corridas


	Intercalacao de n corrdias previamente ordenadas em arquivos individuais

	// valores iniciais (simplificacao: o buffer proxChave armazena apenas 1 chave por corrida)
	// 원래는 laco 안에 laco 있어야댐. 여러 개 불러오니까
	for (int i = 0; i < n; i++){
		arq[i] = fopen(nome[i], "rw");
		proxChave[i] = INFINITO ; // se nao ler nada fica como infinito
		int lidos = fread(&proxChave[i], tam, buffersize, arq[i]); // le n itens no buffer
		// tam - tamanho de dados; buffersize - 1 pq eh vetor de inteiro
		if (lidos == 0) fclose(arq[i]);
	}


	// intercalacao
	while (true){

		arqAlvo = -1;							// qual arquivo que contem melhor/menor chave
		menorChave = INFINITO;					// qual eh essa chave?

		for (i = 0; i < n; i++){
			if (proxChave[i] < menorChave){		// pressupoe buffersize = 1. Certo seria usar um vetor
				arqAlvo = i;					// 1 eh a corrida de onde vai sair a chave escolhida
				menorChave = proxChave[i];
			}
		}

		if (arqAlvo == -1) return 0;			// acabaram-se todas as corridas

		printf("%d", proxChave[arqAlvo]);		// saida ordenada (deveria escrever em um arquivo) => guarda em buffer de escrita e insere em um unico fwrite
		proxChave[arqAlvo] = INFINITO;			// deixa corrida como INFINITO a menos que leia algo
		int lidos = fread(&proxChave[arqAlvo], tam, 1, arq[arqAlvo]);
		if (lidos == 0) fclose(arq[arqAlvo]);
	}



# CONVENCOES E CONFIGURACOES DE EXEMPLO
- Memoria interna (MI) de 1.5Mb
- 1 acesso ao arquivo = 30ms (seek+rotate)
- Simplificacao : DADOS OCUPAM POSICOES CONTIGUAS EM DISCO 		// n precisa de fseek
- Taxa de transferencia : 1500 bytes/ms 
- Buffering : 20Kb (i.e., um acesso ao disco a cada 20kb para escrita final na saida da intercalacao, evitando escrever chaves uma por uma)
- O buffer nao eh usado na ordenacao porque leitura e escrita sao em blocos



# PROBLEMA 1 : ORDENAR ARQUIVO DE 90MB
- Ordenacao 	
	Ler m = 60 corridas (90mb / 1.5mb)
	Escrever m = 60 corridas ordenadas		// em arquivo temporario
- Intercalacao
	Ler/intercalar as m = 60 corridas ordenadas		// ler fragmentos de cada corrida
	Escrever o arquivo final						// acumular no buffer de escrita e colocar no arquivo de volta


- Tabela 

	Transferencia eh sempre o tamamho do arquivo

	Passo 1 : ler o arquivo de 90mb inteiro
			  em m=60 blocos (ou corridas) de tamanho MI=1.5 cada
			  com transferencia de 1500bytes/s + tempo de acesso 30ms
			  e entao ordenar em memoria (sem considerar custo)

	Passo 2 : reescrever cada uma das 60 corridas ordenadas (totalizando 90mb)
			  com transferencia de 1500bytes/s
			  (sem uso de buffer de escrita ainda pq eh escrita em bloco)

	Passo 3 : ler m = 60 fragmentos de corridas, de tamanho MI/60 cada
			  (que eh o maximo de cada corrida que cabe simultaneamente em memoria (proxChave[]))
			  Sendo um arquivo de 90mb, sera realizado um total de 90mb / (MI/60) acessos ao disco
			  Mesma taxa de transferencia de 1500bytes/s

			  														// 코드에 있는 부분
┌─────────────────────────────────────────────────────────────────────────────────────────────────────────────┐
│          │          │                Ordenacao                  │       Intercalacao de m = 60 vias         │
├─────────────────────────────────────────────────────────────────────────────────────────────────────────────┤
│          │          │       Leitura       │       Escrita       │       Leitura       │       Escrita       │
├─────────────────────────────────────────────────────────────────────────────────────────────────────────────┤
│          │          │   Seek   │ Transfer │   Seek   │ Transfer │   Seek   │ Transfer │   Seek   │ Transfer │
├─────────────────────────────────────────────────────────────────────────────────────────────────────────────┤
│ Operacao │   90mb   │    60    │   90mb   │    60    │   90mb   │   3600   │   90mb   │   4500   │   90mb   │
├─────────────────────────────────────────────────────────────────────────────────────────────────────────────┤
│  Tempo   │││±8min││││   1.8s   │   60s    │   1.8s   │   60s    │   108s   │   60s    │   135s   │   60s    │
└─────────────────────────────────────────────────────────────────────────────────────────────────────────────┘
//           reposta          단순 곱하기       다시 쓰니까, 동일함     3600어디서 나왓나...




# PROBLEMA 2 : ORDENAR ARQUIVO DE 900MB
- Entrada eh 10 vezes maior que a do problema 1

- Tabela
	Passo 1 e 2 : ler o arquivo de 900MB inteiro, em m=600 corridas
				  ordenar e reescrever cada uma (totalizando 900mb)
				  com transferencia de 1500bytes/s
				  (sem uso de buffer de escrita ainda pq eh escrita em bloco)

	Passo 3 : ler m=600 corridas, de tamanho MI/600 cada 
			  (que eh o maximo de cada corrida que cabe simultaneamente em memoria (proxChave[]))
			  Sendo um arquivo de 900mb, sera realizado um total de 900mb / (MI/600) acessos ao disco
			  Mesma taxa de transferencia de 1500bytes/s



┌─────────────────────────────────────────────────────────────────────────────────────────────────────────────┐
│          │          │                Ordenacao                  │       Intercalacao de m = 600 vias        │
├─────────────────────────────────────────────────────────────────────────────────────────────────────────────┤
│          │          │       Leitura       │       Escrita       │       Leitura       │       Escrita       │
├─────────────────────────────────────────────────────────────────────────────────────────────────────────────┤
│          │          │   Seek   │ Transfer │   Seek   │ Transfer │   Seek   │ Transfer │   Seek   │ Transfer │
├─────────────────────────────────────────────────────────────────────────────────────────────────────────────┤
│ Operacao │  900mb   │   600    │  900mb   │   600    │  900mb   │  360000  │  900mb   │   45000  │   90mb   │
├─────────────────────────────────────────────────────────────────────────────────────────────────────────────┤
│  Tempo   ││││±4h│││││   18s    │  600s    │   18s    │  600s    │  10800s  │  600s    │   1350s  │   600s   │
└─────────────────────────────────────────────────────────────────────────────────────────────────────────────┘



# ONDE ESTA O PROBLEMA
- Claramente na fase de leitura do algoritmo de intercalacao (passo 3) // comparar todas as n chaves
- Mais especificamente, o problema eh a necessidade de manter fragmentos de todas as corridas \
simultaneamente em memoria, para entao escolher a proxima chave a ser escrita na saida
- Arquivos grandes = muitas corridas = pequenos fragmentos de cada uma
- Se os fragmentos sao pequenos, a leitura completa vai exigir muitos acessos \
ate esgotar cada corrida (900mb = 360mil seeks no exemplo)
- E o tempo de seek eh justamente o problema



# QUAL A SOLUCAO
- Reduzir o numero de acessos no passo 3 (leitura de intercalacao)
- Estrategia : ao inves de intercalar todas as m corridas de uma unica vez, intercalar em fases
	fase 1 : 600 corridas intercaladas em 20 grupos x 30 corridas cada
	fase 2 : intercalar as 20 corridas "longas" resultantes da fase 1
- Estrategia em duas fases exige o dobro de leitura e escrita, mas ainda assim compensa
- Na configuracao exemplo, a ordenacao do arquivo de 900mb levaria ±2h