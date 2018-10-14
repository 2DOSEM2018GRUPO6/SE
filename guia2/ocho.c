#include <stdio.h>
#include <string.h>

void deco(char trama[]);
//void data(char trama[]);
//char direccion[8];

int main()
{
    char trama[25];
    printf("Escriba una cadena de caracteres: ");
    scanf("%s",trama);
    deco(trama);
    //data(trama);
    return 0;
}

void deco(char trama[])
{
    int a = 0;
    char direccion[8];
    char data[3];
    char sen1[8]="40F39550";
	//char sen2[]="40F39550";
    for(int i = 11; i < 19 ; i++)				
	{											
        direccion[a] = trama[i];
        a++;
	}
	printf(" address: %s \n", direccion);
	
	if (direccion == sen1)
    {
		printf("temperature: ");
		for(int i = 19; i < 21 ; i++)				
		{											
			printf("%s", data);
		}
	}
    else
    {
		printf ("humedity: ");
		for(int i = 19; i < 22 ; i++)				
		{											
			
		}
	}

}
/*void data(char trama[])
{
    char data[3];
    char sen1[]="40F39550";
	//char sen2[]="40F39550";
    if (direccion == sen1)
    {
		printf ("temperature: ");
		for(int i = 19; i < 21 ; i++)				
		{											
			printf("%s", data);
		}
	}
    else
    {
		printf ("humedity: ");
		for(int i = 19; i < 22 ; i++)				
		{											
			
		}
	}
    
}
*/
