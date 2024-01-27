all: main

main: mfile.o main.o
    gcc -o main mfile.o main.o

mfile.o: mfile.c mfile.h
    gcc -c mfile.c

main.o: main.c mfile.h
    gcc -c main.c

clean:
    rm