#include <iostream>
#include <type_traits>
#include <typeinfo>
#include <string>
#include <chrono>
#include <typeinfo>
#include <vector>
#include <boost/type_index.hpp>
#include <memory>

using namespace std;
using namespace std::chrono;
using namespace boost::typeindex;

///////////////////////////////////////////////////////////////////////////
//	21�� Perfect forwarding ���ǻ��� #2
///////////////////////////////////////////////////////////////////////////

template<typename F, typename ... Types>
decltype(auto) logTime(F&& f, Types&& ... args)
{
	return f(forward<Types>(args)...);
}


void foo(int a) {}
void foo(double b) {}


template<typename T> T square(T a) { return a*a; }
int main()
{
	//foo(0);
	//foo(3.4);

	//logTime(foo, 3.4);		//�Ķ���Ͱ� ���� �������� ������ � foo�� ������� �˼� ����

	logTime(static_cast<void(*)(double)>(&foo), 3.4);


	square(3);
	//logTime(square, 3);
	logTime(square<int>, 3);
}
