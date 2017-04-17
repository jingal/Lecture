#include <iostream>
#include <type_traits>
#include <typeinfo>
#include <string>
#include <chrono>
#include <typeinfo>
#include <vector>
#include <boost/type_index.hpp>
#include <memory>
#include <functional>
#include <thread>

using namespace std;
using namespace std::chrono;
using namespace boost::typeindex;

///////////////////////////////////////////////////////////////////////////
//	21�� reference wrapper ���� #2
///////////////////////////////////////////////////////////////////////////

void foo(int& r) { r = 10; }

template<typename F, typename T> void logTime(F f, T arg)
{
	f(arg);
}

template<typename T> xreference_wrapper<T> xref(T& obj)
{
	return xreference_wrapper<T>(obj);
}

int main()
{
	int n = 0;

	//function<void()> f = bind(&foo, n);
	function<void()> f = bind(&foo, ref(n));	//������ ����, cref(n) ������ ����

	thread t(&foo, ref(n));

	cout << n << endl;
}
