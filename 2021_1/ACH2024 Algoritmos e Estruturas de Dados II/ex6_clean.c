#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 2

struct registro {
	char nrousp[8]; // precisa de um espaco para guardar \0
	char nome[20];
	int idade;
	int valido; // | 1 = ok | 0 = excluido |
};



void trocaRegistro(char *nome, int r1, int r2){

	struct registro reg1;
	struct registro reg2;

	FILE *arq = fopen(nome, "rb+");

	rewind(arq);

	fseek(arq, r1 * sizeof(struct registro), SEEK_SET);
	fread(&reg1, sizeof(struct registro), 1, arq);

	fseek(arq, r2 * sizeof(struct registro), SEEK_SET);
	fread(&reg2, sizeof(struct registro), 1, arq);



	fseek(arq, r1 * sizeof(struct registro), SEEK_SET);
	fwrite(&reg2, sizeof(struct registro), 1, arq);

	fseek(arq, r2 * sizeof(struct registro), SEEK_SET);
	fwrite(&reg1, sizeof(struct registro), 1, arq);



	fclose(arq);

}



int main(){

	char nome[20];
	trocaRegistro(gets(nome), 0, 1);

	return 0;
}
