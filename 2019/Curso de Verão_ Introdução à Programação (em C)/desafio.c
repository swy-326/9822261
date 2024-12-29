#include <stdio.h>
#include <string.h>
#define MAX 500
#define TRUE 1
#define FALSE 0

int main(){
	char frase[MAX], plvra1[MAX], plvra2[MAX];
	char subst[MAX];
	int posicao[MAX];
	int tf = TRUE;
	int tam1, tam2, difTam;
	int i, k, j=0;

	scanf(" %[^\n]", frase);
	scanf(" %[^\n]", plvra1);
	scanf(" %[^\n]", plvra2);

	tam1 = strlen(plvra1);
	tam2 = strlen(plvra2);
	difTam = tam1 - tam2;

	// 단어 찾기 및 위치 보관
	for (i = 0, k = 0; frase[i] != '\0'; i++){
		if (frase[i] == plvra1[0]){
			while (tf){
				j = 0;
				while (j < tam1){
					printf("caso 0\n"); //loop
					if (frase[i] == plvra1[j]){
						i++;
						j++;
					} else { 
						tf = FALSE;
						printf("caso 2\n"); //loop
					}
				}
			}
			if (tf){
				posicao[k] = i;
				k++;
			} else {
				tf = TRUE;
			}

		}

	}

	posicao[k] = '\0';


	for (i=0; posicao[i] != '\0'; i++){
		printf("%d\n", posicao[i]);
	} 


	return 0;
}