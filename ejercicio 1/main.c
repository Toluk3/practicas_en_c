#include <stdio.h>
#include <stdlib.h>
#include "archivosio.h"

#define BATCH_SIZE 10
#define FILE_NAME "producto.txt"

void produce() {
    FILE *file;
    int i;
    i=0;
    
    file = abrirArchivoEscritura(FILE_NAME);
    if (file == NULL) {
        exit(1);  
    }

    i=0;

    while(i <= BATCH_SIZE){
        fprintf(file, "PRODUCTO-%02d\n", i);
        i=i+1;

    };

    fclose(file);
}

void consume() {
    char line[20];
    FILE *file;
    
    abrirArchivoLectura(FILE_NAME);
    if (file == NULL) {
        exit(1);  
    }

    
    while (fgets(line, sizeof(line), file) != NULL) {
        printf("Consumiendo: %s", line);
    }

    fclose(file);
}

int main() {
    produce();  
    consume();  

    return 0;
}
