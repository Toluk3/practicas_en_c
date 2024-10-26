#include "stdlib.h"
#include "stdio.h"
#include "unistd.h"
#include "funciones.h"
#include "archivo.h"
#include "semaforos.h"
#include "def.h"

void ingresaVuelo(int numero_de_vuelo, char ciudad[LARGO_CADENA]){
	if (openfile("vuelos.dat") == TRUE){
		fprintf(archivo,"%02d-%s", numero_de_vuelo, ciudad);
		memset(ciudad,0x00,sizeof(ciudad));
		fclose(archivo);
	}else{

	}
	
}


int main (){
	
	
	int num = 0; 
	int id_semaforo = 0;
	char ciudad[LARGO_CADENA];
	
	id_semaforo = creo_semaforo();
	inicia_semaforo(id_semaforo,VERDE);
	if (openfile("vuelos.dat") == TRUE){
		fclose(archivo);
	}else{

	}
	while (1)
	{
		
		
		
		/*scanf("%s",&ciudad);*/
		
		/*memset(ciudad,0x00,sizeof(ciudad));*/
		espera_semaforo(id_semaforo);
		/*CARGAR EN ARCHIVO*/
		printf("ingreso numero de vuelo> ");
		scanf("%d",&num);
		printf("ingreso ciudad> ");
		scanf("%d",ciudad);
		printf("-------------");
		ingresaVuelo(num,ciudad);
		memset(ciudad,0x00,sizeof(ciudad));
		levanta_semaforo(id_semaforo);
		if (num == 0){
		elimina_semaforo(id_semaforo);
		return 1;		
		}else{}
		
		usleep(1000);
	}
}



