#include <iostream>
#include <random>
#include <functional>
using namespace std;

int main(int argc, char const *argv[])
{

	default_random_engine re;   // the default engine
	normal_distribution<double> nd(31 /* mean */,8 /* sigma */);

	auto norm = bind(nd, re);

	vector<int> mn(64);

		for (int i = 0; i<1200; ++i) ++mn[round(norm())]; // generate
	
		for (int i = 0; i<mn.size(); ++i) {
			cout << i << '\t';
			for (int j=0; j<mn[i]; ++j) cout << '*';
			cout << '\n';
		}
	
	return 0;
}