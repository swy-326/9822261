#include<stdio.h>

/*
int main(){
  char letra;
  scanf("%c", &letra);
  switch(letra){
    case 'a':
    case 'e':
    case 'i': 
    case 'o':
    case 'u':
    case 'A': 
    case 'E': 
    case 'I': 
    case 'O':
    case 'U':
              printf("Vogal\n");
              break;
    default: printf("Cosoante\n");
  }
  return 0;
}
*/

/*
int main(){
  int mes;
  //printf("Insira o mês: ");
  scanf("%d",&mes);
  switch(mes){
    case 1: printf("January\n");
            break;
    case 2: printf("February\n");
            break;
    case 3: printf("March\n");
            break;
    case 4: printf("April\n");
            break;
    case 5: printf("May\n");
            break;
    case 6: printf("June\n");
            break;
    case 7: printf("July\n");
            break;
    case 8: printf("August\n");
            break;
    case 9: printf("September\n");
            break;
    case 10: printf("October\n");
            break;
    case 11: printf("November\n");
            break;
    case 12: printf("December\n");
  }

  return 0;
}
*/

/*
int main(){
  int mes;
  //printf("Insira o mês: ");
  scanf("%d",&mes);
  switch(mes){
    case 1: printf("Janeiro\n");
    case 2: printf("Fevereiro\n");
    case 3: printf("Março\n");
            printf("Este é o primeiro trimestre.\n");
            break;
    case 4: printf("Abril\n");
    case 5: printf("Maio\n");
    case 6: printf("Junho\n");
            printf("Este é o segundo trimestre.\n");
            break;
    case 7: printf("Julho\n");
    case 8: printf("Agosto\n");
    case 9: printf("Setembro\n");
            printf("Este é o terceiro trimestre.\n");
            break;
    case 10: printf("Outubro\n");
    case 11: printf("Novembro\n");
    case 12: printf("Dezembro\n");
            printf("Este é o quarto trimestre.\n");
            break;
    default: printf("Mês invalido.\n");
  }

  return 0;
}
*/

/*
int main(){
  int idade;
  scanf("%d", &idade);
  if(idade < 0) printf("Você tá louco!\n");
  else{
    switch(idade){
      case 0 ... 7: printf("Newborn\n");
                    break;
      case 8 ... 12: printf("Nemo\n");
                     break;
      case 13 ... 14: 
      case 16 ... 17: printf("Juvenil\n");
                      break;
      case 15: printf("Promoção\n");
               break;
      case 18 ... 29: printf("Adulto\n");
                      break;
      case 30 ... 50: printf("Profissa\n");
                      break;
      default: printf("Senior\n");
    }
  }
  return 0;
}
*/

/*
int main(){
  int op;
  float valor1, valor2;
  printf("PROGRAMA PARA CONVERSÃO\n");
  printf("1 - Polegadas para Cm\n");
  printf("2 - Cm para Polegadas\n");
  printf("3 - Metros para Km\n");
  printf("4 - Km para Metro\n");
  printf("Escolha sua opção: ");
  scanf("%d", &op);
  switch(op){
    case 1:
      printf("Entre com o valor em polegadas: ");
      scanf("%f", &valor1);
      printf("%.2f polegadas são %.2fcm!\n", valor1, valor1*2.54);
      break;
    case 2:
      printf("Entre com o valor em centimetros: ");
      scanf("%f", &valor1);
      printf("%.2fcm são %.2f polegadas!\n", valor1, valor1/2.54);
      break; 
    case 3:
    case 4:
    default: printf("Falta fazer\n");   
  }
  return 0;
}
*/

/*
int main(){
  float num1, num2, result;
  char op;
  scanf("%f %f %c", &num1, &num2, &op);
  switch(op){
    case '+': result = num1 + num2;
              break;
    case '-': result = num1 - num2;
              break;
    case '*': result = num1 * num2;
              break;
    case '/': result = num1 / num2;
              break;
    default:  printf("Operação inválida\n");
              result = 0;
  }
  printf("%.2f\n", result);
  return 0;
}
*/


/*
int main(){
  int valor;
  scanf("%d", &valor);
  valor%2==0?printf("Par\n"):printf("Ímpar\n");
  return 0;
}

int main(){
  int n1, n2, maior;
  scanf("%d %d", &n1, &n2);
  maior = (n1 > n2) ? n1 : n2;
  printf("%d\n", maior);
  // (n1 > n2) ? printf("%d\n", n1) : printf("%d\n", n2);
  // printf("%d\n", (n1>n2)?n1:n2);
  return 0;
}*/