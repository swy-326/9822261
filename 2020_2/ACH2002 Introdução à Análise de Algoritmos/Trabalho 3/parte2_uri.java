import java.util.Scanner;
import java.io.File;
import java.io.FileNotFoundException;

// Foi aceito com todos os casos de udebug e tres exemplos do uri, mas deu time limit exceeded no uri

class outro {

    public static int[] numeros;
    public static int f, n;

    public static boolean flag;
    public static char[] sinais;
    public static char[] sinaisFinal;


    public static void main(String[] args) {

    	Scanner sc = new Scanner(System.in);

        while( sc.hasNextLine() ){

            n = sc.nextInt();
            f = sc.nextInt();

            if (n == 0) break;

            numeros = new int[n]; sinais = new char[n]; 
            sinaisFinal = new char[n]; flag = false;

            for (int i = 0; i < n; i++){
                numeros[i] = sc.nextInt();
                sinaisFinal[i] = '0';
            }

            soma(0, 0);
            if (flag){
                for (int j = 0; j < n; j++){
                    System.out.printf("%c", sinaisFinal[j]);
                }
                System.out.printf("\n");
            }
            else{
                System.out.printf("*\n");
            }
        }
    }


    public static void soma(int atual, int soma){

        if (atual == n) {
            if (soma == f) {
                repeticao();
                flag = true;
            }
            return;
        }

        sinais[atual] = '+';
        soma(atual+1, soma+numeros[atual]);
        sinais[atual] = '0';

        sinais[atual] = '-';
        soma(atual+1, soma-numeros[atual]);
        sinais[atual] = '0';

    }

    public static void repeticao(){

        for (int i = 0; i < n; i++){

            if (sinaisFinal[i] == '+' && sinais[i] == '+') continue;
            else if (sinaisFinal[i] == '-' && sinais[i] == '-') continue;
            else if ((sinaisFinal[i] == '+' && sinais[i] == '-') || (sinaisFinal[i] == '-' && sinais[i] == '+')) sinaisFinal[i] = '?';
            else if (sinaisFinal[i] == '0') sinaisFinal[i] = sinais[i];
            
        }
    }

}