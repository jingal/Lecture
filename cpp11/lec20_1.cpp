#include <iostream>
#include <type_traits>
#include <typeinfo>
#include <string>
#include <chrono>
#include <typeinfo>
//#include <vector>
#include <boost/type_index.hpp>

using namespace std;
using namespace std::chrono;
using namespace boost::typeindex;

///////////////////////////////////////////////////////////////////////////
//	20강 완벽한(Perfect Forwarding)개념
///////////////////////////////////////////////////////////////////////////

void goo(int& n) { cout << "goo" << endl; n = 20; }
void foo(int n) { cout << "foo" << endl; }

template<typename F, typename T> void logTime(F f, T&& arg)
//template<typename F, typename T> void logTime(F f, const T& arg)
{
		//시간측정..
		f(arg);
		//시간측정..
}


int main()
{
	int n = 10;	
	logTime(foo, n);
	cout << n << endl;		//20나와야 한다.
	logTime(goo, n);
	cout << n << endl;		//20나와야 한다.
	logTime(foo, 10);
	cout << n << endl;		//20나와야 한다.
}
