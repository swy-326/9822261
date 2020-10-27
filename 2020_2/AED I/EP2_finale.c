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

float calculaOperacao(float first, char op, float last, int** codigo){
	switch(op){
		case '+':
			(**codigo) = 1;
			printf("soma\n");
			return first + last;
	
    	case '-':
			(**codigo) = 1;
			printf("subtracao\n");
			return first - last;
	
		case '*':
			(**codigo) = 1;
			printf("multiplicacao\n");
			return first * last;
	
		case '/':
			if(last == 0){ (**codigo) = 0; return -1;}
			(**codigo) = 1;
			printf("divisao\n");
			return first / last;

		default:
			**codigo = -1;
			return -1;
		}
}

void excluiExpressao(NO** qian4, NO** qian3, NO** qian2, NO** qian1, NO** qian){
    NO* inicio = *qian4;
    NO* final = *qian;


    	printf("excluindo qian3, valor : %f\n", (*qian3)->valor);
		printf("excluindo qian2, valor : %c\n", (*qian2)->simbolo);
		printf("excluindo qian1, valor : %f\n", (*qian1)->valor);
		printf("excluindo qian, valor : %c\n", (*qian)->simbolo);

    free(*qian2); free(*qian3); free(*qian1);

    inicio->prox = final->prox;
    free(final);

}


int isNumber(NO** topoPilha){
	if((*topoPilha)->tipo == 2) return 0;
	else return -1;
}

int isChar(NO** topoPilha){
	if((*topoPilha)->tipo == 1) return 0;
	else return -1;
}




float calcular(char* expressao, int* codigo){

	// calcula o tamanho inicial
	int tam = 0; int i; int esq = 0, dir = 0;
	NO* pilhaExpressao = NULL;
	while(expressao[tam] != '\0'){
		if(expressao[tam] == '(') esq++;
		else if (expressao[tam] == ')') dir++;
		tam++;
	}

	if (tam < 5 || expressao[0] != '(' || expressao[tam-1] != ')' || esq != dir){
		printf("ou nao comeca ou fecha com parentesis ou o num eh diferente\n");
		*codigo = -1;
		return -1;
	}

	// copia o string para uma lista ligada ao contrario
	i = tam-1;
	while(i >= 0){
		copia(expressao[i], &pilhaExpressao);
		i--;
	}

	imprimir(&pilhaExpressao);


	*codigo = 1;
	NO* tempCalculo = NULL;

	// ate sobrar apenas um 
	while(tam > 2){
		NO* runner1 = pilhaExpressao;
        NO* qian4 = NULL; NO* qian3 = NULL; NO* qian2 = NULL; NO* qian1 = NULL; NO* qian = NULL;

		// cria um stack temp apenas para calculo
		while( runner1->simbolo != ')'){
            push(runner1, &tempCalculo);

            qian4 = qian3; qian3 = qian2; qian2 = qian1; qian1 = runner1;
			runner1 = runner1->prox;
		}
        qian = runner1;
		runner1 = runner1->prox;


		excluiExpressao(&qian4, &qian3, &qian2, &qian1, &qian);

		imprimir(&pilhaExpressao);
		// se eh numero ou char, faz o pop
		float last, first, lixo; char op = '=';


		if ( isNumber(&tempCalculo) == 0 ) pop(&tempCalculo, &last, &op);
		else *codigo = -1;

		if ( isChar(&tempCalculo) == 0) pop(&tempCalculo, &lixo, &op);
		else *codigo = -1;

		if ( isNumber(&tempCalculo) == 0) pop(&tempCalculo, &first, &op);
		else *codigo = -1;

		if ( (*codigo) != 1 ) return -1;


		// se o calculo deu errado devido ao erro de sintaxe
		// ou por divisao por zero, devolve qq valor
		float novoValor = calculaOperacao(first, op, last, &codigo);
		if ( *codigo != 1 ) return -1;


		// 확인 필요
        qian4->tipo = 2;
        qian4->valor = novoValor;


		imprimir(&pilhaExpressao); 
		tam -= 4; 
		//printf("tamanho : %d\n", tam);

	}

	if (tam != 1){ *codigo = -1; return -1; };
	//*codigo = 1;
	return pilhaExpressao->valor;
}


int main() {
	char exp[200];
	strcpy(exp, "(1/3)");

	int codigo;

	float resp = calcular(exp,&codigo);

	if ( codigo == 1 ) printf("resposta final : %f\n", resp);
	else if ( codigo == 0 ) printf("tentativa de divisao por 0\n");
	else if ( codigo == -1 ) printf("erro de sintaxe\n");
	else printf("nao era para estar imprimindo isso, codigo : %d\n", codigo);

}
