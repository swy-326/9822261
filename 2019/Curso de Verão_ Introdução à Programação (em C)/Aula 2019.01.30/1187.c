#include <stdio.h>
#define MAX 12
int main(){
	//uri 1187
	float matriz[MAX][MAX], total = 0;
	int i, j;
	char O;

	scanf("%c", &O);
	for (i=0; i < MAX; i++){
		for (j=0; j < MAX; j++){
			scanf("%f", &matriz[i][j]);
		}
	}

	for (i=0; i <= 4; i++){
		for (j=1; j <= MAX-2-i; j++)
		total += matriz[i][i+j];
	}

	switch(O){
		case 'S' : printf("%.1f\n", total); break;
		case 'M' : printf("%.1f\n", total/MAX); break;
	}

	return 0;
}