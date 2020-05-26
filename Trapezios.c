#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
#include <math.h>

void alocaFloat(float **p, int tam);
float ReceberValores();
float Calculo(float divisao, float a, float b, int grau, float *valores, float *expoente,float c);

void main(){
    ReceberValores();
}
// Função utilizada para receber os valores
float ReceberValores(){

    setlocale(LC_ALL,"Portuguese");

    int grau = 0,i=0;
    float divisao, *expoente = NULL, *valores = NULL, aux, c, a, b;
    printf("Digite o grau da equação de 1 a 10 - ");
    scanf("%i",&grau);
    if(grau>10 || grau<1){
        printf("\nGrau da equação incorreto.");
        main();
    }

    alocaFloat(&expoente,grau);
    alocaFloat(&valores,grau);

    printf("Digite os valores dos expoentes - ");
    for(i=0;i<grau;i++){
        scanf("%f",expoente+i);
    }

    printf("Digite os valores da função - ");
    for(i=0;i<grau;i++){
        scanf("%f",valores+i);
    }
    
    printf("Digite o valor da constante - ");
    scanf("%f",&c);

    printf("Digite o intervalo - ");
    scanf("%f",&a);
    scanf("%f",&b);

    if(a > b){
        aux = a;
        a = b;
        b = aux;
    }

    printf("Digite a quantidade de divisões - ");
    scanf("%f",&divisao);
    if(divisao<1){
        printf("Divisão incorreta");
        main();
    }

    Calculo(divisao,a,b,grau,valores,expoente,c);

    return;

}
//Função utilizada para realizar os calculos
float Calculo(float divisao, float a, float b, int grau, float *valores, float *expoente,float c){
    
    setlocale(LC_ALL,"Portuguese");

    int i=0,j=0, repete;
    float s1, s2, s3, h, IT, res;
	//Calculo da altura
    h = (b - a) / divisao;
    printf("\n %.2f = (%.2f - %.2f) / %.2f ",h,b,a,divisao);

    // Calculo dos polinomios
    for(i=0;i<grau;i++){
		s1 += (*(valores+i) * (pow(a, (*(expoente+i)))));
	}
    s1 += c;

    for(i=0;i<grau;i++){
		s2 += (*(valores+i) * (pow(b, (*(expoente+i)))));
	}
    s2 += c;
    // Teste realizado para verificar se é trapézio simples ou composto
    if(divisao>1){
        res = a;
        for(i=0;i<divisao;i++){
            res += h;
            for(j=0;j<grau;j++){
		        s3 += (*(valores+j) * (pow(res , (*(expoente+j))))) + c;
	        }
        }        
    }
    s3 -= s1+s2;
    IT = (h/2) * ((s1+s2) + (2*s3));
    printf("\nIT: %.4f",IT);

    printf("\nDejesa realizar outro calculo? - ");
    printf("\nsim - 1\nNão - 2\n");
    scanf("%i",&repete);
    switch (repete)
    {
    case 1:
        free(expoente);
        free(valores);
        main();
    
    default:
        free(expoente);
        free(valores);
        break;
    }
    return;
}
// Função utilizada para a alocação de dados
void alocaFloat(float **p, int tam)
{
    // IF usado para a alocação da memória com a variável usada para receber os valores e o tamanho que será alocado 
	if( (*p=(float *)realloc(*p,tam*sizeof(float)) )==NULL)
	{
		printf("Erro na alocação!\n\n");
		exit(1);
	}
}
