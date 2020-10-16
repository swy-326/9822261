package BX;

import java.util.Scanner;

public class AceitoSeuDesafioFurquim_senpai {


    public static void main(String[] args) {

        Scanner scan = new Scanner(System.in);
        String nu = scan.nextLine();
        int n = Integer.parseInt(nu);
        int c = 0;

        while (c < n) {

            String entr = scan.nextLine();
            String ent  = entr.toLowerCase();
            if(mellon(ent)){
                System.out.println("YESSS");
            }
            else{
                System.out.println(":(");
            }
            c++;
        }
    }

    static boolean mellon (String ent){
        boolean resposta = false;
        // m e l l o n
        String entrada []= ent.split(" ");
        for(int i = 0; i < entrada.length; i++) {
            int mmm = entrada[i].indexOf('m');
            if (mmm == 0) {
                if (m(entrada[i], 'e', 0)) {
                    resposta = true;
                    return true;
                }
            }
        }

        return resposta;
    }

    static boolean m (String ent, char ini, int l){
        int i = 0;
        boolean achou = false;
        while(ent.charAt(i) != ini && i < ent.length()){
            if(ent.charAt(i) == ini){
                achou = true;
            }
            i++;
        }
        if(achou){
            if(ini == 'e'){
                m(ent, 'l', 0);
            }
            if(ini == 'l' && l == 0){
                m(ent, 'l', 1);
            }
            if(ini == 'l' && l == 1){
                m(ent, 'o', 0);
            }
            if(ini == 'o'){
                m(ent, 'n', 0);
            }
            if(ini == 'n'){
                return true;
            }
        }
        return false;
    }
}
/*
42
Fale, amigo, e entre
Mellon
OH, abriu!
Voce viu so, loucura ne?
Abre sempre que eu falo mellon ?
Aham
Mesmo se eu gritar MELLON ?
Sim
Mas eh so desses jeitos? Eu posso falar tipo meeeeeeeellooon
Funciona tambem
Loco, e se tiver grudadinho com outros caracteres? Tipo caramellon
Nao, ai nao
Nem se for antes? Tipo melloncolia
Nope
Hmm e se eu fizer um remix tipo m e l l o n ?
Maluco, essas portas sao inteligentes para caramba, elas vao reconhecer
Por acaso, Mellon eh amigo em elfico?
O que voce disse?
POR ACASO MELLON EH AMIGO EM ELFICO?
Calma, nao precisa gritar
Vai atrair alguma criatura indesejada
Parece um boc´o
pOR aCaSO Me L L o N eH AmiGO eM ELfiCo
Eu hein
...e se eu cantar uma mellondia?
Por favor, nao
mmmmmmeeeeeeeeeellllllooooooooooonnnnnn
Pare, por favor
m m m m mmme e e e e e l l l l oooooooooo NNNNNNNNNN
Eu nunca te pedi nada
mmmmeeeeellllooonnn~ao vou parar
Eu n~ao aguento mais
S´o mais uma vaime ll o o o ooooooo NNNNNNNNNN
Eu desisto
Eu disse me e e llon
Eu vou embora
Cante comigo vaimmmmm m m m m e e e l l l l lllloooo o o nnnn nn nnnmmmeee
Nem que o oliphant tussa
Bora! Eh m eh e eh l eh l eh o eh n
Ok, minha hora chegou
Hora do solo m m m m e e e e e l o o o n n n
Flw

42 tentativas
Nada acontece
As Portas de Durin se abrem
Nada acontece
Nada acontece
As Portas de Durin se abrem
Nada acontece
As Portas de Durin se abrem
Nada acontece
As Portas de Durin se abrem
Nada acontece
Nada acontece
Nada acontece
Nada acontece
Nada acontece
As Portas de Durin se abrem
Nada acontece
As Portas de Durin se abrem
Nada acontece
As Portas de Durin se abrem
Nada acontece Nada acontece
Nada acontece
As Portas de Durin se abrem
Nada acontece
Nada acontece
Nada acontece
As Portas de Durin se abrem
Nada acontece
As Portas de Durin se abrem
Nada acontece
Nada acontece
Nada acontece
Nada acontece
Nada acontece
As Portas de Durin se abrem
Nada acontece
As Portas de Durin se abrem
Nada acontece
Nada acontece
Nada acontece
Nada acontece
Nada acontece

 */