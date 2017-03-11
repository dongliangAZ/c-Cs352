DEST = rpn
CC = gcc
CFLAGS = -Wall -g

$(DEST) : rpn.c
	gcc -Wall -Werror rpn.c -o rpn
	


.PHONY: clean coverage
clean:
	/bin/rm -f $(DEST) *.gcov *.gcno *.gcda

coverage:
	$(CC) $(CFLAGS) -fprofile-arcs -ftest-coverage rpn.c -o $(DEST)


