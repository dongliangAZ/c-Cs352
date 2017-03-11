CFLAGS = -Wall
COVFLAGS = -Wall -fprofile-arcs -ftest-coverage
OBJ = famrel.o tool.o

famrel: $(OBJ)
	gcc $(CFLAGS) $(OBJ) -o famrel

%.o : %.c easy.h
	gcc $(CFLAGS) -c $*.c

.PHONY:coverage
coverage:
	gcc $(COVFLAGS) -o famrel famrel.c tool.c

.PHONY:clean
clean:
	rm -f *.o famrel *.gcov *.gcno *.gcda
