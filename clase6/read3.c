#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <wiringPiI2C.h>
#include <wiringPi.h>
#include <stdint.h>
//#include <math.h>


int main (){
	int res;
	int fd = wiringPiI2CSetup(0x08);	//Inicializa el sistema I2C con la direccion del dispositivo esclavo.
	int i;
	int datos[32000];
	for (i=0 ; i<32000 ; i++)			//Este for permite guardar los 32000 datos enviados desde arduino 
	{									//en un arreglo.
		res = wiringPiI2CRead(fd);		
		datos[i] = res;
		printf(" %d)\t", i+1);
		printf(" %d\n", res);
		delay(10);	
	} 
		
	printf("32000 datos guardados\n");
	printf("Creando archivo 'datos.txt' ...\n");
	FILE *fp = fopen("/home/pi/Desktop/SE/clase6/datos.txt","w");  //Se crea el archivo de datos.txt
	for (i=0 ; i<32000 ; i++)									//en el directorio deseado.
	{	
		fprintf(fp," %d)\t", i+1);
		fprintf(fp,"%d\r\n", datos[i]);
	}
	fclose(fp);
	printf("Listo!\n");

    return 0;
}
