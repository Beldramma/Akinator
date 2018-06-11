# Fichier Makefile contenant les directives de compilation
# Vous utiliserez le compilateur gcc et les flags -ansi -Wall
# L'executable doit s'appeller ExamenTP2018
CC		=gcc
FLAGS	= -ansi -Wall
OBJS	= main.o fonctions.o
EXE		= Akinator

$(EXE) : $(OBJS)
	$(CC) $(FLAGS) $(OBJS) -o $(EXE)
	
main.o : fonctions.h main.c
	$(CC) $(FLAGS) -c main.c -o main.o

fonctions.o : fonctions.h fonctions.c
	$(CC) $(FLAGS) -c fonctions.c -o fonctions.o
