#include <stdio.h>
#include <math.h>

void maxima(float, int);
void minima(float, int);
void suma(float);

int hmax, hmin;
float max = -100.0;
float min = 100.0;
float sum = 0.0;

void main(void)
{
	int i;
	float TEM;
	for (i=1 ; i<=24 ; i++)
		{
			printf("Temperatura a las %dHrs: ", i);
			scanf("%f", &TEM);
			maxima(TEM,i);
			minima(TEM,i);	
			suma(TEM);
		}	
	printf("\nTemperatura Máxima de %f a las %dHrs.", max, hmax);
	printf("\nTemperatura Mínima de %f a las %dHrs.", min, hmin);
	printf("\nPromedio de la temperatura en el día: %f\n", (sum/24));
}

void maxima(float T, int H)
{	
	if (max < T)
		{
			max=T;
			hmax=H;
		}
	
}
void minima(float T, int H)
{	
	if (min > T)
		{
			min = T;
			hmin = H;
		}
	
}
void suma(float T)
{	
	sum+=T;
}

