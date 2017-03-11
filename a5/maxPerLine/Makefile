DEST = maxPerLine
CC = gcc
CFLAGS = -Wall -g

$(DEST) : maxPerLine.c
	gcc -Wall -Werror  maxPerLine.c -o maxPerLine
	


.PHONY: clean coverage
clean:
	/bin/rm -f $(DEST) *.gcov *.gcno *.gcda

coverage:
	$(CC) $(CFLAGS) -fprofile-arcs -ftest-coverage maxPerLine.c -o $(DEST)
