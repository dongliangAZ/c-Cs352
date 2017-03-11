INC_DIR = .
CC = gcc
CFLAGS = -Wall -g -I$(INC_DIR)
DEST = mymake

$(DEST) : mymake.c easy.h
	$(CC) $(CFLAGS) mymake.c easy.h  -o mymake

 
.PHONY: coverage clean
coverage: mymake.c
	$(CC) $(CFLAGS) -fprofile-arcs -ftest-coverage mymake.c -o $(DEST)

clean:
	/bin/rm -f $(DEST) *.gcov *.gcno *.gcda *.o

