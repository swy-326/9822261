#LE3 - 5
#Nome : Sungwon Yoon
#Nº USP: 9822261
#Curso : Letras

def main():
    print("Este programa calcula e imprime sem repetição os raios das circuferências centradas no ponto digitado pelo usuário (x, y) que passsam por pelo menos um dos n pontos dados.")
    print()

    x_central = float(input("Digite o x do ponto central:"))
    y_cetnral = float(input("Digite o y do ponto central: "))

    n = int(input("Digite a quantidade de coordenadas desejadas: "))

    i = 1
    pontos = []
    while i <= n:
        x = float(input("Digite o x do %dº ponto: " %i))
        y = float(input("Digite o y do %dº ponto: " %i))
        pontos.append(x)
        pontos.append(y)
        i += 1

    i = 0
    achou = False
    lista_resultados = []
    resultado_final = []
    comp = len(lista_resultados)
    while i < comp:
        resultado = distancia_entre_dois_pontos(pontos[i], pontos[i+1], x_central, y_cetnral)
        j = 0
        while j < n and not achou:
            if resultado == lista_resultados[j]:
                achou = True
            else:
                j += 1
        print("ㅅㅂ")
        if not achou:
            resultado_final.append(resultado)
        i += 1

    print("yes")
    
    for elementos in resultado_final:
        print(elementos)
    print("외않")


def distancia_entre_dois_pontos (x1, y1, x2, y2):
	import math
	soma_quadrado = ((x1 - x2) ** 2) + ((y1 - y2) ** 2)
	return math.sqrt(soma_quadrado)



main()
		 
