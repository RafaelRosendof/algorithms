#include <stdio.h>


void printaValor(int a , int b){

  printf("\n %d %d " , a , b);

}


 // Aqui é um comentário dando // 
int main(){

  printf("A linguagem mais usada no mundo \n");

  int var = 10;

  float var1 = 10.25;

  //char s = "d";

  char s [] = "olá mundo";
  //

  printf("%d e %f  e %s" , var , var1 , s);


  int var3 = 7256;
  int var4 = 28554;

  //quebra de linha 
  printf("\n\n\n");

  int var5 = var3 * var4; 

  printf("%d",var5);



  int var6;

  printf("\n Digite o valor agora: ");
  scanf("%d", &var6);
 
  int var7 =  var5 / var6;

  printf("\n valor resultante é : %d " , var7);

  printaValor(10 , 20);

  /*
   * 1 ATIVIDADE fazer um código que recebe um número e faz o quadrado dele;
   *
   * 2 ATIVIDA fazer um c´odigo que receber a altura e o peso e vai retornar o IMC;
   *
   * 3 ATIVIDADE fazer um código que vai receber uma equação quadrática ( 4 , 10 , 20) retornar só o x1;
   *
   *
   * Caso fique em dúvida, proxima aula tem arrays loops e condições 
   */

  return 0;



}

