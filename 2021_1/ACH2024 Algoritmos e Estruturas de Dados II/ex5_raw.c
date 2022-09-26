/*

	https://stackoverflow.com/questions/18468229/concatenate-two-char-strings-in-a-c-program/18468387

	Teh/9.2/Oh aew/10/Tharn/3.8/Judy/26/Sungwon Yoon/49.12/Bass/49.00/Boss/63/Mean/190/Goy/3.1/kate d/34.1/aaaaa/242/bbbbbbbb/43/ccccccccc/2/dddd ddd/45.5/eeeeee/3/f/2/g/6/h/63/i/0.1/j/-2/k/23/l/243/m/253/n/76/o/19/p/9/q/53/r/2830/s/45/t/3849/

	cd directory
	youtube-dl -f "bestvideo[ext=mp4]+bestaudio[ext=m4a]/mp4" --playlist-items 1-4 --restrict-filenames -o "%(title)s" https://youtube.com/playlist?list=PLIsLFZTOf0vimqbZRBGY6COovJfBkR1Eo

*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#define MAX 30

struct registro {
	char nome[20];
	float nota;
};


void arqFix(char *nome){

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
		printf("%s\n", alunos[prox].nome);
		
		fscanf(fp, "%f/", &alunos[prox].nota);
		printf("%f\n", alunos[prox].nota);

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




// ------------------------------------



#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define MAX 30

struct registro {
	char nome[20];
	float nota;
};



int main(){


	FILE *fp = fopen("notas_struct.txt", "rb");
	struct registro alunos[MAX];

	if (fp == NULL) exit(1);

	fread(alunos, sizeof(struct registro), MAX, fp);

	for (int i = 0; i < MAX; i++){
		printf("\n\nnome : %s", alunos[i].nome);
		printf("\nnota : %f", alunos[i].nota);
	}


	fclose(fp);
	return 0;
}



// -------------------



#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define MAX 30

struct registro {
	char nome[20];
	float nota;
};


// https://stackoverflow.com/questions/20007872/how-do-i-read-a-float-value-when-this-value-have-comma-instead-of-dot


int main(){

	FILE *fp = fopen("nomes.txt", "rb");
	if (fp == NULL) exit(1);


	FILE *fp2 = fopen("notas_struct.txt", "wb");
	if (fp2 == NULL) exit(1);

	struct registro alunos[MAX];
	int prox = 0; 

	
	while (prox < MAX) {

		fscanf(fp, "%[^/]%*c", alunos[prox].nome);
		printf("%s\n", alunos[prox].nome);
		
		fscanf(fp, "%f/", &alunos[prox].nota);
		printf("%f\n", alunos[prox].nota);

		prox++;

	}

	fwrite(alunos, sizeof(struct registro), MAX, fp2);

	fclose(fp2); fclose(fp);
	return 0;
}



// -----------------------------



#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define MAX 5

struct registro {
	char nome[20];
	float nota;
};



int main(){


	FILE *fp2 = fopen("notas_struct.txt", "wb");
	struct registro alunos[MAX];
	int prox = 0; 

	if (fp2 == NULL){
		printf("\n");
		printf("Error cannot open file");
		exit(1);		
	}

	
	while (prox < MAX) {

		printf("nome : "); fflush(stdin); gets(alunos[prox].nome);
		printf("nota : "); fflush(stdin); scanf("%f", &alunos[prox].nota);
		prox++;

	}

	fwrite(alunos, sizeof(struct registro), MAX, fp2);

	fclse(fp2);
	return 0;
}

















#include <stdio.h>
#include <stdlib.h>

// https://youtu.be/jxTGwfoD4Nc

#define MAX 5

struct registro {
	char nome[20];
	float nota;
};



int main(){


	FILE *fp = fopen("notas_struct.txt", "rb");
	struct registro alunos[MAX];

	if (fp == NULL) exit(1);

	fread(alunos, sizeof(struct registro), MAX, fp);

	for (int i = 0; i < MAX; i++){
		printf("\n\nnome : %s", alunos[i].nome);
		printf("\nnota : %f", alunos[i].nota);
	}


	fclose(fp);
	return 0;
}
