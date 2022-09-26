import java.util.Scanner;

/*********************************************************************/
/**   ACH2001 - Introdução à Programação                            **/
/**   EACH-USP - Primeiro Semestre de 2020                          **/
/**   turma 02 - Luciano Antonio Digiampietri                       **/
/**                                                                 **/
/**   Primeiro Exercício-Programa                                   **/
/**                                                                 **/
/**   Sungwon Yoon                                 9822261          **/
/**                                                                 **/
/**   27-03-2020                                                    **/
/*********************************************************************/

/*
	Caixa eletrônico das Ilhas Weblands, com estoque ilimitado de cédulas
	de B$50,00, B$10,00, B$5,00 e B$1,00.
*/
public class CaixaEletronico {
	// Número de cédulas de B$50,00
	static int n50 = 0;
	
	// Número de cédulas de B$10,00
	static int n10 = 0;

	// Número de cédulas de B$5,00
	static int n5 = 0;
	
	// Número de cédulas de B$1,00
	static int n1 = 0;


	/*
		Determina a quantidade de cada nota necessária para totalizar
		um determinado valor de retirada, de modo a minimizar a quantidade
		de cédulas entregues.
		
		Abastece as variáveis globais n50,n10, n5 e n1 com seu respectivo
		número de cédulas.
		
		Parâmetro:
			valor - O valor a ser retirado
	*/
	static void fazRetirada(int valor) {
		int i;

		//Calcula somente quando o valor inserido for maior que 0
		if (valor < 0){
			n50 = -1;
			n10 = -1;
			n5 = -1;
			n1 = -1;
		} else if (valor == 0){
			n50 = 0;
			n10 = 0;
			n5 = 0;
			n1 = 0;
		} else {
			while (valor >= 50){
				valor -= 50;
				n50++;
			}
			while (valor >= 10){
				valor -= 10;
				n10++;
			}
			while (valor >= 5){
				valor -= 5;
				n5++;
			}
			while (valor >= 1){
				valor -= 1;
				n1++;
			}
		}
	}
	
	public static void main(String[] args) 
	{
		// Recebe o valor
		Scanner sc = new Scanner(System.in);
		System.out.print("Digite o valor : ");
		int valor = sc.nextInt();
		sc.close();

		// Calcula a quantidade de notas:
		fazRetirada(valor);

		// Imprime a quantidade de notas
		System.out.println("Notas de 50: "+n50);
		System.out.println("Notas de 10: "+n10);
		System.out.println("Notas de 5:  "+n5);
		System.out.println("Notas de 1:  "+n1);
	}
}
