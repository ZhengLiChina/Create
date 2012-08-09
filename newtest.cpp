#include <iostream>

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
	return 0;
}