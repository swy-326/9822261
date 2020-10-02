import java.util.Scanner;
import java.io.File;
import java.io.FileNotFoundException;

class aaa {

    public static void main(String[] args) {

    	Scanner sc = new Scanner(System.in);
    	int n = sc.nextInt();

    	for (int k = 0; k < n; k++){
    		int i = sc.nextInt();
    		int j = sc.nextInt();

    		if (i == 9) System.out.println("Esse deve ser preenchido!");
    		else if ( i <= 4) System.out.println("Ei, isso nao vai formar um triangulo!");
    		else if (i == 5 && j == 4 || j == 5) System.out.println("Esse deve ser preenchido!");
    		else if ( i == 6 && j >= 3 && j <= 6) System.out.println("Esse deve ser preenchido!");
    		else if (i == 7 && j >= 2 && j <= 7) System.out.println("Esse deve ser preenchido!");
    		else if (i == 8 && j >= 1 && j <= 8) System.out.println("Esse deve ser preenchido!");
    		else System.out.println("Ei, isso nao vai formar um triangulo!");

    	}

	}
}
