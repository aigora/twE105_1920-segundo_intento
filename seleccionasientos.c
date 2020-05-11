#include <stdio.h>

void selecasiento();
int main()
{
	selecasiento();
	return 0;
}
void selecasiento()
{
	int i=0, j=0,k=0, h=0;
	int fila, asiento;
	int n;//numero de asientos
	int asientos[10][20];
	int vfila[10], vasiento[10];
	printf("numero de asientos:\n");
	scanf("%i", &n);
	for(i=0;i<10;i++)//creamos la matriz de los asientos con 0 por espacios vacios;
	{
		for (j=0; j<20; j++){
		asientos[i][j]=0;//asignamos 0 a espacios vacios
		printf("%i ", asientos[i][j]);
		}
		printf("\n");
	}
	for (k=0;k<n;k++)
{
	do
	{
	printf("seleccione el asiento %i\n", k+1);
	printf("fila (de arriba a abajo):\n");
	scanf("%i", &fila);
	vfila[k]=fila;
	printf("asiento (de izda a derecha):");
	scanf("%i", &asiento);
	vasiento[k]=asiento;
	}while(asiento>20||fila>10);
	asiento=asiento-1;//ajustamos el asiento y la fila a los correspondientes en la matriz
	fila=fila-1;
	asientos[fila][asiento]=1;}
	i=0;
	j=0;
	for(i=0;i<10;i++)//volvemos a imprimir la matriz con el asiento seleccionado cambiado
	{
		for (j=0; j<20; j++){
		printf("%i ", asientos[i][j]);
		}
		printf("\n");
	}
	for (h=0;h<n;h++){
	printf("%i\t", vfila[h]);}
	printf("\n");
	h=0;
	for(h=0;h<n;h++){
		printf("%i\t", vasiento[h]);
	}
}
