//--------------------------------------------------------------
// NOME : Sungwon Yoon
//--------------------------------------------------------------

#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

// ######### ESCREVA O NROUSP AQUI
int nroUSP() {
    return 9822261;
}
 
//-------------------------------------------

// CHLINK eh um par <chave,link> - dentro de cada página há 3 CHLINKs
typedef struct {
	int chave;
	int linkdir;
} CHLINK;

// definicao de pagina da árvore / registro do arquivo
typedef struct {
	int np; // armazene aqui o nro da pagina no arquivo
	int cont; // armazene aqui a quantidade de chaves existentes no vetor CHLINK[]
	CHLINK item[3]; // a chave[0] eh desprezada, e o linkdir[0] eh na verdade o link esquerdo da chave[1]
} PAGINA;




// funcoes
PAGINA* criaNovaPagina(int* numPag);
int buscarItem(PAGINA* temp, int ch);
int ehFolha(PAGINA* temp);
void insercaoNaoCheia(PAGINA* temp, int ch, int filhoDir);
PAGINA* split(PAGINA* metadeEsq, int* numPag);
int organizarValorMedio(PAGINA* temp, int ch);
void buscarPagina (FILE* fp, int pagAtual, int* pagNovoEsq, int* pagNovoDir, int* valorMedio, int* novaRaiz, int raizInicial, int* numPag);
void inserir(char nomearq[], int* raiz, int ch);






// cria nova pagina com 1 chave
PAGINA* criaNovaPagina(int* numPag){

	PAGINA* temp = (PAGINA*) malloc (sizeof(PAGINA));

	for (int i = 0; i <= 2; i++){
		temp->item[i].chave = -1;
		temp->item[i].linkdir = -1;
	}

	temp->cont = 1;
	temp->np = (*numPag);

	(*numPag)++;

	return temp;
}


// aonde tem q ser inserido
int buscarItem(PAGINA* temp, int ch){

	// return -1 - ja existe
	// return 1 - esq
	// return 2 - meio
	// return 3 - dir

	int i;
	for (i = 1; i <= temp->cont; i++){
		if (ch == temp->item[i].chave) return -1;
		if (ch < temp->item[i].chave) break;
	}

	return i;
}


// verifica se eh folha
int ehFolha(PAGINA* temp){

	return ((temp->item[0].linkdir == -1) && (temp->item[1].linkdir == -1) && (temp->item[2].linkdir == -1)) ? 1 : 0;
}


// inserir qnd a pag nao esta cheia
void insercaoNaoCheia(PAGINA* temp, int ch, int filhoDir){

	// pagina nao cheia
	if (temp->cont == 1){

		// se for menor (vem da esq)
		if (ch < temp->item[1].chave){

			temp->item[2].linkdir = temp->item[1].linkdir;
			temp->item[2].chave = temp->item[1].chave;
			
			temp->item[1].chave = ch;
			temp->item[1].linkdir = filhoDir;			
		} 

		// se for maior (vem da dir)
		else {

			temp->item[2].chave = ch;
			temp->item[2].linkdir = filhoDir;
		}
	}

	temp->cont = 2;
}


// split pagina
PAGINA* split(PAGINA* metadeEsq, int* numPag){

	PAGINA* metadeDir = criaNovaPagina(numPag);
	
	// mover para nova pagina
	metadeDir->item[1].chave = metadeEsq->item[2].chave;
	metadeDir->item[1].linkdir = metadeEsq->item[2].linkdir;

	// deletar os elementos movidos da pagina original
	metadeEsq->item[2].chave = -1;
	metadeEsq->item[2].linkdir = -1;
	metadeEsq->cont = 1;

	return metadeDir;	
}


// insere a chave; deleta e retorna o valor medio
int organizarValorMedio(PAGINA* temp, int ch){

	int medio;
	int v1 = temp->item[1].chave;
	int v2 = temp->item[2].chave;

	if (ch < v1){
		medio = v1;
		temp->item[1].chave = ch;
	}

	else if (ch > v1 && ch < v2){
		medio = ch;
	}

	else {
		medio = v2;
		temp->item[2].chave = ch;
	}

	return medio;
}


