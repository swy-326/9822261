/*
	Usando o struct da aula arquivos parte 3, 
	escreva um programa que recebe como entrada um arquivo com registros deste tipo (ou seja, de tamanho fixo) 
	e dois endereços (bytes iniciais) de registro r1 e r2, 
	e faça a troca destes dois registros, ou seja, escrevendo r1 na posição r2 e vice-versa. 

	Lembre-se de que o primeiro registro está na posição (byte) zero do arquivo. 

*/

#include <stdio.h>
#include <stdlib.h>


#define MAX 30

struct registro {
	char nrousp[7];
	char nome[20];
	int idade;
	int valido; // | 1 = ok | 0 = excluido |
};


void criaArquivoFixo (){

	int ret = remove("resultado.txt");

	FILE *fp = fopen("teste.txt", "rb");
	if (fp == NULL) exit(1);

	FILE *fp2 = fopen("resultado.txt", "wb");
	if (fp2 == NULL) exit(1);

	struct registro alunos[MAX];
	int prox = 0; 

	while (prox < MAX) {

		fscanf(fp, "%[^/]%*c", alunos[prox].nrousp);
		fscanf(fp, "%[^/]%*c", alunos[prox].nome);
		fscanf(fp, "%d/", &alunos[prox].idade);
		fscanf(fp, "%d/", &alunos[prox].valido);

		prox++;
	}


	fwrite(alunos, sizeof(struct registro), MAX, fp2);

	fclose(fp2); fclose(fp);

}



void leArquivoResultado (){

	FILE *fp = fopen("resultado.txt", "rb");
	struct registro alunos[MAX];

	if (fp == NULL) exit(1);

	fread(alunos, sizeof(struct registro), MAX, fp);

	for (int i = 0; i < MAX; i++){
		printf("\nnro usp : %s", alunos[i].nrousp);
		printf("\nnome : %s", alunos[i].nome);
		printf("\nidade : %d", alunos[i].idade);
		printf("\nvalido : %d", alunos[i].valido);
		printf("\n===========================");
	}

	fclose(fp);

}





void trocaRegistro(char *nome, int r1, int r2){

	struct registro reg1;
	struct registro reg2;

	FILE *arq = fopen(nome, "rb");

	rewind(arq);

	fseek(arq, r1 * sizeof(struct registro), SEEK_SET);
	fread(&reg1, sizeof(struct registro), 1, arq);

	fseek(arq, r2 * sizeof(struct registro), SEEK_SET);
	fread(&reg2, sizeof(struct registro), 1, arq);

	printf("reg1 : %d\n", reg1.idade);
	printf("reg2 : %d\n", reg2.idade);




	swap(&reg1, &reg2);





	fseek(arq, r1 * sizeof(struct registro), SEEK_SET);
	fwrite(&reg1, sizeof(struct registro), 1, arq);

	fseek(arq, r2 * sizeof(struct registro), SEEK_SET);
	fwrite(&reg2, sizeof(struct registro), 1, arq);


	fclose(arq);

}



int main(){

	char nome[20];

	// cria arquivo novo 
	criaArquivoFixo();
	//leArquivoResultado();
	trocaRegistro(gets(nome), 4, 5);
	leArquivoResultado();

	return 0;
}