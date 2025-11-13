LDFLAGS=-O2 -std=c23

targets = $(patsubst %.c,%.o,$(wildcard *.c))

all: main

run: main
	./main

debug: LDFLAGS+=-g
debug: main
	gdb main

main: $(targets)
	gcc -o main $(LDFLAGS) $(targets)

$(targets): %.o: %.c
	gcc $(LDFLAGS) -c $< -o $@

clean:
	rm $(targets) main
