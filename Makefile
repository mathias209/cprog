LDFLAGS=-O2

all: main
debug: LDFLAGS+=-g
debug: main
	gdb main
	
run: main
	./main

clean:
	rm -f main main.o cipher.o

main: main.o cipher.o strings.o
	gcc -o main main.o cipher.o strings.o

main.o: main.c
	gcc -o main.o -c $(LDFLAGS) main.c

cipher.o: cipher.c
	gcc -o cipher.o -c $(LDFLAGS) cipher.c

strings.o: strings.c
	gcc -o strings.o -c $(LDFLAGS) strings.c
