#include <stdio.h>
#include <stdlib.h>
#include "info.h"

// https://www.youtube.com/watch?v=VMFKz7Klx7I

int main(){

	// "variavel" de tipo user contido em info.h
	struct user judyy;
	struct user swyy;

	judyy.userID = 9822261;
	swyy.userID = 9822262;

	puts("Enter the first name of judyy: ");
	gets(judyy.firstName);
	puts("Enter the first name of swyy: ");
	gets(swyy.firstName);

	printf("Judyy userID : %d\n", judyy.userID);
	printf("Judyy firstName : %s\n", judyy.firstName);
	printf("Swyy userID : %d\n", swyy.userID);
	printf("Swyy firstName : %s\n", swyy.firstName);

	return 0;
}
