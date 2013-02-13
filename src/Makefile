CC=gcc
CFLAGS=-ggdb -O0 -Wall -Wstrict-prototypes
LFLAGS=-lftdi

all: libusbrabbit.so

libusbrabbit.so: main.o
	$(CC) $(CFLAGS) $(LFLAGS) -o app main.o

clean:
	rm -f *.o libusbrabbit.so
