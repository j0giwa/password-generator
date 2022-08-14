# variables
NAME=password-generator
COMPILER=gcc
COMPILER_FLAGS=-g -Wall

# directorys
SRC=./src
OBJ=./obj
BINDIR=./bin

# filepatters
SRCS=$(wildcard $(SRC)/*.[ch])
OBJS=$(patsubst $(SRC)/*.[ch], $(OBJ)/%.o, $(SRCS))
BIN=$(BINDIR)/$(NAME)
TARNAME=$(NAME).tar.gz

all:$(BIN)

release: $(BIN)
release: COMPILER_FLAGS=-Wall -O2 -DNDEBUG
release: clean

# compile .o files
$(OBJ)/%.o: $(SRC)/%.c
	$(COMPILER) $(COMPILER_FLAGS) -c $< -o $@

# compile binarys from .o files
$(BIN): $(OBJS)
	$(COMPILER) $(COMPILER_FLAGS) $(OBJS) -o $@ 

# remove previous binarys/objs
clean:
	$(RM) -r $(BIN)/* $(BIN)/*

#Make tarball
tar:
	$(RM) $(TARNAME)
	gzip $(TARNAME) $(BIN)