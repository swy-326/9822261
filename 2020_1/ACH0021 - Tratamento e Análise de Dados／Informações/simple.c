#include <stdio.h>
#include <math.h>

// calculate medidas of single line
#define COLUNA 6


void calculaXMandYM();
void desvioPadrao();
void calculaMediana();
void calculaAmplitude();
void coeficienteVar();


float tabela[COLUNA];
float x, xm, mediana, amp, var, dp, coefvar;

int i, j;



int main(){
  
  for (i = 0; i < COLUNA; i++){
    scanf("%f", &tabela[i]);
  }
  
  calculaXMandYM();
  desvioPadrao();
  calculaMediana();
  calculaAmplitude();
  coeficienteVar();
  
  
  printf("soma : %f\n", x);
  printf("media : %f\n", xm);
  printf("mediana : %f\n", mediana);
  printf("ampitude : %f\n", amp);
  printf("var : %f\n", var);
  printf("dp : %f\n", dp);
  printf("coef de var : %f\n", coefvar);
  
  
  
  return 0;
}


void calculaXMandYM(){
  
  x = 0;
 
  for (j = 0; j < COLUNA; j++){
      x += tabela[j];
  }
  
  xm = x / COLUNA;
  
}




void desvioPadrao(){
  
  dp= 0;
  var=0;
  
  for (j = 0; j < COLUNA; j++){
      
      var += (tabela[j] - xm)*(tabela[j] - xm);
  }
  var /= COLUNA;
  dp = sqrt(var);
  
}

void calculaMediana(){
  
  int aux = COLUNA/2;
  
  if (COLUNA%2 == 1) mediana = tabela[aux];
  else mediana = (tabela[aux] + tabela[aux+1]) / 2;
  
}

void calculaAmplitude(){
  
  float min, max;
  
  min = tabela[0];
  max = tabela[0];
  
  for (j = 1; j < COLUNA; j++){
    if (min > tabela[j]) min = tabela[j];
    else if (max < tabela[j]) max = tabela[j];
  } 
  
  amp = max - min;
  
}


void coeficienteVar(){
  
  coefvar = dp / xm * 100;
  
}
