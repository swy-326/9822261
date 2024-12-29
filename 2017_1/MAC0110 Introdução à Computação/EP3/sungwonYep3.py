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
    lista_criada = cria_lista(numAlunos, 0)

    #-----------------------------------------------------------------
    #... Para cada aluno deve fazer o seguinte:
    i = 0
    while i < numAlunos:
    
        # lê de uma linha do arquivo de entrada as infos de um aluno 
        linhaArq = arqEntra.readline()
        # linhaArq é um string com o conteúdo da linha lida do arquivo
        infoAluno = linhaArq.split(';')
        # infoAluno é uma lista de strings
   
        #... atualiza a lista infoAluno, substituindo os strings
        #    que representam as notas de provas e de eps por números
        #    em ponto flutuante
        #...

        j = 1
        while j < 8:
            infoAluno[j] = float(infoAluno[j])
            j += 1


        #-------------------------------------------------------------
        #... determina as três médias de um aluno
        #    (mediaProvasAluno, mediaEpsAluno e mediaAluno)
        #    e sua situação (situacao)
        #...
        mediaProvasAluno, mediaEpsAluno, mediaAluno, situacao \
        = determina_medias_situacao_aluno(infoAluno, pesosProvas, pesosEps, pesoMediaProvas, pesoMediaEps)

        
        #-------------------------------------------------------------
        #... escreve no arquivo de saída todas as infos de um aluno
        #...
        escreve_info_aluno(arqSai, infoAluno, mediaProvasAluno, mediaEpsAluno, mediaAluno, situacao)
        #-------------------- ----------------------------------------
        #... atualiza as listas a seguir com as infos de um aluno: 
        #    nomesAlunos, notasP1, notasP2, notasP3, mediasProvas, 
        #    notasEP1, notasEP2, notasEP3, notasEP4, mediasEps,
        #    mediasAlunos, situacaoAlunos
        #... /*이름바꾸기*/

        lista_criada[0][i] = infoAluno[0]
        lista_criada[1][i] = infoAluno[1]
        lista_criada[2][i] = infoAluno[2]
        lista_criada[3][i] = infoAluno[3]
        lista_criada[4][i] = mediaProvasAluno
        lista_criada[5][i] = infoAluno[4]
        lista_criada[6][i] = infoAluno[5]
        lista_criada[7][i] = infoAluno[6]
        lista_criada[8][i] = infoAluno[7]
        lista_criada[9][i] = mediaEpsAluno   
        lista_criada[10][i] = mediaAluno
        lista_criada[11][i] = situacao

        i += 1

    #-----------------------------------------------------------------
 
    arqEntra.close()
    
    #-----------------------------------------------------------------
    #... cria uma lista, mediasTurma, com as médias da turma em
    #    cada uma das provas, seguida da média das médias de provas,
    #    seguida das médias da turma em cada um dos eps,
    #    seguida da média das médias de eps e seguida da média das
    #    médias dos alunos
    #...
    i = 1
    mediasTurma = []
    while i < 11:
        media_calculada = determina_media_turma(lista_criada[i])
        mediasTurma.append(media_calculada)
        i += 1


    #... escreve no arquivo de saída as médias de mediasTurma
    #...    
    escreve_medias_turma(arqSai, mediasTurma)
   
    #-----------------------------------------------------------------
    #... cria uma lista, desviosPadraoTurma, com os desvios padrão
    #    da turma em cada uma das provas, seguido do desvio padrão
    #    das médias de provas, seguido do desvio padrão da turma em
    #    cada um dos eps, seguido do desvio padrão das médias de eps
    #    e seguido do desvio padrão das médias dos alunos
    #...
    desviosPadraoTurma = []
    i = 1
    j = 0
    while i < 11:
        calculada = determina_desvio_padrao(lista_criada[i], mediasTurma[j])
        desviosPadraoTurma.append(calculada)
        i += 1
        j += 1
    
    #... escreve no arquivo de saída os desvios padrão de
    #    desviosPadraoTurma
    #...
    escreve_desvios_padrao_turma(arqSai, desviosPadraoTurma)

    #-----------------------------------------------------------------
    #... determina as quantidades, numAlunosAp, numAlunosRec e
    #    numAlunosRep, respectivamente, de alunos aprovados, em
    #    recuperação e reprovados
    #...
    numAlunosAp, numAlunosRec, numAlunosRep = conta_alunos_ap_rec_rep(lista_criada[11])

    #... escreve no arquivo de saída essas quantidades e as
    #    porcentagens correspondentes
    #...
    escreve_contadores_porcentagens(arqSai, numAlunos, numAlunosAp, numAlunosRec, numAlunosRep)
    
    #-----------------------------------------------------------------
    #... escreve no arquivo de saída uma listagem dos alunos (com
    #    nome, média de provas, média de eps e média final) que
    #    foram aprovados
    #...
    escreve_lista_alunos_mesma_situacao(arqSai, lista_criada[11], lista_criada[0], lista_criada[4], lista_criada[9], lista_criada[10], "Ap", numAlunosAp)
   
    #... escreve no arquivo de saída uma listagem dos alunos (com
    #    nome, média de provas, média de eps e média final) que
    #    ficaram de recuperação
    #...
    escreve_lista_alunos_mesma_situacao(arqSai, lista_criada[11], lista_criada[0], lista_criada[4], lista_criada[9], lista_criada[10], "Rec", numAlunosRec)

    #... escreve no arquivo de saída uma listagem dos alunos (com
    #    nome, média de provas, média de eps e média final) que
    #    foram reprovados
    #...
    escreve_lista_alunos_mesma_situacao(arqSai, lista_criada[11], lista_criada[0], lista_criada[4], lista_criada[9], lista_criada[10], "Rep", numAlunosRep)
    
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
    content = "Nome : Sungwon Yoon \nNúmero Usp : 9822261 \nCurso : Letras \n\n"
    content += "\nEste programa calcula a média final dos alunos de uma turma, \
algumas médias e desvios padrão relacionados à turma e algumas listagens específicas \
da turma. \n\n"

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

    strng_linha_arq = arqentra.readline()
    lista_linha_arq = strng_linha_arq.split(";")
    info_pesos_provas = []
    info_pesos_eps = []

    i = 0
    while i < 1:
        info_num_alunos = int(lista_linha_arq[i])
        i += 1
    while i < 4:
        peso_prova_splitted = int(lista_linha_arq[i])
        info_pesos_provas.append(peso_prova_splitted)
        i += 1
    while i < 8:
        peso_ep_splitted = int(lista_linha_arq[i])
        info_pesos_eps.append(peso_ep_splitted)        
        i += 1
    while i < 9:
        info_peso_media_provas = int(lista_linha_arq[i])
        i += 1
    while i < 10:
        info_peso_media_eps = int(lista_linha_arq[i])
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
    
    content = "Há %d alunos, %d provas e %d EPs." %(num_alunos, num_provas, num_eps)
    content += "\n\nPesos das provas: "

    for elementos in pesos_provas:
        content += str(elementos)
        content += " "

    content += "\nPeso média das provas: %d" %(peso_media_provas)
    content += "\nPeso média dos Eps: %d" %(peso_media_eps)

    content += "\n\n\n%-32s%6s%6s%6s%6s%6s%6s%6s%6s%6s%6s%7s \n" %("Nome do aluno", "P1", "P2", "P3", "MP", "EP1", "EP2", "EP3", "EP4", "MEP", "MF", "Sit")

    arqsai.write(content)
    
