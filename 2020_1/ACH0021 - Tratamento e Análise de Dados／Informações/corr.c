#include <stdio.h>
#include <math.h>

// only works with 2 lines
#define LINHA 2
#define COLUNA 10

void resetTabela();
void calculaXandY();
void calculaXMandYM();
void calculaXXandYY();
void calculaXY();
void caculaFormula();


float tabela[LINHA][COLUNA];
float x, xx, y, yy, xy, xm, ym, wan;
float dpx, dpy;
float numerador, denominador;

int i, j;



int main(){
  
  for (i = 0; i < LINHA; i++){
    for (j = 0; j < COLUNA; j++){
      scanf("%f", tabela[i][j]);
    }
  }

  calculaXandY();
  calculaXMandYM();
  calculaXXandYY();
  calculaXY();
  calculaFormula();
  desvioPadrao();
  
  
  printf("x : %f\n", x);
  printf("xx : %f\n", xx);
  printf("xm : %f\n", xm);
  printf("y : %f\n", y);
  printf("yy : %f\n", yy);
  printf("ym : %f\n", ym);
  printf("xy : %f\n", xy);
  printf("\nwan : %f\n", wan);
  
  printf("\ndpx : %f\n", dpx);
  printf("dpy : %f\n", dpy);
  
  
  return 0;
}

void resetTabela(){
  
  for (i = 0; i < LINHA; i++){
    for (j = 0; j < COLUNA; j++){
      tabela[i][j] = 0;
    }
  }
}

void calculaXandY(){
  
  x = 0;
 
  for (j = 0; j < COLUNA; j++){
      x += tabela[0][j];
  }
  
  y = 0;
  
  for (j = 0; j < COLUNA; j++){
      y += tabela[1][j];
  }
  
}

void calculaXMandYM(){
  
  xm = x / COLUNA;
  ym = y / COLUNA;
  
}

void calculaXXandYY(){
  
  xx = 0;
 
  for (j = 0; j < COLUNA; j++){
      xx += tabela[0][j] * tabela[0][j];
  }
  
  yy = 0;
  
  for (j = 0; j < COLUNA; j++){
      yy += tabela[1][j] * tabela[1][j];
  }
  
  
}

void calculaXY(){
  
  xy = 0;
  
  for (j = 0; j < COLUNA; j++){
      xy += tabela[0][j] * tabela[1][j];
  }
  
}

void calculaFormula(){
  
  wan = 0;
  
  
  numerador = xy - (COLUNA * xm * ym);
  denominador = (xx - (COLUNA * xm * xm)) * (yy - (COLUNA * ym * ym));
  denominador = sqrt(denominador);
  
  wan = numerador / denominador;
  
}

void desvioPadrao(){
  
  dpx= 0;
  
  for (j = 0; j < COLUNA; j++){
      
      dpx += (tabela[0][j] - xm)*(tabela[0][j] - xm);
  }
  dpx /= COLUNA;
  dpx = sqrt(dpx);
  
  
  dpy = 0;
  
  for (j = 0; j < COLUNA; j++){
      dpy += (tabela[1][j] - ym)*(tabela[1][j] - ym);
  }
  dpy /= COLUNA;
  dpy = sqrt(dpy);
  
}





