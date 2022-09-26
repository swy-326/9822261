import java.util.Scanner;

public class RaizRec {
	static double raizQuadrada(double a, double epsilon) {

		if(a < 0 || epsilon <= 0 || epsilon >= 1){
			return -1;
		}

		double xAnterior, xProximo;

		xAnterior = a / 2;
		xProximo = (xAnterior + (a/xAnterior)) / 2;

		return raizRecursivo(a, epsilon, xAnterior, xProximo);
	}

	static double raizRecursivo(double a, double epsilon, double xAnterior, double xProximo){

		if (xAnterior - xProximo < epsilon){
			return xProximo;
		}

		xAnterior = xProximo;
		xProximo = (xAnterior + (a/xAnterior)) / 2;

		return raizRecursivo(a, epsilon, xAnterior, xProximo);

	}

	public static void main(String[] args) {
		double valor = 9;
		double precisao = 0.001;
		System.out.println("Raiz de : "+valor+" = "+raizQuadrada(valor, precisao));
	}
}
