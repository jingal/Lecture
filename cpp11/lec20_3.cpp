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

//void foo(int& n) { cout << "foo" << endl; n = 20; }
//void goo(int n) { cout << "goo" << endl; }
//void hoo(int&& a) { cout << "hoo" << endl; }

// int& : lvalue reference
// int&& : rvalue reference
// T&& : forward reference
//		 ���ڷ� lvalue�� ���޵Ǹ� T : int &�� ����, T&& : int& && => int&
//		        rvalue�� ���޵Ǹ� T : ��Ÿ��(int), T&& : int && => int&&		

/*
2��° ����
template<typename F, typename T> void logTime(F f, T&& a)
{
	//a�� lvaule�̹Ƿ� �ٽ� rvalue�� ĳ�����ؾ��Ѵ�.
	f(static_cast<int&&>(a));
}
*/

/* 3��° ����
template<typename F, typename T> void logTime(F f, T&& a)
{	
	//f(static_cast<int&&>(a));
	f(forward<T>(a));				//���������� static_cast<T&&> ����.
}
*/

//void foo(int a, int& b, int&& ) { b = 20; }
int& foo(int a, int& b, int&&) { b = 20;  return b; }


// ������ ������ �������, ���ϰ��� ������� perfect forwarding �Լ�
/* 4��° ����
template<typename F, typename ...Types> decltype(auto) logTime(F f, Types&& ... args)
{	
	return f(forward<Types>(args)...);				//���������� static_cast<T&&> ����.
}
*/

// �����ٴ� ������
template<typename F, typename ...Types> decltype(auto) logTime(F&& f, Types&& ... args)
{
	return f(forward<Types>(args)...);				//���������� static_cast<T&&> ����.
}


int main()
{
	int n = 10;

	int& r = logTime(foo, 10, n, 10);
	//logTime(foo, n);
	//logTime(goo, 10);
	cout << n << endl;		//20���;� �Ѵ�.

							// hoo(10);	//ok..
	//logTime(hoo, 10);		//10�� rvalue, int&&  a = 10; //a �� rvalue reference �������� lvalue


}