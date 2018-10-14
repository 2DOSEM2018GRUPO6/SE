#include <stdio.h>
#include <string.h>

int contar(char cad[],char car);

int main()
{
    char cad[50];
    char car;
    int res;
    printf("Escriba una cadena de caracteres: ");
    scanf("%s", cad);
    printf("Letra que desea contar: ");
    scanf("%s", &car);
    res=contar(cad,car);						//Llama función contar
    printf("Se repite: %i veces\n", res);
    return 0;
}

int contar(char cad[], char car)
{
    int num = 0;
    for(int i = 0; i < 50 ; i++)				//Se recorre el string (cad) y el "if" registra en una
	{											//variable cada vez que se repite el caracter "car"
        if (cad[i+1] == car) 					//dentro del string (cad).
			{
				num++;
			}
	}
    return num;
}
