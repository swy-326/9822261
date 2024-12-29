#include <stdio.h>
int main(){
	int h, a, b;
	scanf("%d %d %d", &h, &a, &b);

	if (a < b){
		a = a + b;
		b = a - b;
		a = a - b;
	}

	if (a > h) {
		a = a + h;
		h = a - h;
		a = a - h;
	}

	if (h*h == a*a + b*b){
		printf("1 %.d\n", h*h);
	} else {
		printf("0\n");
	}

	return 0;
}