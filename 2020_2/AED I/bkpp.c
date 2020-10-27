#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <malloc.h>
#include <string.h>

// ######### ESCREVA O NROUSP AQUI
const char* nroUSP() {
    return("9822261");
}

// ######### ESCREVA SEU NOME AQUI
const char* nome() {
    return("Sungwon Yoon");
}

// elemento da pilha
typedef struct estrutura {
	struct estrutura *prox;
    int tipo; // 1=char e 2=float
    union {
       	char simbolo;
       	float valor;
    };
} NO;




// respctivas explicacoes estao acima de cada funcao
void imprimir(NO** head);


float calcular(char* expressao, int* codigo);
void copia(char ch, NO** topoPilha);
void push(NO* atual, NO** topoPilha);
void pop(NO** topoPilha, float* valor, char* op);
float calculaOperacao(float first, char op, float last, int** codigo);
void excluiExpressao(NO** qian4, NO** qian3, NO** qian2, NO** qian1, NO** qian);
int isNumber(NO** topoPilha);
int isChar(NO** topoPilha);


// apenas para teste
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


// cria uma lista no a partir da expressao passado como string
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


// usado apenas para construir pilha auxiliar de calculo
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

// retira o valor de float ou simbolo dependendo do seu tipo 
// e libera memoria desse no
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

// faz as operacoes de soma, subtracao, mult e divisao
// caso haja divisao por 0, codigo eh atualizado para 0 
float calculaOperacao(float first, char op, float last, int** codigo){
	switch(op){
		case '+':
			(**codigo) = 1;
			return first + last;
	
    	case '-':
			(**codigo) = 1;
			return first - last;
	
		case '*':
			(**codigo) = 1;
			return first * last;
	
		case '/':
			if(last == 0){ (**codigo) = 0; return -1;}
			(**codigo) = 1;
			return first / last;

		default:
			**codigo = -1;
			return -1;
		}
}

// exclui ) e a expressao que foi calculada como 1+1)
// e atualiza o prox de ( para o proximo de )
// ex)   ( 1 + 2 ) / 9  ==> ( / 9
// posteriormente em ( sera colocado o resultado da operacao
void excluiExpressao(NO** qian4, NO** qian3, NO** qian2, NO** qian1, NO** qian){
    NO* inicio = *qian4;
    NO* final = *qian;

    free(*qian2); free(*qian3); free(*qian1);

    inicio->prox = final->prox;
    free(final);
}

// usado antes de pop, para verificar se o valor contido em NO eh numero
int isNumber(NO** topoPilha){
	if((*topoPilha)->tipo == 2) return 0;
	else return -1;
}

// usado antes de pop, para verificar se o valor contido em NO eh char
int isChar(NO** topoPilha){
	if((*topoPilha)->tipo == 1) return 0;
	else return -1;
}

// funcao principal para calcular a expressao dada
float calcular(char* expressao, int* codigo){

    int tam = 0; int i; int esq = 0, dir = 0, num = 0; *codigo = 1;
	NO* pilhaExpressao = NULL;

	/* 
        calcula o tamanho inicial e procura por possiveis erros de sintaxe

        a quantidade minima de string deve ser 5 para ser sintaticamente correta
        deve haver mesma quantidade de '(' e ')'
        alem disso, deve comecar com '(' e terminar com ')'
    */
	while(expressao[tam] != '\0'){
		if(expressao[tam] == '(') esq++;
		else if (expressao[tam] == ')') dir++;
        else if (expressao[tam] >= '0' && expressao[tam] <= '9') num++;
		tam++;
	}

	if (tam < 5 || expressao[0] != '(' || expressao[tam-1] != ')' || esq != dir || num-1 != esq){
		*codigo = -1;
		return -1;
	}


	// copia o string para uma lista ligada ao contrario
	i = tam-1;
	while(i >= 0){
		copia(expressao[i], &pilhaExpressao);
		i--;
	}


    // pilha auxiliar para retirar os elementos
	NO* tempCalculo = NULL;

	// ate sobrar apenas um numero 
	while(tam > 2){

		NO* runner1 = pilhaExpressao;

		// para guardar enderecos de nos anteriores
        NO* qian4 = NULL; NO* qian3 = NULL; NO* qian2 = NULL; NO* qian1 = NULL; NO* qian = NULL;

        // push na pilha auxiliar para usar posteriormente nos calculos
		while( runner1->simbolo != ')'){
            push(runner1, &tempCalculo);

            qian4 = qian3; qian3 = qian2; qian2 = qian1; qian1 = runner1;
			runner1 = runner1->prox;
		}
        qian = runner1;
		runner1 = runner1->prox;
        imprimir(&pilhaExpressao);


        // exclui as tres nos do meio
		excluiExpressao(&qian4, &qian3, &qian2, &qian1, &qian);

		// se eh numero ou char, faz o pop
        // se nao retorna qualquer valor com codigo -1 
        // (divisao por zero eh verificado posteriormente, portanto aqui sempre eh erro de sintaxe)
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


        // finalmente atualiza o no '(' para o resultado
        if (qian4->tipo == 1 && qian4->simbolo == '('){
            qian4->tipo = 2;
            qian4->valor = novoValor;
            printf("aqui?\n");
        } else {
            *codigo = -1;
            return -1;
        }

        // atualiza o tamanho
		tam -= 4; 
	}

    // se o tamanho != 1, eh porque houve numeros ou operandos a mais, 
    // ou seja, erro de sintaxe
	if (tam != 1){ *codigo = -1; return -1; };
	return pilhaExpressao->valor;
}



//----------------------------------------------------------------
// use main() apenas para fazer chamadas de teste ao seu programa
//----------------------------------------------------------------
int main() {

    char testes[14][200] = {
        "(0*(((1+(2*4))-6)/6))", 
        "(0*((1+(2*4)/6)))", // erro
        "(0*(((1+(2*4))-6)/0))", // 0
        "(5+((2-(4+5))*4))",
        "(1-((2/4)+4))", 
        "(10-((20/0)+4))", // 0 ou syntax
        "(0*(((1+(2*4))-6)/6)", // erro
        "10+(5)", // erro
        "4-(6+(2-1)))", // erro
        "(55+1)", // erro
        "(4-20)", // erro
        "(1+(2**4))", // erro
        "(0*(((1+(2*4))--6)/6))", // erro
        "(1()+7)", // erro
    };

	int codigo;

    for (int i = 0; i < 14; i++){
        printf("\n\n\nexpressao : %s     ", testes[i]);
        float resp = calcular(testes[i], &codigo);

	    if ( codigo == 1 ) printf("resposta final : %f\n", resp);
	    else if ( codigo == 0 ) printf("tentativa de divisao por 0\n");
	    else if ( codigo == -1 ) printf("erro de sintaxe\n");
	    else printf("nao era para estar imprimindo isso, codigo : %d\n", codigo);

    }

}