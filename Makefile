CC=gcc
CEFLAGS= -W -Wall -ansi -pedantic
FICHIERS=graphe-1.o graphe.o  main.o
PROG = Go

all: $(FICHIERS)
	$(CC) $(FICHIERS) $(CEFLAGS) -o $(PROG)

graphe-1.o: graphe-1.c
	$(CC) -c $(CEFLAGS) graphe-1.c

graphe.o: graphe.c
	$(CC) -c $(CEFLAGS) graphe.c

main.exe: graphe-1.o graphe.o main.o
	$(CC) $(CEFLAGS) $(FICHIERS) $(PROG)
clean:
	rm -f *.o
