#include <stdio.h>
#define MAX 12
int main(){
	//uri 1181
	float matriz[MAX][MAX], total = 0;
	int L, i, j;
	char T;

	scanf("%d", &L);
	scanf(" %c", &T);

	for (i = 0; i < MAX; i++){
		for (j=0; j < MAX; j++){
			scanf("%f", &matriz[i][j]);
		}
	}

	switch(T){
		case 'S': for (i = 0; i < MAX; i++){
					total += matriz[L][i];
				} printf("%.1f\n", total); 
				break;

		case'M': for (i = 0; i < MAX; i++){
					total += matriz[L][i];
				} printf("%.1f\n", total/MAX);
				break;
	}


	return 0;
}