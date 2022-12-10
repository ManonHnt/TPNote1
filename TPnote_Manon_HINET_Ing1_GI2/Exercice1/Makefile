all : prog

prog : tab.o logement.o fichier.o main.o
	gcc -o prog tab.o logement.o fichier.o main.o -lm
	
tab.o : tab.c
	gcc -o tab.o -c tab.c -lm

logement.o : logement.c
	gcc -o logement.o -c logement.c -lm
	
fichier.o : fichier.c
	gcc -o fichier.o -c fichier.c -lm
	
main.o : main.c
	gcc -o main.o -c main.c -lm

clean :
	rm -rf *.o prog
