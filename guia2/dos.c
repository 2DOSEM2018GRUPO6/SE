#include <stdio.h>

void main(void)
{
	int s;
	float FA, CE;
	printf("\nNúmero de sonidos emitidos por minuto: ");
	scanf("%d", &s);
	FA = (s/4.0)+40;
	CE = (FA/1.8) - (32/1.8);
	
	if (s>=0)
	printf("\nLa temperatura en Celcius corresponde a %fºC\n", CE);
		
}

