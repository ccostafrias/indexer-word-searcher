# compilador
CC = gcc
# flags de compilação (ativam warnings e padrão C)
CFLAGS = -Wall -Wextra -std=c11 -Iinclude

LDFLAGS = -lm

# diretório final dos .o
OBJDIR = build

# nome do executável
TARGET = main

# pega todos os arquivos .c no diretório atual, exceto o antigo lista_ligada.c
SRC = $(filter-out src/lista_ligada.c, $(wildcard src/*.c))

# itera sobre SRC e transforma os arquivos src/*.c em build/*.o
OBJ = $(SRC:src/%.c=$(OBJDIR)/%.o)

# compila o target principal
all: $(TARGET)

$(TARGET): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(OBJDIR)/$(TARGET) $(LDFLAGS)

# Regra para compilar cada .c em .o (colocando os .o dentro de build/)
$(OBJDIR)/%.o: src/%.c | $(OBJDIR)
	$(CC) $(CFLAGS) -c $< -o $@

# Cria a pasta build se não existir
$(OBJDIR):
	mkdir $(OBJDIR)