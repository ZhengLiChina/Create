#include <iostream>
#include <string>
using namespace std;
int main(int argc, char const *argv[])
{
	cout<<__cplusplus<<endl;
	cout<<"hello world"<<endl;
	string mytest=R"hhhhhhhhhh("hello\\\sdfsdf)()()()()()""""""""")hhhhhhhhhh";
	cout<<mytest;
	return 0;
}