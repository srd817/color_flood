edit: grill.o fichier.o test_cunit.o
	gcc -Wall -Wextra -ansi -o edit grill.o fichier.o test_cunit.o -lcunit
grill.o: grill.c grill.h
	gcc -Wall -Wextra -ansi -c grill.c
fichier.o: fichier.c fichier.h grill.h 
	gcc -Wall -Wextra -ansi -c fichier.c 
test_cunit.o: test_cunit.c fichier.h grill.h 
	gcc -Wall -Wextra -ansi -c test_cunit.c -lcunit
.PHONY:clean
clean:
	-rm edit grill.o fichier.o test_cunit.o