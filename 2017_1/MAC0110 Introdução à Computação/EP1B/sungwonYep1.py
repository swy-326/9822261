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
  Exercício-Programa EP1B

  Referências: Com exceção das rotinas que podem ser fornecidas
  no enunciado ou em sala de aula, caso você tenha utilizado
  alguma referência, liste-as abaixo para que o seu programa não
  seja considerado plágio ou irregular.

"""




def main():
    print("Este programa testa se os digitos verificadores de numeros de CPF ou de CNPJ")
    
    print("ou de cartoes de credito estao corretos.")
    print()
    print("====================================================================================")
    print()
    print("Qual documento deseja escolher?")
    print("1. CPF     2. CNPJ     3. Cartao de credito")
    print()
    opc = int(input("Digite a sua opção (de 1 a 3) ou 0 para terminar: "))





#---------
# 0
#---------

    if opc == 0:
        print()
        print("====================================================================================")





#---------
# CPF
#---------

    if opc == 1:
        print()
        print("Obs.: Um número de CPF deve ser fornecido como um único número inteiro de")
        print("onze dígitos (ou seja, sem os pontos e sem o hífen).")
        print()
        cpf = int(input("Digite um número de CPF: "))

# CALCULAR 1O DIGITO
        soma1_cpf = 0
        soma2_cpf = 0
        cont1_cpf = 9
        cont2_cpf = 8

        cpf1 = cpf // 100
        while cont1_cpf >= 1:
            dig1_cpf = cpf1 % 10
            soma1_cpf = soma1_cpf + dig1_cpf * cont1_cpf
            cont1_cpf = cont1_cpf - 1
            cpf1 = cpf1 // 10
        dv1_cpf = soma1_cpf % 11
        if soma1_cpf % 11 == 10:
            dv1_cpf = 0

# CALCULAR 2O DIGITO
        cpf2 = cpf // 100
        while cont2_cpf >= 0:
            dig2_cpf = cpf2 % 10
            soma2_cpf = soma2_cpf + dig2_cpf * cont2_cpf
            cont2_cpf = cont2_cpf - 1
            cpf2 = cpf2 // 10
        soma2_cpf = soma2_cpf + dv1_cpf * 9
        dv2_cpf = soma2_cpf % 11
        if soma2_cpf % 11 == 10:
            dv2_cpf = 0

# PRINT
        print()
        print("O primeiro dígito verificador deve ser", " ", dv1_cpf, ".", sep="")
        print("O segundo dígito verificador deve ser", " ", dv2_cpf, ".", sep="")
        print()

        part_a = cpf // 10**8
        part_b = cpf // 10**5 % 1000
        part_c = cpf // 100 % 1000
        part_d = cpf % 100

        if (dv2_cpf != cpf % 10) and (dv1_cpf != cpf % 100 // 10):
            print("Os dois dígitos verificadores do CPF", "%03d.%03d.%03d-%02d" %(part_a, part_b, part_c, part_d), "estão incorretos.")
        elif (dv1_cpf != cpf % 100 // 10):
            print("O primeiro dígito verificador do CPF", "%03d.%03d.%03d-%02d" %(part_a, part_b, part_c, part_d), "está incorreto.")
        elif (dv2_cpf != cpf % 10):
            print("O segundo dígito verificador do CPF", "%03d.%03d.%03d-%02d" %(part_a, part_b, part_c, part_d), "está incorreto.")
        else:
            print("Os dois dígitos verificadores do CPF", "%03d.%03d.%03d-%02d" %(part_a, part_b, part_c, part_d), "estão corretos.")
    
        print("------------------------------------------------------------------------------------")





#---------
# CNPJ
#---------

    if opc ==  2:
        print()
        print("Obs.: Um número de CNPJ deve ser fornecido como um único número inteiro de")
        print("quatorze dígitos (ou seja, sem os pontos, sem a barra e sem o hífen).")
        print()
        cnpj = int(input("Digite um número de CNPJ: "))

# CALCULAR 1O DIGITO
        soma_cnpj = 0
        cnpj1 = cnpj // 100 
        cont_cnpj = 9
        while cont_cnpj >= 2:
            dig_cnpj = cnpj1 % 10
            mult_cnpj = dig_cnpj * cont_cnpj
            soma_cnpj = soma_cnpj + mult_cnpj
            cnpj1 = cnpj1 // 10
            cont_cnpj = cont_cnpj - 1

        cont_cnpj = 9
        while cont_cnpj >= 5:
            dig_cnpj = cnpj1 % 10
            mult_cnpj = dig_cnpj * cont_cnpj
            soma_cnpj = soma_cnpj + mult_cnpj
            cnpj1 = cnpj1 // 10
            cont_cnpj = cont_cnpj - 1

        dig_1 = soma_cnpj % 11
        if dig_1 == 10:
            dig_1 = 0

# CALCULAR 2O DIGITO
        mult_cnpj = 0
        soma_cnpj = 0
        cont_cnpj = 8
        cnpj1 = cnpj // 100
        while cont_cnpj >= 2:
            dig_cnpj = cnpj1 % 10
            mult_cnpj = dig_cnpj * cont_cnpj
            soma_cnpj = soma_cnpj + mult_cnpj
            cnpj1 = cnpj1 // 10
            cont_cnpj = cont_cnpj - 1


        cont_cnpj = 9
        while cont_cnpj >= 5:
            dig_cnpj = cnpj1 % 10
            mult_cnpj = dig_cnpj * cont_cnpj
            soma_cnpj = soma_cnpj + mult_cnpj
            cnpj1 = cnpj1 // 10
            cont_cnpj = cont_cnpj - 1

        soma_cnpj = soma_cnpj + dig_1 * 9
        dig_2 = soma_cnpj % 11
        if dig_2 == 10:
            dig_2 = 0

# PRINT
        print()
        print("Deve ser", dig_1)
        print("Deve ser", dig_2)
        print()

        part_a = cnpj // 10**12
        part_b = cnpj // 10**9 % 1000
        part_c = cnpj //10**6 % 1000
        part_d = cnpj // 100 % 10000
        part_e = cnpj % 100

        if (dig_1 == cnpj % 100 // 10) and (dig_2 == cnpj % 10):
            print("Os dois dígitos verificadores do CNPJ", "%02d.%03d.%03d/%04d-%02d" %(part_a, part_b, part_c, part_d, part_e), "estão corretos.")
        else:
            print("Um ou dois dígitos verificadores do CNPJ", "%02d.%03d.%03d/%04d-%02d" %(part_a, part_b, part_c, part_d, part_e), "estão incorretos.")

        print("------------------------------------------------------------------------------------")





#----------------------
# Cartao de credito
#----------------------

    if opc == 3:
        print()
        print("Obs.: Um número de cartão de crédito deve ser fornecido como um único número")
        print("inteiro de dezesseis dígitos (ou seja, sem os espaços).")
        print()
        cc = int(input("Digite um número de cartão de crédito: "))

# CACULAR DIG VERF.
        cont_cc = 2
        soma_cc = 0
        cc1 = cc // 10
        while n1 != 0:
            dig_cc = cc1 % 10
            mult_cc = dig_cc * cont_cc 
            if mult_cc > 9:
                mult_cc = mult_cc - 9
            soma_cc = soma_cc + mult_cc
            cc1 = cc1 // 10
            if cont_cc == 2:
                cont_cc = 1
            else:
                cont_cc = 2

        dv_cc = soma_cc // 10 * 10 + 10 - soma_cc
        if dv_cc == 10:
            dv_cc = 0
            
# PRINT
        print()    
        print("O dígito verificador deve ser ", dv_cc, ".", sep="")
        print()

        part_a = cc // 10**12
        part_b = cc // 10**8 % 10000
        part_c = cc // 10**4 % 10000
        part_d = cc % 10000

        if (cc % 10) == dv_cc:
            print("O dígito verificador do cartão de crédito", "%04d %04d %04d %04d" %(part_a, part_b, part_c, part_d), "está correto.")
        else:
            print("O dígito verificador do cartão de crédito", "%04d %04d %04d %04d" %(part_a, part_b, part_c, part_d), "está incorreto.")
            
        print("------------------------------------------------------------------------------------")



main()
