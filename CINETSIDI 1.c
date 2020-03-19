#include <stdio.h>
#include <string.h>
#include <locale.h>

double main()
{
	int op1;
	int op2;
	int num;
	int peli;//pelicula elegida
	
	setlocale(LC_ALL, "spanish");//poder escribir caracteres como la ñ y los acentos
	
	printf(" \t\t  -----CINETSIDI-----\n");
	do
	{
	
	printf("¿Qué desea hacer?:\n\t 1.INICIAR SESIÓN\t 2.CREAR UNA CUENTA\n");
	scanf("%i", &op1);//decide si iniciar sesion o crear una cuenta
	if (op1!=1&&op1!=2) //este bucle if es para decir al usuario que esta escribiendo mal el numero
	 {printf("Operación no valida.\n Escriba 1 ó 2 en función de si desea iniar sesión o crear una cuenta.\n");
	 }
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
			printf(" Repita la contraseña:\n");
			scanf("%10s", contra2);
			while(strcmp(contra1,contra2)!=0)
			{
			printf("Las contraseñas no coinciden, vuelva a introducirlas\n");
			printf("Contraseña (menos de 10 caracteres):\n");
			scanf("%10s", contra1);
			printf(" Repita la contraseña:\n");
			scanf("%10s", contra2);
			}
			for (i=0;i<10;i++)
			{
				contra[i]=contra1[i];
			}
		break;
	}
	char peli1[10]="SONIC", peli2[10]="PARÁSITO", peli3[10]="ONWARD";//peliculas en cartelera
	char np[10];//peli que se desea cambiar
	printf(" \t\t -----BIENVENIDO %s-----\n \t ¿Qué operación desea realizar?\n", nombre);
	printf(" 1.COMPRA DE ENTRADAS\n 2.CANCELACIóN DE ENTRADAS\n 3.GESTIóN DE LAS PELÍCULAS \n");
	scanf("%i", &op2);
	int j=0;
	switch(op2)
	{
		case 1:
		printf("¿Cuántas entradas desea comprar?\n");
		scanf("%i", &num);
		printf("Seleccione la película\n sala 1:%s\n sala 2:%s\n sala 3:%s\n", peli1, peli2, peli3);
		scanf("%i", &peli);
		break;
		case 2:
		printf("¿Cuántas entradas desea devolver?\n");
		scanf("%i", &num);
		printf("Seleccione la película\n sala 1:%s\n sala 2:%s\n sala 3:%s\n", peli1, peli2, peli3);
		scanf("%i", &peli);
		break;
		case 3:
		printf("Seleccione la película que desea modificar\n sala 1:%s\n sala 2:%s\n sala 3:%s\n", peli1, peli2, peli3);
		scanf("%i", &peli);
		switch (peli)
		{
			case 1:
				printf("Introduce la nueva pelIcula\n");
				scanf("%s", np);
				for (j=0;j<10;j++)
			{
				peli1[j]=np[j];
			}
			break;
			case 2:
			printf("Introduce la nueva película\n");
				scanf("%s", np);
				for (j=0;j<10;j++)
			{
				peli2[j]=np[j];
			}
			break;
			case 3:
			printf("Introduce la nueva película\n");
				scanf("%s", np);
				for (j=0;j<10;j++)
			{
				peli3[j]=np[j];
			}
			break;
		}
	}
}
