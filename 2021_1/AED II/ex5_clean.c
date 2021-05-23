#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#define MAX 30

struct registro {
	char nome[20];
	float nota;
};


void arqFix (char *nome){

	FILE *fp = fopen(nome, "rb");
	if (fp == NULL) exit(1);

	char nome2[20]; strcpy(nome2, "novo");
	strcat(nome2, strrchr(nome, '.'));

	FILE *fp2 = fopen( nome2 , "wb");
	if (fp2 == NULL) exit(1);


	struct registro alunos[MAX];
	int prox = 0; 

	while (prox < MAX) {

		fscanf(fp, "%[^/]%*c", alunos[prox].nome);
		fscanf(fp, "%f/", &alunos[prox].nota);

		prox++;
	}


	fwrite(alunos, sizeof(struct registro), MAX, fp2);

	fclose(fp2); fclose(fp);

}



int main(){

	char nome[20];

	arqFix(gets(nome));

	return 0;
}

