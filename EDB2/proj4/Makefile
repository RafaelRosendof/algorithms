EXEC = jogoEXE

SRC = main.c trie.c jogo.c avl.c

OBJ = $(SRC:.c=.o)

CC = gcc #linux comum
CCFLAGS = -Wall -g

all: $(EXEC)

$(EXEC): $(OBJ)
	$(CC) -o $@ $^

clean:
	rm -f $(OBJ) $(EXEC)

run: $(EXEC)
	./$(EXEC)
