#include <stdio.h>
#include <stdlib.h> 					/* system */
#include <string.h>						/* gets, strcmp */
#include <locale.h>						/* permite poner caracteres de otros lenguajes como tíldes o 'ñ' */

#define USUARIO 			"a"			/* usuario a introducir */
#define CLAVE 				"b"			/* clave a introducir */

#define N 					20			/* longitud de las cadenas */
#define NUM_PELICULAS 		3			/* Número de películas o salas */
#define FILA_SALA 			6			/* Altura y longitud de asientos en una sala */
#define COLUM_SALA			10
#define PRECIO 				9.89
#define D_FAMILIA_NUMEROSA 	0.15
#define D_ESTUDIANTE 		0.10
#define D_JUBILADO 			0.13

#define FICH_RECIBO			"recibo.txt"
#define FICH_ENTRADAS		"entradas.txt"






typedef struct
{
	int 	sala;
	char 	pelicula[N];
	char 	hora[N];
	char	asientos[FILA_SALA][COLUM_SALA];
	int 	asientoslibres;
	
}cartelera;



typedef struct
{
	int 	numasientos;
	int		fila[FILA_SALA];
	int		columna[COLUM_SALA];

}entradas;



int iniciosesion();							/* función de inicio de sesión */

void introducepelis(cartelera cart[]);		/* función introducir datos */

void llenamatrices(cartelera cart[]);

void menu(cartelera cart[], entradas *aux);

void compraentradas(cartelera cart[], entradas *aux);

void reservarasientos(int elige, cartelera cart[], entradas *aux);

void precio(int numentradas, cartelera cart[], int elige, entradas *aux);

void recibodecompra(cartelera cart[], float descuento, float totalsindescuento, float totalcondescuento, int elige, entradas *aux);

void dibujarsala(int elige, cartelera cart[]);

void limpiar_pantalla();					/* Función que limpia la pantalla */

void titulo();								/* Imprime Titulo */



/* El programa esta pensado para un trabajador de cine que almacenará los datos de cada sala de manera manual y atenderá a las peticiones del consumidor.
Toda la informacion refernete a las salas se almacenará en un vector de estructuras cuyas dimensiones pueden ser alteradas mediante un define.
Todo el programa es completamente modificable mediante los defines iniciales, desde el numero de películas/salas y las dimensiones de cada una hasta
el precio individual de cada entrada y el valor de sus descuentos.

Las funciones han sido utilizadas a lo largo de todo el programa con distintas utilidades.

Por último, el programa creará 2 ficheros que según avance el programa se irán ñadiendo nuevos datos y al reiniciar el programa se limpiaran simulando así el inicio de
una nueva jornada laboral. El fichero recibo actua a modo de ticket de compra almacenando toda la información de ese cliente, el número de entradas, el precio y su descuento.
El fichero entrada almacena la información de cada cliente así como la sala y hora de sus entradas, el número de asientos y su ubicación individual */


int main()
{
	cartelera cart[NUM_PELICULAS];
	
	entradas aux;
	
	int ingresa;
	
	FILE *f;
	
	
	
	
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
	
	
	
	
	f = fopen(FICH_ENTRADAS,"w");					/* Limpia el fichero del día anterior */
	
	fclose(f);
	
	f = fopen(FICH_RECIBO, "w");
	
	fclose(f);

	
	
	
	
	introducepelis(cart);
	
	
	llenamatrices(cart);
	
	
	menu(cart, &aux);
	
	
	
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
		
		printf("\n\n\tIntroduce los datos de las 3 salas\n\n");
		
	
		for(i = 0; i < NUM_PELICULAS; i++)								/* bucle que hace que el empleado introduzca los datos */
		{
			cart[i].sala = 1 + i;										/* se le proporciona a la variable de tipo estructura el número de sala */
			
			printf("\n\n\n\tSala %d: ", cart[i].sala);					/* se muestra en pantalla */
			printf("\n\t-------");
			
			printf("\n\n\tIntroduce el nombre de la pelicula: ");		/* se le proporciona a la variable de tipo estructura el nombre de la película */
			fflush(stdin);												/* limpia el buffer */
			gets(cart[i].pelicula);										/* almacena los caracteres introducidos */
			
			printf("\n\n\tIntroduce la hora: ");						/* se le proporciona a la variable de tipo estructura la hora de la película */
			fflush(stdin);												/* limpia el buffer */
			gets(cart[i].hora);											/* almacena los caracteres introducidos */
		}
		
		limpiar_pantalla();				/* limpia la pantalla */
		titulo();						/* muestra el título */
		
		for(i = 0; i < NUM_PELICULAS; i++)									/* bucle que imprime la información recopilada */
		{
			printf("\n\n\n\tSala %d: ", cart[i].sala);
			printf("\n\t-------");
			
			printf("\n\n\tPelicula: %s", cart[i].pelicula);
			
			printf("\n\n\tHora: %s", cart[i].hora);
		}
		
		
		do
		{
			printf("\n\n\n\n\tSon estos datos correctos?");					/* el programa pregunta si los datos son correctos */
			printf("\n\t1.-Si");
			printf("\n\t2.-No\n\t");
			fflush(stdin);
			scanf("%d", &correcto);
		}while(correcto != 1 && correcto != 2);
		
		
	}while(correcto==2);												/* si son correctos, el programa avanza, si no lo son se repite el do while */
}





