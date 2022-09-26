/*********************************************************************/
/**   ACH2001 - Introdução à Programação                            **/
/**   EACH-USP - Primeiro Semestre de 2020                          **/
/**   turma 02 - Luciano Antonio Digiampietri                       **/
/**                                                                 **/
/**   Terceiro Exercício-Programa                                   **/
/**                                                                 **/
/**   Sungwon Yoon                                 9822261          **/
/**                                                                 **/
/**   07-05-2020                                                    **/
/*********************************************************************/

/*
	Jogo da Velha - programa para verificar o status de um jogo.
	
	Lista de Status calculado:
    0 - Jogo não iniciado: o tabuleiro está 'vazio', isto é sem peças X e O;
    1 - Jogo encerrado1: o primeiro jogador (que usa as peças X) é o ganhador;
    2 - Jogo encerrado2: o segundo jogador (que usa as peças O) é o ganhador;
    3 - Jogo encerrado3: empate - todas as casas do tabuleiro estáo preenchidas com X e O, mas nenhum dos jogadores ganhou;
    4 - Jogo já iniciado e em andamento: nenhuma das alternativas anteriores.	
*/

public class JogoDaVelha {
	static final char pecaX = 'X';
	static final char pecaY = 'O';
	static final char espacoVazio = ' ';

	/*
		Determina o status de uma partida de Jogo da Valha
		
		Entrada:
			tabuleiro - matriz 3x3 de caracteres representando uma partida valida de Jogo da Velha
			
		Saída:
			um inteiro contendo o status da partida (valores válidos de zero a quatro)
	*/
	static int verificaStatus(char[][] tabuleiro) {
		int status;

		/* 
			Se o tabuleiro estiver vazio, retorna 0
			Caso contrário, prossegue a próxima verificação
		*/
		if (verificaVazio(tabuleiro)) return 0;

		/* 
			Verifica as três linhas do tabuleiro
			Se não encontrar bingo, prossegue a próxima verificação
		*/
		status = verificaLinhas(tabuleiro);
		if (status != -1) return status;
		
		/*
			Verifica as três colunas do tabuleiro
			Se não encontrar bingo, prossegue a próxima verificação
		*/
		status = verificaColunas(tabuleiro);
		if (status != -1) return status;

		/*
			Verifica as duas diagonais do tabuleiro
			Se não encontrar bingo, prossegue a próxima verificação
		*/
		status = verificaDiagonais(tabuleiro);
		if (status != -1) return status;

		/*
			Verifica se houve empate
			Se não, como insatisfez todas as condições acima, assume-se que o jogo está em andamento 
		*/
		if (verificaEmpate(tabuleiro)) return 3;
		return 4;

	}

	/*
		Verifica se há espaço vazio no tabuleiro
		Se encontrar um não-vazio, imediatamente retorna false
	*/
	static boolean verificaVazio (char[][] tabuleiro){
		for (int i = 0; i < 3; i++){
			for (char casa : tabuleiro[i]){
				if (casa != espacoVazio) return false;
			}
		}

		return true;
	}

	/*
		Apenas verifica se todas as casas estão preenchidas,
		dado que todas as condições de bingo foram previamente verificadas na função verificaStatus
		Se encontrar uma casa vazia, imediatamente retorna false
	*/
	static boolean verificaEmpate (char[][] tabuleiro){
		for (int i = 0; i < 3; i++){
			for (char casa : tabuleiro[i]){
				if (casa == espacoVazio) return false;
			}
		}

		return true;
	}

	/* 
		Verifica as três linhas do tabuleiro
		Se a casas de uma linha forem todas iguais e for 'X' retorna 1
		Se a casas de uma linha forem todas iguais e for 'O' retorna 2
		Se não, retorna -1
	*/
	static int verificaLinhas (char[][] tabuleiro){
		for (int i = 0; i < 3; i++){
			if (tabuleiro[i][0] == tabuleiro[i][1] && tabuleiro[i][1] == tabuleiro[i][2]){
				if (tabuleiro[i][0] == pecaX) return 1;
				if (tabuleiro[i][0] == pecaY) return 2;
			}
		}

		return -1;
	}

	/* 
		Verifica as três colunas do tabuleiro
		Se a casas de uma coluna forem todas iguais e for 'X' retorna 1
		Se a casas de uma coluna forem todas iguais e for 'O' retorna 2
		Se não, retorna -1
	*/
	static int verificaColunas (char[][] tabuleiro){
		for (int i = 0; i < 3; i++){
			if (tabuleiro[0][i] == tabuleiro[1][i] && tabuleiro[1][i] == tabuleiro[2][i]){
				if (tabuleiro[0][i] == pecaX) return 1;
				if (tabuleiro[0][i] == pecaY) return 2;
			}
		}

		return -1;
	}
	
	/* 
		Verifica as duas diagonais do tabuleiro
		Se a casas de uma diagonal forem todas iguais e for 'X' retorna 1
		Se a casas de uma diagonal forem todas iguais e for 'O' retorna 2
		Se não, retorna -1
	*/
	static int verificaDiagonais (char[][] tabuleiro){
		if (tabuleiro[0][0] == tabuleiro[1][1] && tabuleiro[1][1] == tabuleiro[2][2]){
			if (tabuleiro[0][0] == pecaX) return 1;
			if (tabuleiro[0][0] == pecaY) return 2;
		}

		if (tabuleiro[0][2] == tabuleiro[1][1] && tabuleiro[1][1] == tabuleiro[2][0]){
			if (tabuleiro[0][2] == pecaX) return 1;
			if (tabuleiro[0][2] == pecaY) return 2;
		}

		return -1;
	}
	

	public static void main(String[] args) {

		char[][] tab0 = {{' ',' ',' '},{' ',' ',' '},{' ',' ',' '}};
		char[][] tab1 = {{'X','X','X'},{'O','O',' '},{' ',' ',' '}};
		char[][] tab2 = {{'O','X','X'},{'X','O','O'},{' ',' ','O'}};
		char[][] tab3 = {{'O','X','X'},{'X','O','O'},{'O','X','X'}};
		char[][] tab4 = {{' ',' ',' '},{'X','O','X'},{' ',' ',' '}};

		System.out.println("Status calculado: " + verificaStatus(tab0));
		System.out.println("Status esperado para o tabuleiro0: 0\n");

		System.out.println("Status calculado: " + verificaStatus(tab1));
		System.out.println("Status esperado para o tabuleiro1: 1\n");

		System.out.println("Status calculado: " + verificaStatus(tab2));
		System.out.println("Status esperado para o tabuleiro2: 2\n");
		
		System.out.println("Status calculado: " + verificaStatus(tab3));
		System.out.println("Status esperado para o tabuleiro1: 3\n");
		
		System.out.println("Status calculado: " + verificaStatus(tab4));
		System.out.println("Status esperado para o tabuleiro4: 4\n");

	}
}
