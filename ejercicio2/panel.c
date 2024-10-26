#include "stdlib.h"
#include "stdio.h"
#include "unistd.h"
#include "funciones.h"
#include "archivo.h"
#include "semaforos.h"
#include "def.h"
#include "string.h"

typedef struct  {
    int numero_vuelo;
    char ciudad[LARGO_CADENA];
}avion;

void mostrarVuelos(avion *aviones, int contador_vuelos) {
    int i = 0;
	printf("Vuelos cargados:\n");
    while( i < contador_vuelos) {
        printf("Vuelo %d: %s\n", aviones[i].numero_vuelo, aviones[i].ciudad);
		i=i+1;
    }
}


void CargarVuelos(avion *aviones, int *contador_vuelos){
	char cadena[LARGO_CADENA];
	int numVuelo;
	char ciudad[LARGO_CADENA];
	char auxiliar[LARGO_CADENA];
	
	if(openfileread("vuelos.dat") == TRUE)
	{
		while(!feof(archivo))
		{	
			//limpieza de cadenas
			memset(ciudad,0x00,sizeof(ciudad));
			memset(auxiliar,0x00,sizeof(auxiliar));
			memset(cadena,0x00,sizeof(cadena));
			//escaneo de archivo
			fscanf(archivo,"%s",cadena);
			//funcion que busca patrones de posicion para cargar datos en variables(string,caracter de separado,posicion,auxiliar) agregado a funciones
			StringPosicionT(cadena,"-",0,auxiliar);//en funciones.c esta el codigo
			
			StringPosicionT(cadena,"-",1,ciudad);
			printf("%s \n",cadena);
			if(auxiliar[0] != '\0' && ciudad[0] != '\0'){
				numVuelo=atoi(auxiliar);
				aviones[*contador_vuelos].numero_vuelo = numVuelo;
				strcpy(aviones[*contador_vuelos].ciudad, ciudad);
				(*contador_vuelos)++;
			}
		}
	fclose(archivo);
	}
	
	if(openfileclean("vuelos.dat") == TRUE){fclose(archivo);}//limpiar archivo para evitar duplicados
	
	
}



int main (){
	struct avion vuelos[10];
	int id_semaforo = 0;
	int contador_vuelos = 0;
	int maxVuelos=10;
	id_semaforo = creo_semaforo();
	
	
	
	while (1)
	{
		if (contador_vuelos == 9) {
            contador_vuelos = 0;
            memset(vuelos, 0x00, maxVuelos * sizeof(struct avion));  // Limpiar los datos cargados previamente
            printf("Reiniciando el contador y limpiando los vuelos.\n");
        }


		espera_semaforo(id_semaforo);
		
		CargarVuelos(vuelos, &contador_vuelos);
		mostrarVuelos(vuelos, contador_vuelos);	
		levanta_semaforo(id_semaforo);
		
		usleep(10000);
	}
	free(vuelos);
}

