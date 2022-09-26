import java.util.*;
import java.io.Console;  
import java.time.LocalDate;
import java.time.LocalDateTime;
import java.time.LocalTime;
import java.time.format.DateTimeFormatter;


public class MarcadorDeReuniao {   

	private LocalDateTime dataInicialTime;
	private LocalDateTime dataFinalTime;

	private HashMap<String, List<Tuple<LocalDateTime>>> todosParticipantes = new HashMap<>();

	private	List<Tuple<LocalDateTime>> sobreposicao = new ArrayList<>();
	private boolean modificado = false;

	Console con = System.console();
	DateTimeFormatter formatter = DateTimeFormatter.ofPattern("dd-MM-yyyy HH:mm:ss");




	public void marcarReuniaoEntre (LocalDate dataInicial, LocalDate dataFinal, Collection<String> listaDeParticipantes){

		if (dataInicial.isBefore(dataFinal)){
			
			// converte para LocalDateTime
			this.dataInicialTime = dataInicial.atTime(LocalTime.MIN);
			this.dataFinalTime = dataFinal.atTime(LocalTime.MAX);
			sobreposicao.add(new Tuple<LocalDateTime>(this.dataInicialTime, this.dataFinalTime));

			// cria lista de participantes
			for (String s : listaDeParticipantes)
				todosParticipantes.put(s, null);

			// imprime titulo
			con.writer().println("============================================");
			con.writer().println("Marcar reuniao entre " + dataInicial.format(DateTimeFormatter.ofPattern("dd-MM-yyyy")) + " e " + dataFinal.format(DateTimeFormatter.ofPattern("dd-MM-yyyy")));
			con.writer().println("============================================\n");
		}

		// data inicial > data final
		else {
			con.writer().println("Data inicial nao pode ser maior que data final");
			con.writer().println("Digite novamente a data inicial e final");
			con.writer().println();
		}
	}



	public void indicaDisponibilidadeDe (String participante, LocalDateTime inicio, LocalDateTime fim){

		if (todosParticipantes.containsKey(participante)) {
			if (inicio.isBefore(fim)){

				// dentro do intervalo determinado na marcarReuniaoEntre
				if ( (inicio.isBefore(this.dataFinalTime)) && (fim.isAfter(this.dataInicialTime)) ){

					// descarta horarios fora do intervalo marcarReuniaoEntre
					if (inicio.isBefore(this.dataInicialTime)) inicio = dataInicialTime;
					if (fim.isAfter(this.dataFinalTime)) fim = dataFinalTime;


					// cria lista de horarios, se nao houver
					List<Tuple<LocalDateTime>> horariosDisponiveis = todosParticipantes.get(participante);
					if (horariosDisponiveis == null){
						horariosDisponiveis = new ArrayList<>();
						todosParticipantes.put(participante, horariosDisponiveis);
					}

					// adiciona horario recebido
					Tuple<LocalDateTime> tupleHorario = new Tuple<LocalDateTime>(inicio, fim);
					horariosDisponiveis.add(tupleHorario);
					todosParticipantes.put(participante, horariosDisponiveis);


					con.writer().println("adicionado " + participante + " : " + inicio.format(formatter) + " ~ " + fim.format(formatter));
				}

				else con.writer().println("nao adicionado " + participante + " : disponibilidade fora do intervalo de reuniao definido");
			}
			else con.writer().println("nao adicionado " + participante + " : data inicial nao pode ser maior que data final");
		}
		else con.writer().println("nao adicionado " + participante + " : " + "nao encontrado na lista de participantes");
	}



	public void mostraSobreposicao(){
 
 		// calcula sobreposicoes possiveis e concatena intervalos consequentes
		calculaSobreposicao();
		if (modificado && sobreposicao.size() > 1) resolveConflitoSobreposicao();


		// imprimir sobreposicao
		con.writer().println("\n============================================");
		con.writer().println("possiveis horarios de reuniao :\n");

		if (modificado && sobreposicao.size() > 0) 
			sobreposicao.forEach(t -> con.writer().println(t.inicio.format(formatter) + " ~ " + t.fim.format(formatter)));
		else con.writer().println("Nao existe um horario comum para todos os participantes");

		con.writer().println("============================================\n");
	}



	public void calculaSobreposicao(){

		// variaveis temporais para calculo de sobreposicao
		List<Tuple<LocalDateTime>> parcial = new ArrayList<>();
		
		// calculo de sobreposicao
		try {

			// todos os horarios de todos os participantes
			for (List<Tuple<LocalDateTime>> l : todosParticipantes.values()){

				parcial.clear();

				// horario a ser avaliado de um participante
				for (Tuple<LocalDateTime> t1 : l){

					// percorre os horarios ate agora sobrepostos
					for (Tuple<LocalDateTime> t2 : sobreposicao){

						if (haSobreposicaoExclusivo(t1.inicio, t1.fim, t2.inicio, t2.fim)){

							parcial.add(new Tuple<LocalDateTime>(maximo(t1.inicio, t2.inicio), minimo(t1.fim, t2.fim)));
							modificado = true;
						}
					}
				}

				sobreposicao.clear(); 
				sobreposicao.addAll(parcial);
			}
		}

		catch (Exception e){

			// participante sem horario disponivel ou lista de participantes vazia
			modificado = false;
		}	
	}


	
	public void resolveConflitoSobreposicao(){

		int tam = sobreposicao.size();
		boolean sobre;

		for (int i = tam-1; i > 0; i--){

			sobre = false;
			Tuple<LocalDateTime> t1 = sobreposicao.get(i);

			for (int j = i-1; j >= 0; j--){

				Tuple<LocalDateTime> t2 = sobreposicao.get(j);

				if (haSobreposicaoInclusivo(t1.inicio, t1.fim, t2.inicio, t2.fim)){

					t2.inicio = minimo(t1.inicio, t2.inicio);
					t2.fim = maximo(t1.fim, t2.fim);
					sobreposicao.set(j, t2);

					sobre = true;
				}
			}

			if (sobre == true){
				sobreposicao.remove(i);
			}

		}
	}		



	public boolean haSobreposicaoInclusivo (LocalDateTime inicio1, LocalDateTime fim1, LocalDateTime inicio2, LocalDateTime fim2){
   		return !(inicio2.isAfter(fim1)) && !(fim2.isBefore(inicio1));
	}



	public boolean haSobreposicaoExclusivo (LocalDateTime inicio1, LocalDateTime fim1, LocalDateTime inicio2, LocalDateTime fim2){
   		return inicio2.isBefore(fim1) && fim2.isAfter(inicio1); 
	}



	public LocalDateTime maximo (LocalDateTime t1, LocalDateTime t2){
		return t1.isBefore(t2) ? t2 : t1;
	}



	public LocalDateTime minimo (LocalDateTime t1, LocalDateTime t2){
		return t1.isBefore(t2) ? t1 : t2;
	}

}