// arovre nao vazia
void buscarPagina (FILE* fp, int pagAtual, int* pagNovoEsq, int* pagNovoDir, int* valorMedio, int* novaRaiz, int raizInicial, int* numPag){

	// traz para memoria
	PAGINA temp;
	fseek(fp, pagAtual*sizeof(PAGINA), SEEK_SET);
	fread(&temp, sizeof(PAGINA), 1, fp);


	// se nao for repetido
	int i = buscarItem(&temp, *valorMedio);
	if (i != -1){

		// recursao ate a folha certa
		if (!ehFolha(&temp)) {

			// qual filho
			int npDescer = temp.item[i-1].linkdir;
			if (npDescer != -1)
				buscarPagina(fp, npDescer, pagNovoEsq, pagNovoDir, valorMedio, novaRaiz, raizInicial, numPag);
		}


		/* fim da recursao */


		// se houver so 1 chave
		if (temp.cont == 1) {

			// insere
			if (*valorMedio != -1)
				insercaoNaoCheia(&temp, *valorMedio, *pagNovoDir);

			// atualiza arquivo
			fseek(fp, pagAtual*sizeof(PAGINA), SEEK_SET);
			fwrite(&temp, sizeof(PAGINA), 1, fp);

			(*valorMedio) = -1;
		}


		// se houver 2 chavevs, split
		else if (temp.cont == 2 && (*valorMedio) != -1) {

			// organizar chave recebida
			int middle = organizarValorMedio(&temp, *valorMedio);

			// split
			PAGINA* novoDir = split(&temp, numPag);
			

			/*  organizar os filhos, dependendo de qual lado veio */

			// orig esq
			if (temp.item[1].chave == (*valorMedio)) {
				novoDir->item[0].linkdir = temp.item[1].linkdir;
				temp.item[1].linkdir = (*pagNovoDir);
			}
			// orig dir
			else if (novoDir->item[1].chave == (*valorMedio)){
				novoDir->item[0].linkdir = novoDir->item[1].linkdir;
				novoDir->item[1].linkdir = (*pagNovoDir);
			}
			// orig meio
			else 
				novoDir->item[0].linkdir = (*pagNovoDir);
			
			// organiza pagina e atualiza
			temp.item[2].chave = -1;
			temp.item[2].linkdir = -1;
			temp.cont = 1;
			fseek(fp, temp.np * sizeof(PAGINA), SEEK_SET); fwrite(&temp, sizeof(PAGINA), 1, fp);
			fseek(fp, 0, SEEK_END); fwrite(novoDir, sizeof(PAGINA), 1, fp);




			// se estamos na raiz
			if (temp.np == raizInicial){

				// cria nova pagina e atualiza fp e raiz
				PAGINA* nuevo = criaNovaPagina(numPag);
				nuevo->item[1].chave = middle;
				nuevo->item[0].linkdir = temp.np;
				nuevo->item[1].linkdir = novoDir->np;

				fseek(fp, 0, SEEK_END); fwrite(nuevo, sizeof(PAGINA), 1, fp);

				(*novaRaiz) = nuevo->np;
			} 

			// pagina interna
			else {

				// valores a serem tratados na prox recursao

				(*pagNovoDir) = novoDir->np;
				(*pagNovoEsq) = temp.np;
				(*valorMedio) = middle;
			}
		}
	}
}


// funcao principal
void inserir(char nomearq[], int* raiz, int ch){

	FILE *fp = fopen(nomearq, "rb+");

	// se o arquivo existir
	if (fp != NULL){

		// arvore vazia
		if ((*raiz) == -1){

			// cria nova pagina com chave dada e atualiza o arquivo e a raiz

			int numPag = 0;
			PAGINA* temp = criaNovaPagina(&numPag);
			temp->item[1].chave = ch;

			fwrite(temp, sizeof(PAGINA), 1, fp);

			(*raiz) = 0;
		}

		// arvore nao vazia
		else {

			// qntde de paginas existentes e verifica se ha repeticao
			PAGINA temp; int numPag = 0; int repeticao = 0;
			
			rewind(fp);
			while (1 == fread(&temp, sizeof(PAGINA), 1, fp)){

				if (temp.item[1].chave == ch || temp.item[2].chave == ch) {
					repeticao = -1; break;
				}

				numPag += 1;
			} 		


			if (repeticao != -1){

				// valores para recursao
				int pagFilhoEsq = -1, pagFilhoDir = -1, valorMedio = ch, novaRaiz = -1;

				// recursao
				rewind(fp);
				buscarPagina(fp, (*raiz), &pagFilhoEsq, &pagFilhoDir, &valorMedio, &novaRaiz, (*raiz), &numPag);

				// atualiza raiz
				if (novaRaiz != -1) (*raiz) = novaRaiz;
			}

		}

		fclose(fp);
	}
}