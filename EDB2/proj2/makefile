# Nome do executável final
TARGET = projB

# Compilador e flags
CC = gcc
CFLAGS = -Wall -Wextra -g

# Arquivos fonte e headers
SRCS = main.c functions.c
HEADERS = headers.h

# Objetos gerados a partir dos fontes
OBJS = $(SRCS:.c=.o)

# Regra principal para compilar o executável
$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJS)

# Regra para compilar arquivos .c em .o
%.o: %.c $(HEADERS)
	$(CC) $(CFLAGS) -c $< -o $@

# Limpeza dos arquivos gerados
clean:
	rm -f $(OBJS) $(TARGET)

# Regra para rodar o programa
run: $(TARGET)
	./$(TARGET) dados.csv
