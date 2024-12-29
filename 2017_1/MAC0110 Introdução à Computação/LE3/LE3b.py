#LE3 - 9
#Nome : Sungwon Yoon
#Nº USP: 9822261
#Curso : Letras


def main():
    print("Este programa calcula a soma dos dois inteiros em forma de list.")
    print()
    n = int(input("Digite a quantidade das casas dos inteiros: "))
    print()

    #receber numeros
    i = 1
    prim_lista = []
    while i <= n:
        num_1a = int(input("Digite o %dª casa do primeiro número: " %i))
        prim_lista.append(num_1a)
        i += 1

    print()
    i = 1
    seg_lista = []
    while i <= n:
        num_2a = int(input("Digite o %dª casa do segundo número: " %i))
        seg_lista.append(num_2a)
        i += 1

    #imprimir numeros recebidos
    print("O resultado da soma do", end=" ")
    for elements in prim_lista:
        print(elements, end="")

    print(" e do", end=" ")
    for elements in seg_lista:
        print(elements, end="")

    #calcular a soma
    soma_lista = soma_dois_inteiros(prim_lista, seg_lista)

    #imprimir a soma
    print(" é:", end=" ")
    for elements in soma_lista:
        print(elements, end="")




def soma_dois_inteiros (lista1, lista2):
    '''   (list, list) --> list

    Recebe duas listas, lista1 e lista2, de mesmo comprimento,
    sendo que cada uma delas representa um número inteiro positivo, 
    e retorna uma lista contendo os dígitos do inteiro que
    representa a soma desses dois inteiros.
    '''   

    resultado = []
    final = []
    i = len(lista2) - 1

    while i > 0:
        soma = lista1[i] + lista2[i]
        if soma > 9:
            soma = soma % 10
            lista1[i-1] += 1
        resultado.append(soma)
        i -= 1

    soma = lista1[0] + lista2[0]     
    resultado.append(soma)

    i = len(resultado) - 1
    while i >= 0:
        adicionar = resultado[i]
        final.append(adicionar)
        i -= 1
        
    return final
            



main()
