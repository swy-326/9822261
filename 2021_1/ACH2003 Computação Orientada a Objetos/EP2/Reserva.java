import java.time.*;

public class Reserva {
    
    private Sala sala;
    private LocalDateTime inicio;
    private LocalDateTime fim;


    public Reserva(Sala sala, LocalDateTime inicio, LocalDateTime fim){
        this.sala = sala;
        this.inicio = inicio;
        this.fim = fim;
    }

    // devolve o objeto sala referente a reserva
    public Sala getSala(){

        return sala;
    }

    // devolve a data de inicio
    public LocalDateTime getInicio(){

        return inicio;
    }

    // devolve a data final
    public LocalDateTime getFim(){

        return fim;
    }
}
