PWD=$(shell pwd)
VPATH=$(PWD)
OBJDIR=obj


SRC_C=$(foreach dir,$(subst :,,$(VPATH)),$(wildcard $(dir)/*.c))
OBJ_C=$(addsuffix .o,$(basename $(SRC_C)))


LDFLAGS=


#CC=gcc -Wall -Werror
CC=gcc -Wall
TARGET=mz

all:$(TARGET)

$(TARGET):$(OBJ_C)
	$(CC) -o $@ $^ $(LDFLAGS)

$(OBJ_C):$(SRC_C)
	$(CC) -c $(SRC_C)

clean:
	rm -rf $(OBJ_C) $(TARGET)
