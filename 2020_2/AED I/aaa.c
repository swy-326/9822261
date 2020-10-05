#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <malloc.h>
#include <string.h>

typedef struct estrutura {
	struct estrutura *prox;
    int tipo; // 1=char e 2=float
    union {
        char simbolo;
        float valor; // -48
    };
} NO;

// 문제 없음
void imprimir(NO** topoPilha){
	NO* runner = *topoPilha;

	while(runner){
		if(runner->tipo == 1) printf("%c", runner->simbolo);
		else printf("%f", runner->valor);
		runner = runner->prox;
	}
	printf("\n");
}

// 문제 없음
int stringlength(char* expressao){
	int i;
	for(i = 0; expressao[i] != '\0'; i++){}
	return i;
}

// 문제 없음
int pilhalength(NO** topoPilha){
	int tam = 0;
	NO* runner = *topoPilha;
	while(runner){
		tam++;
		runner = runner->prox;
	}
	return tam;
}

// 아마 없음
void push(char ch, NO** topoPilha){
	NO* novo = (NO*) malloc (sizeof(NO));

	if(ch > 0 && ch < 10){
		novo->tipo = 2;
		novo->valor = ch;
	} else {
		novo->tipo = 1;
		novo->simbolo = ch;
	}

	if (*topoPilha == NULL){
		novo->prox = NULL;
		*topoPilha = novo;
	} else {
		novo->prox = *topoPilha;
		*topoPilha = novo;
	}
}

// float를 이딴식으로 넘기면 안됨
char pop(NO** topoPilha){
	NO* aux = *topoPilha;
	NO* runner = *topoPilha;
	char ch;

	if (aux){
		if(aux->tipo == 1) ch = aux->simbolo;
		else if(aux->tipo == 2) ch = (int)aux->valor;
	
		*topoPilha = runner->prox;
		free(aux);
	}

	return ch;
}

void pushCalculatedValue(float novoValor, NO** topoPilha){
	NO* runner = *topoPilha;

	NO* novo = (NO*) malloc (sizeof(NO));
	novo->tipo = 2;
	novo->valor = novoValor;

	if(runner == NULL) novo->prox = NULL;
	else novo->prox = runner;
	runner = novo;
}

void popParentesis(NO** topoPilha){
	NO* aux;
	NO* runner = *topoPilha;

	if(runner != NULL){
		aux = runner;
		runner = runner->prox;
		free(aux);
	}
}

void calculaPilha(NO** topoPilha, int* codigo){

	float last = pop(topoPilha) - 48;
	printf("last : %f\n", last);

	char operacao = pop(topoPilha);
	printf("operacao : %c\n", operacao);

	float first = pop(topoPilha) - 48;
	printf("first : %f\n", first);

	float novoValor;

	if (last == 0 && operacao == '/') *codigo = 0;
	else {
		switch(operacao){
			case '+':
				novoValor = first + last;
				break;
	
			case '-':
				novoValor = first - last;
				break;
	
			case '*':
				novoValor = first * last;
				break;
	
			case '/':
				novoValor = first / last;
				break;
		}

		popParentesis(topoPilha); // ( 날려버림
		push(novoValor, topoPilha); // 계산된 값 스택에 넣기
	}
}


float calcular(char* expressao, int* codigo){
	int strIndex = 1;
	int tam = strlen(expressao);

	NO* topoPilha = NULL; // 얘는 topo인 no의 주소를 담고있음

	while(tam > 3){
		// )제외한 )까지 쌓기, loop 후 strIndex는 ) 다음 요소로++
		while(expressao[strIndex] != ')'){
			push(expressao[strIndex], &topoPilha);
			strIndex++;
		}
		
		imprimir(&topoPilha);

		calculaPilha(&topoPilha, codigo);
		if (*codigo == -1) return -1;
		else if (*codigo == 0) return 0;

		tam = pilhalength(&topoPilha);

	}

	// 마지막 계산
	// float 넘기는 법만 찾으면 이 부분 필요 X


	// 하나만 남음
	return topoPilha->valor;

}



//----------------------------------------------------------------
// use main() apenas para fazer chamadas de teste ao seu programa
//----------------------------------------------------------------
int main() {


	// o EP sera testado com chamadas deste tipo

	char exp[200];
	strcpy(exp, "(7*9)");

	int codigo;

	float resp = calcular(exp,&codigo);
	printf("%f", resp);

}

// por favor nao inclua nenhum cуdigo abaixo da funзгo main()