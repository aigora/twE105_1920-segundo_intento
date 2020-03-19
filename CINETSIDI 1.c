#include <stdio.h>
#include <string.h>
double main()
{
	int op1;
	int op2;
	int num;
	int peli;//pelicula elegida
	do
	{
	printf(" \t\t  -----CINETSIDI-----\n");
	printf("¿Que desea hacer?:\n\t 1.INICIAR SESION\t 2.CREAR UNA CUENTA\n");
	scanf("%i", &op1);//decide si iniciar sesion o crear una cuenta
	}
	while(op1!=1&&op1!=2);
	char nombre[10];
	char contra[10];
	char contra1[10];
	char contra2[10];
	int i=0;
	switch (op1)
	{
		case 1://inicio de sesion
			printf("Nombre de usuario (menos de 10 caracteres):\n");
			scanf("%10s", nombre);
			printf("Contraseña (menos de 10 caracteres):\n");
			scanf("%10s", contra);
			break;
		case 2://crear una cuenta
			printf("Nombre de usuario (menos de 10 caracteres):\n");
			scanf("%10s", nombre);
			printf("Contraseña (menos de 10 caracteres):\n");
			scanf("%10s", contra1);
			printf(" Repite la contraseña:\n");
			scanf("%10s", contra2);
			while(strcmp(contra1,contra2)!=0)
			{
			printf("las contraseñas no coinciden, vuelva a introducirlas\n");
			printf("Contraseña (menos de 10 caracteres):\n");
			scanf("%10s", contra1);
			printf(" Repite la contraseña:\n");
			scanf("%10s", contra2);
			}
			for (i=0;i<10;i++)
			{
				contra[i]=contra1[i];
			}
		break;
	}
	char peli1[10]="SONIC", peli2[10]="PARASITO", peli3[10]="ONWARD";//peliculas en cartelera
	char np[10];//peli que se desea cambiar
	printf(" \t\t -----BIENVENIDO %s-----\n \t ¿que operacion desea realizar?\n", nombre);
	printf(" 1.COMPRA DE ENTRADAS\n 2.CANCELACION DE ENTRADAS\n 3.GESTION DE LAS PELICULAS \n");
	scanf("%i", &op2);
	int j=0;
	switch(op2)
	{
		case 1:
		printf("¿cunatas entradas desea comprar?\n");
		scanf("%i", &num);
		printf("seleccione la pelicula\n sala 1:%s\n sala 2:%s\n sala 3:%s\n", peli1, peli2, peli3);
		scanf("%i", &peli);
		break;
		case 2:
		printf("¿cunatas entradas desea devolver?\n");
		scanf("%i", &num);
		printf("seleccione la pelicula\n sala 1:%s\n sala 2:%s\n sala 3:%s\n", peli1, peli2, peli3);
		scanf("%i", &peli);
		break;
		case 3:
		printf("seleccione la pelicula que desea modificar\n sala 1:%s\n sala 2:%s\n sala 3:%s\n", peli1, peli2, peli3);
		scanf("%i", &peli);
		switch (peli)
		{
			case 1:
				printf("introduce la nueva pelicula\n");
				scanf("%s", np);
				for (j=0;j<10;j++)
			{
				peli1[j]=np[j];
			}
			break;
			case 2:
			printf("introduce la nueva pelicula\n");
				scanf("%s", np);
				for (j=0;j<10;j++)
			{
				peli2[j]=np[j];
			}
			break;
			case 3:
			printf("introduce la nueva pelicula\n");
				scanf("%s", np);
				for (j=0;j<10;j++)
			{
				peli3[j]=np[j];
			}
			break;
		}
	}
}
