# Nome do executável
EXEC = corrida_threads

# Compilador e flags
CC = gcc
CFLAGS = -Wall -Wextra -pthread

# Arquivos de origem e objetos
SRC = main.c race.c
OBJ = $(SRC:.c=.o)

# Regra principal
all: $(EXEC)

# Regra para compilar o executável
$(EXEC): $(OBJ)
	$(CC) $(CFLAGS) -o $@ $^

# Regra para compilar os arquivos objeto
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Regra para limpar os arquivos gerados
clean:
	rm -f $(OBJ) $(EXEC)

# Regra para forçar a limpeza e recompilação
rebuild: clean all

# Regra para compilar e executar o programa
run: all
	./$(EXEC)
