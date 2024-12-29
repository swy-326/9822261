#include <stdio.h>
int main(){
	int num, somaPos = 0, somaNeg = 0;
	scanf("%d", &num);

	while (num != 0){
		if (num > 0) somaPos += num;
		else if (num < 0) somaNeg += num;
		scanf("%d", &num);
	}

	printf("%d %d", somaPos, somaNeg);

	return 0;
}