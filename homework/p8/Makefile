family.out: file.o main.o search.o vector.o
	gcc -Wall -g -o family.out file.o main.o search.o vector.o 

file.o: file.c file.h vector.h main.h 
	gcc -Wall -g -c file.c

main.o: main.c file.h vector.h search.h main.h
	gcc -Wall -g -c main.c

search.o: search.c search.h main.h
	gcc -Wall -g -c search.c

vector.o: vector.c vector.h main.h
	gcc -Wall -g -c vector.c

clean:
	rm -f family.out file.o main.o search.o vector.o 
