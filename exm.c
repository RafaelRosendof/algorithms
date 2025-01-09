#include <stdio.h>
#include<math.h>

int fun1(int a){

    printf("Digite um número: ");
    scanf("%d" , &a);

    int quad = a * a;

    return quad;
}

float fun2(float alt , float peso){

    printf("Solicito a altura e o peso, respectivamente: ");
    scanf("%f %f", &alt , &peso);

    float imc = peso / (alt * alt);

    if( imc >70.0){
        printf("MORTE!!!!!!");
        return imc;
    }
    else if (imc < 70.0 && imc > 30.0) {
        printf("GORDÃOOOOO!!!! ");
        return imc;
    }
    else if (imc < 30.0 && imc > 19.0) {
        printf("FEZ O MÍNIMO   ");
        return imc;
    }
    else {
       printf("NINGUEM LIGA ");
      return imc;
    }


}


double x2(double a , double b, double c ){
    printf("Digite o a depois o b depois o C: ");
    scanf("%lf %lf %lf", &a , &b , &c);

    double delta = (b*b) - (4 *a*c);
    double d2 = sqrt(delta);
    double x1 = (-b + d2) / (2 * a);

    return x1;
}

int fun4(int i){

    if(i == -1){return -1;}

    printf("fala figas %d \n",i);
    return fun4(i--);
}


int main(){

    //int a;
    //a = fun1(a);

    //printf("o quadrado foi %d", a);

    //printf("\n\n\n\n\n\n função 2");

    //float alt , peso;

    //fun2(alt , peso);

    //double a,b,c;
    //double val = x2( a,  b,  c);


    //printf("Valor da raiz foi %lf: ", val);

    for(int i = 0 ; i < 1000 ; i++){
        printf("fala figas %d \n",i);
    }

    for(int i = 1000 ; i > 0 ; i--){
        printf("fala figas %d \n",i);
    }

    int def = 1000;

    while(def > 0){
        printf("fala figas %d \n",def);
        def--;
    }

    do {

        printf("fala figas %d \n",def);
        def--;
    }while (def > 0);

    fun4(def);

    return 0;
}

/*

for

while

do while

recursão



EX1 = a soma dos números divisiveis por 3 do 0 ao 1 milhão

EX2 = Criar um sistema para saber se o aluno passou por média (aprovado por nota =5 ) aprovado = 7, se tirar uma nota abaixo de 3 média vai para 21,a reposiçaõ a média é 14
duas maiores notas

EX3 = Jogo de adivinhar números dado um número de 0 a 100 tem que adivinhar o número e avisar se é maior ou menor e tem que ter as vidas e os níveis


*/
