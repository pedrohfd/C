//Nome: Pedro Henrique França de Deus       RA: 190418

//Bibliotecas utilizadas.
#include <stdio.h>
#include <locale.h>

//Protótipo das funções.
float calcula(float p, float *x,int quant, float *fx);
float Recebe_valores();
void alocaFloat(float **p, int tam);

void main(){

	//Função usada para habilitar a utilizaçõo de acentos dentro de todos os printf.
    setlocale(LC_ALL,"Portuguese");
    printf("------------------------ Métodos numéricos computacionais - Lagrange ------------------------\n");

    // Chamada da função para coleta dos valores
    Recebe_valores();
}

// Função usada para o cálculo de lagrange
float calcula(float p, float *x,int quant, float *fx){

    // Variáveis usadas na função
    float P,L;
    int j=0,i=0;

    // For usado na lógica do cálculo
    for(i=0;i<quant;i++){
        L =  1;
        for(j=0;j<quant;j++){
            // Ternário utilizado para a lógica e cálculo de lagrange
            (i!=j) ? L *= (( p  -  *( x  +  j )) / (  *( x  +  i )  -  *( x  +  j )))  : 0;
        }
        printf("\nL%i = %.2f",i ,L);

        // Cálculo do p(x)
        P += (L* (*(fx + i)));
    }
    printf("\nP = %.2f\n\n",P);
    return;   
}

// Função usada para o recebimento dos valores
float Recebe_valores(){

    // Variáveis usadas na função
    int i, quant,s;
    float *fx = NULL, *x = NULL, p, P;

    // Recebimento da quantidade de pontos
    printf("Digite a quantidade de valores de x: ");
    scanf("%d",&quant);
    
    // Chamada da função para a alocação de memória para x e f(x)
    alocaFloat(&x,quant);
    alocaFloat(&fx,quant);

    // For usado para o recebimento dos valores de x e f(x)
    for(i=0;i<quant;i++)
    {
        printf("Digite os valores de x%i: ",i);
        scanf("%f",&x[i]);
    }
    for(i=0;i<quant;i++)
    {
        printf("Digite os valores de f(%i): ",i);
        scanf("%f",&fx[i]);
    }

    // Recebimento do valor que será usado na interpolação
    printf("Digite o valor do x de p(x): ");
    scanf("%f", &p);

    // Chamada da função para o cálculo de lagrange
    calcula(p,x,quant,fx);

    // Teste para a continuidade do programa
    printf("Deseja continuar?\n");
    printf("1. Sim\n2. Não\n");
    scanf("%d",&s);
    (s!=1)?system("CLS"):(system("CLS"),system("PAUSE"),main());

    // Liberação da memória alocada na não continuidade do programa
    free(fx);
    free(x);
    printf("Memória liberada");
    return;
}

// Função usada para a alocação na memória
void alocaFloat(float **p, int tam)
{
    // IF usado para a alocação da memória com a variável usada para receber os valores e o tamanho que será alocado 
	if( (*p=(float *)realloc(*p,tam*sizeof(float)) )==NULL)
	{
		printf("Erro na alocação!\n\n");
		exit(1);
	}
	printf("Espaco alocado com sucesso! End= %u\n\n",*p);
}	