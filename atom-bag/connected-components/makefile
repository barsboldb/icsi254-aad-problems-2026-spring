GR_DIR = ../../graph-structure-c
CFLAGS = -Wall -I$(GR_DIR)

result: solution.o $(GR_DIR)/graphDS.o
	gcc solution.o $(GR_DIR)/graphDS.o -o result

solution.o: solution.c
	gcc $(CFLAGS) -c solution.c

clean:
	rm -f *.o result