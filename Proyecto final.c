#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

void iniciarTablero();
void mostrarTablero(int band); 
void leerCoordenadas(FILE *f);
void archivo(char nombre[],int tam, int edad, int ganada, int barcos);
void leer_dat(char nombre[],int tam, int *edad);

int tablero[10][10];

int main() 
{
	printf("\n");
	printf(".................................CARGANDO......................................");
	sleep(3);
	printf("\n");
	printf("\n");
	printf("__________          __    __  .__                  .__    .__          \n");
    printf("\\______   \\_____  _/  |__/  |_|  |    ____   ______|  |__ |__|______ \n");
    printf(" |    |  _/\\__  \\ \\   __\\   __\\  |  _/ __ \\ /  ___/|  |  \\|  |\\____ \\  \n");
    printf(" |    |   \\ / __ \\_|  |  |  | |  |__\\  ___/ \\___ \\ |      \\  ||  |_> >    \n");
    printf(" |______  /(______/|__|  |__| |____/ \\_____>______>|___|  /__||   __/          \n");
    printf("       _\\/ _     _   _   _   _   _     _   _   _   _    \\/    |__|            \n");
	printf("\n");
	printf("\n");
	sleep(1);
    printf("                                  _/|                           \n");
    printf("                                 _|:|                           \n");
    printf("                               _|:::|                           \n");
    printf("                         _ /|  |::::|                           \n");
    printf("                         |::|  |::::|                           \n");
    printf("                         |::|  |:::::)__                        \n");
    printf("                       /:|:::: |::::::::|                       \n");
    printf("                      :::|::::_|::::::::|                       \n");
    printf("                ____(:::::::::::::::::::|___ _______         __ \n");
    printf("               (::::::::::::::::::::::::|:::|::::::|  ______|::)\n");
    printf("     ___________\\:::::::::::::::::::::::::::|:::|___|:::::::::|\n");
    printf("     \\::::::::::::::::::::::::::::::::::::::::::::::::::::::::|\n");
    printf("      |:::::::::::::::::::::::::::::::::::::::::::::::::::::::| \n");
    printf("\n");
    printf ("\n\n");
	printf ("                        REGLAS DEL JUEGO:                          \n");
	printf ("1. ALGO....\n");
	printf("\n");
	printf ("2. ALGO............................................\n");
	printf ("\n");
	printf ("3. ALGO...............................................\n");
	printf ("\n");
	printf ("4. ALGO...,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,\n"); 
	printf ("\n");
	printf ("5. ALGO..............................................................\n");
	printf ("\n");
	printf ("6. ALGO......................................................................\n");
	printf("\n");
    printf("      / \\ / \\   / \\ / \\ / \\ / \\ / \\   / \\ / \\ / \\ / \\   \n");
    printf("     ( 1 | : ) ( S   T   A   R   T ) ( G   A   M   E )             \n");
    printf("      \\_/ \\_/   \\_/ \\_/ \\_/ \\_/ \\_/   \\_/ \\_/ \\_/ \\_/   \n");
    printf("\n");
	printf("\n");
	printf("\n");


	FILE *f;
	
	char nombre[10];
	int edad;

        leer_dat(nombre,10,&edad);
	if(edad <= 17){
	    printf("LO SIENTO NO PUEDES JUGAR, TIENES QUE SER MAYOR DE EDAD!!!!\n");
	    system("pause");
	    return 0;
		}
		
	iniciarTablero();
	mostrarTablero(0);
	
		int fi;
		int c;
		int i;
		for (i=1; i <=10; i++)
	{
		//lee fila y cumna ejemplo f[3] c[4]

			    printf("Dame la FILA donde crees que esta el barco : ");
				scanf("%d" ,&fi);

				printf("Dame la COLUMNA donde crees que esta el barco : ");
				scanf("%d",&c);	
				
				
	
		
	}
		

	leerCoordenadas(f);

	printf("\n");


	mostrarTablero(1);

	printf("\n");		
	system("pause");
	return 1;
}


void iniciarTablero()
{
	int i,j;
	
	for(i = 0; i < 10; i++)
	{
		for(j = 0; j < 10; j++)
		{
			tablero[i][j] = 0;	
		}
	}
}
void mostrarTablero(int band	)
{
	int i,j;
	
	printf("   ");										
	for(i = 0; i < 10; i++)
	printf("%d   ",i);
	printf("\n");
	for(i = 0; i < 10; i++)
	{
		printf("%d  ", i);
		for(j = 0; j < 10; j++)
		{
			
			if(band)
			{
				if(tablero[i][j] == 1)
				
				printf("%c   ", 254);
				else
				printf("%c   ", 120);
			}
				else printf("%c   ",120);	
		}
		
	printf("\n");
	}
}   
void leerCoordenadas(FILE *f)
{
	int num, i, line,col,j;
	char car;
	
	srand(time(NULL));
	num = 1 + rand()%(3-1);
	
	if(num == 1)
		f = fopen("coordenadas1.txt","r");
	if(num == 2)
		f = fopen("coordenadas2.txt","r");
	if(num == 3)
		f = fopen("coordenadas3.txt","r"); 
	
	if(f != NULL);
	
	{
		for(i = 0; i < 10; i++)
		{
			fscanf(f,"%d%c%d", &line, &car, &col);
		
				for(j = 0; j < 3; j++)
				{
					tablero[line ][col+j] = 1;
				}
		}		
	}
} 

void leer_dat(char nombre[],int tam, int *edad){
    do{
		printf("Escribe tu nombre(MAX 10 letras) : ");
        scanf("%[^\n]", nombre);
		fflush(stdin);
	}while((strlen(nombre)) > 10 );
        printf("cual es tu edad : ");
        scanf("%d",edad);
}

void archivo(char nombre[], int tam, int edad, int ganada, int barcos){
   /*la funcion recibe 4 parametros
   char nombre[]: es la cadena del nombre
   int edad: la edad
   int ganada: recibe un 1 o un 0, si el jugador gana guardara 1
               y si pierde guardara un 0
   int barcos: recibe el numero de barcos que logo hundir si perdio*/
   FILE * flujo;
   flujo = fopen("informacion.txt", "a");
   if(flujo == NULL){
      perror("Error al crear el archivo\n");
   } else {
      if(ganada==1){
        fprintf(flujo, "%s     %d     ganador",nombre, edad);
        fputc('\n', flujo);
      } else{
        fprintf(flujo, "%s     %d     perdedor  %d    barcos hundidos",nombre, edad, barcos);
        fputc('\n', flujo);
      }
      fflush(flujo);
      fclose(flujo);
      printf("DATOS GUARDADOS EXITOSAMENTE!!!!!\n\n");
   }
}
