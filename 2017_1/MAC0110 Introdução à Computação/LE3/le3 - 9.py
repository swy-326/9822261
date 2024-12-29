#LE3 - 9



def main():
    print("Este programa calcula a soma dos dois inteiros?")
    print()
    n = int(input("Digite o numero dos inteiros: "))
    print()

    i = 1
    prim_lista = []
    while i <= n:
        num_1a = int(input("Digite o %dº da primeira seq: " %i))
        prim_lista.append(num_1a)
        i += 1

    print()
    i = 1
    seg_lista = []
    while i <= n:
        num_2a = int(input("Digite o %dº da segunda seq: " %i))
        seg_lista.append(num_2a)
        i += 1

    # 숫자 프린트
    cont_lista1 = n - 1
    while cont >= 0:
        print 


    # 결과값 프린트
    soma_lista = soma_dois_inteiros(prim_lista, seg_lista)

    cont_lista_soma = n - 1
    while cont > 0:
        print(soma_lista[cont_lista_soma], end=' ')
        cont_lista_soma -= 1

    print(soma_lista[0])







def soma_dois_inteiros (lista1, lista2):
    '''   (list, list) --> list

    Recebe duas listas, lista1 e lista2, de mesmo comprimento,
    sendo que cada uma delas representa um número inteiro positivo, 
    e retorna uma lista contendo os dígitos do inteiro que
    representa a soma desses dois inteiros.
    '''   
    i = len(lista1) - 1
    result = []

    while i >= 0 :
        soma = lista1[i] + lista2[i]
        i -= 1
        if soma >= 10:
           soma = soma % 10
           result.append(soma)
           lista[1] += 1
        else:
            result.append(soma)

    return result


main()
