#include <stdio.h>
#include <string.h>

int main(){
	char original[] = "hola me llamo Cristian.";
	char parte[] = "me ";
	char nueva[ 21 ];
	int posicion = strlen( original ) - strlen( strstr( original, parte ) );
 
	// copiar la primera parte
	for( int a = 0; a < posicion; a++ )
		nueva[ a ] = original[ a ];
 
	// copiar la segunda parte
	for( int a = posicion; a < strlen( original ); a++ )
		nueva[ a ] = original[ a+3 ]; // 3 es el tamaño de la parte
 
	nueva[ 20 ] = '\0';
	printf( "%s", nueva );
	return 0;
}

