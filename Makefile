LDFLAGS=-O2

all: main
debug: LDFLAGS+=-g
debug: main
	gdb main
	
run: main
	./main

clean:
	rm -f main main.o rpssl.o

main: main.o rpssl.o utility.o
	gcc -o main main.o rpssl.o utility.o

main.o: main.c
	gcc -o main.o -c $(LDFLAGS) main.c

rpssl.o: rpssl.c
	gcc -o rpssl.o -c $(LDFLAGS) rpssl.c

utility.o: utility.c
	gcc -o utility.o -c $(LDFLAGS) utility.c
