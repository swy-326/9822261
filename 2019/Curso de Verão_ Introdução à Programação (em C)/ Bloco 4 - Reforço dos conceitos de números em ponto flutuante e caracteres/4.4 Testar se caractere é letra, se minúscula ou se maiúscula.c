#include <stdio.h>
int main(){
  char c;

  do{ 
 		scanf(" %c", &c);
 		switch(c){
 			case 'A' ... 'Z' : printf("2\n");
 			break;
 			case 'a' ... 'z' : printf("1\n");
 			break;
      case '0' : break;
 			default : printf("-1\n");
 			break;
    }
  } while (c != '0');

  return 0;
}