
battleship: battleship.c
	gcc -Wall -Werror -o battleship battleship.c 

.PHONY: coverage
coverage:
	gcc -Wall -Werror -fprofile-arcs -ftest-coverage -o  battleship battleship.c

.PHONY: clean
clean:
	     rm -f battleship *.o *.gcov *.gcno *.gcda
