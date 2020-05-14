#include <stdio.h>
#include <stdlib.h> 			/* system */
#include <string.h>				/* gets, strcmp */
#include <locale.h>				/* permite poner caracteres de otros lenguajes como tíldes o 'ñ' */

#define USUARIO "a"				/* usuario a introducir */
#define CLAVE "b"				/* clave a introducir */

#define N 					20			/* longitud de las cadenas */
#define NPeliculas 			3			/* Número de películas o salas */
#define FSala 				6			/* Altura y longitud de asientos en una sala */
#define CSala				10
#define Precio 				9.89				
#define DFamiliaNumerosa 	0.15
#define DEstudiante 		0.10
#define DJubilado 			0.13




typedef struct
{
	int 	sala;
	char 	peliula[N];
	char 	hora[N];
	char	asientos[FSala][CSala];
	int 	asientoslibres;
	
}cartelera;



int iniciosesion();							/* función de inicio de sesión */

void introducepelis(cartelera cart[]);		/* función introducir datos */

void llenamatrices(cartelera cart[]);

void menu(cartelera cart[]);

void compraentradas(cartelera cart[]);

void reservarasientos(int elige, cartelera cart[]);

void precio(int numentradas);

void devuelventradas(cartelera cart[]);

void cancelarasientos(int elige, cartelera cart[]);

void precio(int numentradas);

void preciodev(numentradas);

void dibujarsala(int elige, cartelera cart[]);

void limpiar_pantalla();					/* Función que limpia la pantalla */

void titulo();								/* Imprime Titulo */






