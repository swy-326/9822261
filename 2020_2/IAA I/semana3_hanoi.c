//FVFC

#include <stdio.h>

void hanoi(char ori, char dst, char aux, int n);

int main(){

	hanoi('1', '3', '2', 3);

	return 0;
}

void hanoi(char ori, char dst, char aux, int n){

	if (ori == '1' && dst == '2' && aux == '3') printf("caso 1, n : %d\n", n);
	else if (ori == '1' && dst == '3' && aux == '2') printf("caso 2, n : %d\n", n);
	else if (ori == '2' && dst == '3' && aux == '1') printf("caso 3, n : %d\n", n);
	else if (ori == '2' && dst == '1' && aux == '3') printf("caso 4, n : %d\n", n);
	else if (ori == '3' && dst == '1' && aux == '2') printf("caso 5, n : %d\n", n);
	else if (ori == '3' && dst == '2' && aux == '1') printf("caso 6, n : %d\n", n);

	if (n == 1) printf("%c >>> %c \n\n", ori, dst);
//	if (n == 1) printf("Mova de %c para %c \n", ori, dst);
	else {
		hanoi(ori, aux, dst, n-1); // 맨 밑을 제외하고 다 aux로 옮김
		hanoi(ori, dst, aux, 1); // ori에 있던 맨 밑 애를 dst로 옮김
		hanoi(aux, dst, ori, n-1); // aux에 있던 모든 애들을 dst로 옮김
	}
}

/*

sempre na ultima instancia:


hanoi(ori, aux, dst, n-1)              hanoi(ori, dst, aux, 1)         hanoi(aux, dst, ori, n-1)

   |         |         |              |         |         |
   |         |         |      ->      |         |         |         ->        完
  ***        *         |              |         *        ***
 -------------------------           ---------------------------



   |         |         |              |         |         |
   |         *         |      ->      |         *         |         ->        完
 *****      ***        |              |        ***      *****
--------------------------           ---------------------------


   |         |         |              |         |         |
   |         *         |      ->      |         *         |         ->        完
   |        ***        |              |        ***        |
*******    *****       |              |       *****    *******

--------------------------           ---------------------------


*/



/*

n = 3

hanoi (1, 3, 2, 3) // case 2
	hanoi (1, 2, 3, 2) // case 1
		hanoi (1, 3, 2, 1) // case 2
			print 1 >> 3
		hanoi (1, 2, 3, 1) // case 2
			print 1 >> 2
		hanoi (3, 2, 1, 1) // case 6
			print 3 >> 2

	hanoi (1, 3, 2, 1) // case 2
		print 1 >> 3

	hanoi (2, 3, 1, 2)
		hanoi (2, 1, 3, 1) // case 4
			print 2 >> 1
		hanoi (2, 3, 1, 1) // case 3
			print 2 >> 3
		hanoi (1, 3, 2, 1) // case 2
			print 1 >> 3
*/




/*
Output : 

caso 2, n : 3
caso 1, n : 2
caso 2, n : 1
1 >>> 3

caso 1, n : 1
1 >>> 2

caso 6, n : 1
3 >>> 2

caso 2, n : 1
1 >>> 3

caso 3, n : 2
caso 4, n : 1
2 >>> 1

caso 3, n : 1
2 >>> 3

caso 2, n : 1
1 >>> 3

*/


/*

Se n == 1, o unico disco é movido de local de origem para o destino
Se n >= 2:
	primeiramente executa hanoi(ori, aux, dst, n-1), o que move todos os discos acima do disco maior para auxiliar
	segundo executa hanoi(ori, dst, aux, 1), o que move o disco maior para o destino
	terceiro executa hanoi(aux, dst, ori, n-1), o que move o resto dos discos ordenados haste auxiliar

*/