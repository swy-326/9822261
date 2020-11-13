import java.util.Scanner;
import java.io.File;
import java.io.FileNotFoundException;
import java.util.regex.Pattern;
import java.util.regex.*;


class aa {

    public static boolean isPrime(int n){ 
        if (n <= 1) 
            return false; 
  
        for (int i = 2; i < n; i++) if (n % i == 0) 
            return false; 
  
        return true; 
    }    

    public static void main(String[] args) {

        int[] arr = new int[5133];
        int index = 0;
        for(int j = 1; j <= 50000; j++){
            if( isPrime(j) ){
                arr[index] = j;
                index++;
            }
        }
        

    	Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        sc.nextLine();


        for(int i = 0; i < n; i++){

            int numero = sc.nextInt();

            if ( isPrime(numero) ){

                int k = 0; int count = 0;
                while(numero >= arr[k] && k < 5133){
                    if(numero >= arr[k]) count++;
                    k++;
               }

                int valor = (int)  ( (Math.log(count) / Math.log(2)));
                System.out.println("Ipi pegou jenipapo do galho " + valor);     
            }

            else{
                System.out.println("Viajou, Ipi? Aqui tem essa fruta nao");
            } 
            
        }
    }
}