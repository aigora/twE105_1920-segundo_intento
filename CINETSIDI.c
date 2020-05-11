#include <stdio.h>
#include <stdlib.h> 	/* system */
#include <string.h>		/* gets, strcmp */
/*#include <conio.h>*/		/* getch */
#include <locale.h>		/* permite poner caracteres de otros lenguajes como tíldes o 'ñ' */

#define USUARIO "Alumnos"		/* usuario a introducir */
#define CLAVE "Etsidi1"			/* clave a introducir */

#define LONGITUD 20		/* longitud de las cadenas */




int iniciosesion();			/* función de inicio de sesión */

void introducepelis();		/* función introducir datos */

void limpiar_pantalla();	/* Función que limpia la pantalla */

void compraentradas(); 	/*funcion de comprar entradas*/

void devolverentradas();	/*funcion de devoluciones*/

void cartelera(char cartelera[]); /*cartelera*/


int main()
{
	int ingresa;
	int op;
	
	
	ingresa = iniciosesion();
	
	
	
	
	if(ingresa == 1)								/* si la función devuelve un 1, puedes continuar el programa */
	{
		printf("\n\n\tBienvenido al Sistema\n");
	}
	
	else											/* si la función devuelve otro número, sales del programa */
	{
		printf("\n\tHa sobrepasado el numero maximo de intentos permitidos\n");
		return 1;
	}
	
	
	
	introducepelis();
	
	
	
	
	
	do
	{
	printf("\n\n\tQue operacion desea realizar?\n");
	printf(" 1.COMPRA DE ENTRADAS\n 2.CANCELACION DE ENTRADAS \n");
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
	int		intento = 0;			/* registra el número de intentos */
	int		ingresa = 0;			/* registra si la los credenciales son correctos */
		
	do
	{
		limpiar_pantalla();							/* limpia la pantalla en caso de tener que repetir el bucle */
		printf("\n\t\t\tINICIO DE SESION\n");	
		printf("\t\t\t----------------\n");
		printf("\n\tUSUARIO (%s): ", USUARIO);				/* pregunta usuario */
		gets(usuario);								/* almacena usuario */
		printf("\n\tCONTRASENA (%s): ", CLAVE);					/* pregunta clave */
		gets(clave);
		
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




void introducepelis()
{
	char	peli [LONGITUD + 1];
	int		sala;
	FILE *f;
	
	printf("\n\nIntroduce el nombre de la pelicula: ");
	gets(peli);
	
	printf("\n\nIntroduce el numero de sala: ");
	scanf("%i", &sala);
	
	f=fopen("cartelera.txt","w");
	fprintf(f, "%s\t %d\n", peli, sala);
	fclose(f);
}


void limpiar_pantalla()
{
  #ifdef _WIN32
    system("cls");
  #else
    system("clear");
  #endif
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

