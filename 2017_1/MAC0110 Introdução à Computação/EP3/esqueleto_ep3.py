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
  Exercício-Programa 3

  Referências: Com exceção das rotinas que podem ser fornecidas
  no enunciado ou em sala de aula, caso você tenha utilizado
  alguma referência, liste-as abaixo para que o seu programa não
  seja considerado plágio ou irregular.

"""

#---------------------------------------------------------------------

#  Módulo necessário para usar a função math.sqrt 
import math  

#  Definindo algumas constantes 
NUM_PROVAS = 3
NUM_EPS = 4

#---------------------------------------------------------------------

def main():
    nomeArqEntra = input("Digite o nome do arquivo com os dados de entrada: ")
    arqEntra = open(nomeArqEntra, 'r', encoding='utf-8')
        
    nomeArqSai = input("Digite o nome do arquivo de saída: ")
    arqSai = open(nomeArqSai, 'w', encoding='utf-8')
    
    # escreve no arquivo de saída uma introdução
    escreve_introducao(arqSai)
            
    # obtém as informações gerais da 1a. linha do arquivo de entrada
    numAlunos, pesosProvas, pesosEps, pesoMediaProvas, pesoMediaEps   \
                                       = obtem_info_gerais(arqEntra)
    
    #... escreve no arquivo de saída as informações gerais lidas
    #    e também os números de provas e de eps.
    #    Escreve também uma linha com os rótulos das infos dos alunos.
    # ...
    escreve_info_gerais(arqSai, numAlunos, NUM_PROVAS, NUM_EPS, pesosProvas, pesosEps, pesoMediaProvas, pesoMediaEps)
    
    
    #-----------------------------------------------------------------
    #... cria listas, todas com numAlunos elementos, para 
    #    nomesAlunos, notasP1, notasP2, notasP3, mediasProvas,
    #    notasEP1, notasEP2, notasEP3, notasEP4, mediasEps,
    #    mediasAlunos, situacaoAlunos.
    #    A i-ésima posição de cada uma dessas listas representará
    #    a informação correspondente do i-ésimo aluno.
    # ...

    #-----------------------------------------------------------------
    #... Para cada aluno deve fazer o seguinte:
    
        # lê de uma linha do arquivo de entrada as infos de um aluno 
        linhaArq = arqEntra.readline()
        # linhaArq é um string com o conteúdo da linha lida do arquivo
        infoAluno = linhaArq.split(';')
        # infoAluno é uma lista de strings
   
        #... atualiza a lista infoAluno, substituindo os strings
        #    que representam as notas de provas e de eps por números
        #    em ponto flutuante
        #...

        #-------------------------------------------------------------
        #... determina as três médias de um aluno
        #    (mediaProvasAluno, mediaEpsAluno e mediaAluno)
        #    e sua situação (situacao)
        #...
        
        #-------------------------------------------------------------
        #... escreve no arquivo de saída todas as infos de um aluno
        #...
        
        #-------------------- ----------------------------------------
        #... atualiza as listas a seguir com as infos de um aluno: 
        #    nomesAlunos, notasP1, notasP2, notasP3, mediasProvas, 
        #    notasEP1, notasEP2, notasEP3, notasEP4, mediasEps,
        #    mediasAlunos, situacaoAlunos
        #...

    #-----------------------------------------------------------------
 
    arqEntra.close()
    
    #-----------------------------------------------------------------
    #... cria uma lista, mediasTurma, com as médias da turma em
    #    cada uma das provas, seguida da média das médias de provas,
    #    seguida das médias da turma em cada um dos eps,
    #    seguida da média das médias de eps e seguida da média das
    #    médias dos alunos
    #...

    #... escreve no arquivo de saída as médias de mediasTurma
    #...    
   
    #-----------------------------------------------------------------
    #... cria uma lista, desviosPadraoTurma, com os desvios padrão
    #    da turma em cada uma das provas, seguido do desvio padrão
    #    das médias de provas, seguido do desvio padrão da turma em
    #    cada um dos eps, seguido do desvio padrão das médias de eps
    #    e seguido do desvio padrão das médias dos alunos
    #...

    #... escreve no arquivo de saída os desvios padrão de
    #    desviosPadraoTurma
    #...

    #-----------------------------------------------------------------
    #... determina as quantidades, numAlunosAp, numAlunosRec e
    #    numAlunosRep, respectivamente, de alunos aprovados, em
    #    recuperação e reprovados
    #...

    #... escreve no arquivo de saída essas quantidades e as
    #    porcentagens correspondentes
    #...
    
    #-----------------------------------------------------------------
    #... escreve no arquivo de saída uma listagem dos alunos (com
    #    nome, média de provas, média de eps e média final) que
    #    foram aprovados
    #...
   
    #... escreve no arquivo de saída uma listagem dos alunos (com
    #    nome, média de provas, média de eps e média final) que
    #    ficaram de recuperação
    #...
    
    #... escreve no arquivo de saída uma listagem dos alunos (com
    #    nome, média de provas, média de eps e média final) que
    #    foram reprovados
    #...
    
    #-----------------------------------------------------------------

    arqSai.close()
 
######################################################################
#.........................  Outras funções  ..........................
#.....................................................................

def escreve_introducao(arqsai):
    ''' (arquivo) -> NoneType
    
    Recebe um arquivo aberto para escrita.
    Escreve em arqsai um cabeçalho com seu nome completo, número
    USP e curso. 
    Em seguida, escreva uma descrição suscinta deste ep3.
    '''
    content = "Nome : Sungwon Yoon \nNúmero Usp : 9822261 \nCurso : Letras \n"
    content += "Este programa calcula a média final dos alunos de uma turma, \
    algumas médias e desvios padrão relacionados à turma e algumas listagens específicas \
    da turma."
    arqsai.write(content)
    
#.....................................................................

def obtem_info_gerais(arqentra):
    ''' (arquivo) -> int, list, list, int, int

    Recebe um arquivo aberto para leitura.
    Lê da primeira linha de arqentra as informações gerais:
    o número de alunos, os pesos das provas, os pesos dos eps, 
    o peso da média de provas e o peso da média de eps.
    Cria duas listas: uma com os pesos das provas e outra
    com os pesos dos eps.
    Retorna todas essas informações na ordem especificada.
    '''

    lista_entra = arqentra.readline()
    info_pesos_provas = []
    info_pesos_eps = []
    i = 0
    elementos = lista_entra.split(;)
    while i < 1:
    	info_num_alunos = elementos
    	i += 1
    while i < 4:
    	elementos = lista_entra.split(;)
    	info_pesos_provas.append(elementos)
    	i += 1
    while i < 8:
    	elementos = lista_entra.split(;)
    	info_pesos_eps.append(elementos)
    	i += 1
    while i < 9:
    	elementos = lista_entra.split(;)
    	info_peso_media_provas = elementos
    	i += 1
    while i < 10:
    	elementos = lista_entra.split(;)
    	info_peso_media_eps = elementos
    	i += 1
    return info_num_alunos, info_pesos_provas, info_pesos_eps, info_peso_media_provas, info_peso_media_eps

      
#.....................................................................

def escreve_info_gerais(arqsai, num_alunos, num_provas, num_eps,
     pesos_provas, pesos_eps, peso_media_provas, peso_media_eps):
    ''' (arquivo, int, int, int, list, list, int, int) -> NoneType

    Recebe um arquivo de saída e as informações gerais:
    os números de alunos, de provas e de eps, os pesos das provas
    e dos eps e os pesos das médias de provas e de eps.
    Escreve esssas informações em arqsai.
    Escreve também uma linha com os rótulos das info dos alunos.

    '''
    
    # escreva a sua função a seguir
    
#.....................................................................

def cria_lista(n, valor):
    ''' (int, objeto) -> list

    Cria uma lista com n elementos, todos iguais a valor, e 
    retorna essa lista.
    '''
    
    # escreva a sua função a seguir
    
#.....................................................................

def determina_medias_situacao_aluno(info_aluno, pesos_provas, pesos_eps,
                                    peso_media_provas, peso_media_eps):
    ''' (list, list, list, int, int) -> float, float, float, str
    
    Recebe três listas: info_aluno, pesos_provas e pesos_eps,
    e dois inteiros: peso_media_provas e peso_media_eps.
    Calcula e retorna a média de provas, a média de eps, a
    média desse aluno, e sua situação ("Ap" ou "Rec" ou "Rep").
    Obs.: Use a função media_notas_aluno para determinar a média
          de provas e também para determinar a média de eps.
    '''

    # escreva a sua função a seguir
   
#.....................................................................

def media_notas_aluno(notas, pesos):
    ''' (list, list) -> float
   
    Recebe duas listas, notas e pesos, com as notas e os 
    respectivos pesos.
    Retorna a média ponderada com esses valores.
    Obs.: Cuidado com os valores -1.0.
    '''
 
    # escreva a sua função a seguir
  
#.....................................................................

def determina_media_turma(notas):
    ''' (list) -> float
   
    Recebe uma lista notas com as notas de uma turma.
    Retorna a média aritmética dos valores em notas.
    Obs.: Cuidado com os valores -1.0.
    '''
    
    # escreva a sua função a seguir
  
#.....................................................................

def determina_desvio_padrao(notas, media):
    ''' (list, float) -> float
   
    Recebe uma lista notas com as notas de uma turma e 
    um número real media com a média dessas notas.
    Retorna o desvio padrão dos valores em notas.
    Obs.: Cuidado com os valores -1.0.
    '''
    
    # escreva a sua função a seguir
    
#.....................................................................

def escreve_info_aluno(arqsai, info_aluno, media_provas_aluno,
                       media_eps_aluno, media_aluno, situacao):
    ''' (arquivo, list, float, float, float, str) -> NoneType

    Recebe um arquivo de saída e todas as informações de um aluno.
    Escreve todas essas informações numa linha de arqsai,
    utilizando o formato especificado.
    '''
  
    # escreva a sua função a seguir
 
#.....................................................................

def escreve_medias_turma(arqsai, medias_turma):
    ''' (arquivo, list) -> NoneType

    Recebe um arquivo de saída e uma lista contendo a média da turma 
    em cada prova, a média das médias de provas, a média da turma em
    cada ep, a média das médias de eps e a média das médias dos alunos.
    Esta função escreve todas essas informações numa linha de arqsai,
    utilizando o formato especificado.
    '''
 
    # escreva a sua função a seguir
    
#.....................................................................

def escreve_desvios_padrao_turma(arqsai, desvios_turma):
    ''' (arquivo, list) -> NoneType

    Recebe um arquivo de saída e uma lista contendo o desvio padrão 
    da turma em cada prova, o desvio padrão das médias de provas, o 
    desvio padrão da turma em cada ep, o desvio padrão das médias de
    eps e o desvio padrão das médias dos alunos.
    Esta função escreve todas essas informações numa linha de arqsai,
    utilizando o formato especificado.
    '''
 
    # escreva a sua função a seguir
    
#.....................................................................
 
def conta_alunos_ap_rec_rep(s):
    '''  (list) -> int, int, int

    Recebe uma lista s com a situação dos alunos.
    Retorna os números de alunos aprovados, em recuperação e reprovados.
    '''
  
    # escreva a sua função a seguir

#.....................................................................

def escreve_contadores_porcentagens(arqsai, num_alunos, num_alunos_ap,
                                    num_alunos_rec, num_alunos_rep):
    ''' (arquivo, int, int, int, int) -> NoneType

    Recebe um arquivo de saída, o número de alunos e os números de 
    alunos aprovados, em recuperação e reprovados.
    Esta função escreve em arqsai os números de alunos aprovados,
    em recuperação e reprovados, cada um deles seguido pela sua
    porcentagem em relação ao número total de alunos, utilizando 
    o formato especificado.
    '''
 
    # escreva a sua função a seguir

#.....................................................................

def escreve_lista_alunos_mesma_situacao(arqsai, situacoes, nomes,
                         medias_provas, medias_eps, medias_aluno,
                                    uma_situacao, num_alunos_sit):
    ''' (arquivo, list, list, list, list, list, str, int) -> NoneType

    Recebe um arquivo de saída, uma lista com a situação dos alunos, 
    uma lista com os nomes dos alunos, uma lista com as médias de
    provas, uma lista com a média de eps, uma lista com as médias
    finais dos alunos, um string ("Ap" ou "Rec" ou "Rep") e um
    inteiro.
    Esta função escreve em arqsai uma listagem com os nomes dos 
    num_alunos_sit alunos que ficaram na situação uma_situacao, 
    e as suas respectivas médias de provas, de eps e finais.
    '''

    # escreva a sua função a seguir

#.....................................................................

main()
