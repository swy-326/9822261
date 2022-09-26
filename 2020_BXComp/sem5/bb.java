import java.util.Scanner;
import java.io.File;
import java.io.FileNotFoundException;

class bb {

    public static void main(String[] args) {

        int hoy = 30 + (10*30) + (30*12*2020);

    	Scanner sc = new Scanner(System.in);


        String n1 = sc.nextLine();
        int n = Integer.parseInt(n1);


        for(int i = 0; i < n; i++){

            String str1 = sc.nextLine();

            String[] dados = str1.split(" ");

            String sexo = dados[1];
            String[] datas = dados[0].split("/");

            
            int[] fechas = new int[3];
            int temp;

            temp = Integer.parseInt(datas[0]);
            fechas[0] = temp;

            temp = Integer.parseInt(datas[1]);

            fechas[1] = temp;
            temp = Integer.parseInt(datas[2]);
            fechas[2] = temp;


            int total = (fechas[0] + fechas[1]*30 + fechas[2]*12*30);
            int diff = hoy - total;


            double diffmeses = diff/30;
            int diff2 = (diffmeses - 1)/6;
                        


            if (diff2 % 2 == 0 && sexo.equals('H')) {
                System.out.println("Oxumare eh homem, podemos ver um arco-iris.");
            }
            else if (diff2 % 2 == 0 && sexo.equals('M')){ 
                System.out.println("Oxumare eh mulher, esta protegendo a terra.");
            }
            else if (diff2 % 2 != 0 && sexo.equals('H')) {
                System.out.println("Oxumare eh mulher, esta protegendo a terra.");
            }
            else {
                System.out.println("Oxumare eh homem, podemos ver um arco-iris.");
            }

//(diff2 % 2 != 0 && sexo.equals('M')) 
        }

    }
}