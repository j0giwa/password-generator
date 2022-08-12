# This is am Makefile

COMPILER=gcc
COMPILER_FLAGS=-g -Wall
OBJS=
BIN = main

all:$(BIN)

main: $(OBJS)
	$(COMPILER) $(COMPILER_FLAGS) $(OBJS) -o main

%.o: %.c
	$(COMPILER) $(COMPILER_FLAGS) -c $< -o $@

clean:
	$(RM) -r main.c +.o *.dSYM