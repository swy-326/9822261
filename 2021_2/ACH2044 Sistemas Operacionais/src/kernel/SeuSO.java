package kernel;
import kernel.PCB.BurstComparator;
import kernel.PCB.Estado;
import kernel.PCB.RemainingTimeComparator;

import java.util.List;
import java.util.ArrayList;
import java.util.Collections;

import operacoes.Operacao;
import operacoes.OperacaoES;

public class SeuSO extends SO {

	private Escalonador escalonador;
	private int ultimoId = -1;
	private int trocasDeContexto = 0;

	private ArrayList<PCB> processosNovos = new ArrayList<PCB>();
	private ArrayList<PCB> processosProntos = new ArrayList<PCB>();
	private PCB processoExecutando = null;
	private ArrayList<PCB> processosEsperando = new ArrayList<PCB>();
	private ArrayList<PCB> processosTerminados = new ArrayList<PCB>();


	@Override
	// ATENCÃO: cria o processo mas o mesmo 
	// só estará "pronto" no próximo ciclo
	protected void criaProcesso(Operacao[] codigo) {
		ultimoId++;
		int idProcesso = ultimoId;
		PCB pcb = new PCB(idProcesso, codigo);
		processosNovos.add(pcb);
	}

	@Override
	protected void trocaContexto(PCB pcbAtual, PCB pcbProximo) {

		trocasDeContexto++;
		pcbAtual.registradores = processador.registradores.clone();
		if(pcbAtual.OperacaoES == null){
			pcbAtual.estado = Estado.PRONTO;
			processosProntos.add(pcbAtual);
		}
		else{
			pcbAtual.estado = Estado.ESPERANDO;
			processosEsperando.add(pcbAtual);
		}

		pcbProximo.estado = Estado.EXECUTANDO;
		pcbProximo.jaEsteveNaCPU = true;
		processador.registradores = pcbProximo.registradores.clone();
		processoExecutando = pcbProximo;
	}

	@Override
	// Assuma que 0 <= idDispositivo <= 4
	protected OperacaoES proximaOperacaoES(int idDispositivo) {

		for(PCB pcb : processosEsperando){
			if(pcb.OperacaoES != null){
				OperacaoES OperacaoES = (OperacaoES) pcb.OperacaoES;

				if(OperacaoES.idDispositivo == idDispositivo)
					return OperacaoES;
			}
		}

		return null;
	}

	@Override
	protected Operacao proximaOperacaoCPU() {

		PCB pcb;

		switch (escalonador) {

			case FIRST_COME_FIRST_SERVED:

				if(processoExecutando != null){
					pcb = processoExecutando; 
					return pcb.proximoCodigo();
				}

				break;

			case SHORTEST_JOB_FIRST:

				if(processoExecutando != null){
					pcb = processoExecutando; 
					pcb.contadorBurst++;
					return pcb.proximoCodigo();
				}
				
				break;

			case SHORTEST_REMANING_TIME_FIRST:
			case SHORTEST_REMAINING_TIME_ADIVINHA:

				if(processoExecutando != null){
					pcb = processoExecutando; 
					pcb.contadorBurst++;
					pcb.remainingTime--;
					return pcb.proximoCodigo();
				}

				break;

			case ROUND_ROBIN_QUANTUM_5:

				if(processoExecutando != null){
					pcb = processoExecutando;
					if (pcb.quantumRestante > 0){
						pcb.quantumRestante--;
						return pcb.proximoCodigo();
					}
				}

				break;

		}

		return null;
	}

