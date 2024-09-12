#include "stdlib.h"
#include "stdio.h"
#include "unistd.h"
#include "consumidor.h"
#include "funciones.h"
#include "gestorArchivos.h"
#include "semaforo.h"
#include "global.h"
#include "string.h"

int main (){
	int optmenu = 0, id_semaforo = 0;
	id_semaforo = creo_semaforo();
	inicia_semaforo(id_semaforo,VERDE);
	while (optmenu != -1)
	{
		printf("\n \nIngrese una opcion: \n");
		printf("1 Leer la lista de productos\n");
		printf("2 Lee y elimina la lista de producots\n");
		printf("3 Loop to hell\n");
		printf("-1 Salir \n");
		scanf("%d", &optmenu);
		switch(optmenu){
			case 1:
				espera_semaforo(id_semaforo);
				mostrarProducto();
				levanta_semaforo(id_semaforo);
				break;
			case 2:
				
				espera_semaforo(id_semaforo);
				mostrarProducto();
				openfileclean("producto.txt");
				fclose(archivo);
				levanta_semaforo(id_semaforo);
				break;
			case 3:
				while (1){
					espera_semaforo(id_semaforo);
					mostrarProducto();
					openfileclean("producto.txt");
					fclose(archivo);
					levanta_semaforo(id_semaforo);
					usleep(500000);
				}			
			case -1:
				printf("\nBye\n");
				break;
			default:
				printf("%d no es una opcion valida",optmenu);
			
		}
		
	
	}
	
	
	return 0;
}



void mostrarProducto(){
	char cadena[LARGO_CADENA];
	if(openfileread("producto.txt") == TRUE)
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
