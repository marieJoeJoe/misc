DIR=$(PWD)
#BIN=$(DIR)/tcpcali
BIN=kf
CFLAG=
LFLAG=
CC=gcc
AR=
CO=$(CC)

SRC = input.c filter.c main.c
OBJ = $(patsubst %.c,%.o,$(SRC))


all:$(BIN)
$(BIN):$(OBJ)
	$(CO) -o $@ $^ $(LFLAG)

$(DIR)/%.o:$(DIR)/%.c
	$(CC) $@ -c $< $(CFLAG)


.PHONY:clean
clean:
	rm $(OBJ) $(BIN)
#	echo $(OBJ) $(BIN)