	@Override
	protected void executaCicloKernel() {

		PCB pcb;
		lidarComNovos();
		lidarComEspera();

		switch (escalonador) {

			case FIRST_COME_FIRST_SERVED:

				do{
					Collections.sort(processosProntos); // sempre deixar a lista de prontos em ordem crescente

					if(processoExecutando != null){
						pcb = processoExecutando;
					}
					// para o primeiro processo ou após todos processos estarem no estado de esperando
					else if(!processosProntos.isEmpty()){
						pcb = pegarProcessoPronto(0);
						processador.registradores = pcb.registradores.clone();
						// contar como troca de contexto caso prox já tenha passado pela CPU
						if(pcb.jaEsteveNaCPU)
							trocasDeContexto++;
						else
							pcb.jaEsteveNaCPU = true;
					}
					else{
						break;
					}
					
					if (pcb.contadorDePrograma == pcb.nOperacoes){

						pcb.estado = Estado.TERMINADO;
						processosTerminados.add(pcb);

						if(!processosProntos.isEmpty()){
							pcb = pegarProcessoPronto(0);
							processador.registradores = pcb.registradores.clone();
							// contar como troca de contexto caso prox já tenha passado pela CPU
							if(pcb.jaEsteveNaCPU)
								trocasDeContexto++;
							else
								pcb.jaEsteveNaCPU = true;
						}
						else {
							processoExecutando = null;
						}
					}
					
					// caso a proxima operação seja E/S bota o processo no estado esperando
					if(pcb.estado == Estado.EXECUTANDO){
						if(pcb.iniciarES()){
							pcb.registradores = processador.registradores.clone();
							pcb.estado = Estado.ESPERANDO;
							processosEsperando.add(pcb);
							processoExecutando = null;
						}
					}
				} while(processoExecutando == null && !processosProntos.isEmpty());

			break;

			case SHORTEST_JOB_FIRST:

				do{
					if(processoExecutando != null){
						pcb = processoExecutando;
					}
					// para o primeiro processo ou após todos processos estarem no estado de esperando
					else if(!processosProntos.isEmpty()){
						pcb = pegarProcessoPronto(0);
						processador.registradores = pcb.registradores.clone();
						// contar como troca de contexto caso prox já tenha passado pela CPU
						if(pcb.jaEsteveNaCPU)
							trocasDeContexto++;
						else
							pcb.jaEsteveNaCPU = true;
					}
					else{
						break;
					}

					// organiza os processos prontos em ordem crescente de burst
					BurstComparator burstComparator = pcb.new BurstComparator();
					Collections.sort(processosProntos, burstComparator);

					if (pcb.contadorDePrograma == pcb.nOperacoes){

						pcb.estado = Estado.TERMINADO;
						processosTerminados.add(pcb);

						if(!processosProntos.isEmpty()){
							pcb = pegarProcessoPronto(0);
							processador.registradores = pcb.registradores.clone();
							// contar como troca de contexto caso prox já tenha passado pela CPU
							if(pcb.jaEsteveNaCPU)
								trocasDeContexto++;
							else
								pcb.jaEsteveNaCPU = true;
						}
						else {
							processoExecutando = null;
						}
					}

					// caso a proxima operação seja E/S bota o processo no estado esperando e calcula novo chute
					if(pcb.estado == Estado.EXECUTANDO){
						if(pcb.iniciarES()){
							pcb.chuteBurst = (pcb.chuteBurst+pcb.contadorBurst)/2;
							pcb.contadorBurst = 0;
							pcb.registradores = processador.registradores.clone();
							pcb.estado = Estado.ESPERANDO;
							processosEsperando.add(pcb);
							processoExecutando = null;
						}
					}
				} while(processoExecutando == null && !processosProntos.isEmpty());

			break;

			case SHORTEST_REMANING_TIME_FIRST:

				do {
					if(processoExecutando != null){
						pcb = processoExecutando;
					}
					// para o primeiro processo ou após todos processos estarem no estado de esperando
					else if(!processosProntos.isEmpty()){
						pcb = pegarProcessoPronto(0);
						processador.registradores = pcb.registradores.clone();
						// contar como troca de contexto caso prox já tenha passado pela CPU
						if(pcb.jaEsteveNaCPU)
							trocasDeContexto++;
						else
							pcb.jaEsteveNaCPU = true;
					}
					else{
						break;
					}

					// organiza os processos prontos em ordem crescente de remaining time
					RemainingTimeComparator remainingTimeComparator = pcb.new RemainingTimeComparator();
					Collections.sort(processosProntos, remainingTimeComparator);

					if (pcb.contadorDePrograma == pcb.nOperacoes){

						pcb.estado = Estado.TERMINADO;
						processosTerminados.add(pcb);

						if(!processosProntos.isEmpty()){
							pcb = pegarProcessoPronto(0);
							processador.registradores = pcb.registradores.clone();
							// contar como troca de contexto caso prox já tenha passado pela CPU
							if(pcb.jaEsteveNaCPU)
								trocasDeContexto++;
							else
								pcb.jaEsteveNaCPU = true;
						}
						else {
							processoExecutando = null;
						}
					}

					// caso a proxima operação seja E/S bota o processo no estado esperando e calcula novo chute
					if(pcb.estado == Estado.EXECUTANDO){
						if(pcb.iniciarES()){
							pcb.chuteBurst = (pcb.chuteBurst+pcb.contadorBurst)/2;
							pcb.contadorBurst = 0;
							pcb.remainingTime = pcb.chuteBurst;
							pcb.registradores = processador.registradores.clone();
							pcb.estado = Estado.ESPERANDO;
							processosEsperando.add(pcb);
							processoExecutando = null;
						}
						else if(!processosProntos.isEmpty()){
							PCB pcbProx = processosProntos.get(0);
							if(pcb.remainingTime > pcbProx.remainingTime){
								processosProntos.remove(0);
								trocaContexto(pcb, pcbProx);
							}
						}
					}
				} while(processoExecutando == null && !processosProntos.isEmpty());

			break;

			case ROUND_ROBIN_QUANTUM_5:

				do{
					if(processoExecutando != null){
						pcb = processoExecutando;
					}
					// para o primeiro processo ou após todos processos estarem no estado de esperando
					else if(!processosProntos.isEmpty()){
						pcb = pegarProcessoPronto(0);
						pcb.quantumRestante = 5;
						processador.registradores = pcb.registradores;
						// contar como troca de contexto caso prox já tenha passado pela CPU
						if(pcb.jaEsteveNaCPU)
							trocasDeContexto++;
						else
							pcb.jaEsteveNaCPU = true;
					}
					else{
						break;
					}

					// caso ainda existam processos no estado pronto pegar o proximo pcb de processosProntos
					PCB pcbProx = null;
					if(!processosProntos.isEmpty())
						pcbProx = processosProntos.get(0);

					if (pcb.contadorDePrograma == pcb.nOperacoes){

						pcb.estado = Estado.TERMINADO;
						processoExecutando = null;
						processosTerminados.add(pcb);

						if(pcbProx != null) {
							processosProntos.remove(pcbProx);
							pcb = pcbProx;
							pcb.estado = Estado.EXECUTANDO;
							pcb.quantumRestante = 5;
							processoExecutando = pcb;
							processador.registradores = pcb.registradores;
							// contar como troca de contexto caso prox já tenha passado pela CPU
							if(pcb.jaEsteveNaCPU)
								trocasDeContexto++;
							else
								pcb.jaEsteveNaCPU = true;
						}
					}
					else {
						if(pcb.iniciarES()){
							if(pcbProx != null){
								processosProntos.remove(pcbProx);
								pcbProx.quantumRestante = 5;
								trocaContexto(pcb, pcbProx);
							}
							else{
								pcb.registradores = processador.registradores.clone();
								pcb.estado = Estado.ESPERANDO;
								processosEsperando.add(pcb);
								processoExecutando = null;
							}
						}
						else if(pcb.quantumRestante <= 0 && pcbProx != null){
							processosProntos.remove(pcbProx);
							pcbProx.quantumRestante = 5;
							trocaContexto(pcb, pcbProx);
						}
						else if(pcb.quantumRestante <= 0){
							pcb.quantumRestante = 5;
							trocasDeContexto++; // contar como troca de contexto mesmo se o processo "trocou" para si mesmo
						}
					}
				} while(processoExecutando == null && !processosProntos.isEmpty());

			break; 

			case SHORTEST_REMAINING_TIME_ADIVINHA:

				pegaRemainingTime();

				do {
					if(processoExecutando != null){
						pcb = processoExecutando;
					}
					// para o primeiro processo ou após todos processos estarem no estado de esperando
					else if(!processosProntos.isEmpty()){
						pcb = pegarProcessoPronto(0);
						processador.registradores = pcb.registradores.clone();
						// contar como troca de contexto caso prox já tenha passado pela CPU
						if(pcb.jaEsteveNaCPU)
							trocasDeContexto++;
						else
							pcb.jaEsteveNaCPU = true;
					}
					else{
						break;
					}

					// organiza os processos prontos em ordem crescente de remaining time
					RemainingTimeComparator remainingTimeComparator = pcb.new RemainingTimeComparator();
					Collections.sort(processosProntos, remainingTimeComparator);

					if (pcb.contadorDePrograma == pcb.nOperacoes){

						pcb.estado = Estado.TERMINADO;
						processosTerminados.add(pcb);

						if(!processosProntos.isEmpty()){
							pcb = pegarProcessoPronto(0);
							processador.registradores = pcb.registradores.clone();
							// contar como troca de contexto caso prox já tenha passado pela CPU
							if(pcb.jaEsteveNaCPU)
								trocasDeContexto++;
							else
								pcb.jaEsteveNaCPU = true;
						}
						else {
							processoExecutando = null;
						}
					}

					// caso a proxima operação seja E/S bota o processo no estado esperando e calcula novo chute
					if(pcb.estado == Estado.EXECUTANDO){
						if(pcb.iniciarES()){
							pcb.registradores = processador.registradores.clone();
							pcb.estado = Estado.ESPERANDO;
							processosEsperando.add(pcb);
							processoExecutando = null;
						}
						else if(!processosProntos.isEmpty()){
							PCB pcbProx = processosProntos.get(0);
							if(pcb.remainingTime > pcbProx.remainingTime){
								processosProntos.remove(0);
								trocaContexto(pcb, pcbProx);
							}
						}
					}
				} while(processoExecutando == null && !processosProntos.isEmpty());

			break;
		}

		contarTempoDeEspera(); // adiciona no contador de tempo de espera
		contarTempoDeResposta(); // adiciona no contador de tempo de resposta
		contarTempoDeRetorno(); // adiciona no contador de tempo de retorno
	}

