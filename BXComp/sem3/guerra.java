package BX;

import java.util.Scanner;

public class guerra {

    public static int tam;
    public static int exer;
    public static boolean ganhou = false;

    public static int atacar(int tribo){

        int resposta = 0;
        int exertr = (int) (tribo/2);

        int p70 = (int) (0.7 * exer);
        int p10 = (int) (0.1 * exer);

        if(exertr <= p10){
            resposta = 1;
            exer = exer + exertr;
            ganhou = true;

        }
        else if(exertr <= p70){
            resposta = 2;
            exer = exer + (int) (exertr/2);
            ganhou = true;
        }

        return resposta;
    }

    public static void main(String[] args) {

        Scanner scan = new Scanner(System.in);

        int tam = scan.nextInt();
        exer = (int) (tam/2);

        while ( !(String ent = scan.nextLine()).equals("Bora Comemora!") ){

            String ataques[]= ent.split(" ");
            int tribo = Integer.parseInt(ataques[1]);

            int res = atacar(tribo);

            if(res == 0){
                System.out.println("Quale Comandante, melhor meter o pe...");
            }
            if(res == 1){
                System.out.println(ataques[0] + " aceitou o acordo e agora faz parte nosso Imperio!");
            }
            if(res == 2){
                System.out.print("Apos uma grande batalha, vencemos de ");
                System.out.println(ataques[0] + ", e eles se uniram ao nosso Imperio!");
            }
        }
        System.out.println("Nosso Imperio agora tem " + exer + " soldados!");
        
        if(ganhou){
            System.out.println("Que Mama-Quilla abencoe as novas terras e seu plantio!");
        }

    }
}

/*
1000
Jotunraim 100
Yorha 700
Comprex 1160
Bora Comemora!

Jotunraim aceitou o acordo e agora faz parte do nosso Imperio!
Apos uma grande batalha, vencemos de Yorha, e eles se uniram ao nosso
Imperio!
Quale Comandante, melhor meter o pe...
Nosso Imperio agora tem 725 soldados!
Que Mama-Quilla abencoe as novas terras e seu plantio!
 */