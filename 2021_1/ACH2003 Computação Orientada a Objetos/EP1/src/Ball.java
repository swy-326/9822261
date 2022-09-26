import java.awt.*;
import java.util.Random;


/**
	Esta classe representa a bola usada no jogo. A classe princial do jogo (Pong)
	instancia um objeto deste tipo quando a execução é iniciada.
*/

public class Ball {

	private double cx;
	private double cy;
	private double width;
	private double height;
	private Color color;
	private double speed;
	
	private double directionX;
	private double directionY;

	private Object lasthit;

	/**
		Construtor da classe Ball. Observe que quem invoca o construtor desta classe define a velocidade da bola 
		(em pixels por millisegundo), mas não define a direção deste movimento. A direção do movimento é determinada 
		aleatóriamente pelo construtor.

		@param cx coordenada x da posição inicial da bola (centro do retangulo que a representa).
		@param cy coordenada y da posição inicial da bola (centro do retangulo que a representa).
		@param width largura do retangulo que representa a bola.
		@param height altura do retangulo que representa a bola.
		@param color cor da bola.
		@param speed velocidade da bola (em pixels por millisegundo).
	*/

	public Ball(double cx, double cy, double width, double height, Color color, double speed){
	
		this.cx = cx;
		this.cy = cy;
		this.width = width;
		this.height = height;
		this.color = color;
		this.speed = speed;

		defineDirection();
	}

	/**
		Metodo chamado para definir o modulo e o sentido da velocidade da bola.
	*/

	public void defineDirection(){

		Random r = new Random();

		// peso do speed para cada eixo
		double angle = 0;
		while (angle == 0) angle = r.nextDouble();

		// sentido da bola nos eixos x e y
		int signX = r.nextBoolean() ? 1 : -1;
		int signY = r.nextBoolean() ? 1 : -1;

		directionX = signX * angle * this.speed;
		directionY = signY * (1 - angle) * this.speed;
	}

	/**
		Método chamado sempre que a bola precisa ser (re)desenhada.
	*/

	public void draw(){

		GameLib.setColor(this.color);
		GameLib.fillRect(this.cx, this.cy, this.width, this.height);
	}

	/**
		Método chamado quando o estado (posição) da bola precisa ser atualizado.
		
		@param delta quantidade de millisegundos que se passou entre o ciclo anterior de atualização do jogo e o atual.
	*/

	public void update(long delta){

		this.cx += delta * this.directionX;
		this.cy += delta * this.directionY;
	}

	/**
		Método chamado quando detecta-se uma colisão da bola com um jogador.
	
		@param playerId uma string cujo conteúdo identifica um dos jogadores.
	*/

	public void onPlayerCollision(String playerId){

		this.directionX = - (this.directionX);
	}

	/**
		Método chamado quando detecta-se uma colisão da bola com uma parede.

		@param wallId uma string cujo conteúdo identifica uma das paredes da quadra.
	*/

	public void onWallCollision(String wallId){

		if (wallId.equals("Top") || wallId.equals("Bottom")) this.directionY = -(this.directionY);
		else if (wallId.equals("Right") || wallId.equals("Left")) this.directionX = -(this.directionX);
	}

	/**
		Método que verifica se houve colisão da bola com uma parede.

		@param wall referência para uma instância de Wall contra a qual será verificada a ocorrência de colisão da bola.
		@return um valor booleano que indica a ocorrência (true) ou não (false) de colisão.
	*/
	
	public boolean checkCollision(Wall wall){

		if (this.lasthit == wall) return false;

		String wallId = wall.getId();
		
		if (wallId.equals("Top")) {
			if (this.cy - this.height/2 <= wall.getCy() + wall.getHeight()/2){
				this.lasthit = wall;
				return true;
			}
		}

		else if (wallId.equals("Bottom")) {
			if (this.cy + this.height/2 >= wall.getCy() - wall.getHeight()/2){
				this.lasthit = wall;
				return true;
			}
		}

		else if (wallId.equals("Right")) {
			if (this.cx + this.width/2 >= wall.getCx() - wall.getWidth()/2){
				this.lasthit = wall;
				return true;
			}
		}

		else if (wallId.equals("Left")) {
			if (this.cx - this.width/2 <= wall.getCx() + wall.getWidth()/2){
				this.lasthit = wall;
				return true;
			}
		}

		return false;
	}

	/**
		Método que verifica se houve colisão da bola com um jogador.

		@param player referência para uma instância de Player contra o qual será verificada a ocorrência de colisão da bola.
		@return um valor booleano que indica a ocorrência (true) ou não (false) de colisão.
	*/	

	public boolean checkCollision(Player player){

		//if (lasthit.equals(player.getId()))	return false;
		if (lasthit == player) return false;

		double playerTop = player.getCy() - player.getHeight() / 2;
		double playerBottom = player.getCy() + player.getHeight() / 2;
		double playerRight = player.getCx() + player.getWidth() / 2;
		double playerLeft = player.getCx() - player.getWidth() / 2;

		boolean collision = (this.cy + this.height/2 >= playerTop
		&& this.cy - this.height/2 <= playerBottom
		&& this.cx + this.width/2 >= playerLeft
		&& this.cx - this.width/2 <= playerRight);

		//if (collision == true) lasthit = player.getId();
		if (collision == true) lasthit = player;

		return collision;
	}

	/**
		Método que devolve a coordenada x do centro do retângulo que representa a bola.
		@return o valor double da coordenada x.
	*/
	
	public double getCx(){

		return this.cx;
	}

	/**
		Método que devolve a coordenada y do centro do retângulo que representa a bola.
		@return o valor double da coordenada y.
	*/

	public double getCy(){

		return this.cy;
	}

	/**
		Método que devolve a velocidade da bola.
		@return o valor double da velocidade.

	*/

	public double getSpeed(){

		return this.speed;
	}

}
