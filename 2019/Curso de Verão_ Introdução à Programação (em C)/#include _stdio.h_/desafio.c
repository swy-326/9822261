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
	int tam1, tam2, difTam, tamFrase, tamSubst;
	int i, k, j, l, cont = 0, qtde = 0;

	scanf(" %[^\n]", frase);
	scanf(" %[^\n]", plvra1);
	scanf(" %[^\n]", plvra2);

	tam1 = strlen(plvra1);
	tam2 = strlen(plvra2);
	difTam = tam1 - tam2;
	tamFrase = strlen(frase); 

	// 단어 찾기 및 위치 보관
	for (i = 0, k = 0; frase[i] != '\0'; i++){
		if (frase[i] == plvra1[0]){
			j = 0;
				while (j < tam1 && tf){
					if (frase[i] == plvra1[j]){
						i++;
						j++;
					} else { 
						tf = FALSE;
					}
				}
			if (tf){
				posicao[k] = i - tam1;
				k++;
				qtde++;
			} else {
				tf = TRUE;
			}

		}

	}

	posicao[k] = '\0';

	tamSubst = tamFrase + (difTam * qtde);

	for (i = 0, j = 0, k = 0; frase[i] != '\0'; i++, j++){
		if (i == posicao[k]){
			for (l = 0; l < tam2; l++, j++){
				subst[j] = plvra2[l];
			}
			cont++;
			k++;
		}
		subst[j] = frase[i+(difTam*cont)];
	}

	subst[j] = '\0';

	printf("why\n");
	printf("%s\n", subst);

	return 0;
}