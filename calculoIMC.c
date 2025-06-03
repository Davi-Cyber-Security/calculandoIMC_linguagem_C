#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
int main()
{
    setlocale(LC_ALL, "");
    float altura, peso, imc;
    int verificado = 0;
    char nome[20];
    char *classificacao;
    
    printf("\nDigite o seu nome: ");
    scanf("%s", nome);
    do{
    printf("\nDigite seu peso: ");
    if(scanf("%f", &peso) != 1){
        printf("Entrada inválida! Por gentileza digite o seu peso corretamente! ");
        while(getchar() != '\n');
        continue;
    }
    printf("\nDigite a sua altura: ");
    if(scanf("%f", &altura) != 1){
        printf("Entrada inválida! Por gentileza digite a sua altura corretamente! ");
        while(getchar() != '\n');
        continue;
    }
    
    if(peso > 0 && altura > 0){
        imc = peso/(altura*altura);
        classificacao = (imc < 18.5) ? "Abaixo do peso" : 
        (imc < 25.0) ? "Peso normal" : 
        (imc < 30.0) ? "Sobrepeso" : 
        (imc < 35.0) ? "Obesidade 1" : 
        (imc < 40.0) ? "Obesidade 2" : 
                       "Obesidade grau 3 (mórbida)";
                       
        printf("Olá %s seu IMC e: %.2f ", nome, imc);
        printf("\nClassificação: %s", classificacao);
        verificado = 1;
    } else if(peso != peso || altura != altura){
        printf("Valores inválidos, digite corretamente! ");
    } else{
        printf("Valore inválidos! Peso e Altura devem ser positivos.\n");
    }
    } while(verificado <= 0);
    return 0;
}