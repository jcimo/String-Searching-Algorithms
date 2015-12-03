all: main

main: main.o
	g++ -std=c++11 -g main.o -o main

main.o: main.cpp naive.h boyer-moore.h knuth-morris-pratt.h
	g++ -std=c++11 -g -c main.cpp

clean:
	rm *.o *~ main