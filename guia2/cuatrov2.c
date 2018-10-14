#include <stdio.h>
#include <time.h>
#include <stdlib.h>



int * getRandom()
{
	static int TEM[24];
	int i,hmax,hmin;
	float max = -100.0;
	float min = 100.0;
	float suma = 0.0;
	
	srand( (unsigned)time( NULL) );
	for(i=1; i<=24; i++)
	{
		TEM[i]=(rand()%15)+15;  			// temperaturas entre 15 y 30
		printf("TEM%d = %d\n", i, TEM[i]);
		
		
		
		if (TEM[i] > max)			// Calculo maximo
			{ 					
				max = TEM[i];
				hmax = i;
			}
		
		if (min > TEM[i])		// Calculo minimo
			{ 					
				min = TEM[i]; 
				hmin = i;
			}		
			
		suma+=TEM[i];			//Suma de temperaturas
	}
		      		
	printf("\nTemperatura Máxima TEM%d = %0.1f a las %dHrs.", hmax, max, hmax);
	printf("\nTemperatura Mínima TEM%d = %0.1f a las %dHrs.", hmin, min, hmin);
	printf("\nPromedio de la temperatura en el día: %0.1f\n", (suma/24));
	return TEM;
}


int main() 
{
	
	int *p;
	p = getRandom();
	return 0;

}
