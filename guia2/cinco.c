#include <stdio.h>
#include <stdlib.h>
#include <math.h>

const int MAX = 100;
void Lectura(int *, int);
float Media(int *, int);
float Varianza(int *, int, float);
float Desviacion(float);
void Frecuencia(int *, int, int *);
int Moda(int *, int);

void main(void)
{
	int TAM, MOD, ALU[MAX], FRE[11] = {0};
	float MED, VAR, DES;
	do
	{
		printf("¿Cantidad de calificaciones a ingresar?: ");
		scanf("%d", &TAM);
	}
	while (TAM > MAX || TAM < 1);
	Lectura(ALU, TAM);
	MED = Media(ALU, TAM);
	VAR = Varianza(ALU, TAM, MED);
	DES = Desviacion(VAR);
	Frecuencia(ALU, TAM, FRE);
	MOD = Moda(FRE, 11);
	
	printf("\na) Media: %.1f", MED);
	printf("\nb) Varianza: %.1f", VAR);
	printf("\nc) Desviación: %.1f", DES);
	printf("\nd) Moda: %d\n", MOD);
}
void Lectura(int A[], int T) 
{
	int i;
	for (i=0 ; i<T ; i++)
	{
		printf("Ingrese calificación Nº%d: ", i+1);
		scanf("%d", &A[i]);
	}
}
float Media(int A[], int T) 
{
	int i;
	float SUM = 0.0;
	for (i=0 ; i<T ; i++)
	{
		SUM += A[i];
	}
	return (SUM/T);
}
float Varianza(int A[], int T, float M) 
{
	int i;
	float SUM = 0.0;
	for (i=0 ; i<T ; i++)
	{
		SUM += pow ((A[i] - M), 2);
	}
	return (SUM/T);
}
float Desviacion(float V) 
{
	return (sqrt(V));
}
void Frecuencia(int A[], int P, int B[]) 
{
	int i;
	for (i=0 ; i<P ; i++)
	{
		B[A[i]]++;
	}
}
int Moda(int A[], int T) 
{
	int i, MOD = 0, VAL = A[0];
	for (i=1 ; i<T ; i++)
	{
		if (MOD < A[i])
		{
			MOD = i;
			VAL = A[i];
		}
	}
	return (MOD);
}
