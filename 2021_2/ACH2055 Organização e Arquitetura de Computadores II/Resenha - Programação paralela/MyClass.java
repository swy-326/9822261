import java.lang.Thread;

public class MyClass {
    public static void executaParalelo(){
        new Thread(() -> {
            //Tempo inicial
            long start = System.currentTimeMillis();

            for(int i = 0; i < 5; i++){
                System.out.println("Contador em: " + i);
            }

            //Tempo final
            long elapsedTime = System.currentTimeMillis()-start;
            
            //Tempo de execução em segundos
            float elapsedTimeSec = elapsedTime/1000F;
            System.out.println("Tempo execução com for paralelo: "+ elapsedTimeSec + "s\n");
        }).start();
    }
    
    public static void executaSequencial(){
        //Tempo inicial
        long start = System.currentTimeMillis();

        for(int i = 0; i < 5; i++){
            System.out.println("Contador em: " + i);
        }

        //Tempo final
        long elapsedTime = System.currentTimeMillis()-start;

        //Tempo de execução em segundos
        float elapsedTimeSec = elapsedTime/1000F;
        System.out.println("Tempo execução com for sequencial: "+ elapsedTimeSec + "s\n");
    }
    
    public static void main(String args[]) {
	    System.out.println("    ------------------------------------------------    ");
	    System.out.println("Desempenho de um contador em função sequencial e paralela");
	    System.out.println("    ------------------------------------------------    \n");
        executaSequencial();
        executaParalelo();
    }
}