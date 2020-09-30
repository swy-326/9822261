#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct estrutura {
	struct estrutura *prox;
    int tipo; // 1=char e 2=float
    union {
        char simbolo;
        float valor; // -48
    };
} NO;


void pushUntilClose(char ch, NO* subexpressao){

	NO* novo = (NO*) malloc (sizeof(NO));
	novo->prox = NULL;
	if(ch > 0 && ch < 10){
		novo->tipo = 2;
		novo->union->valor = ch;
	} else {
		novo->tipo = 1;
		novo->union->simbolo = ch;
	}

	if (subexpressao == NULL){
		subexpressao = novo;
	} else {
		NO* runner = subexpressao;
		while(runner->prox) runner->prox;
		runner->prox = novo;
	}

}

NO* popUntilOpen(NO* subexpressao){
	NO* expressaoCalcular;
}

float calcular(char* expressao, int* codigo){

	// 시작은 달콤ㅎ...이 아니라 (로 시작해야됨
	if(expressao[0] != '(') {
		codigo = -1;
		return -1;
	}


	NO* subexpressao;
	int tam = strlen(expressao);
	for(int i = 0; expressao[i] != '('; i++){
		pushUntilClose(expressao[i], subexpressao);
		i++;
	}


	NO* expressaoCalcular;
	expressaoCalcular = popUntilOpen();
	resultado_parcial = resultadoParcial(subexpressao);

	calcular(expressao);

}



int main() {
	char exp[200];
	strcpy(exp, "(7*5)");

	int codigo;

	float resp = calcular(exp);
	printf("resp : %f", resp);
}


/*
- array를 사용한 버전인듯...?

	expressao 에서 일단 )를 발견될 때까지 char을 subexpressao이라는 string에 쌓음
	)가 발견되면, 쌓기를 중지함.
	// 세번 앞으로 갔는데 )가 안 나오면 그건 잘못된 식임
	이 )는 expressao에서 삭제함


	pop(subexpressao)함수에서 크기가 3인 NO가 만들어질 예정
	(가 발견될 때까지 숫자면 숫자, 기호면 기호를 집어넣음
		ㄴ (발견될 때까지 할 필요 없이 3번만 앞으로 가면 됨)
		ㄴ 세번 앞으로 갔는데 (가 안 나오면 그건 잘못된 식
	이 (는 expressao에서 삭제하지 않고 위치 기억*

	크기가 3인 NO의 첫 주자를 calcula_parcial에 넘겨줌
	두번째 NO가 case : '+' 이면 첫번째 세번째 더하기
				case : '/' 이면 0 주의하고 나누기 하기 등등등...
	calcula_parcial이 정답을 넘겨주면 그 답을 위 문단에서 기억*했던 위치에 넣어줌

	그러면 식 하나 계산이 끝난 거임.

	기억했던 위치*의 다음부터 또 저 짓을 다시 시작함

	recursive로 불러서, 만약에 크기가 1이라면 끝난 거.


*/