public class Sala {

    private String nome;
    private String local;
    private Integer capacidade;
    private String observacoes;


    public Sala(String nome, Integer capacidade, String observacoes){
        this.nome = nome;
        this.capacidade = capacidade;
        this.observacoes = observacoes;
        this.local = "Nao especificado";
    }

    // devolve o nome da sala
    public String getNome(){

        return nome;
    }

    // devolve o local da sala
    public String getLocal(){

        return local;
    }
    
    // devolve a capacidade da sala
    public Integer getCapacidade(){

        return capacidade;
    }

    // devolve as observacoes da sala
    public String getObservacoes(){

        return observacoes;
    }

    // atualiza o valor da variavel local
    public void setLocal(String local){
        this.local = local;
    }
}
