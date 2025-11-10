LDFLAGS=-O2 -lraylib -lGL -lm -lpthread -ldl -lrt -lX11 -std=c2y

all: main
debug: LDFLAGS+=-g
debug: main
	gdb main
	
run: main
	./main

clean:
	rm -f main main.o

main: main.o
	gcc -o main $(LDFLAGS) main.o

main.o: main.c
	gcc -o main.o -c $(LDFLAGS) main.c

utility.o: utility.c
	gcc -o utility.o -c $(LDFLAGS) utility.c
