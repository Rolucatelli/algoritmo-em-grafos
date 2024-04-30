# Organizando os arquivos no makefile

# Nome do projeto
PROJ_NAME=algoritmo_em_grafos

# Nome do arquivo de Debug
DEBUG_NAME=algoritmo_em_grafos_debug

# Arquivos .c
C_SOURCE=$(wildcard ./src/*.c)

# Arquivos .h
H_SOURCE=$(wildcard ./hdr/*.h)

# Arquivos objeto
OBJ=$(subst .c,.o,$(subst src,objects,$(C_SOURCE) ./objects/main.c))

# Compilador
CC=gcc

# Flags (opções) para o compilador
CC_FLAGS=-c -W -Wall -pedantic

# Comando utilizado como target do clean
RM = rm -rf

#########################
# Compilação e linkagem #
#########################
all: objFolder exeFolder $(PROJ_NAME) input
debug: objFolder exeFolder $(DEBUG_NAME)

run: all input
	@ ./exe/${PROJ_NAME}

$(DEBUG_NAME): $(OBJ)
	@ echo 'Construindo arquivo de Debug usando o linker GCC: $@'
	$(CC) $^ -o ./exe/$@ -g
	@ echo 'Arquivo de Debug pronto!: $@'
	@ echo ' '

$(PROJ_NAME): $(OBJ)
	@ echo 'Construindo o binário usando o linker GCC: $@'
	$(CC) $^ -o ./exe/$@
	@ echo 'Binário pronto: $@'
	@ echo ' '

./objects/%.o: ./src/%.c ./hdr/%.h
	@ echo 'Construindo target usando o compilador GCC: $<'
	$(CC) $< $(CC_FLAGS) -o $@
	@ echo ' '

./objects/main.o: ./main/main.c $(H_SOURCE)
	@ echo 'Construindo target usando o compilador GCC: $<'
	$(CC) $< $(CC_FLAGS) -o $@
	@ echo ' '

objFolder:
	@ mkdir -p objects ./objects/algoritmos ./objects/estruturas

exeFolder:
	@ mkdir -p exe ./exe/grafos ./exe/output

input:
	@ python3 py/create_graphs.py
	@ echo 'Criando os arquivos de entrada $<'

clean:
	@ $(RM) ./objects/* ./exe/* *~
	@ rmdir objects
echo:
	@ echo 'Compilando e linkando o projeto: $(PROJ_NAME)'
	@ echo 'Arquivos .c: $(C_SOURCE)'
	@ echo 'Arquivos .h: $(H_SOURCE)'
	@ echo 'Arquivos .o: $(OBJ)'
	@ echo ' '

.PHONY: all clean debug run what
# Se existir algum arquivo com o mesmo nome que uma tag, como clean.c ou all.c, ele ignora