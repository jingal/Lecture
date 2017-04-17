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
//	19�� 5.Rvalue reference �� ������ lvaule�̴�.
///////////////////////////////////////////////////////////////////////////

void foo(int& r) { cout << "int&" << endl; }					//	1
void foo(int&& r) { cout << "int&&" << endl; }					//	2

int main()
{
	int v = 10;
	foo(v);			// lvalue, 1
	foo(10);		// rvalue, 2

	int& r1 = v;

	foo(r1);		//1

	int&& r2 = 10;	// 10�� rvalue, r2�� ����Ŵ���� �̸��� ����,
	foo(r2);		// 1? 2.. 1
					// 10��ü�� rvalue
					// r2�� lvaule
					// "�̸��� �ִ� rvalue reference �� ������ lvalue �̴�."
	r2 = 30;

	foo(static_cast<int&&>(r2)); //r2 (lvalue)�� rvalue�� ĳ�����ϴ� �ڵ�.
}
