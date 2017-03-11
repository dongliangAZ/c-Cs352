DEST = spellcheck
CC = gcc
CFLAGS = -Wall -g

$(DEST) : spellcheck.c
	gcc -Wall -Werror  spellcheck.c -o spellcheck	


.PHONY: clean coverage
clean:
	/bin/rm -f $(DEST) *.gcov *.gcno *.gcda

coverage:
	$(CC) $(CFLAGS) -fprofile-arcs -ftest-coverage spellcheck.c -o $(DEST)
