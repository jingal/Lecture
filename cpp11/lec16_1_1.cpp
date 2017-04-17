#include <iostream>
#include <type_traits>
#include <typeinfo>
#include <string>
#include <chrono>
//#include <vector>
//#include <boost\\type_index.hpp>

using namespace std;
using namespace std::chrono;

///////////////////////////////////////////////////////////////////////////
//	user define literal #2
///////////////////////////////////////////////////////////////////////////

void foo(string s) { cout << "string" << endl; }
void foo(const char* s) { cout << "const char*" << endl; }


int main()
{

	foo("hello"); // const char*
	foo("hello"s); // string, string operator""s(const char*, int len)


	seconds s = 1h + 2min + 30s;
	cout << s.count() << endl;
}
