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
  Exercício-Programa EP2

  Referências: Com exceção das rotinas que podem ser fornecidas
  no enunciado ou em sala de aula, caso você tenha utilizado
  alguma referência, liste-as abaixo para que o seu programa não
  seja considerado plágio ou irregular.
"""

#--------------------------------------------------------------------------------

def main():
    ''' EP2
    '''
    
    print()
    print("   Este programa resolve uma sequência de problemas.")
    print("   Cada problema pode ser de um dos tipos a seguir: ")
    print("    1- ('v') Determinar o valor do pagamento à vista.")
    print("    2- ('p') Determinar o valor da prestação.")
    print("    3- ('j') Determinar o valor dos juros.")
    print("    4- ('n') Determinar o número e o valor das prestações.")
    print("    5- ('t') Determinar os valores à vista, total a pagar e porcentagem.")
    print("   Um usuário escolhe o tipo de problema que deseja resolver, ")
    print("  digitando um dos símbolos descritos acima ou 'f' para finalizar.")
    
    print()
    print("======================================================================")
    print()

    opc = str(input("Digite o tipo do problema que deseja resolver ou 'f' para finalizar: "))



    if opc == "v":
        #Receber numeros
        print()
        print("- Determinar o valor à vista.")
        in_vp = float(input("Digite o valor da prestação: "))
        in_vj = float(input("Digite o valor da taxa de juros: "))
        in_np = int(input("Digite o número de prestações: "))
        
        #imprimir na formata
        print()
        out_vp = formata(in_vp)
        print("Valor da prestação: %s" %(out_vp))
        print("Valor da taxa de juros: %.02f%%" %(in_vj))
        print("Número de prestações:", in_np)

        #imprimir o numero calculado
        out_vv = valor_vista(in_vp, in_vj, in_np)
        out_vv = formata(out_vv)
        print("- Valor calulado à vista: %s" %(out_vv))



    elif opc == "p":
        #Receber numeros
        print()
        print("- Determinar o valor da prestação.")
        in_vv = float(input("Digite o valor à vista: "))
        in_vj = float(input("Digite o valor da taxa de juros: "))
        in_np = int(input("Digite o número de prestações: "))

        #imprimir na formata
        print()
        print("Valor à vista:", formata(in_vv))
        print("Valor da taxa de juros: %.02f%%" %(in_vj))
        print("Número de prestações: %s" %(in_np))

        #imprimir o numero calculado
        out_vp = valor_prestacao(in_vv, in_vj, in_np)
        out_vp = formata(out_vp)
        print("- Valor calculado da prestação:", out_vp)



    elif opc == "j":
        #Receber numeros
        print()
        print("- Determinar o valor da taxa de juros.")
        in_vv = float(input("Digite o valor à vista: "))
        in_vp = float(input("Digite o valor da prestação: "))
        in_np = int(input("Digite o número de prestações: "))

        print()

        #imprimir na formata
        print("Valor à vista:", formata(in_vv))
        print("Valor da prestação:", formata(in_vp))
        print("Número de prestações: %s" %(in_np))

        #imprimir o numero calculado
        out_vj = valor_juros(in_vv, in_vp, in_np)
        print("- Valor calculado da taxa de juros: %.02f%%" %(out_vj))



    elif opc == "n":
        #Receber numeros
        print()
        print("- Determinar o número e o valor das prestações.")
        in_vv = float(input("Digite o valor à vista: "))
        in_vmaxp = float(input("Digite o valor máximo da prestação: "))
        in_vj = float(input("Digite o valor da taxa de juros: "))

        #imprimir na formata
        print()
        print("Valor à vista:", formata(in_vv))
        print("Valor máximo da prestação:", formata(in_vmaxp))
        print("Valor da taxa de juros: %.02f%%" %(in_vj))

        #imprimir o numero calculado
        out_np, out_vp = num_prestacoes_e_valor_prestacao(in_vv, in_vmaxp, in_vj)
        if out_np == 0 and out_vp == 0.0:
            print ("- O valor máximo da prestação deve ser maior.")
        else:
            print("- Valor calculado do número de prestações: %s" %(out_np))
            print("- Valor calculado da prestação:", formata(out_vp))


    elif opc == "t":
        #Receber numeros
        print()
        print("- Determinar os valores à vista, total a pagar e porcentagem.")
        in_vp = float(input("Digite o valor da prestação: "))
        in_vj = float(input("Digite o valor da taxa de juros: "))
        in_np = int(input("Digite o número de prestações: "))

        #imprimir na formata
        print()
        print("Valor da prestação:", formata(in_vp))
        print("Valor da taxa de juros: %.02f%%" %(in_vj))
        print("Número de prestações: %s" %(in_np))

        #imprimir o numero calculado
        out_vv, out_tt, out_comp_porctg = valores_vista_total_porcentagem(in_vp, in_vj, in_np)
        print("- Valor calculado à vista:", formata(out_vv))
        print("- Valor calculado do total a pagar:", formata(out_tt))
        print("- O total a pagar é %.02f%% a mais do que o valor à vista." %(out_comp_porctg))


    elif opc == "f":
        print()
        print("======================================================================")
        exit()


    else:
        print()
        print("Tipo do problema '%s' é inválido." %(opc))


#--------------------------------------------------------------------------------

def potencia(x, n):
    '''  (float, int) -> float

    Recebe um valor real x e um inteiro n >= 0, e retorna o valor da  
    n-ésima potência de x.
    '''
    df_pot = 1 - ( 1 / (( 1 + x ) ** n) )
    return df_pot

#--------------------------------------------------------------------------------

def valor_vista(vp, vj, np):
    vj = vj / 100
    df_vv = (vp / vj) * potencia(vj, np)
    return df_vv

#--------------------------------------------------------------------------------

def valor_prestacao(vv, vj, np):
    '''  (float, float, int) -> float

    Recebe o valor à vista vv, o valor dos juros vj e
    o número de prestações np. 
    A função retorna o valor da prestação a ser pago.   
    '''
    vj = vj / 100
    df_vp = (vv * vj) / potencia(vj, np)
    return df_vp

#--------------------------------------------------------------------------------

def valor_juros(vv, vp, np):
    '''  (float, float, int) -> float

    Recebe o valor à vista vv, o valor da prestação vp e
    o número de prestações np. 
    A função retorna o valor dos juros que está sendo cobrado. 
    
    Obs. Utiliza o método da bissecção descrito na seção 5 do enunciado.
    '''
    a = 0.00001
    b = 3
    while b - a > 0.00000001:
        m = (a + b) / 2 
        if funcaof(vv, vp, a, np) * funcaof(vv, vp, m, np) < 0:
            b = m
        else:
            a = m
    df_vj = (a + b) / 2
    return df_vj * 100


#--------------------------------------------------------------------------------

def funcaof(vv, vp, vj, np):
    '''  (float, float, float, int) -> float

    Recebe o valor à vista vv, o valor da prestação vp, o valor dos 
    juros vj e o número de prestações np. 
    A funcao retorna o valor da função f descrita na seção 3.   
    '''
    
    df_f = vv - (vp / vj) * (1 - (1 / ((1 + vj) ** np)))
    return df_f


#--------------------------------------------------------------------------------

def num_prestacoes_e_valor_prestacao(vv, vmaxp, vj):
    '''  (float, float, float) -> int, float

    Recebe o valor à vista vv, o valor máximo a ser pago em cada 
    prestação vmaxp e o valor dos juros vj.
    Caso seja possível o pagamento do valor à vista vv, a função
    retorna o número de prestações e o valor exato de cada prestação.
    Em caso contrário, a função retorna 0 e 0.0 .
    '''
    vj = vj / 100
    n = 1
    while n <= 96:
        if vv <= (vmaxp / vj) * potencia(vj, n):
            vj = vj * 100
            df_vp = valor_prestacao(vv, vj, n)
            return n, df_vp

        else:
            n += 1

    return 0, 0.0

#--------------------------------------------------------------------------------

def valores_vista_total_porcentagem(vp, vj, np):
    '''  (float, float, int) -> float, float, float

    Recebe o valor da prestação vp, o valor dos juros vj e
    o número de prestações np. 
    A função retorna o valor à vista correspondente,
    o valor total a pagar e o valor da porcentagem porcento 
    tal que o total a pagar correspondente a porcento% a mais
    do que o valor à vista.   
    '''
    df_vv = valor_vista(vp, vj, np)
    df_tt = vp * np
    df_comp_porctg = ((df_tt - df_vv) / df_vv) * 100
    return df_vv, df_tt, df_comp_porctg

#--------------------------------------------------------------------------------

def formata(num):
    '''  (float) -> str
 
    Recebe um número em ponto flutuante que representa um valor em reais.
    A função retorna um string com a representação correspondente
    usando 'R$', '.', ',' e centavos.
    '''
    num = num * 1000
    num = int(num)

    if num % 10 >= 5:
        num = num // 10 + 1
        cent = num % 100
        num = num // 100
    else:
        num = num // 10
        cent = num % 100
        num = num // 100

    num_copy = num_copy_copy = num

    soma = "1" #Apenas para evitar a perda de "0"s
    while num > 99:
        soma += "%03d" %(num % 1000)
        num = num // 1000

    front = num

    frm_prt = "R$: "
    if front != 0:
        frm_prt += str(front)
        isnt_zero = True
    else:
        isnt_zero = False
 
    soma = int(soma)


    if soma == 1 and not isnt_zero:
        frm_prt += "00"


    if soma != 1:
        while soma > 99:
            if soma > 999 and isnt_zero:
                frm_prt += "."
            zheng = soma % 1000
            frm_prt += "%03d" %(zheng)
            soma = soma // 1000
            isnt_zero = True


    frm_prt += ","
    frm_prt += "%02d" %(cent)

    return frm_prt

#--------------------------------------------------------------------------------
# Início da execução do programa

main()

