#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct { 
	int v1;
	int v2;
	int custo;
} REGISTRO;


int buscaAresta (int v1, int v2, char *nome){

	FILE *fp = fopen(nome, "rb");
	if (fp == NULL) exit(1);

	fseek(fp, sizeof(int), SEEK_SET);

	REGISTRO tempReg;
	while (fread(&tempReg, sizeof(REGISTRO), 1, fp) == 1){
		if (tempReg.v1 == v1 && tempReg.v2 == v2){
			fclose(fp);
			return tempReg.custo;
		}
	}

	fclose(fp);
	return -1;
}


int main(){

	int v1 = 8;
	int v2 = 9;
	char nome[20];

	int custo = buscaAresta(v1, v2, gets(nome));

	return 0;
}
