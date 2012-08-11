all:test.exe pop3test.exe

pop3test.exe:pop3test.cpp
	g++ -std=c++11  pop3test.cpp -lws2_32 -o $@

test.exe:test.o
	g++ -std=c++11 test.o -o $@

test.o:test.cpp
	g++ -std=c++11 -c test.cpp -o $@

# use nmake (got from VS2012) on windows 8
# so I cannot use $^
clean:
	del test.exe *.o