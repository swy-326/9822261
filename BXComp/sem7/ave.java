import java.util.Scanner;
import java.io.File;
import java.io.FileNotFoundException;
import java.util.regex.Pattern;
import java.util.regex.Matcher;


class arb {

    public static void main(String[] args) {

    	Scanner sc = new Scanner(System.in);
        Pattern p = Pattern.compile("f{1}o{1,}i{1}");

        String inputt = sc.nextLine();

        while(!(inputt.equals("XIU!"))){

            String lowerr = inputt.toLowerCase();
            Matcher m = p.matcher(lowerr);

            long count = 0 ;
            //while(m.find()) count++;
            count = m.results().count();

            System.out.println(count);

            inputt = sc.nextLine();
            
        }

    }
}