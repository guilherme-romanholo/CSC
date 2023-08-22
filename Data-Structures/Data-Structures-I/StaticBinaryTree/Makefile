CC = gcc
CFLAGS = -Wall
OBJS = tree.o main.o
PROGRAM = tree

$(PROGRAM): $(OBJS)
	$(CC) $(FLAGS) $(OBJS) -o $(PROGRAM)

tree.o: tree.c tree.h
	$(CC) $(CFLAGS) -c tree.c

main.o: main.c tree.h
	$(CC) $(CFLAGS) -c main.c

execute:
	./$(PROGRAM)

clean:
	rm $(OBJS) $(PROGRAM)

