#include <stdio.h>
#include <string.h>

void comparador(char trama[]);

int main()
{
    char trama[30];
    printf("Introduzca simulación de puerta RX: ");
    scanf("%s",trama);
    comparador(trama);
    return 0;
}

void comparador(char trama[])
{
    char sen1[]="7EB3A50110140F395502560";
	if (trama [17] == sen1[17])
    {
		printf("address: 40F39550\n");
		printf("temperature: 25\n");
	}
    else
    {
		printf("address: 40F39577\n");
		printf ("humedity: 301\n");				
	}

}
