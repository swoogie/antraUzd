main:
	g++ -o main.exe main.cpp math.cpp fun.cpp

compile:
	g++ -c main.cpp math.cpp fun.cpp

link:
	g++ -o main.exe main.o fun.o math.o

del:
	rm *.o *.exe