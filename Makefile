all:test.exe

test.exe:test.o
	g++ -std=c++11 test.o -o $@

test.o:test.cpp
	g++ -std=c++11 -c test.cpp -o $@

# use nmake (got from VS2010) on windows 8
# so I cannot use $^
clean:
	del test.exe *.o