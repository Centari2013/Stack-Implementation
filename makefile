stack: main.o
	g++ -o stack main.o

main.o: main.cpp stack.h
	g++ -c main.cpp



