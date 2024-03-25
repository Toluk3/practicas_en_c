#ifndef ARCHIVOSIO_H
#define ARCHIVOSIO_H

#include <stdio.h>

FILE *abrirArchivoLectura(const char *nombreArchivo);
FILE *abrirArchivoEscritura(const char *nombreArchivo);
FILE *abrirArchivoAnadir(const char *nombreArchivo);
void cerrarArch(FILE *arch);

#endif 
