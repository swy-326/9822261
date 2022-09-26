import java.util.Scanner;
import java.io.File;
import java.io.FileNotFoundException;

// https://www.codesdope.com/blog/article/backtracking-to-solve-a-rat-in-a-maze-c-java-pytho/

public class Main {

    static int [][] m = new int[5][5];
    static int [][] visitou = new int[5][5]; //USADA PARA VERIFICAR SE A POSIÇÃO JÁ FOI VISITADA

    // condicoes validas
    public static boolean podeAvancar(int i, int j){
        return ( i >= 0 && i <= 4 && j >= 0 && j <= 4 && m[i][j] == 0 && visitou[i][j] == 0);
    }

    // funcao principal para achar solucao
    public static boolean visita(int i, int j) {

        // se chegou no final
        if (i == 4 && j == 4 && m[i][j] == 0){
            visitou[i][j] = 1;
            return true;
        } 

        // se for um indice valido
        if (podeAvancar(i, j)){

            visitou[i][j] = 1;
            if( visita(i+1, j) ) return true;
            if( visita(i, j+1) ) return true;
            if( visita(i-1, j) ) return true;
            if( visita(i, j-1) ) return true;

            // backtracking
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


            // recebe numero e atribui "nao-visitado" para matriz visistou
            sc.nextLine();
            for(int i = 0; i < 5; i++) {
                for(int j = 0; j < 5; j++) {
                    visitou[i][j] = 0;
                    m[i][j] = sc.nextInt();
                }
            }


            // achar solucao
            sucesso=visita(0, 0);

            if(sucesso) System.out.println("COPS");
            else System.out.println("ROBBERS");


            // imprime a solucao
            for(int i = 0; i < 5; i++) {
                for(int j = 0; j < 5; j++) {
                    System.out.printf("%d ", visitou[i][j]);
                }
                System.out.printf("\n");
            }
            System.out.printf("\n\n\n");

            cont++;
        }
    }
}