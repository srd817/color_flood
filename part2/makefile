edit: boucle.o grill.o fichier.o main.o
	gcc -Wall -Wextra -ansi -o edit boucle.o grill.o fichier.o main.o 
grill.o: grill.c grill.h
	gcc -Wall -Wextra -ansi -c grill.c
fichier.o: fichier.c fichier.h grill.h 
	gcc -Wall -Wextra -ansi -c fichier.c 
boucle.o: boucle.c boucle.h grill.h fichier.h
	gcc -Wall -Wextra -ansi -c boucle.c
main.o: main.c fichier.h grill.h boucle.h
	gcc -Wall -Wextra -ansi -c main.c 
.PHONY:clean
clean:
	-rm edit boucle.o grill.o fichier.o main.o