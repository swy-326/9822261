import java.util.Scanner;
import java.io.File;
import java.io.FileNotFoundException;


class pp {

    public static void main(String[] args) {

    	Scanner sc = new Scanner(System.in);

        int n = sc.nextInt();
        sc.nextLine();

        for(int i = 0; i < n; i++){

            String aa = sc.nextLine();

            String[] test = aa.split(" ");
            long a = Long.parseLong(test[0]);
            long b = Long.parseLong(test[1]);

            if (a < 0) a *= -1;
            if (b < 0) b *= -1;

            double distance = Math.sqrt(b*b + a*a);

        //    System.out.println("maior : " + distance);
            if (distance >= 0 && distance <= 40)System.out.println("Faixa amarela! Voce sera o melhor cacador da aldeia!");
            if (distance > 40 && distance <= 55) System.out.println("Faixa vermelha! Quase la, nao desista!");
            if (distance > 55 && distance <= 70) System.out.println("Faixa azul! Por pouco!");
            if (distance > 70 && distance <= 85) System.out.println("Faixa preta! Continue tentando!");
            if (distance > 85 && distance <= 100)System.out.println("Faixa branca, preste atencao!!");
            else if (distance > 100) System.out.println("Vish, passou longe...");



/*

            int x = 0, y = 0;

            if (a <= 40) x = 0;
            else if (a <= 55) x = 1;
            else if (a <= 70) x = 2;
            else if (a <= 85) x = 3;
            else if (a <= 100) x = 4; 
            else if (a > 100) x = 5;

            if (b <= 40) y = 0;
            else if (b <= 55) y = 1;
            else if (b <= 70) y = 2;
            else if (b <= 85) y = 3;
            else if (b <= 100) y = 4; 
            else if (b > 100) y = 5;

            int z = -5;

            if (x < y) z = x;
            else z = y;


                if (z == 0) System.out.println("Faixa amarela! Voce sera o melhor cacador da aldeia!");
                else if (z == 1) System.out.println("Faixa vermelha! Quase la, nao desista!");
                else if (z == 2) System.out.println("Faixa azul! Por pouco!");
                else if (z == 3) System.out.println("Faixa preta! Continue tentando!");
                else if (z == 4) System.out.println("Faixa branca, preste atencao!!");
                else System.out.println("Vish, passou longe...");
*/

        }
    }
}