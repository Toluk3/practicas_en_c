#include "stdlib.h"
#include "stdio.h"
#include "archivo.h"
#include "def.h"
FILE *archivo;

int openfile(char filename[LARGO_CADENA]){
	if ((archivo=fopen(filename, "a+"))==NULL)
	{
		printf("\n No se pudo abrir el archivo %s", filename);
		return FALSE;
	}else	
		return TRUE;
}
int openfileclean(char filename[LARGO_CADENA]){
	if ((archivo=fopen(filename,"w")) ==NULL)
	{
		printf("\nNo se pudo abrir el archivo %s \n",filename);
		return FALSE;
	}else
		return TRUE;

}

int openfileread(char filename[LARGO_CADENA])
{
	if ((archivo=fopen(filename, "r+"))==NULL)
	{
		printf("\n No se pudo abrir el archivo %s", filename);
		return FALSE;
	}else	
		return TRUE;

}