#.....................................................................

def cria_lista(n, valor):
    ''' (int, objeto) -> list

    Cria uma lista com n elementos, todos iguais a valor, e 
    retorna essa lista.
    '''
    
    i = 0
    lista_cria = []
    while i < 12:
        j = 0
        cada = []
        while j < n:
            cada.append(valor)
            j += 1
        lista_cria.append(cada)
        i += 1

    return lista_cria

    
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

    media_provas = media_notas_aluno(info_aluno[1:4], pesos_provas)
    media_eps = media_notas_aluno(info_aluno[4:8], pesos_eps)

    if media_provas >= 4.95 and media_eps >= 4.95:
        media_notas = ((media_provas * peso_media_provas) + (media_eps * peso_media_eps)) / (peso_media_eps + peso_media_provas)
        situacao = "Ap"

    elif media_provas <= 2.95 and media_eps <= 2.95:
        if media_provas < media_eps:
            media_notas = media_provas
        else:
            media_notas = media_eps
        situacao = "Rep"

    elif media_provas <= 2.95 and media_eps >= 2.95:
        media_notas = media_provas
        situacao = "Rep"

    elif media_provas >= 4.95 and media_eps <= 2.95:
        media_notas = media_eps
        situacao = "Rep"

    else:
        if media_provas < media_eps:
            media_notas = media_provas
        else:
            media_notas = media_eps
        situacao = "Rec"

    return media_provas, media_eps, media_notas, situacao
   
#.....................................................................

def media_notas_aluno(notas, pesos):
    ''' (list, list) -> float
   
    Recebe duas listas, notas e pesos, com as notas e os 
    respectivos pesos.
    Retorna a média ponderada com esses valores.
    Obs.: Cuidado com os valores -1.0.
    '''
 
    n = len(pesos)
    i = soma = 0
    while i < n:
        if notas[i] == -1.0:
            nota = 0
        else:
            nota = notas[i]
        soma += nota * pesos[i]
        i += 1

    soma_pesos = 0
    for elementos in pesos:
        soma_pesos += elementos

    return soma / soma_pesos

  
#.....................................................................

def determina_media_turma(notas):
    ''' (list) -> float
   
    Recebe uma lista notas com as notas de uma turma.
    Retorna a média aritmética dos valores em notas.
    Obs.: Cuidado com os valores -1.0.
    '''
    cont = soma = 0
    for x in notas:
        if x == -1.0:
            x = 0
            cont += 1
        soma += x

    med = soma / (len(notas) - cont)

    return med
  
#.....................................................................

