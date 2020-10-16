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

void imprimir(NO** head){
	NO* runner = *head;

	printf("여기서부터 빠짐 : ");

	while(runner){
		if(runner->tipo == 1) printf(" %c ", runner->simbolo, runner);
		else printf(" %f ", runner->valor, runner);
		runner = runner->prox;
	}
	printf("\n");
}

void copia(char ch, NO** topoPilha){
	NO* novo = (NO*) malloc (sizeof(NO));

	if(ch >= '0' && ch <= '9'){
		novo->tipo = 2;
		novo->valor = ch - 48;
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

void push(NO* atual, NO** topoPilha){
	
    NO* novo = (NO*) malloc (sizeof(NO));

	if(atual->tipo == 2){
		novo->tipo = 2;
		novo->valor = atual->valor;
		//printf("foi colocado valor : %d\n", novo->valor);
	} else {
		novo->tipo = 1;
		novo->simbolo = atual->simbolo;
		//printf("foi colocado simbolo : %c\n", novo->simbolo);
	}

	if (*topoPilha == NULL){
		novo->prox = NULL;
		*topoPilha = novo;
	} else {
		novo->prox = *topoPilha;
		*topoPilha = novo;
	}
}

void pop(NO** topoPilha, float* valor, char* op){
    NO* aux = *topoPilha;

    if ( aux->tipo == 1 ){
        (*op) = aux->simbolo;
    }
    else if ( aux->tipo == 2 ){
        (*valor) = aux->valor;
    }

    *topoPilha = aux->prox;
    free(aux);
}

float calculaOperacao(float first, char op, float last, int* codigo){
	switch(op){
		case '+':
			return first + last;
	
    	case '-':
			return first - last;
	
		case '*':
			return first * last;
	
		case '/':
			if(last == 0){ *codigo = 0; return -1;}
			return first / last;

		default:
			*codigo = -1;
			return -1;
		}
}

void excluiExpressao(NO** qian4, NO** qian3, NO** qian2, NO** qian1){
    NO* inicio = *qian4;
    NO* final = *qian1;

    free(*qian2); free(*qian3);

    inicio->prox = final->prox;
    free(final);
}




float calcular(char* expressao, int* codigo){

	// calcula o tamanho inicial
	int tam = 0; int i;
	NO* pilhaExpressao = NULL;
	while(expressao[tam] != '\0'){
		tam++;
	}

	// copia o string para uma lista ligada ao contrario
	i = tam-1;
	while(i >= 0){
		copia(expressao[i], &pilhaExpressao);
		i--;
	}

	imprimir(&pilhaExpressao);

	NO* tempCalculo = NULL;

	while(tam > 1){
		NO* runner1 = pilhaExpressao;
        NO* qian4 = NULL; NO* qian3 = NULL; NO* qian2 = NULL; NO* qian1 = NULL; NO* qian = NULL;

		while( runner1->simbolo != ')'){
            push(runner1, &tempCalculo);

            qian4 = qian3; qian3 = qian2; qian2 = qian1; qian1 = runner1;
			runner1 = runner1->prox;
		}
        qian = runner1;
		runner1 = runner1->prox;

        free(qian2); free(qian3); free(qian1);
        qian4->prox = qian->prox;
        free(qian);

		float last, first, lixo; char op;
		pop(&tempCalculo, &last, &op);
		pop(&tempCalculo, &lixo, &op);
		pop(&tempCalculo, &first, &op);

		float novoValor = calculaOperacao(first, op, last, codigo);

        qian4->tipo = 2;
        qian4->valor = novoValor;

        imprimir(&pilhaExpressao);

        tam -= 4;

        printf("tamanho : %d\n", tam);

	}


	return pilhaExpressao->valor;
}


int main() {
	char exp[200];
	strcpy(exp, "((1+5)-((3*2)+4))");

	int codigo;

	float resp = calcular(exp,&codigo);
	printf("resposta final :  %f", resp);
}