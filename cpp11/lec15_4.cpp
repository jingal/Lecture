#include <iostream>
#include <type_traits>
#include <typeinfo>
//#include <vector>
//#include <boost\\type_index.hpp>

using namespace std;

///////////////////////////////////////////////////////////////////////////
//	nullptr #2 - nullptr_t
///////////////////////////////////////////////////////////////////////////

void foo(int* p) {}

template<typename F, typename T> 
void logTime(F f, T arg)
{
	f(arg);
}

int main()
{
	//foo(0);		// 성능 측정
	//logTime(foo, 0);
	logTime(foo, nullptr);
}




/*
int main()
{
	cout << typeid(34).name() << endl;

	cout << typeid(nullptr).name() << endl;			//nullptr_t
}
*/

