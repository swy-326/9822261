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

int stringlength(char* expressao){
	printf("stringlength\n");
	int i;
	for(i = 0; expressao[i] != '\0'; i++){}
	return i;
}

int pilhalength(NO* topoPilha){
	printf("pilhalength\n");
	int tam = 0;
	NO* runner = topoPilha;
	while(runner) tam++;
	return tam;
}

void push(char ch, NO* topoPilha){
	printf("push\n");
	NO* novo = (NO*) malloc (sizeof(NO));

	if(ch > 0 && ch < 10){
		novo->tipo = 2;
		novo->valor = ch;
	} else {
		novo->tipo = 1;
		novo->simbolo = ch;
	}

	if (topoPilha == NULL){
		novo->prox = NULL;
		topoPilha = novo;
	} else {
		novo->prox = topoPilha;
		topoPilha = novo;
	}
}

char pop(NO* topoPilha){
	printf("pop\n");
	NO* aux;
	char ch;

	if (topoPilha == NULL) return 'n';

	aux = topoPilha;
	if(aux->tipo == 1) ch = aux->simbolo;
	else if(aux->tipo == 2) ch == aux->valor;

	topoPilha = topoPilha->prox;
	free(aux);

	return ch;
}

void pushCalculatedValue(float novoValor, NO* topoPilha){
	printf("pushCalculatedValue\n");
	NO* novo = (NO*) malloc (sizeof(NO));
	novo->tipo = 2;
	novo->valor = novoValor;

	if(topoPilha == NULL) novo->prox = NULL;
	else novo->prox = topoPilha;
	topoPilha = novo;
}

void popParentesis(NO* topoPilha){
	printf("popParentesis\n");
	NO* aux;

	if(topoPilha != NULL){
		aux = topoPilha;
		topoPilha = topoPilha->prox;
		free(aux);
	}
}

void calculaPilha(NO* topoPilha, int *codigo){
	printf("calculaPilha\n");
	float last = pop(topoPilha) - 48;
	char operacao = pop(topoPilha);
	float first = pop(topoPilha) - 48;
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
	printf("calcular\n");
	int strIndex = 0;
	int tam = strlen(expressao);
	NO* topoPilha = NULL;

	printf("strlen\n");
	while(tam != 1){
		printf("while\n");
		// )제외한 )까지 쌓기, loop 후 strIndex는 ) 다음 요소로++
		while(expressao[strIndex] != ')'){
			push(expressao[strIndex], topoPilha);
			strIndex++;
		}
		
		calculaPilha(topoPilha, codigo);
		if (*codigo == -1) return -1;
		else if (*codigo == 0) return 0;

		tam = pilhalength(topoPilha);
	}

	// 하나만 남음
	return topoPilha->valor;

}



//----------------------------------------------------------------
// use main() apenas para fazer chamadas de teste ao seu programa
//----------------------------------------------------------------
int main() {


	// o EP sera testado com chamadas deste tipo

	char exp[200];
	strcpy(exp, "(7*5)");

	int codigo;

	float resp = calcular(exp,&codigo);
	printf("%f", resp);

}

// por favor nao inclua nenhum cуdigo abaixo da funзгo main()