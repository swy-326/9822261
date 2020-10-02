import java.util.Scanner;
import java.io.File;
import java.io.FileNotFoundException;

class bx {
/*
03 - 05, 07, 39
04 - 14, 28
*/
	public static void casos(String str){
		int qnt = 0;

		// furto
		char san = str.charAt(2);
		char si = str.charAt(6);
		char wu = str.charAt(10);
		char qi = str.charAt(14);
		char shisi = str.charAt(18);
		char ershiba = str.charAt(22);
		char sanshijiu = str.charAt(26);

		// cumpriu todos
		if ( san == '0' && si == '0' && wu == '0' && qi == '0' && shisi == '0' && ershiba == '0' && sanshijiu == '0' )
			System.out.println("Otimo, pode prosseguir para a balanca");

		// cumpriu nada
		if ( san == '1' && si == '1' && wu == '1' && qi == '1' && shisi == '1' && ershiba == '1' && sanshijiu == '1')
			System.out.println("Amado que vida foi essa?");
		
		else{

			if( san == '0' && wu == '1' ) qnt++;
			if( san == '0' && qi == '1' ) qnt++;
			if( san == '0' && sanshijiu == '1' ) qnt++;

			if( san == '1' && wu == '1' ) qnt++;
			if( san == '1' && qi == '1' ) qnt++;
			if( san == '1' && sanshijiu == '1' ) qnt++;

			if( si == '0' && shisi == '1' ) qnt++;
			if( si == '0' && ershiba == '1' ) qnt++;

			if( si == '1' && shisi == '1' ) qnt++;
			if( si == '1' && ershiba == '1' ) qnt++;

			if(qnt >= 2) System.out.println("Parabens, o Ammit lhe espera");
			else System.out.println("Otimo, pode prosseguir para a balanca");

		}

	}


    public static void main(String[] args) {

    	Scanner sc = new Scanner(System.in);
    	int n = sc.nextInt();

    	for(int i = 0; i < n; i++){
    		String str = sc.nextLine();
    		casos(str); 
    	}

	}
}
