all: graph

graph: main.c nodes.c edges.c queue.c
	gcc -Wall -g -o graph main.c nodes.c edges.c queue.c

.PHONY: clean all

clean:
	rm -f *.o 