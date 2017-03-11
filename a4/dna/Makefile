
dna: dna.c
	gcc -Wall -Werror -o dna dna.c 

.PHONY: coverage
coverage:
	gcc -Wall -Werror -fprofile-arcs -ftest-coverage -o dna dna.c

.PHONY: clean
clean:
	     rm -f dna *.o *.gcov *.gcno *.gcda
  
