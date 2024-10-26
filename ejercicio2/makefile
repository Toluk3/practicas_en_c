CC=gcc-4.1
CFLAGS = -Wall -O3 -std=gnu89 -pedantic-errors
HEADERS = -I./
all : clean aviones panel

aviones: aviones.c claves.h claves.c semaforos.h semaforos.c def.h archivo.c archivo.h funciones.c funciones.h
	$(CC) -o aviones aviones.c archivo.c claves.c semaforos.c funciones.c $(CFLAGS) $(HEADERS)
	rm vuelos.dat
	touch vuelos.dat


panel: panel.c claves.h claves.c semaforos.h semaforos.c def.h archivo.c archivo.h funciones.c funciones.h
	$(CC) -o panel panel.c archivo.c claves.c semaforos.c funciones.c $(CFLAGS) $(HEADERS)


clean:
	rm -rf *.o aviones panel
