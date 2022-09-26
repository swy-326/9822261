import java.util.Scanner;
import java.io.File;
import java.io.FileNotFoundException;

class aa {

    public static void main(String[] args) {

    	Scanner sc = new Scanner(System.in);

        int[7][35] matriz;

        for(int i = 0; i < 7; i++){
            for(int j = 0; j < 35; j++){
                matriz[i][j] = sc.nextInt();
            }
        }
    }
}