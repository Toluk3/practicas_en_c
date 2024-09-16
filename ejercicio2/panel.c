#include "stdlib.h"
#include "stdio.h"
#include "unistd.h"
#include "funciones.h"
#include "archivo.h"
#include "semaforos.h"
#include "def.h"
#include "string.h"

void mostrarVuelos(){
	char cadena[LARGO_CADENA];
	if(openfileread("vuelos.txt") == TRUE)
	{
		while(!feof(archivo))
		{
			memset(cadena,0x00,LARGO_CADENA);
			fscanf(archivo,"%s",cadena);
			printf("%s \n",cadena);		
		}
	}
	fclose(archivo);
}

int main (){
	int id_semaforo = 0;
	id_semaforo = creo_semaforo();
	
	
	while (1)
	{
		
		espera_semaforo(id_semaforo);
		
		mostrarVuelos();	
		levanta_semaforo(id_semaforo);
		

		usleep(10000);
	}

}

