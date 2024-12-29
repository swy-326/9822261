# 설명 제대로 
# 칸에 맞춰 프린트

def main():
    print("Este programa calcula o raio das circuferencias a partir das coordenadas dos pontos(x,y).")
    x_centro = float(input("Digite o x: "))
    y_centro = float(input("Digite o y: "))
    n = int(input("Digite o numero dos pontos: "))
    print()

    lista_pontos = []
    cont = 1
    while cont <= n:
        x_ponto = float(input("Digite a %dª coordenada x do ponto: " %cont))
        y_ponto = float(input("Digite a %dª coordenada y do ponto: " %cont))
        print()
        lista_pontos.append(x_ponto)
        lista_pontos.append(y_ponto)
        cont += 1

    i = 0
    resultados = []
    while i < n * 2:
        raio = distancia_entre_dois_pontos (x_centro, y_centro, lista_pontos[i], lista_pontos[i+1])
        # 바로 프린트를 할까 리스트를 만들어서 따로 프린트를 할까
        # 따로 만들어야지 비교를 하지 븅신
        resultados.append(raio)
        i += 2

    # 같은 게 있는지 비교
    print("ok")
    i = 0
    j = 1
    lista_out = []
    achou = False
    while i < n:
        while j < n and not achou:
            if lista_pontos[i] == lista_pontos[j]:
                #lista_out.append(lista_pontos[i]) # 혹은 바로 프린트
                print(lista_pontos[i])
                achou = True
            j += 1
            # 근데 또 3개가 같은 게 있을 수도 있잖아.
            # 같은 게 아예 없으면 리스트에 또 추가
        i += 1
    print("ok")

def distancia_entre_dois_pontos (x1, y1, x2, y2):

    '''  (float, float, float, float) -> float

    Recebe as  coordenadas cartesianas de dois pontos (x1, y1) e (x2, y2)
    no plano, e retorna a distância entre eles.
    '''
    import math
    soma_quadrado = ((x1 - x2) ** 2) + ((y1 - y2) ** 2)
    return math.sqrt(soma_quadrado) 

main()
