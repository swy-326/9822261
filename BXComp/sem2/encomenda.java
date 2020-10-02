import java.util.Scanner;
import java.io.File;
import java.io.FileNotFoundException;

class encomenda {


    public static void main(String[] args) {

    	Scanner sc = new Scanner(System.in);
    	int n = sc.nextInt();

    	for(int i = 0; i < n; i++){

    		String str = sc.next();
    		String strr = str.toLowerCase();

    		int flag = 0;
    		int flagg = 0;

    		// ancestral deus
    		if ( strr.contains("akh") && strr.contains("sekhem") && strr.contains("ren") && !strr.contains("ka") && !strr.contains("bah") ){
    			//String strrr = str.replace("akh","").replace("sekhem","").replace("ren","");
    			//if (strrr.equals("")) 
    				System.out.println("Opa, ancestrais e deuses nao empacotam duas vezes.");
    			//else System.out.println("Tem e uma bagunca espiritual aqui!");
    		}


    		else {
    			if (strr.contains("khat") ) flag++;
    			if (strr.contains("ka")) flag++;
    			if (strr.contains("ba")) flag++;
    			if (strr.contains("sahu")) flag++;
    			if (strr.contains("sekhem")) flag++;
    			if (strr.contains("ren")) flag++;
    			if (strr.contains("shwt")) flag++;
    			if (strr.contains("ab")) flag++;

    			String strrr = strr.replace("khat","").replace("ba","").replace("ka","").replace("akh","").replace("sahu","").replace("sekhem","").replace("ren","").replace("shwt","").replace("ab","");


    			if ( flag > 7 && strrr.equals("")) System.out.println("Alma mortal pronta para ser empacotada.");
    			else System.out.println("Tem e uma bagunca espiritual aqui!");

    		}

    	}

	}
}
