DIR=$(PWD)
BIN=string_algo
CFLAG=
LFLAG= 
CC=gcc
AR=ar
CO=$(CC)

#SRC = $(wildcard $(DIR)/*.c)
SRC = main.c utils.c
OBJ = $(patsubst %.c,%.o,$(SRC))


all:$(BIN)
$(BIN):$(OBJ)
	$(CO) -o $@ $^ $(LFLAG)

$(DIR)/%.o:$(DIR)/%.c
	$(CC) $(CFLAG) $@ -c $<


.PHONY:clean
clean:
	rm $(OBJ) $(BIN)
