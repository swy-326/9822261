"""
  AO PREENCHER ESSE CABEÇALHO COM O MEU NOME E O MEU NÚMERO USP, 
  DECLARO QUE SOU O ÚNICO AUTOR E RESPONSÁVEL POR ESSE PROGRAMA. 
  TODAS AS PARTES ORIGINAIS DESSE EXERCÍCIO-PROGRAMA (EP) FORAM 
  DESENVOLVIDAS E IMPLEMENTADAS POR MIM SEGUINDO AS INSTRUÇÕES
  DESSE EP E QUE PORTANTO NÃO CONSTITUEM DESONESTIDADE ACADÊMICA
  OU PLÁGIO.  
  DECLARO TAMBÉM QUE SOU RESPONSÁVEL POR TODAS AS CÓPIAS DESSE
  PROGRAMA E QUE EU NÃO DISTRIBUI OU FACILITEI A SUA DISTRIBUIÇÃO.
  ESTOU CIENTE QUE OS CASOS DE PLÁGIO E DESONESTIDADE ACADÊMICA
  SERÃO SEVERAMENTE PUNIDOS.
  ENTENDO QUE EPS SEM ASSINATURA NÃO SERÃO CORRIGIDOS E, AINDA
  ASSIM, PODERÃO SER PUNIDOS POR DESONESTIDADE ACADÊMICA.

  Nome : Sungwon Yoon
  Número USP : 9822261
  Curso : Letras
  Exercício-Programa EP4

  Referências: Com exceção das rotinas que podem ser fornecidas
  no enunciado ou em sala de aula, caso você tenha utilizado
  alguma referência, liste-as abaixo para que o seu programa não
  seja considerado plágio ou irregular.
"""

#-----------------------------------------------------------------------
# DEFINIÇÃO DAS CONSTANTES
#-----------------------------------------------------------------------

TAMANHO =  8
BOLA    = 'O'
XIS     = 'X'
VAZIA   = '.'
MOLDURA = '*'

#-----------------------------------------------------------------------

def main():
    '''
    Jogo Othello
    '''
      
    print("\nBem vindo ao jogo Otelo/Reversi!")
    print("\nJogador: X \nComputador: O")

    matriz = inicialize_tabuleiro()
    exibe_tabuleiro(matriz)

    quantas_o_x_imprime(matriz)

    while existe_movimento(matriz, XIS) or existe_movimento(matriz, BOLA):
        if existe_movimento(matriz, XIS):
            vez_de_xis(matriz)
        if existe_movimento(matriz, BOLA):
            vez_da_bola(matriz)

    print("\n\n PARTIDA TERMINADA")
    print()

    quem_venceu(matriz)


#-----------------------------------------------------------------------







   
#-----------------------------------------------------------------------

def cria_matriz(nlin, ncol, valor):
    '''  (int, int, str) -> matriz
    Cria e torna uma matriz    
    '''
    
    i = 0
    matriz = []
    while i <= nlin:
        linha = []
        j = 0
        while j <= ncol:
            linha.append(valor)
            j += 1
        matriz.append(linha)
        i += 1
    return matriz

#-----------------------------------------------------------------------

def inicialize_tabuleiro():
    '''  ( ) -> matriz

    Cria e retorna uma matriz (com uma moldura) com a configuração
    inicial de um tabuleiro para o jogo Otelo.
    Obs.: Utiliza as constantes definidas no início do programa.
    '''

    n = TAMANHO + 1
    m = TAMANHO // 2
    matriz = cria_matriz(n, n, VAZIA)
    i = 0

    while i <= n:
        matriz[0][i] = VAZIA
        matriz[n][i] = VAZIA
        i += 1

    j = 0
    while j <= n:
        matriz[j][0] = VAZIA
        matriz[j][n] = VAZIA
        j += 1
    
    matriz[m][m] = matriz[m+1][m+1] = BOLA
    matriz[m][m+1] = matriz[m+1][m] = XIS


    return matriz


 
#-----------------------------------------------------------------------
   
