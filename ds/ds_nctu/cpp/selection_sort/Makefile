DIR=$(PWD)
#BIN=$(DIR)/tcpcali
BIN=selsortoo
CFLAG=
LFLAG=
CC=g++
AR=
CO=$(CC)

#SRC = $(wildcard $(DIR)/*.c)
SRC = calculator.cc algorithm.cc t_main.cc
OBJ = $(patsubst %.cc,%.o,$(SRC))


all:$(BIN)
$(BIN):$(OBJ)
	$(CO) -o $@ $^ $(LFLAG)

$(DIR)/%.o:$(DIR)/%.c
	$(CC) $@ -c $< $(CFLAG)


.PHONY:clean
clean:
	rm $(OBJ) $(BIN)
