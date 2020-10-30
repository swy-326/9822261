import java.util.Scanner;
import java.io.File;
import java.io.FileNotFoundException;
import java.util.regex.Pattern;


class bx {

    public static void main(String[] args) {

    	Scanner sc = new Scanner(System.in);
        String pattern = "\\[(.*)+\\]";

        int n = sc.nextInt();
        sc.nextLine();

        for(int i = 0; i < n; i++){

            String str1 = sc.nextLine();
            String str = str1.toLowerCase();

            if (str.contains("[oxufala]")) System.out.println("...");
            else if ( Pattern.matches(pattern, str) ) System.out.println(str1);
            else System.out.println("...");
        }

    }
}
