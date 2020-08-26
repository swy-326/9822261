#include <stdio.h>

// MUST be +1 each line
#define LINHA 3
#define COLUNA 4

void resetTabela();
void criarCopia();
void imprimirTabela ();
void imprimirTabelaResumido ();
void imprimirTabelaEsperado();
void somarMarginais();
void calcularPorcentagem();
void cemPorcentColuna();
void cemPorcentLinha();
void valorEsperadoColuna();
void valorEsperadoLinha();
void desvioObsEsp();
void medidaAfastamento();
float quiquadrado();


float tabela[LINHA][COLUNA];
float calculo[LINHA][COLUNA];
float esperado[LINHA][COLUNA];
int i, j;

int main(){

  resetTabela();
  

  for (i = 0; i < LINHA - 1; i++){
    for (j = 0; j < COLUNA - 1; j++){
      printf("tabela[%d][%d] : ", i, j);
      scanf("%f", &tabela[i][j]);
    }
  }
    
  printf("\nMarginais Somadas\n");
  somarMarginais();
  criarCopia();
  imprimirTabela();
  
  printf("\nIndicados em %% \n");
  calcularPorcentagem();
  imprimirTabela();

  printf("\nIndicados em %% por Coluna \n");
  cemPorcentColuna();
  imprimirTabela();

  printf("\nValor esperado com 100%% em coluna\n");
  valorEsperadoColuna();
  imprimirTabelaEsperado();

  printf("\nDesvio Observado - Esperado \n");
  desvioObsEsp();
  imprimirTabelaResumido();

  printf("\nMedidas de Afastamento \n");
  medidaAfastamento();
  imprimirTabelaResumido();
  
  printf("\nCoeficiente Qui-quadrado : %.2f", quiquadrado());
 

  return 0;
}




void resetTabela (){
  for (i = 0; i < LINHA; i++){
    for (j = 0; j < COLUNA; j++){
      tabela[i][j] = 0;
      calculo[i][j] = 0;
      esperado[i][j] = 0;
    }
  }
}

void imprimirTabela (){

  printf("\n");

  for (i = 0; i < LINHA; i++){
    for (j = 0; j < COLUNA; j++){
      printf("%.1f  \t", calculo[i][j]);
    }
    printf("\n");
  }
}

void imprimirTabelaResumido (){

  printf("\n");

  for (i = 0; i < LINHA-1; i++){
    for (j = 0; j < COLUNA-1; j++){
      printf("%.1f  \t", calculo[i][j]);
    }
    printf("\n");
  }
}

void imprimirTabelaEsperado (){

  printf("\n");

  for (i = 0; i < LINHA; i++){
    for (j = 0; j < COLUNA; j++){
      printf("%.1f  \t", esperado[i][j]);
    }
    printf("\n");
  }
}


void criarCopia(){
  for (i = 0; i < LINHA; i++){
    for (j = 0; j < COLUNA; j++){
      calculo[i][j] = tabela[i][j];
    }
  }
}

void somarMarginais (){

  float soma = 0;

  // preenche ultima coluna
  for (i = 0; i < LINHA; i++){
    for (j = 0; j < COLUNA -1; j++){
      soma += tabela[i][j];
    }
    tabela[i][j] = soma;
    soma = 0;
  }

  soma = 0;
  
  // preenche ultima linha
  for (i = 0; i < COLUNA; i++){
    for (j = 0; j < LINHA-1; j++){
      soma += tabela[j][i];
    }
    tabela[j][i] = soma;
    soma = 0;
  }
}

void calcularPorcentagem(){

  for (i = 0; i < LINHA; i++){
    for (j = 0; j < COLUNA; j++){
      float aux = calculo[i][j];
      calculo[i][j] = aux / calculo[LINHA-1][COLUNA-1] * 100;
    }
  }
}

void cemPorcentColuna(){
  for (i = 0; i < LINHA; i++){
    for (j = 0; j < COLUNA; j++){
      float aux = calculo[i][j];
      calculo[i][j] = aux / calculo[i][COLUNA-1] * 100;
    }
  }
}

void cemPorcentLinha(){
  for (i = 0; i < LINHA; i++){
    for (j = 0; j < COLUNA; j++){
      float aux = calculo[j][i];
      calculo[j][i] = aux / calculo[LINHA-1][i] * 100;
    }
  }
}

void valorEsperadoColuna(){

  for (i = 0; i < LINHA; i++){
    for (j = 0; j < COLUNA; j++){
      esperado[i][j] = tabela[i][COLUNA-1] * calculo[LINHA-1][j]/ 100;
    }
  }
}

void valorEsperadoLinha(){

  for (i = 0; i < LINHA; i++){
    for (j = 0; j < COLUNA; j++){
      esperado[i][j] = tabela[LINHA-1][j] * calculo[i][COLUNA-1]/ 100;
    }
  }
}

void desvioObsEsp(){
  
  for (i = 0; i < LINHA-1; i++){
    for (j = 0; j < COLUNA-1; j++){
      calculo[i][j] = tabela[i][j] - esperado[i][j];
    }
  }
}


void medidaAfastamento(){
  
  for (i = 0; i < LINHA-1; i++){
    for (j = 0; j < COLUNA-1; j++){
      calculo[i][j] = calculo[i][j] * calculo[i][j] / esperado[i][j];
    }
  }
}

float quiquadrado(){
  
  float soma = 0;
  
  for (i = 0; i < LINHA-1; i++){
    for (j = 0; j < COLUNA-1; j++){
      soma += calculo[i][j];
    }
  }
 return soma;
}
