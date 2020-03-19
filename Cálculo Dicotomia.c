//Nome: Pedro Henrique Fran�a de Deus       RA: 190418


//Bibliotecas utilizadas.
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <locale.h>

//Prot�tipo das fun��es.

void alocaFloat(float **p,int tam);
float fa(float *x, float num,float ix,int g);
float fb(float *x, float num,float ix,int g);
float fm(float *x, float num,float ix,int g);
int TesteG(int *grau);

void main()
{   

	//Fun��o usada para habilitar a utiliza��o de acentos dentro de todos os printf.

	setlocale(LC_ALL,"Portuguese");
	
	//Declara��o de todas as vari�veis.
	
	float f1, f2, f3, f4, x[10], num, ix, iy, pm, e, k, *vet=NULL, *raiz=NULL;
	int g, i;
	int *grau=&g;
	
	//Aloca��o de mem�ria feita com a quantidade m�xima de coeficientes que o programa pode captar.
	
	alocaFloat(&vet,10);

	//Capta��o e teste do grau da equa��o para avaliar se est� dentro dos limites permitidos pelo programa.
	
	printf("-------------------------------------- M�todos Num�ricos Computacionais - Dicotomia ------------------------------------\n\n");
	printf("Digite o grau da equa��o: ");
	scanf("%i",&g);
	
	TesteG(grau);

	//Capta��o dos coeficientes que ser�o usados na equa��o.

	for(i=0;i<g;i++)
	{
		printf("Digite o valor do %io coeficiente de x^%i: ",i+1,i+1);
		scanf("%f",&x[i]);		
	}
	
	//Capta��o do valor do n�mero unit�rio da equa��o.
	
	printf("Digite o valor dor termo independente: ");
	scanf("%f",&num);
	
	//Capta��o dos valores do intervalo que ser�o usados para encontrar o ponto m�dio.
	
	printf("Digite o valor do intervalo (valores com espa�os): ");
	scanf("%f %f",&ix,&iy);
	
	//Capta��o da precis�o que ser� usada para determinar a raiz correta.
	
	printf("Digite a precis�o: ");
	scanf("%f",&e);
	printf("\n\n");
	
	i=0;
	
	//C�lculo do K para determinar aproximadamente a quantidade de itera��es.
	
	k = (log(abs(iy-ix))-log(e))/log(2);
	
	//Aloca��o de mem�ria feita com a quantidade de itera��es aproximadas que o programa pode receber.
	
	alocaFloat(&raiz,k);
	
	printf("\n\n------------------------------------------- Itera��es do M�todo da Dicotomia -------------------------------------------\n\n");
	printf("i                    a                m                b                f(a)                f(m)               f(b)\n");
	
	//For usado para o c�lculo das "fs" e do ponto m�dio sempre que houver uma troca dos pontos.
	
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
		
		//Validador usado para colocar em m�dulo o valor de f(m) se o mesmo for negativo. 
		
		if(f3<0)
		{
			f4 = f3;
			f4 = abs(f4);
			
		}
		
		//Validador para testar se o valor de f(m) � menor que a precis�o para o t�rmino dos c�lculos.
		
		else if(f3<e)
		{
			printf("\n\nA raiz da fun��o � %.3f com erro de %.3f (< %.3f)",pm,f3,e);
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
	
	printf("\n\nA quantidade de itera��es e aproximadamente %.2f (k=%.2f)",ceil(k),k);
	
}

//Fun��o usada para a valida��o do grau da equa��o.

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

//Fun��es usadas para os c�lculos das "fs".

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

//Fun��o usada para a aloca��o de mem�ria.

void alocaFloat(float **p, int tam)
{
	if( (*p=(float *)realloc(*p,tam*sizeof(float)) )==NULL)
	{
		printf("Erro na aloca��o!\n\n");
		exit(1);
	}
	printf("Espaco alocado com sucesso! End= %u\n\n",*p);
}	
