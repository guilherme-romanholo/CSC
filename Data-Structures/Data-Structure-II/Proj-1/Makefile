# Nome do seu programa
TARGET = locadora_filmes

# Compilador C
CC = gcc

# Opções de compilação
CFLAGS = -Wall -O2

# Diretório dos arquivos de código-fonte
SRCDIR = src

# Diretório dos arquivos de cabeçalho
INCDIR = include

# Diretório dos arquivos objeto
OBJDIR = obj

# Arquivos criados
FILES = ititle.idx iprimary.idx movies.dat

# Lista de arquivos de código-fonte
SOURCES = $(wildcard $(SRCDIR)/*/*.c)

# Lista de arquivos objeto (gerados a partir dos arquivos de código-fonte)
OBJECTS = $(patsubst $(SRCDIR)/%.c,$(OBJDIR)/%.o,$(SOURCES))

# Diretórios de busca para arquivos de cabeçalho
INCLUDES = -I$(INCDIR)

# Comando para criar o diretório de objetos, caso não exista
MKDIR_P = mkdir -p

# Compila o código-fonte
all: $(TARGET)

$(TARGET): $(OBJECTS)
	$(CC) $(CFLAGS) $(INCLUDES) -o $(TARGET) $(OBJECTS)

$(OBJDIR)/%.o: $(SRCDIR)/%.c
	$(MKDIR_P) $(dir $@)
	$(CC) $(CFLAGS) $(INCLUDES) -c -o $@ $<

# Limpa os arquivos de build
clean:
	rm -rf $(OBJDIR) $(TARGET)

# Apaga os arquivos de dados
erase:
	rm -rf $(FILES)

# Executa o programa
run:
	./locadora_filmes

.PHONY: all clean
