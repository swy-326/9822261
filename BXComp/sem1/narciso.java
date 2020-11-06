import java.util.Scanner;
import java.io.File;
import java.io.FileNotFoundException;

class bx {

    public static long fatorial (int n){
            long f = 1;
            if (n != 0) {
                f = n * fatorial(n - 1);
            }
            return f;
    }

    public static void narciso (int num1, int num2, char ope) {
        if (ope == 'n') {
            System.out.println(num1 + num2);
        }
        if (ope == 'a') {
            System.out.println(num1 - num2);
        }
        if (ope == 'r') {
            System.out.println(num1 * num2);
        }
        if (ope == 'c') {
            System.out.println(num1 / num2);
        }
        if (ope == 'i') {
            System.out.println(fatorial(num1) / fatorial(num2));
        }
        if (ope == 's') {
            System.out.println(num1 % num2);
        }
        if (ope == 'o') {
        	double a = Math.pow(num1, num2)
            System.out.printf("%.0f\n");
        }
    }

    public static void main(String[] args) {

    	Scanner sc = new Scanner(System.in);
		int num = sc.nextInt();

		for (int i = 0; i <num; i++){

  				String str = sc.next();

  				String numeros[] = str.split("\\D+");
  				String operacao[] = str.split("\\d+");

  				int num1 = Integer.parseInt(numeros[0]);
  				int num2 = Integer.parseInt(numeros[1]);

  				char op = operacao[1].charAt(0);

  				narciso(num1, num2, op);
		}
    }
}
