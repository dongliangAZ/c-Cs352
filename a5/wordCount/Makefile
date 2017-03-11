DEST = wordCount
CC = gcc
CFLAGS = -Wall -g

$(DEST) : wordCount.c
	$(CC) $(CFLAGS) wordCount.c -o $(DEST)

.PHONY: clean coverage
clean:
	/bin/rm -f $(DEST) *.gcov *.gcno *.gcda

coverage:
	$(CC) $(CFLAGS) -fprofile-arcs -ftest-coverage wordCount.c -o $(DEST)
