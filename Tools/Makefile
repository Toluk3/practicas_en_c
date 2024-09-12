CC=gcc-4.1

CFLAGS = -Wall -O4 -std=gnu89 -pedantic-errors
HEADERS = -I./

all : productor consumidor

productor: productor.h productor.c gestorArchivos.c funciones.c semaforo.c clave.c

	$(CC) -o productor productor.c gestorArchivos.c funciones.c semaforo.c clave.c $(CFLAGS) $(HEADERS)
	
consumidor: consumidor.c consumidor.h gestorArchivos.c funciones.c semaforo.c clave.c

	$(CC) -o consumidor consumidor.c gestorArchivos.c funciones.c semaforo.c clave.c $(CFLAGS) $(HEADERS)
	
 
clean:
	rm -rf *o consumidor productor
	
	
	
