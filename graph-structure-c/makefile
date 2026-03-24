graphDS.o: graph.c stack.c list.c queue.c DS.h
	gcc -Wall -c graph.c
	gcc -Wall -c stack.c
	gcc -Wall -c list.c
	gcc -Wall -c queue.c
	gcc -r graph.o stack.o list.o queue.o -o graphDS.o

clean:
	rm -f *.o