	@Override
	protected boolean temTarefasPendentes() {
		
		if(!processosNovos.isEmpty() || !processosProntos.isEmpty() 
			|| !processosEsperando.isEmpty() || processoExecutando != null)
			return true;

		return false;
	}

	@Override
	protected Integer idProcessoNovo() {

		int processosNovosSize = processosNovos.size();
		if (processosNovosSize != 0)
			return processosNovos.get(processosNovosSize-1).idProcesso;

		return null;
	}

	@Override
	protected List<Integer> idProcessosProntos() {

		ArrayList<Integer> idProcessosProntos = new ArrayList<Integer>();

		// retorna -1 caso não existam processos prontos
		if (processosProntos.isEmpty()) 
			idProcessosProntos.add(-1);

		else {
			for (PCB pcb : processosProntos)
				idProcessosProntos.add(pcb.idProcesso);
		}

		Collections.sort(idProcessosProntos);
		return idProcessosProntos;
	}

	@Override
	protected Integer idProcessoExecutando() {

		if (processoExecutando != null)
			return processoExecutando.idProcesso;

		return null;
	}

	@Override
	protected List<Integer> idProcessosEsperando() {

		ArrayList<Integer> idProcessosEsperando = new ArrayList<Integer>();

		if (processosEsperando.isEmpty()) 
			idProcessosEsperando.add(-1);

		else {
			for (PCB pcb : processosEsperando)
				idProcessosEsperando.add(pcb.idProcesso);
		}

		Collections.sort(idProcessosEsperando);
		return idProcessosEsperando;
	}

