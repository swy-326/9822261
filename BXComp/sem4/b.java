import java.util.Scanner;
import java.io.File;
import java.io.FileNotFoundException;

class bx {

    public static void main(String[] args) {

    	Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
        sc.nextLine();

		for (int i = 0; i <n; i++){

  			String str = sc.nextLine();

            String[] numeros = str.split(" ");
            int tam = numeros.length; 

            int mitad = tam/2;
            for(int j = 0; j < tam-1; j+=2){
                System.out.print(numeros[j] + " ");
            }

            for(int k = 1; k <= tam-1; k+=2){
                System.out.print(numeros[k] + " ");                
            }
            
            System.out.println();


		}

    }


}