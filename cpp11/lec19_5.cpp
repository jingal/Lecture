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
//	19강 5. reference와 function overloading
///////////////////////////////////////////////////////////////////////////

void foo(int& r) { cout << "int&" << endl; }					//	1
void foo(const int& r) { cout << "const int&" << endl; }		//	2
void foo(int&& r) { cout << "int&&" << endl; }					//	3

int main()
{
	int v = 10;
	const int c = v;

	foo(v);				// lvalue, 1번 호출, 없다면 2번 호출
	foo(10);			// rvalue, 3번 호출, 없다면 2번 호출
	foo(c);				// 변경불가능한 lvalue, 2번 호출, 없으면 error
}

