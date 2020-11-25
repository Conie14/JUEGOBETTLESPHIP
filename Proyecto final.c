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
void leer_dat(char nombre[],int tam, int *edad);
void lee_archivo_dat();
void reglas();
void portada();

int tablero[10][10];

int main() 
{
	portada();
        reglas();
	
	
		FILE *f;
	int a,b,x;
	char nombre[10];
        int edad;
	leer_dat(nombre,10,&edad);
	if(edad <= 17){
		printf("LO SIENTO NO PUEDES JUGAR, TIENES QUE SER MAYOR DE EDAD!!!!\n");
		system("pause");
		return 0;
	}
	printf("\n");
	printf("El tablero es el su¿iguiente: \n");

	iniciarTablero();
	mostrarTablero(0);
	//mostrarTablero(1);
		printf("\n");
			printf("\n");

	int check;
	int i;
	for(i=0; i<=9;){
	int r=leerCoordenadas(check);
		if(r==1)
		{

			i--;
			printf("NUMERO DE TIRO NUMERO ES  %d : ",i);
					printf("\n");

							printf("\n");
		}
		if(r==2)
		{
			i++;
			printf("NUMERO DE TIRO NUMERO  ES  %d : ",i);
			printf("\n");

			//mostrarTablero(1);
			printf("\n");
			leerArchivos(f);

		}
	
}
						if(i>9)
						{
							printf("GENIAL HAS GANADO");
							//archivo(char nombre[],int tam, int edad, int ganada, int barcos);
							leerArchivos(f);
						}else{
							printf("Ha perdido");
							//archivo(char nombre[],int tam, int edad, int ganada, int barcos);
							leerArchivos(f);
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
	printf("este archivo es el  %d",num);
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
   int i;
   FILE * flujo;
   flujo = fopen("informacion.txt", "a");
   if(flujo == NULL){
      perror("Error al crear el archivo\n");
   } else {
      if(ganada==1){
        
      if(strlen(nombre) < 10){
            fprintf(flujo, "%s",nombre);
            for(i=strlen(nombre);i<10;i++){
                fputc(' ', flujo);
            }
            fprintf(flujo, " %d     ganador",edad);
        } else{
            fprintf(flujo, "%s     %d     ganador",nombre, edad);
        }
        
        fputc('\n', flujo);
      } else{
        if(strlen(nombre) < 10){
            fprintf(flujo, "%s",nombre);
            for(i=strlen(nombre);i<10;i++){
                fputc(' ', flujo);
            }
            fprintf(flujo, " %d     perdedor  %d    barcos hundidos", edad, barcos);
        } else{
            fprintf(flujo, "%s     %d     perdedor  %d    barcos hundidos",nombre, edad, barcos);
        }
        fputc('\n', flujo);
      }
      fflush(flujo);
      fclose(flujo);
      printf("DATOS GUARDADOS EXITOSAMENTE!!!!!\n\n");
   }
}	

void lee_archivo_dat(){
	FILE * lectura;

    lectura= fopen("informacion.txt", "rb");
    if (lectura == NULL){
        perror("Error en la lectura del archivo\n\n");
        return 0;
    }

    char caracter;

	while(feof(lectura) == 0){
		caracter = fgetc(lectura);
		if(caracter == 'Ñ'){
            printf("%c", 165);
		} else{
			if(caracter == 'ñ'){
				printf("%c", 164);
			} else{
				printf("%c", caracter);
			}
            
		}
	}

    fclose(lectura);
}

void reglas(){
	int a=178;
	int b=219;
	int c=223;
	printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n",a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a);
	printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n",a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a);
	printf("%c%c                                               %c%c\n",a,a,a,a);
	printf("%c%c  %c%c%c%c   %c%c%c%c%c   %c%c%c   %c        %c%c%c%c     %c%c%c%c  %c%c\n",a,a,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,a,a);
	printf("%c%c  %c   %c  %c      %c   %c  %c       %c    %c   %c      %c%c\n",a,a,b,b,b,b,b,b,b,b,b,a,a);
	printf("%c%c  %c   %c  %c      %c      %c       %c    %c   %c      %c%c\n",a,a,b,b,b,b,b,b,b,b,a,a);
	printf("%c%c  %c%c%c%c   %c%c%c%c   %c %c%c%c  %c       %c    %c    %c%c%c   %c%c\n",a,a,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,a,a);
	printf("%c%c  %c   %c  %c      %c   %c  %c       %c%c%c%c%c%c       %c  %c%c\n",a,a,b,b,b,b,b,b,b,b,b,b,b,b,b,a,a);
	printf("%c%c  %c   %c  %c      %c   %c  %c       %c    %c       %c  %c%c\n",a,a,b,b,b,b,b,b,b,b,b,a,a);
	printf("%c%c  %c   %c  %c%c%c%c%c   %c%c%c   %c%c%c%c%c   %c    %c   %c%c%c%c   %c%c\n",a,a,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,a,a);
	printf("%c%c                                               %c%c\n",a,a,a,a);
	printf("%c%c                                               %c%c\n",a,a,a,a);
	printf("%c%c     BIENVENIDO AL JUEGO DE BATALLA NAVAL      %c%c\n",a,a,a,a);
	printf("%c%c                                               %c%c\n",a,a,a,a);
	printf("%c%c   Tendr%cs DIEZ intentos para poder hundir     %c%c\n",a,a,160,a,a);
	printf("%c%c   todos los barcos.                           %c%c\n",a,a,a,a);
	printf("%c%c   Si no le atinas a la posici%cn de un barco   %c%c\n",a,a,162,a,a);
	printf("%c%c   se te restara un intento.                   %c%c\n",a,a,a,a);
	printf("%c%c   Pero si le atinas a la posici%cn de un       %c%c\n",a,a,162,a,a);
	printf("%c%c   barco tus intentos seguir%cn intactos        %c%c\n",a,a,160,a,a);
	printf("%c%c                                               %c%c\n",a,a,a,a);
	printf("%c%c                                               %c%c\n",a,a,a,a);
	printf("%c%c   El juego finaliza cuando todos tus          %c%c\n",a,a,a,a);
	printf("%c%c   intentos se hayan acabado, o cuando hayas   %c%c\n",a,a,a,a);
	printf("%c%c   hundido todos los barcos                    %c%c\n",a,a,a,a);
	printf("%c%c                                               %c%c\n",a,a,a,a);
	printf("%c%c                                               %c%c\n",a,a,a,a);
	printf("%c%c                                               %c%c\n",a,a,a,a);
	printf("%c%c        %c%c  %c  %c  %c%c%c  %c%c%c   %c%c%c  %c%c%c          %c%c\n",a,a,c,c,c,c,c,c,c,c,c,c,c,c,c,c,c,c,a,a);
	printf("%c%c       %c    %c  %c  %c    %c  %c   %c   %c            %c%c\n",a,a,c,c,c,c,c,c,c,c,a,a);
	printf("%c%c        %c%c  %c  %c  %c%c%c  %c%c%c    %c   %c%c%c          %c%c\n",a,a,c,c,c,c,c,c,c,c,c,c,c,c,c,c,a,a);
	printf("%c%c          %c %c  %c  %c    %c  %c   %c   %c            %c%c\n",a,a,c,c,c,c,c,c,c,c,a,a);
	printf("%c%c        %c%c   %c%c   %c%c%c  %c  %c   %c   %c%c%c          %c%c\n",a,a,c,c,c,c,c,c,c,c,c,c,c,c,c,a,a);
	printf("%c%c                                               %c%c\n",a,a,a,a);
	printf("%c%c                                               %c%c\n",a,a,a,a);
	printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n",a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a);
	printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n",a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a);
	system("pause");
	system("cls");
	
}

void portada(){
    int a=176;
	printf("\n");
	printf("\n");
	printf("\n");
	printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n",a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a);
	printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n",a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a);
	printf("%c%c                                                                         %c%c\n",a,a,a,a);
	printf("%c%c                                                                         %c%c\n",a,a,a,a);
	printf("%c%c  __________          __    __  .__                  .__    .__          %c%c\n",a,a,a,a);
    printf("%c%c  \\______   \\_____  _/  |__/  |_|  |    ____   ______|  |__ |__|______   %c%c\n",a,a,a,a);
    printf("%c%c   |    |  _/\\__  \\ \\   __\\   __\\  |  _/ __ \\ /  ___/|  |  \\|  |\\____ \\  %c%c\n",a,a,a,a);
    printf("%c%c   |    |   \\ / __ \\_|  |  |  | |  |__\\  ___/ \\___ \\ |      \\  ||  |_> > %c%c\n",a,a,a,a);
    printf("%c%c   |______  /(______/|__|  |__| |____/ \\_____>______>|___|  /__||   __/  %c%c\n",a,a,a,a);
    printf("%c%c         _\\/ _     _   _   _   _   _     _   _   _   _    \\/    |__|     %c%c\n",a,a,a,a);
    printf("%c%c                                                                         %c%c\n",a,a,a,a);
    printf("%c%c                                                                         %c%c\n",a,a,a,a);
    printf("%c%c                                                                         %c%c\n",a,a,a,a);
    printf("%c%c                                  _/|                                    %c%c\n",a,a,a,a);
    printf("%c%c                                 _|:|                                    %c%c\n",a,a,a,a);
    printf("%c%c                               _|:::|                                    %c%c\n",a,a,a,a);
    printf("%c%c                         _ /|  |::::|                                    %c%c\n",a,a,a,a);
    printf("%c%c                         |::|  |::::|                                    %c%c\n",a,a,a,a);
    printf("%c%c                         |::|  |:::::)__                                 %c%c\n",a,a,a,a);
    printf("%c%c                       /:|:::: |::::::::|                                %c%c\n",a,a,a,a);
    printf("%c%c                      :::|::::_|::::::::|                                %c%c\n",a,a,a,a);
    printf("%c%c                ____(:::::::::::::::::::|___ _______         __          %c%c\n",a,a,a,a);
    printf("%c%c               (::::::::::::::::::::::::|:::|::::::|  ______|::)         %c%c\n",a,a,a,a);
    printf("%c%c     ___________\\:::::::::::::::::::::::::::|:::|___|:::::::::|          %c%c\n",a,a,a,a);
    printf("%c%c     \\::::::::::::::::::::::::::::::::::::::::::::::::::::::::|          %c%c\n",a,a,a,a);
    printf("%c%c      |:::::::::::::::::::::::::::::::::::::::::::::::::::::::|          %c%c\n",a,a,a,a);
	printf("%c%c                                                                         %c%c\n",a,a,a,a);
	printf("%c%c                                                                         %c%c\n",a,a,a,a);
	printf("%c%c             / \\  / \\  / \\  / \\  / \\  / \\  / \\  / \\  / \\  / \\            %c%c\n",a,a,a,a);
    printf("%c%c              S    T    A    R    T         G    A    M    E             %c%c\n",a,a,a,a);
    printf("%c%c             \\_/  \\_/  \\_/  \\_/  \\_/  \\_/  \\_/  \\_/  \\_/  \\_/            %c%c\n",a,a,a,a);
    printf("%c%c                                                                         %c%c\n",a,a,a,a);
	printf("%c%c                                                                         %c%c\n",a,a,a,a);
	printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n",a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a);
	printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n",a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a);
	printf("\n");
	system("pause");
	system("cls");
}
