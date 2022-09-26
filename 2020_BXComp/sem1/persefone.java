import java.util.Scanner;
import java.io.File;
import java.io.FileNotFoundException;

class Seis {

	public static String reverse(String a) {
    	char[] novo = new char[a.length()];
   		for (int i = 0, j = a.length() - 1; i < a.length(); i++, j--) {
        	novo[j] = a.charAt(i);
    	}
   		return new String(novo);
}

	public static void main(String[] args){

        Scanner sc = new Scanner(System.in);
		int N = sc.nextInt();

		for (int i = 0; i < N; i++){

			String str = sc.next();
			String str1 = reverse(str);
			
			String datas[] = str1.split("/");

			int diaa = Integer.parseInt(datas[0]);
			int mess = Integer.parseInt(datas[1]);


			if (mess >= 4 && mess <= 8){
				System.out.println(datas[0] + "/" + datas[1] + " O solo nao estara ao nosso favor nesse dia.");
			}
			else if(mess == 3 && diaa >= 20){
				System.out.println(datas[0] + "/" + datas[1] + " O solo nao estara ao nosso favor nesse dia.");
			}
			else if (mess == 9 && diaa <= 21){
				System.out.println(datas[0] + "/" + datas[1] + " O solo nao estara ao nosso favor nesse dia.");
			}
			else{
				System.out.println(datas[0] + "/" + datas[1] + " O solo estara ao nosso favor nesse dia.");
			}

		}
	}
}
