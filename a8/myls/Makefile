DEST = myls
CC = gcc
CFLAGS = -Wall -g

$(DEST) : myls.c
	gcc -Wall -Werror  myls.c -o myls
	


.PHONY: clean coverage
clean:
	/bin/rm -f $(DEST) *.gcov *.gcno *.gcda

coverage:
	$(CC) $(CFLAGS) -fprofile-arcs -ftest-coverage myls.c -o $(DEST)


