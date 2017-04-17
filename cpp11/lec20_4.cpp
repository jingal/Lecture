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

//void foo(int& ) {}		//int lvalue�� ���ް���
//void foo(int&& ) {}		//int rvalue�� ���ް���

//template<typename T> void foo(T&) {}		//��� lvaule�� ���� ����
template<typename T> void foo(T&&) //��� rvalue, lvaule ���� ����
{
	cout << "T : " << type_id_with_cvr<T>().pretty_name() << endl;
	cout << "T&& : " << type_id_with_cvr<T&&>().pretty_name() << endl;
}		


int main()
{
	int n = 10;

	foo(n);			// lvalue, T : int&, T&& : int& && => int&
	foo(10);		// rvalue, T : int, T&& : int&& => int&

	auto&& a1 = n;		//auto : int&		a1 : int& && => int&
	auto&& a2 = 10;		//auto : int		a2 : int&&
}