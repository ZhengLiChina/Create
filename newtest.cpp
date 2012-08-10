#include <iostream>
#include <Winsock2.h>
#pragma comment(lib, "ws2_32.lib") 
void temp(int& a)
{
	std::cout<<a<<std::endl;
}

int main(int argc, char const *argv[])
{
	/* code */
	int a=10;
	temp(a);
	//temp(a++);
	temp(++a);
	std::cout<<a;

	const int * p = new int (10);
	int const * q = new int (20);
	int * const b = new int (30);

	return 0;
}