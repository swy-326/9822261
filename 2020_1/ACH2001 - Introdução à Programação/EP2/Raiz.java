/*********************************************************************/
/**   ACH2001 - Introdução à Programação                            **/
/**   EACH-USP - Primeiro Semestre de 2020                          **/
/**   turma 02 - Luciano Antonio Digiampietri                       **/
/**                                                                 **/
/**   Segundo Exercício-Programa                                    **/
/**                                                                 **/
/**   Sungwon Yoon                            9822261               **/
/**                                                                 **/
/**   17-04-2020                                                    **/
/*********************************************************************/

import java.util.Scanner;

/*
	Cálculo para raiz quadrada
*/
public class Raiz {
	/*
		Calcula a raiz quadrada de um valor, com uma determinada
		precisão. Retorna esse valor, ou -1 quando:
		
		* a < 0
		* epsilon <= 0
		* epsilon >= 1
		
		Parâmetro:
			a - valor cuja raiz quadrada será calculada
			epsilon - precisão do cálculo
	*/
	static double raizQuadrada(double a, double epsilon) {

		double xAnterior, xProximo, diferencaAbs;

		// casos invalidos
		if(a < 0 || epsilon <= 0 || epsilon >= 1){
			return -1;
		}

		// calcula pela primeira vez
		xAnterior = a / 2;
		System.out.println("xAnterior : " + xAnterior);

		/*
		xProximo = (xAnterior + (a/xAnterior)) / 2.0;

		// calcula e torna absoluto o valor da diferenca
		diferencaAbs = xAnterior - xProximo;
		if (diferencaAbs < 0) diferencaAbs *= -1;

		// calcula x(i+1) ate a diferenca ficar menor que epsilon 
		while (diferencaAbs >= epsilon) {
			xAnterior = xProximo;
			xProximo = (xAnterior + (a/xAnterior)) / 2.0;

			diferencaAbs = xAnterior - xProximo;
			if (diferencaAbs < 0) diferencaAbs *= -1;
		} 
		*/

		do {
			xProximo = (xAnterior + (a/xAnterior)) / 2;
			System.out.println("xProximo : " + xProximo);

			diferencaAbs = xProximo - xAnterior;
			if (diferencaAbs < 0) diferencaAbs *= -1;
			System.out.println("Diferenca : " + diferencaAbs);

			xAnterior = xProximo;
			System.out.println("xAnterior : " + xAnterior);

		} while (diferencaAbs >= epsilon);

		return xProximo;

	}


	/*
		Apenas para seus testes. ISSO SERÁ IGNORADO NA CORREÇÃO
	*/
	public static void main(String[] args){

		double valor, precisao;

		/*
		// recebe o valor e epsilon
		Scanner sc = new Scanner(System.in);
		System.out.print("Valor : "); valor = sc.nextDouble();
		System.out.print("Epsilon : "); precisao = sc.nextDouble();
		sc.close();
		*/

		// debug
		valor = 0.0000001;
		precisao = 0.01;

		// guarda o resultado
		double resultado = raizQuadrada(valor, precisao);

		//  imprime o resultado
		if (resultado == -1) System.out.println(-1);
		else System.out.println("Raiz de : " + valor + " = " + resultado);
	}
}
