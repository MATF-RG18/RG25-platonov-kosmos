PROGRAM = main
CC      = gcc
CFLAGS  = -g -Wall -Wextra
LDLIBS  = -lglut -lGLU -lGL -lm

$(PROGRAM): main.o 
	$(CC) $^ -o $@ $(LDLIBS)

main.o: main.c
	$(CC) -c $< $(LDLIBS)

.PHONY: clean

clean:
	-rm *.o $(PROGRAM) *core
