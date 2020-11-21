#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

void iniciarTablero();
void mostrarTablero(int band); 
void mostrarTablero1();
void leerArchivos(FILE *f);
int leerCoordenadas(int check);
void archivo(char nombre[],int tam, int edad, int ganada, int barcos);

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
	int a,b,x;
	 
	char nombre[4];
	int edad;
	printf("Escribe tu nombre(4 letras) : ");
	scanf("%[^\n]", nombre);
	fflush(stdin);
	while((strlen(nombre))!=4 ){
		fflush(stdin);
		printf("Escribe tu nombre(4 letras) : ");
		scanf("%[^\n]", nombre);
		fflush(stdin);
	}
	printf("cual es tu edad : ");
	scanf("%d",&edad);
	if(edad <= 17){
		printf("LO SIENTO NO PUEDES JUGAR, TIENES QUE SER MAYOR DE EDAD!!!!\n");
		system("pause");
		return 0;
	}
	printf("\n");
	printf("El tablero es el siguiente!\n");
	printf("\n");
	
	iniciarTablero();
	mostrarTablero(0);
	printf("\n");
	printf("\n");	

int check;
int i;
	for(i=0; i<=9;){
	
		
		
	int r=leerCoordenadas(check);
		if(r==1){
			
			i--;
			printf("NUMERO DE TIRO NUMERO ES  %d : ",i);
			printf("\n");	
			printf("\n");
		}
		if(r==2){
			
			i++;
			printf("NUMERO DE TIRO NUMERO  ES  %d : ",i);
			printf("\n");
			mostrarTablero(1);
			printf("\n");
			
		}


}

			
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
			tablero[i][j] = '0';	
		}
	}
}


void mostrarTablero(int band)

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
				if(tablero[i][j] == '1')
					
					printf("%c   ", 254);
				else
					printf("%c   ", 'x');
			}
			else printf("%c   ", 'x');	
		}
		
		printf("\n");
	}
}

void leerArchivos(FILE *f)
{
	int num, i, line,col,j,car;
	
	srand(time(NULL));
	num = 1 + rand()%(3-1);
	
	if(num == 1)
		f = fopen("coordenadas1.txt","r");
	if(num == 2)
		f = fopen("coordenadas2.txt","r");
	if(num == 3)
		f = fopen("coordenadas3.txt","r"); 
	
	printf("\n%d\n",num);
	if(f != NULL);
	
	{
		for(i = 0; i < 10; i++)
		{
			fscanf(f,"%d%c%d", &line, &car, &col);
			
			for(j = 0; j < 3; j++)
			{
				tablero[line ][col+j] = '1';
			}
		}		
	}
}

int leerCoordenadas(int check)
{
	
	int y=0,z=0, cont = 0;
	char car;


	
		while(1)
	{
		printf("Genere una coordenada como fila,columna ");
		scanf("%d,%d",&y,&z);
		
		if(tablero[y][z] == '1')
		{
			printf("\nLe ah dado al barco joven\n");
				tablero[y][z] = 'V';
					check=1;
				cont++;
				
				if(cont == 3)
				{
					printf("Genial, lograste hundir un barco\n");
					printf("\n");
					printf("\n");
				check=1;
					cont = 0;
					
					
				}
				
		}else
		{
			printf("No le ah dado al barco joven\n");
			printf("\n");
			printf("\n");
			
			tablero[y][z] = 'F';
			check=2;
		}
				mostrarTablero1();
		return check;

		
	}

}

void mostrarTablero1()

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
			if(tablero[i][j] == '0' || tablero[i][j] == '1')
			{
				printf("x   ");		
			}else
			printf("%c   ",tablero[i][j]) ;		
			
		}
		printf("\n");
	}
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
