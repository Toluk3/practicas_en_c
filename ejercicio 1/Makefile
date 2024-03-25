
CC=gcc
CFLAGS=-std=gnu89 -Wall -pedantic-errors -O3


TARGET=main


SRCS=main.c archivosio.c


HEADERS=archivosio.h


all: $(TARGET)


$(TARGET): $(SRCS) $(HEADERS)
	$(CC) $(CFLAGS) -o $(TARGET) $(SRCS)


clean:
	rm -f $(TARGET)

