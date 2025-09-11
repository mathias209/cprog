LDFLAGS=-O2

all: main
debug: LDFLAGS+=-g
debug: main
	gdb main
	
run: main
	./main

clean:
	rm -f main

main: main.c
	gcc -o main $(LDFLAGS) main.c
