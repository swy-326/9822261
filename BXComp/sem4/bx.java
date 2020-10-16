import java.util.Scanner;
import java.io.File;
import java.io.FileNotFoundException;

class bx {

    public static void main(String[] args) {

    	Scanner sc = new Scanner(System.in);

        String strInput = sc.nextLine();
        String[] casos = strInput.split("/n");


        String nome = "a";
        
		while(nome != ""){

            int vdd = 0;
            nome = sc.nextLine();
            String nomeLower = nome.toLowerCase();


            if( nomeLower.equals("fim") ){
                System.out.println();
                break;
            }


            for(String caso : casos){

                caso = caso.toLowerCase();
                
                if (caso.contains(nomeLower)){

                    String tempoVida = "";


                    caso = caso.replaceAll("[^0-9]+", " ");

                    String[] numeros = caso.split(" ");

                    String ano1 = numeros[2];
                    String ano2 = numeros[3];

                    int tempoReinado = Integer.parseInt(ano1) - Integer.parseInt(ano2);
                    if (tempoReinado < 0) tempoReinado *= -1;

                    System.out.print("Nome => " + nome);
                    System.out.print(", Tempo de Vida => " + numeros[1]);
                    System.out.print(" anos, Reinado => " + numeros[2] + "-" + numeros[3]);
                    System.out.print(", Tempo Reinado => " + tempoReinado + " anos\n");

                    vdd = 1;

                } 
            }
            if (vdd != 1) System.out.println("Erro => " + nome + " nao encontrado(a)");

        }
    }
}