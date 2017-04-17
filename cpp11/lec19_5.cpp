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
//	19�� 5. reference�� function overloading
///////////////////////////////////////////////////////////////////////////

void foo(int& r) { cout << "int&" << endl; }					//	1
void foo(const int& r) { cout << "const int&" << endl; }		//	2
void foo(int&& r) { cout << "int&&" << endl; }					//	3

int main()
{
	int v = 10;
	const int c = v;

	foo(v);				// lvalue, 1�� ȣ��, ���ٸ� 2�� ȣ��
	foo(10);			// rvalue, 3�� ȣ��, ���ٸ� 2�� ȣ��
	foo(c);				// ����Ұ����� lvalue, 2�� ȣ��, ������ error
}

