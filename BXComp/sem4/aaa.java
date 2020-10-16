import java.text.DecimalFormat;
import java.util.Locale;
import java.util.Scanner;

class aaa {

public static String reverse(String a) {
        int j = a.length();
        char[] newWord = new char[j];
        for (int i = 0; i < a.length(); i++) {
            newWord[--j] = a.charAt(i);
        }
        return new String(newWord);
    }

    public static void main(String[] args) {
        // write your code here
        Scanner entrada = new Scanner(System.in);
        entrada.useLocale(Locale.US);
        int quantidade = entrada.nextInt();
        entrada.nextLine();

        for (int i = 0; i < quantidade; i++) {
            String frase = entrada.nextLine();

            String N1 = entrada.next();
            String N2 = entrada.next();
            entrada.nextLine();


            N1 = reverse(N1);
            N2 = reverse(N2);
            
            String frase2 = frase.replace("(x)", N2);
            String frase3 = frase2.replace("(y)", N1);

            System.out.println(frase3);
        }

        entrada.close();
    }}