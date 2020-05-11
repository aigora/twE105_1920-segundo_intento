#include <stdio.h>
#include <stdlib.h> 			/* system */
#include <string.h>				/* gets, strcmp */
#include <locale.h>				/* permite poner caracteres de otros lenguajes como tíldes o 'ñ' */

#define USUARIO "a"		/* usuario a introducir */
#define CLAVE "b"			/* clave a introducir */

#define N 20					/* longitud de las cadenas */
#define NPeliculas 3			/* Número de películas o salas */




typedef struct
{
	int 	sala;
	char 	peliula[N];
	char 	hora[N];
	
}cartelera;

cartelera cart[NPeliculas];


int iniciosesion();			/* función de inicio de sesión */

void introducepelis();		/* función introducir datos */

void limpiar_pantalla();	/* Función que limpia la pantalla */

void titulo();				/* Imprime Titulo */


int main()
{
	int ingresa;
	
	
	
	ingresa = iniciosesion();
	
	
	
	
	if(ingresa == 1)								/* si la función devuelve un 1, puedes continuar el programa */
	{
		printf("\n\n\tBienvenido al Sistema\n");
	}
	
	else											/* si la función devuelve otro número, sales del programa (has fallado más de 3 veces) */
	{
		printf("\n\tHa sobrepasado el numero maximo de intentos permitidos\n");
		return 1;
	}
	
	
	
	introducepelis();
	
	
	
	
	
	
	return 0;
}






int iniciosesion()
{
	char 	usuario	[N];			/* cadena que almacena el usuario introducido */
	char	clave	[N];			/* cadena que almacena la clave introducida */
	int		intento = 0;			/* registra el número de intentos */
	int		ingresa = 0;			/* registra si la los credenciales son correctos */
		
	do
	{
		limpiar_pantalla();							/* limpia la pantalla en caso de tener que repetir el bucle */
		titulo();									/* escribe el título */
		
		printf("\n\tUSUARIO (%s): ", USUARIO);		/* pregunta usuario */
		fflush(stdin);
		gets(usuario);								/* almacena usuario */
		
		printf("\n\tCONTRASENA (%s): ", CLAVE);		/* pregunta clave */
		fflush(stdin);
		gets(clave);
		
		/* printf("\nClave leida: %s\n", clave); */ /* descomentar para imprimir el valor de clave y ver si el programa registra bien la clave */
		
		if(strcmp(usuario, USUARIO) == 0 && strcmp(clave, CLAVE) == 0)	/* compara con la función strcmp si las cadenas son iguales */
		{
			ingresa = 1;												/* si esto se cumple, igresa vale 1 */
		}
		
		else															/* si las cadenas son distintas se ejecuta el else */
		{
			printf("\n\n\tUsuario y/o clave son incorrectos\n");
			intento++;													/* ejecutar el else suma uno a la variable intento */
			getchar();													/* hace que el programa se pare hasta presionar una tecla */
		}
		
	}while( intento < 3 && ingresa == 0 );								/* hace que el programa se repita hasta q falles 3 veces o introduzcas bien los datos */
	
	if(ingresa == 1)													/* si se sale del bucle mediante ingresa == 1, se ejecuta este if y la función devuelve un 1*/
		return 1;
	
	
	return 0; 		/* si se sale del bucle mediante intento < 3, se ejecuta el else y la función devuelve un 0*/
}




void introducepelis()
{
	int 	i;						
	int 	correcto;					/* variable aux para confirmar los datos */
	
	
	do
	{
		
		getchar();						/* pausa el programa hasta que recibe un caracter */
		limpiar_pantalla();				/* limpia la pantalla */
		titulo();						/* muestra el título */
		
		printf("\n\n\tIntroduce los datos de las 3 salas");
	
		for(i = 0; i < NPeliculas; i++)									/* bucle que hace que el empleado introduzca los datos */
		{
			cart[i].sala = 1 + i;										/* se le proporciona a la variable de tipo estructura el número de sala */
			
			printf("\n\n\n\tSala %i: ", cart[i].sala);					/* se muestra en pantalla */
			printf("\n\t-------");
			
			printf("\n\n\tIntroduce el nombre de la pelicula: ");		/* se le proporciona a la variable de tipo estructura el nombre de la película */
			fflush(stdin);												/* limpia el buffer */
			gets(cart[i].peliula);										/* almacena los caracteres introducidos */
			
			printf("\n\n\tIntroduce la hora: ");						/* se le proporciona a la variable de tipo estructura la hora de la película */
			fflush(stdin);												/* limpia el buffer */
			gets(cart[i].hora);											/* almacena los caracteres introducidos */
		}
		
		getchar();						/* pausa el programa hasta que recibe un caracter */
		limpiar_pantalla();				/* limpia la pantalla */
		titulo();						/* muestra el título */
		
		for(i = 0; i < NPeliculas; i++)									/* bucle que imprime la información recopilada */
		{
			printf("\n\n\n\tSala %i: ", cart[i].sala);
			printf("\n\t-------");
			
			printf("\n\n\tPelicula: %s", cart[i].peliula);
			
			printf("\n\n\tHora: %s", cart[i].hora);
		}
		
		printf("\n\n\n\n\tSon estos datos correctos?");					/* el programa pregunta si los datos son correctos */
		printf("\n\t1.-Si");
		printf("\n\t2.-No\n\t");
		scanf("%i", &correcto);
		
	}while(correcto==2);												/* si son correctos, el programa avanza, si no lo son se repite el do while */
}


void limpiar_pantalla()			/*función que limpia la pantalla */
{
  #ifdef _WIN32					/* si estas en windows usa esto */
    system("cls");
  #else							/* si estas en otro usa esto */
    system("clear");
  #endif
}


void titulo()
{
	printf("\n\t\t\tINICIO DE SESION\n");	
	printf("\t\t\t----------------\n");
}
