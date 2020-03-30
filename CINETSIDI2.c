#include <stdio.h>
#include <stdlib.h> /* system */
#include <string.h>		/* gets, strcmp */
#include <conio.h>		/* getch */

#define USUARIO "c"		/* usuario a introducir */
#define CLAVE "java"	/* clave a introducir */

#define LONGITUD 8		/* longitud de las cadenas */

int main()
{
	char 	usuario[LONGITUD + 1];	/* cadena que almacena el usuario introducido */
	char	clave[LONGITUD + 1];	/* cadena que almacena la clave introducida */
	int		intento = 0;			/* registra el número de intentos */
	int		ingresa = 0;			/* registra si la los credenciales son correctos */
	char 	caracter;				/* variable auxiliar para que el programa imprima '*' */
	int		i = 0;					/* variable contador para desplazarnos por clave[] y hacer que el programa imprima '*' */
		
	do
	{
		i = 0;
		system("cls");							/* limpia la pantalla en caso de tener que repetir el bucle */
		printf("\n\t\t\tINICIO DE SESION\n");	
		printf("\t\t\t----------------\n");
		printf("\n\tUSUARIO: ");				/* pregunta usuario */
		gets(usuario);							/* almacena usuario */
		printf("\n\tCLAVE: ");					/* pregunta clave */
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
	
	if(ingresa == 1)								/* si se sale del bucle mediante ingresa == 1, se ejecuta este if */
	{
		printf("\n\n\tBienvenido al Sistema\n");
	}
	
	else										/* si se sale del bucle mediante intento < 3, se ejecuta el else */
	{
		printf("\n\tHa sobrepasado el numero maximo de intentos permitidos\n");
	}
	
	return 0;
}


