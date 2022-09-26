#include <stdio.h>
#include <math.h>

// calculate medidas of single line
#define COLUNA 5     // quantidade de dados que serao inseridos
#define LINHA 2      // contem frequencias dos dados acima

void calculaXMandYM();
void desvioPadrao();
void calculaMediana();
void calculaAmplitude();
void coeficienteVar();


float tabela[LINHA][COLUNA];
float x, xm, mediana, amp, var, dp, coefvar;
float freqTotal;

int i, j;



int main(){
  
  for (i = 0; i < COLUNA; i++){
  	printf("\ntabela[valor][%d] : ", i);
	scanf("%f", &tabela[0][i]);
	printf("\ntabela[freq][%d] : ", i);
	scanf("%f", &tabela[1][i]);

  }
  
  calculaXMandYM();
  desvioPadrao();
  calculaAmplitude();
  coeficienteVar();
  
  
  printf("soma : %f\n", x);
  printf("media : %f\n", xm);
  printf("mediana : se vira, amore\n");
  printf("ampitude : %f\n", amp);
  printf("var : %f\n", var);
  printf("dp : %f\n", dp);
  printf("coef de var : %f\n", coefvar);
  
  
  
  return 0;
}


void calculaXMandYM(){
  
  x = 0;
  freqTotal = 0;
 
  for (j = 0; j < COLUNA; j++){
	  x += tabela[0][j] * tabela[1][j];
	  freqTotal += tabela[1][j];
  }
  
  //printf("\n\n\nfreq total : %f\n\n\n\n", freqTotal);

  xm = x / freqTotal;
  
}




void desvioPadrao(){
  
  dp= 0;
  var = 0;
  
  for (j = 0; j < COLUNA; j++){
	  var += (tabela[0][j] - xm) * (tabela[0][j] - xm) * tabela[1][j];
  }

  var /= freqTotal;
  dp = sqrt(var);
  
}


void calculaAmplitude(){
  
  float min, max;
  
  min = tabela[0][0];
  max = tabela[0][0];
  
  for (j = 1; j < COLUNA; j++){
	if (min > tabela[0][j]) min = tabela[0][j];
	else if (max < tabela[0][j]) max = tabela[0][j];
  } 
  
  amp = max - min;
  
}


void coeficienteVar(){
  
  coefvar = dp / xm * 100;
  
}










