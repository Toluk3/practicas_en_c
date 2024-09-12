#include "stdio.h"
#include "stdlib.h"
#include "funciones.h"
#include "time.h"

void cargarArray(int *array,int longArray){
	int i = 0;

	for(i = 0; i<longArray; i++){
		array[i] = i;
	}
}

void fisherYates(int *array, int longArray){
	int i,j = 0,tmp = 0;
	for(i = longArray-1; i> 0; i--){
		j=rand() %(i+1);
		tmp=array[j];
		array[j] = array[i];
		array[i] = tmp;
	}
}

int createrandomparams(int desde,int hasta){
	int num=0;
	num = (rand() % (desde-hasta +1))+desde;
	return num;
}


