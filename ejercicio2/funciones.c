#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "funciones.h"
#include "unistd.h"
#include "time.h"



int inDevolverAleatorio(int inDesde,int inHasta){

	int numero=0;
	numero=(rand()%(inHasta-inDesde+1))+inDesde;

	return numero;


}

int *inDevolverAleatorioNoRepetido(int inDesde,int inHasta, int inCantidadAleatorios){
	/* Variables */
	int entero=0;
	int x=0,i=0,aciertos=0;
	int *valores;

	/* Bloque de Codigo */
	srand(time(0));
	if(inCantidadAleatorios > (inHasta-inDesde)){

		printf("\nError, no se pueden obtener %i numeros aleatorios con los valores ingresados",inCantidadAleatorios);
		return NULL;
	}else{
		valores = malloc(inCantidadAleatorios * sizeof(int));


		while(x<inCantidadAleatorios){
			entero=inDevolverAleatorio(inDesde,inHasta);
			printf("\n %d",entero);
			for(i=0;i < x;i++){
			
				if(entero==valores[i]){

					aciertos=aciertos+1;

				}

			}			
			if(aciertos==0){

				valores[x]=entero;
				x++;
		
			
			}			

			aciertos=0;
			sleep(1);
					


		}


	}

	

	return valores;

}

void mostrarArreglo(int arreglo[10],int longitudArreglo){

	int i=0;

	for(i=0;i<longitudArreglo;i++){
		
		printf("\n Numero %d: %d",i+1,arreglo[i]);
	}



}
//funcion que le envias string, separador y posicion para que te retorne el string correspondiente de la posicion pos1-pos2
void StringPosicionT(char *string, const char *separador, int posicion, char *retorno) {
    
    int longitud_separador = strlen(separador); 
    int contador_posicion = 0; 
    int inicio = 0; 
    int i = 0; 
	int j = 0;
	char *resultado; 
	resultado=(char *)malloc(100 * sizeof(char));

	if (resultado == NULL) {
        // Si no se puede asignar memoria, retornar NULL
        return;
    }
	memset(resultado, 0x00, sizeof(resultado));

    for (i = 0; string[i] != '\0'; i++) {
        if (strncmp(&string[i], separador, longitud_separador) == 0) {
            if (contador_posicion == posicion) { 
                resultado[j] = '\0'; 
                strcpy(retorno, resultado);
				free(resultado);
				return;
            }
            contador_posicion++;
            i += longitud_separador - 1; 
            j = 0; 
        } else {
            resultado[j++] = string[i];
        }
    }
    if (contador_posicion == posicion) {
        resultado[j] = '\0';

        strcpy(retorno, resultado);
		free(resultado);
		return;
    }
	free(resultado);
    return; 
}


