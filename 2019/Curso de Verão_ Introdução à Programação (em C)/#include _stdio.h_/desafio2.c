#include <stdio.h>
#include <string.h>

#define TRUE 1
#define FALSE 0
#define MAX 500

int main(){
	char frase[MAX], plvra1[MAX], plvra2[MAX];
	char modf[MAX];
	int posicoes[MAX];

	int truefalse = TRUE;
	int tam1, tam2, difTam;
	int qntd = 0, ord;

	int i, j, p = 0;

	printf("frase : ");
	scanf(" %[^\n]", frase);
	printf("plvra1 : ");
	scanf(" %[^\n]", plvra1);
	printf("plvra2 : ");
	scanf(" %[^\n]", plvra2);

	tam1 = strlen(plvra1);
	printf("tam1 : %d\n", tam1);
	tam2 = strlen(plvra2);
	printf("tam2 : %d\n", tam2);
	difTam = tam1 - tam2;
	printf("difTam : %d\n", difTam);

	for (i = 0; frase[i] != '\0'; i++){
		printf("ddddddddd\n");
		if (frase[i] == plvra1[0]){
			printf("00000000000\n");
			for (j = 1; j < tam1 && truefalse; j++){
				printf("15151515151\n");
				if (frase [i+j] != plvra1[j]) {
					truefalse = FALSE;
					printf("111111111\n");
				}
			}
		}
		if (truefalse) {
			qntd += 1;
			posicoes[p] = i;
			p++;
			i += j -1;
			printf("222222222\n");
		} else {
			truefalse = TRUE;
			printf("33333333333\n");
		}
	}

	printf("5555555555\n");
	posicoes[p] = '\0';
	printf("66666666666\n");

	for (i = 0; i < 7; i++){
		printf("poiscoes : %d\n", posicoes[i]);
	}

	printf("\n");
	printf("qntd : %d\n", qntd);

	return 0;
}