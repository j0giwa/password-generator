# variables
COMPILER=gcc
COMPILER_FLAGS=-g -Wall

# directorys
BINDIR=bin
BIN=$(BINDIR)/password-generator
SRC=src
OBJ=obj

# filepatters
SRCS=$(wildcard $(SRC)/*.[ch])
OBJS=$(patsubst $(SRC)/*.[ch], $(OBJ)/%.o, $(SRCS))

# Tarball
TARNAME=password-generator.tar.gz

all:$(BIN)

#Release Target
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