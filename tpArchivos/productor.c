#include "stdlib.h"
#include "stdio.h"
#include "unistd.h"
#include "productor.h"
#include "funciones.h"
#include "gestorArchivos.h"
#include "semaforo.h"
#include "global.h"

static int numeroproducto = 0;

int main (){

	int optmenu = 0, cantproducto = 0, i = 0 , id_semaforo = 0;
	id_semaforo = creo_semaforo();
	inicia_semaforo(id_semaforo,VERDE);
	
	
	while (optmenu != -1)
	{
		printf("\n \nIngrese una opcion: \n");
		printf("1 Genera cantidad aleatoria acotada de productos\n");
		printf("2 Loop to hell\n");
		printf("-1 Salir \n");
		scanf("%d", &optmenu);
		
		switch(optmenu)
		{
			case 1:
				
				cantproducto = createrandomparams(1,30);
				for (i = 0; i< cantproducto; i++){
					espera_semaforo(id_semaforo);
					ingresaProducto(numeroproducto);
					numeroproducto++;
					levanta_semaforo(id_semaforo);
				}
				

				break;
				
			case 2:
				while (1){
					espera_semaforo(id_semaforo);
					ingresaProducto(numeroproducto);
					printf("Se ingreso el producto %d: ",numeroproducto);
					numeroproducto++;
					levanta_semaforo(id_semaforo);
					usleep(1000);
				}
				

				break;
			case -1:
				printf("\nBye\n");
				break;
			default:
				printf("%d no es un codigo valido", optmenu);
				break;
		
		}
		
		
	}
	
	

	return 0;
}


void ingresaProducto(int numeroProducto){
	if (openfile("producto.txt") == TRUE){
		fprintf(archivo,"PRODUCTO-%02d\n", numeroProducto);
		fclose(archivo);
	}else{

	}

}
