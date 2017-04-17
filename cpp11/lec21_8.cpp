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

using namespace std;
using namespace std::chrono;
using namespace boost::typeindex;

///////////////////////////////////////////////////////////////////////////
//	21�� reference wrapper ���� #2
///////////////////////////////////////////////////////////////////////////

template<typename T> struct xreference_wrapper
{
	T* obj;
	xreference_wrapper(T& p) : obj(&p) {}

	operator T&() { return *obj; }
};

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

	//logTime(foo, &n);		//T : int* => int& �Ͻ��� ��ȯ �ȵ�

	//xreference_wrapper<int> r1 = n;		//r1�� n�ּ� ����
	//logTime(foo, r1);		//T : xreference_wrapper => int&

	logTime(foo, xref(n));

	cout << n << endl;
}
