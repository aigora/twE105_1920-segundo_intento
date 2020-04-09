#include <stdio.h>
#include <stdlib.h> 	/* system */
#include <string.h>		/* gets, strcmp */
#include <conio.h>		/* getch */
#include <locale.h>		/* permite poner caracteres de otros lenguajes como tíldes o 'ñ' */

#define USUARIO "Alumnos"		/* usuario a introducir */
#define CLAVE "Etsidi1"			/* clave a introducir */

#define LONGITUD 20		/* longitud de las cadenas */




int iniciosesion();		/* función de inicio de sesión */

void compraentradas(); 	/*funcion de comprar entradas*/

void devolverentradas();	/*funcion de devoluciones*/

void cartelera(char cartelera[]); /*cartelera*/


int main()
{
	int ingresa;
	int op;
	
	
	setlocale(LC_ALL, "spanish");		/* permite poner caracteres del español */
	
	
	ingresa = iniciosesion();
	
	
	
	
	if(ingresa == 1)								/* si la función devuelve un 1, puedes continuar el programa */
	{
		printf("\n\n\tBienvenido al Sistema\n");
	}
	
	else											/* si la función devuelve otro número, sales del programa */
	{
		printf("\n\tHa sobrepasado el número máximo de intentos permitidos\n");
		return 1;
	}
	do
	{
	printf("?Qu? operaci?n desea realizar?\n");
	printf(" 1.COMPRA DE ENTRADAS\n 2.CANCELACI?N DE ENTRADAS \n");
	scanf("%i",&op);
	}
	while(op!=1 && op!=2);
	switch(op)
	{
		case 1://comprar entradas
		compraentradas();
		break;
		case 2://cancelar entradas
		devolverentradas();
		break;
	}
	return 0;
}






int iniciosesion()
{
	char 	usuario	[LONGITUD + 1];	/* cadena que almacena el usuario introducido */
	char	clave	[LONGITUD + 1];	/* cadena que almacena la clave introducida */
	char 	caracter;				/* variable auxiliar para que el programa imprima '*' */
	int		intento = 0;			/* registra el número de intentos */
	int		ingresa = 0;			/* registra si la los credenciales son correctos */
	int		i 		= 0;			/* variable contador para desplazarnos por clave[] y hacer que el programa imprima '*' */
		
	do
	{
		i = 0;
		system("cls");							/* limpia la pantalla en caso de tener que repetir el bucle */
		printf("\n\t\t\tINICIO DE SESIÓN\n");	
		printf("\t\t\t----------------\n");
		printf("\n\tUSUARIO (%s): ", USUARIO);				/* pregunta usuario */
		gets(usuario);							/* almacena usuario */
		printf("\n\tCONTRASEÑA (%s): ", CLAVE);					/* pregunta clave */
		while( ( caracter = getch() ) )			/* almacena clave mostrando '*' en lugar de la contraseña introducida */
		{
			if(caracter == 13)			/* tecla "enter" en ascii vale 13. Equivale a decir if(presionas tecla enter) */
			{
				clave[i] = '\0';		/* en el último caracter almacena el NULL para indicar que la cadena ha acabado ahí */
				break;					/* sale del bucle while */
			}
			
			else if(caracter == 8)		/* tecla "retroceso" en ascii vale 8. Equivale a decir if(presionas tecla retroceso) */
			{
				if(i > 0)				/* hace que solo permita borrar lo que se ha escrito */
				{
					i--;				/* reduce el valor i al presionar el retroceso para retroceder una posición en clave */
					printf("\b \b");	/* elimina el último '*' impreso en pantalla */
				}
			}
			
			else							/* al presionar cualquier tecla que no sea "enter" se va a ejecutar la sentencia else */
			{
				if (i < LONGITUD)
				{
					printf("*");			/* se va a imprimir un '*' en lugar del caracter seleccionado */
					clave[i] = caracter;	/* se almacena el caracter en clave con ayuda de i */
					i++;					/* i aumenta un valor para que clave aumente una posición en el sigiuiente caracter */
				}
				
			}
		}
		
		/* printf("\nClave leida: %s\n", clave); */ /* descomentar para imprimir el valor de clave y ver si el programa registra bien la clave */
		
		if(strcmp(usuario, USUARIO) == 0 && strcmp(clave, CLAVE) == 0)	/* compara con la función strcmp si las cadenas son iguales */
		{
			ingresa = 1;												/* si esto se cumple, igresa vale 1 */
		}
		
		else														/* si las cadenas son distintas se ejecuta el else */
		{
			printf("\n\n\tUsuario y/o clave son incorrectos\n");
			intento++;												/* ejecutar el else suma uno a la variable intento */
			getchar();												/* hace que el programa se pare hasta presionar una tecla */
		}
		
	}while( intento < 3 && ingresa == 0 );		/* hace que el programa se repita hasta q falles 3 veces o introduzcas bien los datos */
	
	if(ingresa == 1)								/* si se sale del bucle mediante ingresa == 1, se ejecuta este if y la función devuelve un 1*/
		return 1;
	
	
	return 0; 		/* si se sale del bucle mediante intento < 3, se ejecuta el else y la función devuelve un 0*/
}
void compraentradas()
{
	int sala;
	char hora;
	do{
	cartelera("cartelera.txt");
	printf("\nindique la sala de la pelicula que desea ver (1, 2, 3)\n");//eleccion de la sala
	scanf("%i", &sala);		
	}
	while(sala!=1 && sala!=2 && sala!=3);
	do{
	printf("\nindique el horario (a, b, c)\n");//eleccion de la sala
	scanf("%c", &hora);}
	while(hora!='a' && hora!='b' && hora!='c');
}

void devolverentradas()
{
	int sala;
	char hora;
	do{
	cartelera("cartelera.txt");
	printf("\nindique la sala de la entrada que desea devolver (1, 2, 3)\n");//eleccion de la sala
	scanf("%i", &sala);
	}
	while(sala!=1 && sala!=2 && sala!=3);
	do{
	printf("\nindique el horario (a, b, c)\n");//eleccion de la sala
	scanf("%c", &hora);}
	while(hora!='a' && hora!='b' && hora!='c');
}

void cartelera(char cartelera[])//funcion para imprimir la cartelera
{
		FILE* archivo;
	char i;
	archivo=fopen(cartelera, "r");
	if (archivo!=NULL)
	{
		while(!feof(archivo))
		{
			fscanf(archivo,"%c", &i);
			printf("%c", i);
		}
			fclose(archivo);
	}
}

