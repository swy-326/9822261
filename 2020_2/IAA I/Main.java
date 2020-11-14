import java.util.Scanner;
import java.io.File;
import java.io.FileNotFoundException;

// https://www.codesdope.com/blog/article/backtracking-to-solve-a-rat-in-a-maze-c-java-pytho/


public class Main {

    static int [][] m = new int[5][5];
    static int [][] visitou = new int[5][5]; //USADA PARA VERIFICAR SE A POSIÇÃO JÁ FOI VISITADA

    public static boolean podeAvancar(int i, int j){
        return ( i >= 0 && i <= 4 && j >= 0 && j <= 4 && m[i][j] == 0 && visitou[i][j] == 0);
    }

    public static boolean visita(int i, int j) {

        boolean temp = false;

        if (i == 4 && j == 4 && m[i][j] == 0){
            visitou[i][j] = 1;
            return true;
        } 

        if (podeAvancar(i, j)){

            visitou[i][j] = 1;
            if( visita(i+1, j) ) return true;
            if( visita(i, j+1) ) return true;
            if( visita(i-1, j) ) return true;
            if( visita(i, j-1) ) return true;

            visitou[i][j] = 0;
            return false;

        }
        
        return false;
    } 
    

    public static void main(String[] args) throws Exception{

        Scanner sc = new Scanner(System.in);
        int casos = sc.nextInt();

        int cont = 0;

        while(cont < casos) {

            boolean sucesso = false;
            visitou = new int[5][5];

            sc.nextLine();

            for(int i = 0; i < 5; i++) {
                for(int j = 0; j < 5; j++) {
                    visitou[i][j] = 0;
                    m[i][j] = sc.nextInt();
                }
            }

            sucesso=visita(0, 0);

            if(sucesso) {
                System.out.println("COPS");
            }
            else {
                System.out.println("ROBBERS");
            }

            cont++;
        }
    }
}