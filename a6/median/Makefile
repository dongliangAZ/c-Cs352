DEST = median
CC = gcc
CFLAGS = -Wall -g

$(DEST) : median.c
	gcc -Wall -Werror  median.c -o median
	


.PHONY: clean coverage
clean:
	/bin/rm -f $(DEST) *.gcov *.gcno *.gcda

coverage:
	$(CC) $(CFLAGS) -fprofile-arcs -ftest-coverage median.c -o $(DEST)


