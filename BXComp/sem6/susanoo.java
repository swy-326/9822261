import java.util.Scanner;
import java.io.File;
import java.io.FileNotFoundException;
import java.util.regex.Pattern;


class a {

    public static void main(String[] args) {

    	Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        sc.nextLine();


        for(int i = 0; i < n; i++){

            int[] flag = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
            int errado = 0;
            int quelinea = 0;

            // cada linea
            for(int j = 0; j < 18; j++){

                int jaTem = 0;

                String str = sc.nextLine();
                String[] linha = str.split("(?!^)");

                // ultima linea no necesita ver
                if (j != 18 && errado != 1){
                
                	if (str.contains("C")){

                		// cada letra
                		for (int k = 0; k < 17 && errado != 1; k++){

                			if (linha[k].equals("C")){
                				
                				if(flag[k] == 1 || jaTem == 1){
                					quelinea = k;
                					errado = 1;
                				}
                				else {
                					flag[k] = 1;
                					jaTem = 1;
                				}

                			}
              
                	}


            	   
                	}

                }

            }

            System.out.printf("que linea : %d\n", quelinea);
            if (errado == 0) System.out.println("Bora Susanoo, ja vou pedir o bolo de casamento!");
            else System.out.println("Yas... Susanoo, nessa pedra nao da pra fazer o 1v8, so vai feedar.");

        }
    }
}