	@Override
	protected List<Integer> idProcessosTerminados() {

		ArrayList<Integer> idProcessosTerminados = new ArrayList<Integer>();

		if (processosTerminados.isEmpty()) 
			idProcessosTerminados.add(-1);

		else {
			for (PCB pcb : processosTerminados)
				idProcessosTerminados.add(pcb.idProcesso);
		}

		Collections.sort(idProcessosTerminados);
		return idProcessosTerminados;
	}

	@Override
	protected int tempoEsperaMedio() {

		int i = 0, tempoEspera = 0;

		for(i = 0; i < processosTerminados.size(); i++) {
			PCB pcb = processosTerminados.get(i);
			tempoEspera += pcb.tempoEspera;
		}

		return (tempoEspera/i);
	}

	@Override
	protected int tempoRespostaMedio() {

		int i = 0, tempoResposta = 0;

		for(i = 0; i < processosTerminados.size(); i++) {
			PCB pcb = processosTerminados.get(i);
			tempoResposta += pcb.tempoResposta;
		}

		return (tempoResposta/i);
	}

	@Override
	protected int tempoRetornoMedio() {
		
		int i = 0, tempoRetorno = 0;

		for(i = 0; i < processosTerminados.size(); i++) {
			PCB pcb = processosTerminados.get(i);
			tempoRetorno += (pcb.tempoRetorno + pcb.tempoEspera); // o tempo de retorno não conta o tempo de espera então se adiciona ele aqui
		}

		return (tempoRetorno/i);
	}

