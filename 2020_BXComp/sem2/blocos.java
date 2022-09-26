import java.util.Scanner;
import java.io.File;
import java.io.FileNotFoundException;

class blocos {

    public static void main(String[] args) {

    	Scanner sc = new Scanner(System.in);
    	int n = sc.nextInt();

        for (int i = 0; i < n; i++){
            int s = sc.nextInt();
            if (s <= 1) System.out.println("Thoth seu doido isso nao eh uma piramide");
            else {
                int tam = 0;
                int num = 1;

                for(int j = 0; j < s; j++){
                    tam += num;
                    num += 1;
                }
                System.out.println("Sao necessarios " + tam + " blocos para a construcao");
            }
        }

	}
}