int main()
{
	cartelera cart[NPeliculas];
	
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
	
	
	
	introducepelis(cart);
	
	
	llenamatrices(cart);
	
	
	menu(cart);
	
	
	
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





void introducepelis(cartelera cart[])
{
	int 	i;						
	int 	correcto;					/* variable aux para confirmar los datos */
	
	
	do
	{
		printf("\n\n\t\t--Presiona enter para continuar--");
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
		
		limpiar_pantalla();				/* limpia la pantalla */
		titulo();						/* muestra el título */
		
		for(i = 0; i < NPeliculas; i++)									/* bucle que imprime la información recopilada */
		{
			printf("\n\n\n\tSala %i: ", cart[i].sala);
			printf("\n\t-------");
			
			printf("\n\n\tPelicula: %s", cart[i].peliula);
			
			printf("\n\n\tHora: %s", cart[i].hora);
		}
		
		
		do
		{
			printf("\n\n\n\n\tSon estos datos correctos?");					/* el programa pregunta si los datos son correctos */
			printf("\n\t1.-Si");
			printf("\n\t2.-No\n\t");
			fflush(stdin);
			scanf("%i", &correcto);
		}while(correcto != 1 && correcto != 2);
		
		
	}while(correcto==2);												/* si son correctos, el programa avanza, si no lo son se repite el do while */
}





void llenamatrices(cartelera cart[])
{
	int i;
	int j;
	int k;
	
	for( i = 0; i < NPeliculas; i++)
	{
		for(j = 0; j < FSala; j++)
		{
			for(k = 0; k < CSala; k++)
			{
				cart[i].asientos[j][k] = '0';
			}
		}
		
		cart[i].asientoslibres = FSala * CSala;
	}
}




void menu(cartelera cart[])
{
	int elige;
	
	do
	{
		printf("\n\n\t\t--Presiona enter para continuar--");
		getchar();						/* pausa el programa hasta que recibe un caracter */
		limpiar_pantalla();				/* limpia la pantalla */
		titulo();						/* muestra el título */
		
		do
		{
			printf("\n\n\tPregunte al cliente que desea hacer:");
			printf("\n\t1.-Comprar Entradas");
			printf("\n\t2.-Devolver Entradas");
			printf("\n\n\t3.-Cerrar el programa\n\t");
			fflush(stdin);
			scanf("%i", &elige);
			
		}while(elige != 1 && elige != 2 && elige != 3);
		
		
		switch(elige)
		{
			case 1:
				compraentradas(cart);
				getchar();
				break;
			
			case 2:
				devuelventradas(cart);
				getchar();
				break;
		}
		
	}while(elige != 3);
	
}




void compraentradas(cartelera cart[])
{
	int elige;
	int i;
	
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
	
	
	
	do
	{
		printf("\n\n\n\tPregunte al cliente que pelicula desea ver:");
		for(i = 0; i < NPeliculas; i++)
		{
			printf("\n\t%i.-Sala %i", 1 + i, 1 + i);
		}
		printf("\n\n\t4.-Cancelar\n\t");
		fflush(stdin);
		scanf("%i", &elige);
		
	}while(elige != 1 && elige != 2 && elige != 3 && elige != 4);
	
	
	if(elige != 4)
	{
		reservarasientos(elige, cart);
	}
}





void reservarasientos(int elige, cartelera cart[])
{
	int numentradas;
	int columna;
	int fila;
	int aux;
	
	
	
	dibujarsala(elige, cart);
	
	
	do
		{
			printf("\n\n\tPregunte al cliente cuantas entradas desea: ");
			printf("\n\tNumero de entradas: ");
			fflush(stdin);
			scanf("%i", &numentradas);
			
		}while(numentradas <= 0 && numentradas > cart[elige -1].asientoslibres);
	
	
	for(aux = 0; aux < numentradas; aux++)
	{
		
		dibujarsala(elige, cart);
		
		
		printf("\n\n\tPregunte al cliente que entradas desea:");
		printf("\n\t(Instrucciones: Introduce 2 numeros siendo el asiento de arriba a la derecha Columna 1 y Fila 1)");
		
		do
		{
			printf("\n\n\tColumna: ");
			fflush(stdin);
			scanf("%i", &columna);
			
		}while(columna <= 0 && columna >  CSala);
		
		
		do
		{
			printf("\n\n\tFila: ");
			fflush(stdin);
			scanf("%i", &fila);
			
		}while(columna <= 0 && columna >  FSala);
		
		cart[elige - 1].asientos[fila - 1][columna - 1] = 'X';
	}
	
	limpiar_pantalla();							/* limpia la pantalla en caso de tener que repetir el bucle */
	titulo();									/* escribe el título */
	dibujarsala(elige, cart);
	fflush(stdin);
	printf("\n\n\n\n\t\t--Presiona enter para continuar--");
	getchar();									/* pausa el programa hasta que recibe un caracter */
	
	precio(numentradas);

}

void devuelventradas(cartelera cart[])
{
	int elige;
	int i;
	
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
	
	
	
	do
	{
		printf("\n\n\n\tPregunte al cliente de que película son las entradas que desea devolver:");
		for(i = 0; i < NPeliculas; i++)
		{
			printf("\n\t%i.-Sala %i", 1 + i, 1 + i);
		}
		printf("\n\n\t4.-Cancelar\n\t");
		fflush(stdin);
		scanf("%i", &elige);
		
	}while(elige != 1 && elige != 2 && elige != 3 && elige != 4);
	
	
	if(elige != 4)
	{
		cancelarasientos(elige, cart);
	}
}



void reservarasientos(int elige, cartelera cart[])
{
	int numentradas;
	int columna;
	int fila;
	int aux;
	
	
	
	dibujarsala(elige, cart);
	
	
	do
		{
			printf("\n\n\tPregunte al cliente cuantas entradas desea devolver: ");
			printf("\n\tNumero de entradas: ");
			fflush(stdin);
			scanf("%i", &numentradas);
		}while(numentradas <= 0 && numentradas > ((FSala*CSala)-cart[elige -1].asientoslibres));
	
	
	for(aux = 0; aux < numentradas; aux++)
	{
		
		dibujarsala(elige, cart);
		
		
		printf("\n\n\tPregunte al cliente que entradas desea devolver:");
		printf("\n\t(Instrucciones: Introduce 2 numeros siendo el asiento de arriba a la derecha Columna 1 y Fila 1)");
		
		do
		{
			printf("\n\n\tColumna: ");
			fflush(stdin);
			scanf("%i", &columna);
			
		}while(columna <= 0 && columna >  CSala);
		
		
		do
		{
			printf("\n\n\tFila: ");
			fflush(stdin);
			scanf("%i", &fila);
			
		}while(columna <= 0 && columna >  FSala);
		
		cart[elige - 1].asientos[fila - 1][columna - 1] = '0';
	}
	
	limpiar_pantalla();							/* limpia la pantalla en caso de tener que repetir el bucle */
	titulo();									/* escribe el título */
	dibujarsala(elige, cart);
	fflush(stdin);
	printf("\n\n\n\n\t\t--Presiona enter para continuar--");
	getchar();									/* pausa el programa hasta que recibe un caracter */
	
	preciodev(numentradas);

}



void precio(numentradas)
{
	float total;
	int elige;
	
	total = 0;
	
	total = numentradas * Precio;
	
	limpiar_pantalla();				/* limpia la pantalla */
	titulo();						/* muestra el título */
	
	do
	{
		printf("\n\n\tPregunte al cliente si posee algun descuento:");
		printf("\n\t1.-Estudiante");
		printf("\n\t2.-Familia Numerosa");
		printf("\n\t3.-Jubilado");
		printf("\n\t4.-Ninguno\n\t");
		fflush(stdin);
		scanf("%i", &elige);
		
	}while(elige != 1 && elige != 2 && elige != 3 && elige != 4);
	
	switch(elige)
	{
		case 1:
			
			break;
			
		case 2:
			
			break;
			
		case 3:
			
			break;
			
		case 4:
			
			break;
	}
	
	
	
}



void dibujarsala(int elige, cartelera cart[])
{
	int i;
	int j;
	
	limpiar_pantalla();				/* limpia la pantalla */
	titulo();						/* muestra el título */
	
	
	printf("\n\n\n\tSala %i: ", cart[elige - 1].sala);
	printf("\n\t-------\n");
	
	for(i = 0; i < FSala; i++)
	{


void preciodev(numentradas)
{
	float total;
	int elige;
	
	total = 0;
	
	total = numentradas * Precio;
	
	limpiar_pantalla();				/* limpia la pantalla */
	titulo();						/* muestra el título */
	
	do
	{
		printf("\n\n\tPregunte al cliente si pago las entradas con algun descuento:");
		printf("\n\t1.-Estudiante");
		printf("\n\t2.-Familia Numerosa");
		printf("\n\t3.-Jubilado");
		printf("\n\t4.-Ninguno\n\t");
		fflush(stdin);
		scanf("%i", &elige);
		
	}while(elige != 1 && elige != 2 && elige != 3 && elige != 4);
	
	switch(elige)
	{
		case 1:
			
			break;
			
		case 2:
			
			break;
			
		case 3:
			
			break;
			
		case 4:
			
			break;
	}
	
	
	
}


void dibujarsala(int elige, cartelera cart[])
{
	int i;
	int j;
	
	limpiar_pantalla();				/* limpia la pantalla */
	titulo();						/* muestra el título */
	
	
	printf("\n\n\n\tSala %i: ", cart[elige - 1].sala);
	printf("\n\t-------\n");
	
	for(i = 0; i < FSala; i++)
	{
		printf("\n\t\t\t");
		
		for(j = 0; j < CSala; j++)
		{
			printf("%c", cart[elige -1].asientos[i][j]);
		}
	}
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
	printf("\n\t\t\tCINE ETSIDI");	
	printf("\n\t\t\t-----------\n");
}
