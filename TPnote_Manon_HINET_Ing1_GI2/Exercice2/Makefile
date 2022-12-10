all : prog

prog : ordonnanceur.o FCFS.o SJF.o priorite.o main.o
	gcc -o prog ordonnanceur.o FCFS.o SJF.o priorite.o main.o
	
ordonnanceur.o : ordonnanceur.c
	gcc -o ordonnanceur.o -c ordonnanceur.c

FCFS.o : FCFS.c
	gcc -o FCFS.o -c FCFS.c
	
SJF.o : SJF.c
	gcc -o SJF.o -c SJF.c

priorite.o : priorite.c
	gcc -o priorite.o -c priorite.c
		
main.o : main.c
	gcc -o main.o -c main.c

clean :
	rm -rf *.o prog
