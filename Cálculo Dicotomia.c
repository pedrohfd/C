//Nome: Pedro Henrique França de Deus       RA: 190418


//Bibliotecas utilizadas.
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <locale.h>

//Protótipo das funções.

void alocaFloat(float **p,int tam);
float fa(float *x, float num,float ix,int g);
float fb(float *x, float num,float ix,int g);
float fm(float *x, float num,float ix,int g);
int TesteG(int *grau);

void main()
{   

	//Função usada para habilitar a utilização de acentos dentro de todos os printf.

	setlocale(LC_ALL,"Portuguese");
	
	//Declaração de todas as variáveis.
	
	float f1, f2, f3, f4, x[10], num, ix, iy, pm, e, k, *vet=NULL, *raiz=NULL;
	int g, i;
	int *grau=&g;
	
	//Alocação de memória feita com a quantidade máxima de coeficientes que o programa pode captar.
	
	alocaFloat(&vet,10);

	//Captação e teste do grau da equação para avaliar se está dentro dos limites permitidos pelo programa.
	
	printf("-------------------------------------- Métodos Numéricos Computacionais - Dicotomia ------------------------------------\n\n");
	printf("Digite o grau da equação: ");
	scanf("%i",&g);
	
	TesteG(grau);

	//Captação dos coeficientes que serão usados na equação.

	for(i=0;i<g;i++)
	{
		printf("Digite o valor do %io coeficiente de x^%i: ",i+1,i+1);
		scanf("%f",&x[i]);		
	}
	
	//Captação do valor do número unitário da equação.
	
	printf("Digite o valor dor termo independente: ");
	scanf("%f",&num);
	
	//Captação dos valores do intervalo que serão usados para encontrar o ponto médio.
	
	printf("Digite o valor do intervalo (valores com espaços): ");
	scanf("%f %f",&ix,&iy);
	
	//Captação da precisão que será usada para determinar a raiz correta.
	
	printf("Digite a precisão: ");
	scanf("%f",&e);
	printf("\n\n");
	
	i=0;
	
	//Cálculo do K para determinar aproximadamente a quantidade de iterações.
	
	k = (log(abs(iy-ix))-log(e))/log(2);
	
	//Alocação de memória feita com a quantidade de iterações aproximadas que o programa pode receber.
	
	alocaFloat(&raiz,k);
	
	printf("\n\n------------------------------------------- Iterações do Método da Dicotomia -------------------------------------------\n\n");
	printf("i                    a                m                b                f(a)                f(m)               f(b)\n");
	
	//For usado para o cálculo das "fs" e do ponto médio sempre que houver uma troca dos pontos.
	
	for( ; ; )
	{
		pm = (ix + iy)/2;
		f1 = fa(x,num,ix,g);
		f2 = fb(x,num,iy,g);
		f3 = fm(x,num,pm,g);
		
		printf("%i                    ",i);
		printf("%.3f            ",ix);
		printf("%.3f            ",pm);
		printf("%.3f            ",iy);
		printf("%.3f              ",f1);
		printf("%.3f              ",f3);
		printf("%.3f\n",f2);
		
		i++;
		
		//Validador usado para colocar em módulo o valor de f(m) se o mesmo for negativo. 
		
		if(f3<0)
		{
			f4 = f3;
			f4 = abs(f4);
			
		}
		
		//Validador para testar se o valor de f(m) é menor que a precisão para o término dos cálculos.
		
		else if(f3<e)
		{
			printf("\n\nA raiz da função é %.3f com erro de %.3f (< %.3f)",pm,f3,e);
			break;
		}
		
		//Validador para a troca dos pontos, do intervalo, anteriores pelos novos pontos.
		
		if((f1>0 && f3<0) || (f1<0 && f3>0))
		{
			iy = pm;
		}
		if((f2>0 && f3<0) || (f2<0 && f3>0))
		{
			ix = pm;
		}
	}
	
	printf("\n\nA quantidade de iterações e aproximadamente %.2f (k=%.2f)",ceil(k),k);
	
}

//Função usada para a validação do grau da equação.

int TesteG(int *grau)
{
	if(*grau>=1 && *grau<=10)
	{}
	else
	{
		printf("\nO valor digitado tem que ser de 1 a 10\n\n");
		system("PAUSE");
		system("CLS");
		main();		
	}
}

//Funções usadas para os cálculos das "fs".

float fa(float *x, float num,float ix,int g)
{
	int i;
	float resultado=0,pot=0;
	for(i=0;i<g;i++)
	{
		pot = pow(ix,i+1);
		resultado = resultado + (pot * x[i]);
		pot = 0;
	}
	resultado = resultado + num;
	
	return resultado;
}
float fb(float *x, float num,float iy,int g)
{
	int i;
	float resultado=0,pot=0;
	for(i=0;i<g;i++)
	{
		pot = pow(iy,i+1);
		resultado = resultado + (pot * x[i]);
		pot = 0;
	}
	resultado = resultado + num;
	
	return resultado;
}
float fm(float *x, float num,float pm,int g)
{
	int i;
	float resultado=0,pot=0;
	for(i=0;i<g;i++)
	{
		pot = pow(pm,i+1);
		resultado = resultado + (pot * x[i]);
		pot = 0;
	}
	resultado = resultado + num;
	
	return resultado;
}

//Função usada para a alocação de memória.

void alocaFloat(float **p, int tam)
{
	if( (*p=(float *)realloc(*p,tam*sizeof(float)) )==NULL)
	{
		printf("Erro na alocação!\n\n");
		exit(1);
	}
	printf("Espaco alocado com sucesso! End= %u\n\n",*p);
}	
