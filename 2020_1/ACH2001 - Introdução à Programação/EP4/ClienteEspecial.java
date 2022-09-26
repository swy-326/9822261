
public class ClienteEspecial extends Cliente{
	static final int dividaMaxima = 50000;
	static final String tipo = "CE";
	
	/* Construtor da Classe ClienteEspecial
	 * Este construtor invoca o construtor da classe Cliente.
	 */
	ClienteEspecial(String nome, int cpf, int valor){
		super(nome, cpf, valor);
	}
	
	/* Metodo que retorna o valor do atributo tipo do objeto atual */
	String retornaTipo() {
		return tipo;
	}
	
	public boolean obterEmprestimo(int valor) {
		
		if (valor <= 0) return false;
		if (valor + super.getValorDaDivida() > dividaMaxima) return false;

		super.setValorDaDivida( super.getValorDaDivida() + valor );
		super.setValorContaCorrente( super.getValorContaCorrente() + valor );

		return true;
	}
	
}
