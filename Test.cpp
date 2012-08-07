#include <iostream>
#include <vector>
#include <memory>
using namespace std;
int main(int argc, char const *argv[])
{
	/* code */
	std::vector<unique_ptr<int>> v;
	v.push_back(unique_ptr<int>(new int(3)));
   cout<<v.capacity()<<" "<<v.size()<<endl;
	v.push_back(unique_ptr<int>(new int(4)));
   cout<<v.capacity()<<" "<<v.size()<<endl;
	v.push_back(unique_ptr<int>(new int(5)));
	auto c=unique_ptr<int>(new int(4));
   cout<<v.capacity()<<" "<<v.size()<<endl;
	v.push_back(unique_ptr<int>(new int(6)));
   cout<<v.capacity()<<" "<<v.size()<<endl;
   cout<<(v[2]<v[3]);
	for(auto& temp:v)
	{
		cout<<(temp<c)<<" ";
	}
	return 0;
}