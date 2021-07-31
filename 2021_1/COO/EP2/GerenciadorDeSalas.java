import java.util.*;  
import java.time.*;
import java.time.format.DateTimeFormatter;
import java.io.Console;

public class GerenciadorDeSalas {


    private HashMap<String, Sala> salasDisponiveis = new LinkedHashMap<>();
    private HashMap<String, Collection<Reserva>> salasReservadas = new HashMap<>();

    Console con = System.console();



    public void adicionaSalaChamada(String nome, int capacidadeMaxima, String descricao){

        // cria objeto com os parametros e adiciona em salasDisponiveis
        Sala sala = new Sala(nome, capacidadeMaxima, descricao);
        salasDisponiveis.put(nome, sala);
    }

    
    
    public void removeSalaChamada(String nomeDaSala){

        // remove a entrada com a key correspondente de salasDisponiveis
        salasDisponiveis.remove(nomeDaSala);
    }



    public List<Sala> listaDeSalas(){

        List<Sala> salasLista = new ArrayList<>();

        // adiciona todos os valores de salasDisponiveis em salasLista
        for(Sala sala : salasDisponiveis.values()) {
            salasLista.add(sala);
        }

        return salasLista;
    }



    public void adicionaSala(Sala novaSala){

        // adiciona a sala passada por parametro em salasDisponiveis
        String nomeDaSala = novaSala.getNome();
        salasDisponiveis.put(nomeDaSala, novaSala);
    }



    public Reserva reservaSalaChamada(String nomeDaSala, LocalDateTime dataInicial, LocalDateTime dataFinal) throws ReservaException{

        Sala sala = salasDisponiveis.get(nomeDaSala);
        Reserva reserva = new Reserva(sala, dataInicial, dataFinal);
        Collection<Reserva> colReserva;
        
        // se ja houver reservacoes na sala adiciona a nova na coleção
        if(salasReservadas.containsKey(nomeDaSala)) {
            colReserva = salasReservadas.get(nomeDaSala);

            // caso a reserva nova tenha colisao em data com alguma existente uma excecao e lancada
            for(Reserva r : colReserva) {
                if(!(dataInicial.isAfter(r.getFim()) || dataFinal.isBefore(r.getInicio())))
                    throw new ReservaException("A sala ja esta reservado dentro do horario especificado");
            }

            colReserva.add(reserva);
        }
        // caso a sala exista porem nao tenha nenhuma reserva
        else if(salasDisponiveis.containsKey(nomeDaSala)) {
            colReserva = new ArrayList<>();
            colReserva.add(reserva);
            salasReservadas.put(nomeDaSala, colReserva);
        }
        // caso a sala nao exista
        else {
            throw new ReservaException("A sala " + nomeDaSala + " nao existe.");
        }

        return reserva;
    }



    public void cancelaReserva(Reserva cancelada){

        // remove a reserva da colecao de sua sala
        Sala sala = cancelada.getSala();
        Collection<Reserva> colReserva = salasReservadas.get(sala.getNome());
        colReserva.remove(cancelada);
    }



    public Collection<Reserva> reservasParaSala(String nomeSala){

        // retorna a colecao da sala especificada
        return salasReservadas.get(nomeSala);
    }



    public void imprimeReservasDaSala(String nomeSala){

        con.printf("A sala %s esta reservada para os seguintes horarios:\n", nomeSala);

        Collection<Reserva> colReserva = salasReservadas.get(nomeSala);

        // imprime a data inicio e fim para todas as reservas presentes na colecao da sala especificada
        for(Reserva reserva : colReserva) {
            DateTimeFormatter formatador = DateTimeFormatter.ofPattern("dd-MM-yyyy HH:mm:ss");

            String dataInicio = reserva.getInicio().format(formatador);
            String dataFim = reserva.getFim().format(formatador);

            con.printf("Das %s ate as %s\n", dataInicio, dataFim);
        }
    }
}