void llenamatrices(cartelera cart[])
{
	int i;
	int j;
	int k;
	
	for( i = 0; i < NUM_PELICULAS; i++)
	{
		for(j = 0; j < FILA_SALA; j++)
		{
			for(k = 0; k < COLUM_SALA; k++)
			{
				cart[i].asientos[j][k] = '0';
			}
		}
		
		cart[i].asientoslibres = FILA_SALA * COLUM_SALA;
	}
}




void menu(cartelera cart[], entradas *aux)
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
			printf("\n\t2.-Cerrar el programa\n\t");
			fflush(stdin);
			scanf("%d", &elige);
			
		}while(elige != 1 && elige != 2);
		
		
		switch(elige)
		{
			case 1:
				compraentradas(cart, aux);
				getchar();
				break;
		}

	}while(elige != 2);
	
}




void compraentradas(cartelera cart[], entradas *aux)
{
	int elige;
	int i;
	
	getchar();						/* pausa el programa hasta que recibe un caracter */
	limpiar_pantalla();				/* limpia la pantalla */
	titulo();						/* muestra el título */
	
	
	
	
	for(i = 0; i < NUM_PELICULAS; i++)									/* bucle que imprime la información recopilada */
	{
		printf("\n\n\n\tSala %d: ", cart[i].sala);
		printf("\n\t-------");
		
		printf("\n\n\tPelicula: %s", cart[i].pelicula);
		
		printf("\n\n\tHora: %s", cart[i].hora);
	}
	
	
	
	do
	{
		printf("\n\n\n\tPregunte al cliente que pelicula desea ver:");
		for(i = 0; i < NUM_PELICULAS; i++)
		{
			printf("\n\t%d.-Sala %d", 1 + i, 1 + i);
		}
		printf("\n\n\t4.-Cancelar\n\t");
		fflush(stdin);
		scanf("%d", &elige);
		
	}while(elige != 1 && elige != 2 && elige != 3 && elige != 4);
	
	
	if(elige != 4)
	{
		reservarasientos(elige, cart, aux);
	}
}





void reservarasientos(int elige, cartelera cart[], entradas *aux)
{
	int numentradas;
	int columna;
	int fila;
	int i;
	
	
	
	dibujarsala(elige, cart);
	
	
	do
		{
			printf("\n\n\tPregunte al cliente cuantas entradas desea: ");
			printf("\n\tNumero de entradas: ");
			fflush(stdin);
			scanf("%d", &numentradas);
			aux->numasientos = numentradas;
			
		}while(numentradas <= 0 || numentradas > cart[elige -1].asientoslibres);
	
	
	for(i = 0; i < numentradas; i++)
	{
		
		dibujarsala(elige, cart);
		
		
		printf("\n\n\tPregunte al cliente que entradas desea:");
		printf("\n\t(Instrucciones: Introduce 2 numeros siendo el asiento de arriba a la derecha Columna 1 y Fila 1)");
		
		do
		{
			printf("\n\n\tColumna: ");
			fflush(stdin);
			scanf("%d", &columna);
			
			aux->columna[i] = columna;
			
		}while(columna <= 0 || columna >  COLUM_SALA);
		
		
		do
		{
			printf("\n\n\tFila: ");
			fflush(stdin);
			scanf("%d", &fila);
			
			aux->fila[i] = fila;
			
		}while(fila <= 0 || fila >  FILA_SALA);
		
		cart[elige - 1].asientos[fila - 1][columna - 1] = 'X';
	}
	
	limpiar_pantalla();							/* limpia la pantalla en caso de tener que repetir el bucle */
	titulo();									/* escribe el título */
	dibujarsala(elige, cart);
	fflush(stdin);
	printf("\n\n\n\n\t\t--Presiona enter para continuar--");
	getchar();									/* pausa el programa hasta que recibe un caracter */
	
	precio(numentradas, cart, elige, aux);

}





