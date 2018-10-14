#include <stdio.h>

void main(void)
{
	int CLA, CAT, ANT, RES;
	printf("\nClave del trabajador: ");
	scanf("%d", &CLA);
	printf("Categoría del trabajador: ");
	scanf("%d", &CAT);
	printf("Antiguedad del trabajador: ");
	scanf("%d", &ANT);
	
	switch(CAT)
		{
			case 3: if (ANT >= 5)
						RES = 1;
					else 	
						RES = 0;
					break;
						
			case 4: if (ANT >= 5)
						RES = 1;
					else 	
						RES = 0;
					break;
						
			case 2: if (ANT >= 7)
						RES = 1;
					else 	
						RES = 0;
					break;
						
			default: RES = 0;
					break;			
		}
	if (RES == 1)
		printf("\nEl trabajador Clave %d reúne las condiciones.\n", CLA);
	else 
		printf("\nEl trabajador Clave %d no reúne las condiciones.\n", CLA);
}

