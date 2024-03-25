#include "archivosio.h"

FILE *abrirArchivoLectura(const char *nombreArchivo) {
    FILE *archivo = fopen(nombreArchivo, "r");
    if (archivo == NULL) {
        perror("Error al abrir el archivo para lectura");
    }
    return archivo;
}

FILE *abrirArchivoEscritura(const char *nombreArchivo) {
    FILE *archivo = fopen(nombreArchivo, "w");
    if (archivo == NULL) {
        perror("Error al abrir el archivo para escritura");
    }
    return archivo;
}

FILE *abrirArchivoAnadir(const char *nombreArchivo) {
    FILE *archivo = fopen(nombreArchivo, "a");
    if (archivo == NULL) {
        perror("Error al abrir el archivo para añadir");
    }
    return archivo;
}

void cerrarArch(FILE *arch){

    if(arch!=NULL){
        fclose(arch);
    }

}
