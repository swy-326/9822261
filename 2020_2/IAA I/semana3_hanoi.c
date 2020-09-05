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

Em caso base em que há apenas um disco, ou seja, n == 1, o disco é movimentado diretamente da origem para o destino. 

Em outros casos em que o número de discos é maior igual que 2:
- Primeiramente, pela chamada da linha 6, movimenta-se todos os discos, exceto o disco maior, da primeira à segunda haste, utilizando como auxiliar a terceira haste. Foi passado como parâmetro (n - 1), e não (n), pois o disco maior deve ser movimentado separadamente.
- Supondo que na função acima (n - 1) discos foram movimentados corretamente, falta movimentar o último disco maior que ficou na primeira haste. Como o parâmetro n da função Hanói é 1 na linha 7, trata-se de um caso base em que movimenta-se direto da origem (primeira haste) para o destino (terceira haste - onde se encontra vazia).
- Por último, supondo que a etapa anterior foi executada corretamente, apenas falta movimentar todos os (n - 1) discos que ficaram na segunda haste. Assim, a função chamada recursivamente na linha 8 movimenta todos eles para a terceira haste, onde se encontra o disco maior.

Assim, todos os discos são movimentados de origem ao destino, como prometida pela função Hanói.

*/
