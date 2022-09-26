import java.util.Scanner;
import java.io.File;
import java.io.FileNotFoundException;

class aa {


	public static void main(String[] args){
		int tam, i;

        Scanner sc = new Scanner(System.in);
        tam = sc.nextInt();
        sc.nextLine();

     	for(i = 0; i < tam; i++){

     		String str = sc.nextLine();
     		
     		String[] splited = str.split(" ");

     		String data1 = splited[0];
     		String[] datas1 = data1.split("/");

            String data2 = splited[1];
            String[] datas2 = data2.split("/");


     		int dia1 = Integer.parseInt(datas1[0]);
     		int mes1 = Integer.parseInt(datas1[1]);
     		int ano1 = Integer.parseInt(datas1[2]);

     		int dia2 = Integer.parseInt(datas2[0]);
     		int mes2 = Integer.parseInt(datas2[1]);
     		int ano2 = Integer.parseInt(datas2[2]);

     		int n1 = (ano1 * 360) + dia1 + (mes1 * 20);
     		int n2 = (ano2 * 360) + dia2 + (mes2 * 20);

     		int diff = n1-n2;
     		if (diff < 0) diff *= -1;
            diff -= 300;

            if(diff < 300) System.out.println("O universo esta perfeitamente balanceado, como todas as coisas devem ser");
            else System.out.printf("Oh nao, atrasei %d dias o sacrificio, o deus Huitzilopochtli vai ficar pistola D:", diff);

     		
     	}
     }
}
