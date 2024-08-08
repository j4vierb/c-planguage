# Nombre del compilador
CC = gcc

# Opciones del compilador
CFLAGS = -Wall -g

# Archivos fuente
SRCS = getch.c getop.c main.c stack.c

# Archivos objeto
OBJS = $(SRCS:.c=.o)

# Nombre del ejecutable
EXEC = rpn_calculator

# Regla por defecto: compilar todo
all: $(EXEC)

# Regla para construir el ejecutable
$(EXEC): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^

# Regla para compilar archivos .c a .o
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Regla para limpiar los archivos compilados
clean:
	rm -f $(OBJS) $(EXEC)

# Regla para ejecutar el programa
run: $(EXEC)
	./$(EXEC)

# Regla para depurar el programa
debug: $(EXEC)
	gdb $(EXEC)