def exibe_tabuleiro(tabuleiro):
    '''  (matriz) -> NoneType

    Recebe uma matriz representando um tabuleiro do jogo Otelo
    e imprime esse tabuleiro com as linhas e colunas numeradas
    e tracejadas para facilitar a visualização do usuário.
    Obs.: Veja o formato desta impressão nos arquivos com exemplos 
    de saída.
    '''
 
    print()
    print('      ', end='')
    i = 1
    while i <= TAMANHO:
        print('   %d  ' %i, end='')
        i += 1
    print()
   
    print('      ', end='')
    i = 1
    while i <= TAMANHO:
        print('+-----', end='')
        i += 1
    print('+')

    i = 1 
    while i <= TAMANHO:
        print('%5d ' %i, end='')
        j = 1
        while j <= TAMANHO:
            print("|  %s  " %(tabuleiro[i][j]), end='')
            j += 1
        print('|')
        
        print('      ', end='')
        j = 1
        while j <= TAMANHO:
            print('+-----', end='')
            j += 1
        print('+')
 
        i += 1

    print()
    
#----------------------------------------------------------------------
   
def numero_reversoes(tabuleiro, jogador, lin, col):
    '''  (matriz, str, int, int) -> int

    Recebe uma matriz tabuleiro, uma marca jogador e uma posição
    (lin, col).
    A função deve retornar 0 (zero), se (lin, col) é uma posição 
    fora do tabuleiro ou se esta posição já tiver uma marca
    ou se o jogador não puder colocar a sua marca nessa posição.
    Em caso contrário, a função retorna o número total de 
    reversões que serão realizadas se o jogador puder colocar
    a sua marca na posição (lin, col).
    '''

    opos = troca_jogador(jogador)

    cont = 0
    total = 0

    if tabuleiro[lin][col] != VAZIA:
        return 0
    if lin > TAMANHO or lin < 1 or col > TAMANHO or col < 1:
        return 0

    i = -1
    while i <= 1:
        j = -1
        while j <= 1:
            if i != 0 or j != 0:
                l = lin + i
                c = col + j
                if tabuleiro[l][c] == opos:
                    while tabuleiro[l][c] == opos:
                        cont += 1
                        l += i
                        c += j
                    if tabuleiro[l][c] == jogador and cont > 0:
                        total += cont
            cont = 0
            j += 1
        i += 1


    return total


        
#----------------------------------------------------------------------

def existe_movimento(tabuleiro, jogador):
    '''  (matriz, str) -> bool

    Recebe uma matriz tabuleiro e uma marca jogador.
    A função retorna True, se existir algum movimento válido para o
    jogador; em caso contrário, retorna False.
    '''

    cont_total = 0
    n = 0


    for linha in tabuleiro:
        for elemento in linha:
            if elemento == VAZIA:
                n += 1
    m = n
    if m == 0:
        return 0


    i = 1
    while i <= TAMANHO:
        j = 1
        while j <= TAMANHO:
            cont = numero_reversoes(tabuleiro, jogador, i, j)
            cont_total += cont 
            j += 1
        i += 1

    if cont_total == 0:
        return False
    else:
        return True

        
#----------------------------------------------------------------------
   
def estrategia_jogo(tabuleiro, jogador):
    '''  (matriz, str) -> int, int, int

    Recebe uma matriz tabuleiro e uma marca jogador.
    Nesta função, supõe-se que jogador é o programa.
    A função determina uma posição (lin, col) para o jogador colocar
    a sua marca, de modo que o número de reversões seja o maior 
    possível, e retorna o número de reversões, lin e col.
    Obs.: A função pode supor que, quando ela é chamada, existe algum
    movimento válido para jogador.
    '''
    
    maxcont = 0


    i = 1
    while i <= TAMANHO:
        j = 1
        while j <= TAMANHO:
            if tabuleiro[i][j] == VAZIA:
                cont = numero_reversoes(tabuleiro, jogador, i, j)
                if cont > maxcont:
                    maxcont = cont
                    maxi = i
                    maxj = j
            j += 1
        i += 1
                
    return maxcont, maxi, maxj
           
#----------------------------------------------------------------------
   
