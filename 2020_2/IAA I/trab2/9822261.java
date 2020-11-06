import java.io.BufferedReader;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.IOException;
import java.util.Scanner;
import java.util.concurrent.TimeUnit;


public class test {

	public static int BinarySearch(double arr[], double valor, int inf, int sup){
		int mid;

		while( inf <= sup){
			mid = (inf + sup) / 2;
			if(arr[mid] > valor) sup = mid - 1;
			else inf = mid + 1;
		}
		return inf;
	}

	public static void BinaryInsertionSort(double arr[], int tam){

		int i, j, index;
		double chave;

		for(i = 1; i < tam; i++){
			chave = arr[i];
			index = BinarySearch(arr, chave, 0, i-1);
			for(j = i; j > index; j--){
				arr[j] = arr[j-1];
			}
			arr[index] = chave;
		}
	}


	public static int BinarySearchR(double arr[], double valor, int inf, int sup){
		int mid;

		if(inf < sup){
			mid = (inf + sup) / 2;

			if (arr[mid] == valor) return mid;

			if (arr[mid] > valor) return BinarySearchR(arr, valor, inf, mid);
			return BinarySearchR(arr, valor, mid+1, sup);
		}

		return inf;
	}

	public static void BinaryInsertionSortR(double arr[], int tam){
		int j, index;
		double chave;

		if (tam > 0){
			BinaryInsertionSortR(arr, tam-1);

			chave = arr[tam];
			index = BinarySearchR(arr, chave, 0, tam);
			for(j = tam; j > index; j--){
				arr[j] = arr[j-1];
			}
			arr[index] = chave;
		}
	}


	public static void InsertionSort(double arr[], int tam){
		int i, j;
		double chave;

		for (i = 1; i < tam; i++){
			chave = arr[i];
			for(j = i - 1; j >= 0 && arr[j] > chave; j--){
				arr[j+1] = arr[j];
			}
			arr[j+1] = chave;
		}
	}

	public static void InsertionSortR(double arr[], int tam){
		int i; double chave;

		if (tam > 0){
			InsertionSortR(arr, tam-1);
			chave = arr[tam];

			for(i = tam-1; i >= 0 && arr[i] > chave; i--){
				arr[i+1] = arr[i];
			}
			arr[i+1] = chave;
		}
	}


	public static void imprimir(double arr[], int tam){
		for(int i = 0; i < tam; i++){
			System.out.print(arr[i] + " ");
		}
	}


	public static void linhas(String fileName, int opcao){

		long timeFinal = 0;

		for(int k = 0; k < 50; k++){

			long startTime = 0, endTime = 0, timeElapsed = 0, timeTotal = 0;


			BufferedReader bR = null;
			String[] vetor1 = null;// Vetor de dados para 1 fila do arquivo
		
			try{

				bR = new BufferedReader(new FileReader(fileName));
				String row = "";

				// le uma linha a uma linha (readLine)
				while( (row = bR.readLine()) != null ){

					// cria novo vetor de float a partir de cada linha
					vetor1 = row.split(" ");
					double vetor[] = new double[vetor1.length];
					for (int i = 0; i < vetor1.length; i++){
						double temp = Double.parseDouble(vetor1[i]);
						vetor[i] = temp;
					}

					// extrai quantidade de vetor a partir do nome do arquivo
					String quantidade = fileName.replaceAll("\\D+", "");
					int qntde = Integer.parseInt(quantidade);

					/* ordena e calcula o tempo
						1-binary insertion sort interativa
						2-binary insertion sort recursiva
						3-insertion sort iterativa
						4-insertion sort recursiva
					*/
					if(opcao == 1){
						startTime = System.nanoTime();
						BinaryInsertionSort(vetor, qntde);
						endTime = System.nanoTime();
					} 

					else if(opcao == 2){
						startTime = System.nanoTime();
						BinaryInsertionSortR(vetor, qntde-1);
						endTime = System.nanoTime();
					}

					else if (opcao == 3){
						startTime = System.nanoTime();
						InsertionSort(vetor, qntde);
						endTime = System.nanoTime();
					}

					else if (opcao == 4){
						startTime = System.nanoTime();						
						InsertionSortR(vetor, qntde-1);
						endTime = System.nanoTime();						
					}


					// temp gasto para um vetor (uma linha)
					timeElapsed = endTime - startTime;

					System.out.printf("Tempo individual : %dns\n", timeElapsed);
					imprimir(vetor, qntde); System.out.println();System.out.println();

					// tempo de todos 50 vetores de txt
					timeTotal += timeElapsed;
				}
			
			} catch (FileNotFoundException e){
				e.printStackTrace();
			} catch (IOException e) {
				e.printStackTrace();
			}

			timeTotal /= 50;
			timeFinal += timeTotal;
			System.out.printf("Tempo media de %da vez : %dns\n", k+1, timeTotal);
		}

		System.out.println("Tempo media de 50 execucoes : " + timeFinal/50 + "ns");
	}


	public static void main(String[] args){


		Scanner sc = new Scanner(System.in);
		int opcao = -1;

		System.out.printf("Digite: \n '1' para ordenacao bianria iterativa\n '2' para ordenacao binaria recursiva\n '3' para ordenacao iterativa\n '4' para ordenacao recursiva\n '5' para sair do programa\n");

		
		do {

			System.out.print("opcao : "); opcao = sc.nextInt();
			sc.nextLine();

			if(opcao == 1 || opcao == 2 || opcao == 3 || opcao == 4){
				
				System.out.print("Digite o nome do arquivo com extensao: ");
				String fileName = sc.nextLine();
				linhas(fileName, opcao);

				System.out.printf("\n");
			}

			else if (opcao == 5){
				System.exit(0);
			}

			else{
				System.out.println("Opcao invalida, digite novamente");
			}

		} while (opcao != 5);
	}
}