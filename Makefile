all:test.exe

test.exe:test.o
	g++ -std=c++11 test.o -o $@

test.o:test.cpp
	g++ -std=c++11 -c test.cpp -o $@

clean:
	del test.exe *.o