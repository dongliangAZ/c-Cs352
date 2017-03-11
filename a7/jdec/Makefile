jdec: jdec.c
	gcc -Wall -Werror jdec.c -o jdec 

.PHONY: coverage clean
coverage: jdec.c
	gcc -Wall -Werror -fprofile-arcs -ftest-coverage -o jdec jdec.c

.PHONY: clean
clean:
	     rm -f jdec *.gcov *.gcno *.gcda
  
