package kernel;
import java.util.Comparator;

import operacoes.Operacao;
import operacoes.OperacaoES;


public class PCB implements Comparable<PCB>{

	public enum Estado {NOVO, PRONTO, EXECUTANDO, ESPERANDO, TERMINADO};
	public int idProcesso; // primeiro processo criado deve ter id = 0
	public Estado estado = Estado.NOVO;
    public int estadoCounter = 2; // usado para esperar um ciclo antes de trocar o estado para PRONTO
	public int[] registradores = new int[5];
	public int contadorDePrograma;
    public int nOperacoes;
	public Operacao[] codigo;
    public Operacao OperacaoES = null; // guarda a operação E/S atual 
    public boolean jaEsteveNaCPU = false;

	public int quantumRestante;

    public int chuteBurst = 5;
    public int contadorBurst = 0;

    public int remainingTime = 5;

    public int tempoEspera;
    public int tempoResposta;
    public int tempoRetorno;


    public PCB(int idProcesso, Operacao[] codigo) {
        this.idProcesso = idProcesso;
        this.contadorDePrograma = 0;
        this.codigo = codigo;
        this.nOperacoes = codigo.length;
    }

    public Operacao proximoCodigo() {
        int PC = contadorDePrograma;
        contadorDePrograma++;
        estado = Estado.EXECUTANDO;
        return codigo[PC];
    }

    public boolean iniciarES(){
        Operacao proxOperacao = codigo[contadorDePrograma];
        if(proxOperacao instanceof OperacaoES){
            contadorDePrograma++;
            OperacaoES = proxOperacao;
            return true;
        }

        return false;
    }

    @Override
    public int compareTo(PCB pcb) {
        return this.idProcesso-pcb.idProcesso;
    }

    // Comparator usado para organizar a lista de processosProntos por burst
    public class BurstComparator implements Comparator<PCB>{

        @Override
        public int compare(PCB pcb1, PCB pcb2) {
            if(pcb1.chuteBurst == pcb2.chuteBurst)
                return pcb1.compareTo(pcb2);
            else if(pcb1.chuteBurst > pcb2.chuteBurst)
                return 1;
            else
                return -1;
        }
    }

    // Comparator usado para organizar a lista de processosProntos por remaining time
    public class RemainingTimeComparator implements Comparator<PCB>{

        @Override
        public int compare(PCB pcb1, PCB pcb2) {
            if(pcb1.remainingTime == pcb2.remainingTime)
                return pcb1.compareTo(pcb2);
            else if(pcb1.remainingTime > pcb2.remainingTime)
                return 1;
            else
                return -1;
        }
    }

}