	@Override
	protected int trocasContexto() {
		return trocasDeContexto;	
	}

	@Override
	public void defineEscalonador(Escalonador e) {
		this.escalonador = e;
	}

	private PCB pegarProcessoPronto(int index) {
		PCB pcb = processosProntos.get(index);
		pcb.estado = Estado.EXECUTANDO;
		processosProntos.remove(index);
		processoExecutando = pcb;
		return pcb;
	}

	private void lidarComNovos(){

		PCB pcb;

		while(!processosNovos.isEmpty()) {
			pcb = processosNovos.get(0);
			pcb.estadoCounter--;

			if (pcb.estadoCounter == 0){
				// caso a primeira operacao seja de E/S
				if(pcb.iniciarES()){
					pcb.estado = Estado.ESPERANDO;
					processosEsperando.add(pcb);
				}
				else{
					pcb.estado = Estado.PRONTO;
					processosProntos.add(pcb);
				}

				processosNovos.remove(pcb);
			}
			else
				break;
		}
	}

	private void lidarComEspera(){

		int index = 0;
		while(!processosEsperando.isEmpty() && index < processosEsperando.size()){
			PCB pcb = processosEsperando.get(index);
			OperacaoES operacaoES = (OperacaoES) pcb.OperacaoES;

			if(operacaoES.ciclos == 0){
				// caso o processo tenha chegado ao fim
				if(pcb.contadorDePrograma == pcb.nOperacoes){
					pcb.estado = Estado.TERMINADO;
					processosTerminados.add(pcb);
					processosEsperando.remove(pcb);
				}
				// caso a próxima operação não seja E/S retira o processo do estado esperando
				else if(!pcb.iniciarES()){
					pcb.OperacaoES = null;
					pcb.estado = Estado.PRONTO;
					processosProntos.add(pcb);
					processosEsperando.remove(pcb);
				}
			}
			else
				index++;
		}
	}

	private void contarTempoDeEspera(){
		for(PCB pcb : processosProntos)
			pcb.tempoEspera++;
	}

	private void contarTempoDeResposta(){
		for(PCB pcb : processosProntos){
			if(!pcb.jaEsteveNaCPU)
				pcb.tempoResposta++;
		}
	}

	// não precisa contar o tempo de espera aqui, só adicionar quando for retornar o valor
	private void contarTempoDeRetorno(){
		if(processoExecutando != null)
			processoExecutando.tempoRetorno++;
		for(PCB pcb : processosEsperando)
			pcb.tempoRetorno++;
	}

	// pega o remaining time para dos processos prontos
	private void pegaRemainingTime(){
		for(PCB pcb : processosProntos){
			int remainingTime = 0;

			for(int i = pcb.contadorDePrograma; i < pcb.nOperacoes; i++){
				if(!(pcb.codigo[i] instanceof OperacaoES))
					remainingTime++;
				else
					break;
			}

			pcb.remainingTime = remainingTime;
		}
	}
}
