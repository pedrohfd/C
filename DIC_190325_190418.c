#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <locale.h>

int *ponta, *pontb, *pontc;


int fa(int n1)
{
	
	int resultado;
	resultado = n1;
	return(resultado);
}


void main()
{
	setlocale(LC_ALL,"Portuguese");
	
	float f1, f2, f3, x[3], num, ix, iy, pm, e;
	int g, i, j=3, resultado;

	printf("Digite o grau da equação: ");
	scanf("%i",&g);
	if(g>=1 && g<=3)
	{
		for(i=1;i<=g;i++)
		{
		printf("Digite o valor do %io coeficiente de x: ",i);
		scanf("%f",&x[j--]);
		}
		printf("Digite o valor dor termo independente: ");
		scanf("%f",&num);
		printf("Digite o valor do intervalo (valores com espaços): ");
		scanf("%f %f",&ix,&iy);
		//printf("Valor intervalos = (%f , %f)",ix,iy);
		printf("Digite a precisão: ");
		scanf("%f",&e);
		printf("Valor precisão: %.2f",e);
		
		*ponta = x[1];
		*pontb = x[2];
		
		resultado = fa(g);
		
		printf("Resultado %i",resultado);
		
	}
	else
	{
		printf("\nO valor digitado tem que ser de 1 a 3\n\n");
		main();
	}
	
}
