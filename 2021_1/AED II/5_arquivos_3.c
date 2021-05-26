// ao inserir
vetor_alunos[proximo].valido = 1; // novo registro valido


// ao salvar arquivo inteiro: salva dados item-a-item do modo a evitar os invalidos
// 지난번엔 한번에 다 집어넣었다면 이건 하나하나씩 valido 한 건만
arq = fopen("teste2.dad", "w");
for (i = 0; i < prox; i++){
	if (vetor_alunos[i].valido == 1)
		fwrite(&vetor_alunos[i], sizeof(tipo_registro), 1, arq);
}

fclose(arq);


// procura item sequencialmente pelo codigo e marca como excluido
bool MarcarComoExcluido (struct tipo_registro vetor_alunos[], char *codigo, int proximo){
	int i = 0;
	for (i = 0; i < proximo; i++){
		if (strcmp(codigo, vetor_alunos[i].nrousp) == 0){ // strcmp : string 비교문
			vetor_alunos[i].valido == 0 // 'apaga' registro
			return true;
		}
	}
	return false;

	// pressupoe que cabe tudo na memoria
	// 2 leituras : O(n) localizar + O(n) excluir (pq so avanca pra frente)

}


/* 
	se cada registro possui b bytes (sizeof(nrousp + nome + idade + valido))
podemos econtrar a posicao de qualquer registro
	O registro 0 comeca na posicao 0*b
	O registro 1 comeca na posicao 1*b

*/


/*
	rewind(arq) : posiciona leitor de arquivo no inicio
	fseek(arq, +-sizeof(tipo), Origem)
							     |							  
							  SEEK_SET
							  SEEK_CUR
							  SEEK_END

*/












#include <stdio.h>
#include <stdlib.h>


struct tipo_registro {
	char nrousp[7];
	char nome[20];
	int idade;
	int valido; // | 1 = ok | 0 = excluido |
}




algumaCoisa buscaRegistro (algumaCoisa){


	rewind(arq); // nao eh necessario se acabou de abrir o arquivo
	tipo_registro aluno;

	printf("\nInforme o nro. USP do aluno a excluir : ");
	fflush(stdin); fgets(codigo, MaxChar, stdin);

	bool ok = false;
	while ( 1 == fread(&aluno, sizeof(tipo_registro), 1, arq) ){ //중요
		if ( strcmp(codigo, aluno.nrousp) == 0 ) {
			aluno.valido = 0;
			fseek(arq, -sizeof(tipo_registro), SEEK_CUR); //중요
			fwrite(&aluno, sizeof(tipo_registro), 1, arq); //중요
			ok = true;
			break;
		}
	}

	if (!ok) printf("\nErro : registro noa encontrado");
	{} while (true);

}



algumaCoisa modificacaoDeCampos (algumaCoisa){

	rewind(arq);
	tipo_registro aluno;
	printf("\nInforme o nro. USP do aulo que fez aniversario : ");
	fflush(stdin); fgets(codigo, MaxChar, stdin);

	bool ok = false;
	while ( 1 == fread(&aluno, sizeof(tipo_registro), 1, arq) ){
		if ( strcmp(codigo, aluno.nrousp) == 0 ){
			aluno.idade++;
			fseek(arq, -sizeof(tipo_registro), SEEK_CUR); // custo alto de buscar no arquivo
			fwrite(&aluno, sizeof(tipo_registro), 1, arq);
			ok = true;
			break;
		}
	}

	if (!ok) printf("\nErro : registro noa encontrado");
	{} while (true);

}

/*

	- Acesso direto melhor que acesso sequencial
	
	- Registro de tamanho fixo ocupa mais espaco
	- Precisa saber numero sequencial do registro para poder acessar
	- 

*/


// ----------------------------------



//	Sequencialmente

int nrousp; // nro usp a modificar
struct registro;

while ( 1 == fread(&registro, sizeof(tipo_registro), 1, arq) ){
	// comparar nrousp com nrousp do registro
	// se for <>, continue

	registro->idade++;

}

// Modificar o enesimo registro do arquivo
// Custo computacional eh de seek

fseek(arq, n * sizeof(registro), SEEK_SET); // posicionamento no registro n
fread(&registro, sizeof(tipo_registro), 1, arq); // leitura
registro->idade++;
fseek(arq, n * sizeof(registro), SEEK_SET); // ou fseek do slide com (-sizeof) SEEK_CUR
fwrite()
