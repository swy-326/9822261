import java.util.Scanner;
import java.io.File;
import java.io.FileNotFoundException;


class a {

    public static void main(String[] args) {

    	Scanner sc = new Scanner(System.in);

        int n = sc.nextInt();
        sc.nextLine();

        for(int i = 0; i < n; i++){

            int a = sc.nextInt();
            int b = sc.nextInt();

            System.out.println(a+b);

        }
    }
}