void precio(int numentradas, cartelera cart[], int elige, entradas *aux)
{
	float totalsindescuento;
	float totalcondescuento;
	float descuento;
	int escoge;
	
	
	totalsindescuento = 0;
	totalcondescuento = 0;
	descuento = 0;
	
	
	totalsindescuento = numentradas * PRECIO;
	
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
		scanf("%d", &escoge);
		
	}while(escoge != 1 && escoge != 2 && escoge != 3 && escoge != 4);
	
	switch(escoge)
	{
		case 1:
			descuento = totalsindescuento * D_ESTUDIANTE;
			break;
			
		case 2:
			descuento = totalsindescuento * D_FAMILIA_NUMEROSA;
			break;
			
		case 3:
			descuento = totalsindescuento * D_JUBILADO;
			break;
			
		case 4:
			descuento = 0;
			break;
	}
	
	totalcondescuento = totalsindescuento - descuento;
	
	
	
	recibodecompra(cart, descuento, totalsindescuento, totalcondescuento, elige, aux);
	
}




void recibodecompra(cartelera cart[], float descuento, float totalsindescuento, float totalcondescuento, int elige, entradas *aux)
{
	int i;

	
	FILE *f;
	
	
	
	f = fopen(FICH_ENTRADAS,"a");
	
	
	fprintf(f, 	"\n\t\t\tCINETSIDI"
				"\n\t\t\t---------\n\n\n");
	
	fprintf(f, 	"\tSala:\t\t\t\t\t\t%d\n\n"
				"\tHora:\t\t\t\t\t\t%s\n\n\n", cart[elige-1].sala, cart[elige-1].hora);
				
	fprintf(f, 	"\tAsientos\n"
				"\t--------\n\n");
	
	for(i = 0; i < aux->numasientos; i++)
	{
		fprintf(f,	"\tFila:\t\t\t\t\t\t%d\n"
					"\tAsiento:\t\t\t\t\t%d\n\n", aux->fila[i], aux->columna[i]);
	}
	fprintf(f,"\n\n");
	fclose(f);
	
	
	
	f = fopen(FICH_RECIBO,"a");
	
	
	fprintf(f, 	"\n\t\t\tCINETSIDI"
				"\n\t\t\t---------\n\n");
	
	fprintf(f, 	"\tDireccion: Ronda de Valencia, 3, 28012 Madrid\n"
				"\tTeléfono: 123 45 67 89\n\n\n");
				
	fprintf(f, 	"\t%d x Entrada\t\t\t\t%.2f\n", aux->numasientos, PRECIO);
	fprintf(f, 	"\t-----------------------------\n\n");
	fprintf(f, 	"\tTOTAL SIN DESCUENTO:\t\t\t%.2f\n", totalsindescuento);
	fprintf(f, 	"\tDESCUENTO:\t\t\t\t%.2f\n", descuento);
	fprintf(f, 	"\tTOTAL CON DESCUENTO:\t\t\t%.2f\n\n", totalcondescuento);
	fprintf(f, 	"\tGRACIAS POR SU VISITA ESPERAMOS VERLE PRONTO\n\n");
	
	fclose(f);
	
	printf(	"\n\n\t\t***IMPRIMIENDO ENTRADAS Y RECIBO***\n\n"
			"\t(Estos datos se han almacenado en los ficheros con sus respectivos nombres.\n"
			"\tCada vez que reinicie el programa estos ficheros se limpian automaticamente\n"
			"\tpara que la nueva informacion del dia pueda ser almacenada)");
	
}





void dibujarsala(int elige, cartelera cart[])
{
	int i;
	int j;
	
	limpiar_pantalla();				/* limpia la pantalla */
	titulo();						/* muestra el título */
	
	
	printf("\n\n\n\tSala %d: ", cart[elige - 1].sala);
	printf("\n\t-------\n");
	
	for(i = 0; i < FILA_SALA; i++)
	{
		printf("\n\t\t\t");
		
		for(j = 0; j < COLUM_SALA; j++)
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
	printf("\n\t\t\tCINETSIDI");	
	printf("\n\t\t\t---------\n");
}
