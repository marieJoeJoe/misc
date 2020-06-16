DIR=$(PWD)
BIN=rs
CFLAG=
LFLAG= -lgsl
CC=gcc
AR=ar
CO=$(CC)

#SRC = $(wildcard $(DIR)/*.c)
SRC = rs.c t_main.c
OBJ = $(patsubst %.c,%.o,$(SRC))


all:$(BIN)
$(BIN):$(OBJ)
	$(CO) -o $@ $^ $(LFLAG)

$(DIR)/%.o:$(DIR)/%.c
	$(CC) $@ -c $< $(CFLAG)


.PHONY:clean
clean:
	rm $(OBJ) $(BIN)
