DIR=$(PWD)
#BIN=$(DIR)/tcpcali
BIN=selsort
CFLAG=
LFLAG=
CC=gcc
AR=ar
CO=$(CC)

#SRC = $(wildcard $(DIR)/*.c)
SRC = selsort.c t_main.c
OBJ = $(patsubst %.c,%.o,$(SRC))


all:$(BIN)
$(BIN):$(OBJ)
	$(CO) -o $@ $^ $(LFLAG)

$(DIR)/%.o:$(DIR)/%.c
	$(CC) $@ -c $< $(CFLAG)


.PHONY:clean
clean:
	rm $(OBJ) $(BIN)
