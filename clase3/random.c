#include <stdio.h>
#include <time.h>
#include <stdlib.h>
int * getRandom()
{
	static int r[30];
	int i, a, b, c, d;
	
	srand( (unsigned)time( NULL) );
	a=0;	
	b = r[0];
	for(i=0; i<30; i++)
	{
		r[i]=rand();
		printf("r[%d]=%d\n", i, r[i]);
		
		
		if (r[i] > a)			// Calculo maximo
			{ 					
				a = r[i];
				c = i;
			}
		
		if (r[0] > r[i])		// Calculo minimo
			{ 					
				b = r[i]; 
				d = i;
			}		
	}
		      		
	printf ("El valor mayor es: r[%d]= %d\n", c,a);
	printf ("El valor menor es: r[%d]= %d\n", d,b);
	return r;
}


int main() 
{
	
	int *p;
	p = getRandom();
	return 0;

}