def determina_desvio_padrao(notas, media):
    ''' (list, float) -> float
   
    Recebe uma lista notas com as notas de uma turma e 
    um número real media com a média dessas notas.
    Retorna o desvio padrão dos valores em notas.
    Obs.: Cuidado com os valores -1.0.
    '''
    mean = media
    soma = cont = 0


    for x in notas:
        if x == -1.0:
            cont += 1
        else:
            soma += (x - mean) ** 2

    var = soma / (len(notas) - 1 - cont)
    std = math.sqrt(var)


    return std


#.....................................................................

def escreve_info_aluno(arqsai, info_aluno, media_provas_aluno,
                       media_eps_aluno, media_aluno, situacao):
    ''' (arquivo, list, float, float, float, str) -> NoneType

    Recebe um arquivo de saída e todas as informações de um aluno.
    Escreve todas essas informações numa linha de arqsai,
    utilizando o formato especificado.
    '''

    content = "\n%-32s" %info_aluno[0]
    for x in info_aluno[1:4]:
        if x == -1.0:
             content += "%6s" %("---")
        else:
            content += "%6.1f" %(x)
    content += "%6.1f" %(media_provas_aluno)
    for x in info_aluno[4:9]:
        if x == -1.0:
             content += "%6s" %("---")
        else:
            content += "%6.1f" %(x)
    content += "%6.1f" %(media_eps_aluno)
    content += "%6.1f" %(media_aluno)

    content += "%7s" %(situacao)


    arqsai.write(content)
    
 
#.....................................................................

def escreve_medias_turma(arqsai, medias_turma):
    ''' (arquivo, list) -> NoneType

    Recebe um arquivo de saída e uma lista contendo a média da turma 
    em cada prova, a média das médias de provas, a média da turma em
    cada ep, a média das médias de eps e a média das médias dos alunos.
    Esta função escreve todas essas informações numa linha de arqsai,
    utilizando o formato especificado.
    '''
    content = "\n\n\n%-32s" %"Medias da turma:"
    for x in medias_turma:
        content += "%6.1f" %(x)
    
    arqsai.write(content)
    
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

    content = "\n\n%-32s" %"Desvios padrão turma:"
    for x in desvios_turma:
        content += "%6.1f" %(x)

    arqsai.write(content)
    
#.....................................................................
 
def conta_alunos_ap_rec_rep(s):
    '''  (list) -> int, int, int

    Recebe uma lista s com a situação dos alunos.
    Retorna os números de alunos aprovados, em recuperação e reprovados.
    '''
    contAp = contRec = contRep = 0

    for x in s:
        if x == "Ap":
            contAp += 1
        elif x == "Rec":
            contRec += 1
        else:
            contRep += 1

    return contAp, contRec, contRep

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
 
    Ap_porc = (num_alunos_ap / num_alunos) * 100
    Rec_porc = (num_alunos_rec / num_alunos) * 100
    Rep_porc = (num_alunos_rep / num_alunos) * 100

    content = "\n\n\n%-40s %d ( %5.2f%%)" %("Número de alunos aprovados:", num_alunos_ap, Ap_porc)
    content += "\n%-40s %d ( %5.2f%%)" %("Número de alunos em recuperação:", num_alunos_rec, Rec_porc)
    content += "\n%-40s %d ( %5.2f%%)\n" %("Número de alunos reprovados:", num_alunos_rep, Rep_porc)

    arqsai.write(content)


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

    i = 0
    if uma_situacao == "Ap":
        content = "\n\nListagem com %d alunos que foram aprovados: \n\n" %(num_alunos_sit)
        content += "%-32s %15s %15s %15s" %("Nome do aluno", "Média provas", "Média eps", "Média final")
        while i < len(nomes):
            if situacoes[i] == "Ap": 
                content += "\n%-32s %15.1f %15.1f %15.1f" %(nomes[i], medias_provas[i], medias_eps[i], medias_aluno[i])
            i += 1
        
    elif uma_situacao == "Rec":
        content = "\n\nListagem com %d alunos que ficaram de recuperação: \n\n" %(num_alunos_sit)
        content += "%-32s %15s %15s %15s" %("Nome do aluno", "Média provas", "Média eps", "Média final")
        while i < len(nomes):
            if situacoes[i] == "Rec": 
                content += "\n%-32s %15.1f %15.1f %15.1f" %(nomes[i], medias_provas[i], medias_eps[i], medias_aluno[i])
            i += 1

    elif uma_situacao == "Rep":
        content = "\n\nListagem com %d alunos que foram reprovados: \n\n" %(num_alunos_sit)
        content += "%-32s %15s %15s %15s" %("Nome do aluno", "Média provas", "Média eps", "Média final")
        while i < len(nomes):
            if situacoes[i] == "Rep": 
                content += "\n%-32s %15.1f %15.1f %15.1f" %(nomes[i], medias_provas[i], medias_eps[i], medias_aluno[i])
            i += 1
  
    content += "\n\n----------------------------------------------------------------------------------------------------"

    arqsai.write(content)
#.....................................................................

main()
