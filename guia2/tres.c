#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <wiringPi.h>
void parteA(); 		// Almacena 256 datos aleatorios.
void parteB();			// Al ingresar variable la devuelve en binario
						// asumiendo una variable decimal entre 0 y 255.
int main (void) 
{
	parteA();
	parteB();
	return 0;
}

void parteA()
{
	static int A[30];
	int i;
	printf("a) 256 datos aleatorios alamcenados en un arreglo\n");
	srand((unsigned)time(NULL));

	for(i=1; i<=256; i++)						// Guarda en un arreglo 256 datos aleatorios.
	{
		A[i]=rand()%255;
		printf("A[%d]=%d\n", i, A[i]);
	}
}

void parteB()
{
	printf("\nb) Transformación a binario\n");
	wiringPiSetup ();
	pinMode (0,OUTPUT);
	int i,j,n,r[8];
	printf("Ingrese variable [0-255]: ");		
	scanf("%i",&n);
	i=0;
	if(n==0)
		{
			printf("%i\n",n);
		}
	else
		{
			while(n>0)									// Divide la variable ingresada por 2
			{											// y guarda el resto en un arreglo hasta
				r[i]=n%2;								// que el resto es 0.
				n/=2;
				++i;
			}
			for(j=i-1;j>=0;--j)							// Recorre el arreglo de forma inversa 
			{											// para contruir el número binario.
				printf("%d",r[j]);
				if (r[j]==1)
					{	printf(" LED (ON)");
						digitalWrite (0, HIGH); 		// Haciendo uso de un único Led, este 
					}									// encenderá si el resto es 1 y se 
				else 									// apagará si el resto es 0.
					{	
						printf(" LED (OFF)");
						digitalWrite (0, LOW); 					
					}
				delay(1000);
				printf("\n");
			}
	delay(1000);
	digitalWrite (0, LOW); 								// Apagaga el led para evitar confusión.
		}
}

