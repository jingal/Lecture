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
//	21�� Perfect forwarding ���ǻ���
///////////////////////////////////////////////////////////////////////////

template<typename F, typename ... Types>
decltype(auto) logTime(F&& f, Types&& ... args)
{
	return f(forward<Types>(args)...);
}


// 0�� int���� Ư���ϰ� ó���ϱ� ������ �����Ͱ� ������, ������ Ÿ���� ��Ƽ���� �����ͷ� ��ȯ �ȵ�
void foo(int* p) {}

int main()
{
	//foo(0);

	//logTime(foo, 0);

	logTime(foo, nullptr); //perfect forwarding���� *0�� ������ �������, nullptr �� ����ؾ� ��.
}
