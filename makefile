main:
	g++ -o main.exe main.cpp failoFun.cpp

compile:
	g++ -c main.cpp failoFun.cpp

link:
	g++ -o main.exe main.o failoFun.o

del:
	rm *.o *.exe