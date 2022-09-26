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
float calcular(char* expressao, int* codigo);
void copia(char ch, NO** topoPilha);
void push(NO* atual, NO** topoPilha);
void pop(NO** topoPilha, float* valor, char* op);
float calculaOperacao(float first, char op, float last, int** codigo);
void excluiExpressao(NO** ant4, NO** ant3, NO** ant2, NO** ant1, NO** ant);
int isNumber(NO** topoPilha);
int isChar(NO** topoPilha);




// cria uma lista a partir dos chars da expressao
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


// extrai o valor de float ou simbolo e libera memoria desse no
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


/*  faz as operacoes de soma, subtracao, mult ou divisao e retorna o resultado
    caso haja divisao por 0, codigo eh atualizado para 0 
    em casos em que a operacao eh um char, mas nao um operador valido, retorna erro de sintaxe */
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
			if(last == 0){ (**codigo) = 0; return 0;}
			(**codigo) = 1;
			return first / last;

		default:
			(**codigo) = -1;
			return -1;
		}
}


/*  exclui ')' e a expressao que foi calculada da lista : 1+1)
    e atualiza o prox de '(' para o proximo de ')'
        ex:   ( 1 + 2 ) / 9  ==> ( / 9
    posteriormente o '(' sera atualizado para o resultado da operacao */
void excluiExpressao(NO** ant4, NO** ant3, NO** ant2, NO** ant1, NO** ant){
    NO* inicio = *ant4;
    NO* final = *ant;

    free(*ant2); free(*ant3); free(*ant1);

    inicio->prox = final->prox;
    free(final);
}


/*  usado antes de pop, para verificar se o valor contido em NO eh numero
    retorna 0, se eh numero; caso contrario retorna -1 */
int isNumber(NO** topoPilha){
	if((*topoPilha)->tipo == 2) return 0;
	else return -1;
}

/*  usado antes de pop, para verificar se o valor contido em NO eh char
    retorna 0, se eh char; caso contrario retorna -1 */
int isChar(NO** topoPilha){
	if((*topoPilha)->tipo == 1) return 0;
	else return -1;
}


// funcao principal (retorna float e int)
float calcular(char* expressao, int* codigo){

    int tam = 0; int i; int esq = 0, dir = 0, num = 0; *codigo = 1;
	NO* pilhaExpressao = NULL;

	/* 
        calcula o tamanho inicial e procura por erros de sintaxe visiveis :

        a quantidade minima de string deve ser 5 para ser sintaticamente correta
		deve comecar com '(' e terminar com ')'
        deve haver mesma quantidade de '(' e ')'
        como sao apenas numeros de 1 digito, a quantidade de numeros deve ser um a mais que um lado de parentesis
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


	// copia o string para uma lista ligada de ordem reversa
	i = tam-1;
	while(i >= 0){
		copia(expressao[i], &pilhaExpressao);
		i--;
	}


    // pilha auxiliar para retirar os elementos
	NO* tempCalculo = NULL;

	// ate sobrar apenas um numero 
	while(tam > 1){

		NO* runner1 = pilhaExpressao;

		// para guardar enderecos de nos anteriores
        NO* ant4 = NULL; NO* ant3 = NULL; NO* ant2 = NULL; NO* ant1 = NULL; NO* ant = NULL;

        // push na pilha auxiliar para usar posteriormente nos calculos
		while( runner1->simbolo != ')'){
            push(runner1, &tempCalculo);

            ant4 = ant3; ant3 = ant2; ant2 = ant1; ant1 = runner1;
			runner1 = runner1->prox;
		}
        ant = runner1;
		runner1 = runner1->prox;


        // exclui as tres nos do meio
		excluiExpressao(&ant4, &ant3, &ant2, &ant1, &ant);

		/*  se eh numero ou char, faz o pop
            se nao retorna qualquer valor com codigo -1 
            divisao por zero eh verificado posteriormente, portanto aqui sempre eh erro de sintaxe */
		float last, first, lixo; char op = '=';
        
        if ( isNumber(&tempCalculo) == 0 ) pop(&tempCalculo, &last, &op);
		else *codigo = -1;

		if ( isChar(&tempCalculo) == 0) pop(&tempCalculo, &lixo, &op);
		else *codigo = -1;

		if ( isNumber(&tempCalculo) == 0) pop(&tempCalculo, &first, &op);
		else *codigo = -1;

		if ( (*codigo) != 1 ) return -1;


		/*  se o calculo deu errado devido ao erro de sintaxe
		    ou por divisao por zero, devolve qq valor */
		float novoValor = calculaOperacao(first, op, last, &codigo);
		if ( *codigo != 1 ) return -1;


        // finalmente atualiza o no '(' para o resultado
        if (ant4->tipo == 1 && ant4->simbolo == '('){
            ant4->tipo = 2;
            ant4->valor = novoValor;
        } else {
            *codigo = -1;
            return -1;
        }

        // atualiza o tamanho
		tam -= 4; 
	}

    // se o tamanho != 1, eh porque sobraram numeros ou operadores a mais, ou seja, erro de sintaxe
	if (tam != 1){ *codigo = -1; return -1; };

	return pilhaExpressao->valor;
}




int main() {

    char testes[3][200] = {
		"((1+5)-((3*2)+4))",
		"(((((2*3)+5)*3)-1)-9)",
		"(0*(((1+(2*4))-6)/6))",
    };

	int codigo;

    for (int i = 0; i < 3; i++){
        printf("\n\n\nexpressao : %s     ", testes[i]);
        float resp = calcular(testes[i], &codigo);

	    if ( codigo == 1 ) printf("resposta final : %f\n", resp);
	    else if ( codigo == 0 ) printf("tentativa de divisao por 0\n");
	    else if ( codigo == -1 ) printf("erro de sintaxe\n");
	    else printf("nao era para estar imprimindo isso, codigo : %d\n", codigo);

    }

}