# include <stdio.h>
# include <ctype.h>						//Permite utilizar isalpha.

void deco(char *);

int main()
{
	char cad[50];
	printf("Escriba una cadena de caracteres: ");
	gets(cad);   						//Obtiene la cadena escrita.
	deco(cad);							//Llama a la funcion para decodificar la cadena.
}

void deco(char *cadena)					
{
	int i = 0, j, k;
	while (cadena[i] != '\0')			//Lo hara hasta que sea el final de la cadena.
	{
		if (isalpha (cadena[i])) 		//Entrará al "if" si la el caracter es una letra.
		{
			k = cadena[i-1] - 48;		//Se obtiene el ascii del numero antecesor al caracter. 
			for (j = 0; j < k; j++)		//Entrara al "for" k veces, imprimiendo
			putchar(cadena[i]);			//la letra correspondiente.
		}
	i++;
	}
	printf("\n");
}
