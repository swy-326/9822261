# passar variaveis de uma pagina pra outra

GET - passadas na URL (ex : busca)
POST - passadas "em segredo" (body) mas nao eh seguro, so nao aparece em URL (senha)


- c와 비슷

- Nao tem tipo

- $variavel

- $_POST $_GET sao um dicionario/mapa
	$_POST['value']는 내가 웹페이지에서 직접 한 메세지를 보낼 때, 그 메세지가 value값이고 POST로 보냄

- isset = variavel 이 존재하냐 안하냐

- include "other.php"
	com todas as definicoces, funcoes, variaveis

	if (isset($_POST['senha']) && isset($_POST['user'])){
		$status = db_login(//valores//)
	}
