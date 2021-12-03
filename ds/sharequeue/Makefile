DIR=$(PWD)
#BIN=$(DIR)/tcpcali
BIN=img_pair_queue
CFLAG= -std=c++11
LFLAG= -pthread
CC=g++
AR=
CO=$(CC)

#SRC = $(wildcard $(DIR)/*.c)
SRC = t_main.cc
OBJ = $(patsubst %.cc,%.o,$(SRC))


all:$(BIN)
$(BIN):$(OBJ)
	$(CO) -o $@ $^ $(LFLAG)

$(DIR)/%.o:$(DIR)/%.c
	$(CC) $@ -c $< $(CFLAG)


.PHONY:clean
clean:
	rm $(OBJ) $(BIN)