def coloque_reverta_marca(tabuleiro, jogador, lin, col):  
    '''  (matriz, str, int, int) -> Nonetype

    Recebe uma matriz tabuleiro, uma marca jogador e uma posição
    (lin, col) em que o jogador pode colocar a sua marca.
    A função coloca a marca do jogador na posição (lin, col) do
    tabuleiro e faz todas as reversões necessárias.
    '''

    tabuleiro[lin][col] = jogador
    opos = troca_jogador(jogador)
    cont = 0

    i = -1
    while i <= 1:
        j = -1
        while j <= 1:
            if i != 0 or j != 0:    
                l = x = lin + i
                c = y = col + j
                if tabuleiro[l][c] == opos:
                    while tabuleiro[l][c] == opos:
                        l += i
                        c += j
                        cont += 1
                    if tabuleiro[l][c] == jogador and cont > 0:
                        #tabuleiro[x][y] = jogador
                        while x!= l or y != c:  
                            tabuleiro[x][y] = jogador
                            x += i
                            y += j
            j += 1
        i += 1
             
#----------------------------------------------------------------------
   
def troca_jogador(jogador):
    '''  (str) -> str
    Recebe uma marca jogador e retorna a marca de seu adversário.
    '''

    if jogador == XIS:
        return BOLA
    else:
        return XIS
             
#----------------------------------------------------------------------

def quantas_o_x_imprime (tabuleiro):
    '''  (matriz) -> NoneType
    Recebe a matriz, conta e imprime quantos O e quantos X tem na matriz
    '''

    cont_o = 0
    cont_x = 0

    for linha in tabuleiro:
        for elemento in linha:
            if elemento == BOLA:
                cont_o += 1
            elif elemento == XIS:
                cont_x += 1

    print("\n'X' tem %d marcas no tabuleiro" %(cont_x))
    print("'O' tem %d marcas no tabuleiro" %(cont_o))

#----------------------------------------------------------------------

def vez_de_xis(tabuleiro):
    '''  (matriz) -> NoneType
    Recebea a matriz e faz todas as ações possíveis para o jogador 'X'
    '''

    print("\n--->  Jogador da vez é 'X'.")

    lin = int(input("\nDigite a linha da posição em que pretende jogar: "))
    col = int(input("Digite a coluna da posição em que pretende jogar: "))

    oqtem = tabuleiro[lin][col]
    naomexe = numero_reversoes(tabuleiro, XIS, lin, col)


    if lin > TAMANHO or lin < 1 or col > TAMANHO or col < 1 or oqtem != VAZIA or naomexe == 0:
        print("\nJogador 'X' não pode jogar na posição (%d, %d)." %(lin, col))

    else:
        print("\nJogador 'X' colocou sua marca na posição (%d, %d)." %(lin, col))
        n = numero_reversoes(tabuleiro, XIS, lin, col)


        coloque_reverta_marca(tabuleiro, XIS, lin, col)

        print("%d 'O'(s) revertido(s) para 'X'(s)." %(n))

    print()
    exibe_tabuleiro(tabuleiro)
    quantas_o_x_imprime(tabuleiro)


#----------------------------------------------------------------------

def vez_da_bola(tabuleiro):
    '''  (matriz) -> NoneType
    Recebea a matriz e faz todas as ações possíveis para o jogador 'O'
    '''
    
    print("\n--->  Jogador da vez é 'O'.")
    
    qnt, lin, col = estrategia_jogo(tabuleiro, BOLA)
    print("\nJogador 'O' colocou sua marca na posição (%d, %d)." %(lin, col))
    
    coloque_reverta_marca(tabuleiro, BOLA, lin, col)
    print("%d 'X'(s) revertido(s) para 'O'(s)." %(qnt))

    print()
    exibe_tabuleiro(tabuleiro)
    quantas_o_x_imprime(tabuleiro)


#----------------------------------------------------------------------

def quem_venceu(tabuleiro):
    '''  (matriz) -> NoneType
    Recebe a matriz e determina e imprime quem é o vencedor
    '''

    cont_o = 0
    cont_x = 0

    for linha in tabuleiro:
        for elemento in linha:
            if elemento == BOLA:
                cont_o += 1
            elif elemento == XIS:
                cont_x += 1

    if cont_x > cont_o:
        print("  Jogador 'X' venceu!!!")
    elif cont_o > cont_x:
        print("  Jogador 'O' venceu!!!")
    else:
        print("Jogadores 'X' e 'O' emprataram.")


#----------------------------------------------------------------------


main()
