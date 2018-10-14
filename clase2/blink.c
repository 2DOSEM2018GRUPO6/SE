#include <wiringPi.h>
#include <stdio.h>

int main(void)
{
	wiringPiSetup () ;
	pinMode (0,OUTPUT);
	for (int i=0; i<10; i++ )
	{
		digitalWrite (0, HIGH); 
		printf("on\n");
		delay(1000); 
		digitalWrite (0, LOW);
		printf("off\n");
		delay(1000); 	
	}
	return 0;
}

