import java.util.Scanner;
import java.io.File;
import java.io.FileNotFoundException;

/*
dia ensolarado - vermelho
sem nuvens - branco
muitas nuvens - verde
sol encoberto - amarelo
neblina - cinza
chuva - azul
garoa - roxo
tempestade - preto
sol fraco - laranha
*/

class a {

    public static void main(String[] args) {

        String[] ordem = {"branco", "vermelho", "verde", "preto", "amarelo", "azul", "cinza", "laranja", "roxo"};

    	Scanner sc = new Scanner(System.in);

        int n = sc.nextInt();
        sc.nextLine();

        for(int i = 0; i < n; i++){

            int flag2 = 0;
            int[] flag = {0, 0, 0, 0, 0, 0, 0, 0, 0};

            String str = sc.nextLine();
            String strLower = str.toLowerCase();

            if (strLower.contains("ensolarado")) flag[1] = 1;
            if (strLower.contains("sol fraco")) flag[7] = 1;
            if (strLower.contains("sem nuvens")) flag[0] = 1;
            if (strLower.contains("muitas nuvens")) flag[2] = 1;
            if (strLower.contains("encoberto")) flag[4] = 1;
            if (strLower.contains("neblina")) flag[6] = 1;
            if (strLower.contains("chuva")) flag[5] = 1;
            if (strLower.contains("garoa")) flag[8] = 1;
            if(strLower.contains("tempestade")) flag[3] = 1;

            for(int j = 0; j < 9; j++){
                if( flag[j] == 1 ){
                    if (flag2 == 0){
                        System.out.print(ordem[j]);
                        flag2 = 1;
                    }
                    else if (flag2 != 0){
                        System.out.print(" - ");
                        System.out.print(ordem[j]);
                    }
                }
            }
            System.out.println();
        }
    }
}