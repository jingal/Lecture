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
//	20�� �Ϻ��� ������ �ذ�å
///////////////////////////////////////////////////////////////////////////

void foo(int& n) { cout << "foo" << endl; n = 20; }
void goo(int n) { cout << "goo" << endl; } 
void hoo(int&& a) { cout << "hoo" << endl; }

//template<typename F, typename T> void logTime(F f, T arg)

// 1�� �켱 int, ���ڴ� �ݵ�� ������ �޾ƾ� ��.
template<typename F> void logTime(F f, int& a)
{	
	f(a);
}


// R Value ����
/*
template<typename F> void logTime(F f, int&& a)
{	
	f(a);
}
*/


template<typename F> void logTime(F f, int&& a)
{
	//a�� lvaule�̹Ƿ� �ٽ� rvalue�� ĳ�����ؾ��Ѵ�.
	f(static_cast<int&&>(a));
}



int main()
{
	int n = 10;
	
	logTime(foo, n);
	logTime(goo, 10);
	cout << n << endl;		//20���;� �Ѵ�.

	// hoo(10);	//ok..
	logTime(hoo, 10);		//10�� rvalue, int&&  a = 10; //a �� rvalue reference �������� lvalue
}


// �����Լ��� ���� �Լ��� ����(int)�� �Ϻ��� �����Ϸ���
// 1. �Լ� ���ڴ� ������ �޾ƾ� �Ѵ�.
// 2. int&�� int&&�� ���ڷ� �޵��� 2���� �Լ��� �����ε� �ؾ��Ѵ�.
// 3. int&& ������ �Լ������� �����Լ��� ȣ���� �� �ݵ�� rvalue�� ĳ�����ؾ� �Ѵ�.
// ������ : ���� �Լ��� ���ڰ� �Ѱ��� �ƴ϶� 2��, 3��, N�����.
