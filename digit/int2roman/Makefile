DIR=$(PWD)
#BIN=$(DIR)/tcpcali
BIN=int2roman
CFLAG=
LFLAG= -lm
CC=gcc
AR=ar
CO=$(CC)

#SRC = $(wildcard $(DIR)/*.c)
SRC = linux_main.c int2roman.c
OBJ = $(patsubst %.c,%.o,$(SRC))


all:$(BIN)
$(BIN):$(OBJ)
	$(CO) -o $@ $^ $(LFLAG)

$(DIR)/%.o:$(DIR)/%.c
	$(CC) $@ -c $< $(CFLAG)


.PHONY:clean
clean:
	rm $(OBJ) $(BIN)
