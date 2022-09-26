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
            int d1 = Integer.parseInt( numeros[0] );
            int d2 = Integer.parseInt( numeros[1] ); 
            int vy = Integer.parseInt( numeros[2] ); 
            int vx = Integer.parseInt( numeros[3] ); 

            int tempo = ( (vy / 10)*2 );
            int distancia = ( tempo * vx );

            if (distancia >= d1 && distancia <= d2) System.out.println("YEEEEET");
            else System.out.println("Traga mais uma pedra!!");

		}

    }


}