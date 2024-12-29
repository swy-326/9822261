#include <stdio.h>
#define MAX 200
int main(){
	char vetc[100][MAX];
	int n, i, j, soma = 0, z = 0, digito[MAX];

	scanf("%d", &n);

	for (i=0; i < n; i++){
		scanf(" %[^\n]", vetc[i]);
		for (j=0; vetc[i][j] != '\0'; j++){
			if(vetc[i][j] >= '0' && vetc[i][j] <= '9'){
				digito[z] = vetc[i][j]-48;
			 	z++;
			}
		}
	}

	digito[z] = '\0';

	for (z=0; digito[z] != '\0'; z++){
		soma += digito[z];
	}

	printf("soma %d\n", soma);
	for (z=0; digito[z] != '\0'; z++){
		printf("%d\t", digito[z]);
	}

	return 0;
}