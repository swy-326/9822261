import java.util.Scanner;
import java.io.File;
import java.io.FileNotFoundException;

class a {

	public static void main(String[] args){

        Scanner sc = new Scanner(System.in);
        String strr = null;

		while(!(strr = sc.nextLine()).isEmpty()) {

			boolean encontrou = false;
			boolean geral = false;

			String[] sttr = strr.split(" ", -1);
			for (String str : sttr){
				int tam = str.length();


				if ( tam % 2 == 0 ){
				if (str.charAt(0) == str.charAt( tam - 1 )){
					
					if ( str.contains("a") ){

						int index = str.indexOf('a');
						
						while(index >= 0) {
							char qian = str.charAt(index-1);
							char hou = str.charAt(index+1);
							if (qian != 'e' && qian != 'i' && qian != 'o' && qian != 'u' && hou != 'e' && hou != 'i' && hou != 'o' && hou != 'u'){
	   							index = str.indexOf('a', index+1);
							} else {
								encontrou = true;
							}
						}
					} else {
						geral = false;
					}
				} else {
					geral = false;
				}
			}
			else System.out.println("Eles sao forasteiros, joguem no vulcao!!");
		
			}

			
		if (encontrou == true) System.out.println("Todos saudam os deuses.");
		else if(encontrou == false || geral == false) System.out.println("Eles sao forasteiros, joguem no vulcao!!");


		}

		
		
	}
}