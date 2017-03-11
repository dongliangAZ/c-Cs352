DEST = shuffle
CC = gcc
CFLAGS = -Wall -g

$(DEST) : shuffle.c
	gcc -Wall -Werror  shuffle.c -o shuffle
	


.PHONY: clean coverage
clean:
	/bin/rm -f $(DEST) *.gcov *.gcno *.gcda

coverage:
	$(CC) $(CFLAGS) -fprofile-arcs -ftest-coverage shuffle.c -o $(DEST)

