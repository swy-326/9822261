#LE3 - 5
#Nome : Sungwon Yoon
#Nº USP: 9822261
#Curso : Letras


def main():
    print("Este programa calcula e imprime sem repetição os raios das circuferências centradas no ponto digitado pelo usuário (x, y) que passsam por pelo menos um dos n pontos dados.")
    print()

    x_central = float(input("Digite o x do ponto central: "))
    y_cetnral = float(input("Digite o y do ponto central: "))
    print()

    n = int(input("Digite a quantidade de coordenadas desejadas: "))
    print()

    i = 1
    lista_resultados = []
    while i <= n:
        x = float(input("Digite o x do %dº ponto: " %i))
        y = float(input("Digite o y do %dº ponto: " %i))
        print()
        resultado = distancia_entre_dois_pontos(x, y, x_central, y_cetnral)

        achou = False
        j = 0
        while j < len(lista_resultados) and not achou:
            if lista_resultados == []:
                lista_resultados.append(resultado)
            elif resultado == lista_resultados[j]:
                achou = True
            else:
                j += 1
        if not achou:
            lista_resultados.append(resultado)
            
        i += 1

    print()
    print("As distâncias calculadas são: ", end='')
    for elementos in lista_resultados:
        print("%.02f" %(elementos), end=" ")


def distancia_entre_dois_pontos (x1, y1, x2, y2):
    '''  (float, float, float, float) -> float

    Recebe as  coordenadas cartesianas de dois pontos (x1, y1) e (x2, y2)
    no plano, e retorna a distância entre eles.
    '''
    import math
    soma_quadrado = ((x1 - x2) ** 2) + ((y1 - y2) ** 2)
    return math.sqrt(soma_quadrado)



main()
		 
