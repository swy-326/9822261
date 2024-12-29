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
  Curso : MAC0110 Introdução à Computação
  Exercício-Programa EP1A

  Referências: Com exceção das rotinas que podem ser fornecidas
  no enunciado ou em sala de aula, caso você tenha utilizado
  alguma referência, liste-as abaixo para que o seu programa não
  seja considerado plágio ou irregular.

"""



def main():
    print(" Este programa testa se os dois dígitos verificadores de um número de")
    print(" CPF estão corretos.")
    print(" Obs.: Um número de CPF deve ser fornecido como um número inteiro de")
    print(" onze dígitos (ou seja, sem os pontos e sem o hífen).")
    print()
    n = int(input("Digite um número de CPF: "))
    soma1 = 0
    soma2 = 0
    cont1 = 9
    cont2 = 8

    n1 = n // 100
    while cont1 >= 1:
        dig1 = n1 % 10
        soma1 = soma1 + dig1 * cont1
        cont1 = cont1 - 1
        n1 = n1 // 10
    x1 = soma1 % 11
    if soma1 % 11 == 10:
        x1 = 0

    n2 = n // 100
    while cont2 >= 0:
        dig2 = n2 % 10
        soma2 = soma2 + dig2 * cont2
        cont2 = cont2 - 1
        n2 = n2 // 10
    soma2 = soma2 + x1 * 9
    x2 = soma2 % 11
    if soma2 % 11 == 10:
        x2 = 0
            
    print()
    print("O primeiro dígito verificador deve ser"," ",x1,".", sep="")
    print("O segundo dígito verificador deve ser"," ", x2,".", sep="")
    print()

    if x2 != n % 10:
        print("Um ou dois dígitos verificadores do CPF",n,"estão incorretos.")
    else:   
        if x1 != n % 100 // 10:
            print("Um ou dois dígitos verificadores do CPF",n,"estão incorretos.")
        else:
            print("Os dois dígitos verificadores do CPF",n,"estão corretos.")
            
main()
