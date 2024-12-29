
/* Criar um programa para ler dois fracionários
divisor e dividendo e retornar a divisão.

#include<stdio.h>
int main(){
  float divisor, dividendo, resultado;
  scanf("%f%f", &dividendo, &divisor);

  if(divisor == 0){
    printf("Divisão por zero não definida nos reais.\n");
    scanf("%f",&divisor);
  }
  else{  
    resultado = dividendo / divisor;
    printf("%f", resultado);
  }

  return 0;
}

*/

/* Criar um programa para verificar se 
um natural é par.
○ Caso seja informado um valor negativo, 
exibir a mensagem “Valor inválido”.

#include<stdio.h>
int main(){
  int valor;
  scanf("%d",&valor);
  if(valor < 0){
    printf("Valor inválido!\n");
  }
  else{
    if(valor%2 == 0){
      printf("%d é par!\n",valor);
    }
    else{
      printf("%d é ímpar!\n",valor);
    }
  }
  return 0;
}

*/

//Imposto em Lisarb
/*
#include<stdio.h>
int main(){
  float valor;
  scanf("%f", &valor);
  if(valor <= 2000){
    printf("Isento\n");
  }
  else if(valor <= 3000){
    printf("%.2f", (valor-2000)*0.08);
  }
  else if(valor <= 4500){
    printf("%.2f", (valor-3000)*0.18 + 80);
  }
  else{
    printf("%.2f", (valor-4500)*0.28 + 80 + 270);
  }
  return 0;
}
*/