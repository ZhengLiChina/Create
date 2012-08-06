#include <iostream>
#include <string>
using namespace std;
	#define  __FUNC__ __func__

	typedef int ppp();
template<class t>
int test(t f)
{
	return f();
}
	class absInt
	{
	public:
		// absInt(int c)
		// {
		// 		val=c;
		// }
		int operator()()
		{
			return 3;
		}
		//int val;
	};
int main(int argc, char const *argv[])
{
	cout<<__cplusplus<<endl;

	cout<<"hello world"<<endl;
	string mytest=R"hhhhhhhhhh(hello\\\\sdfsdf)()()()()()""""""""))hhhhhhhhhh";
	cout<<mytest<<endl;



	int i=-42;

	//absInt s(i);
	unsigned int ui = test(absInt());
	cout<<ui<<endl;

	constexpr int sizez=alignof (long long);
	cout<<sizez;
	cout<<__FUNC__<<endl;
	cout<<__LINE__<<endl;
	cout<<__FILE__<<endl;


	return 0;
}