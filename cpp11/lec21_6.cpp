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
//	21강 reference wrapper 개념 #2
///////////////////////////////////////////////////////////////////////////

void foo(int& r) { r = 10;  }



// 포인터가 참조로 암시적 형변환이 필요하다. reference wrapper
//void logTime(F f, T&& arg)		//int& arg
template<typename F, typename T> void logTime(F f, T arg)		// T : int*
{
//	f(std::forward<T>(arg));
	f(arg);
}

int main()
{
	int n = 0;

	function<void()> f = bind(&foo, n);		//n을 참조가 아닌 값으로 보관하게 된다.

	//logTime(foo, n);
	logTime(foo, &n);

	cout << n << endl;
}


/*
int main()
{
	function<void()> f;

	{
		int n = 0;
		logTime(foo, n);		//중간에 복사본 생기면 안됨, 참조로 전달
								// 이 순간.. 이미 foo가 실행된다.

		f = bind(&foo, n);		// 이순간 foo와 n을 보관한다. => n을 값으로 보관한다.
								// bind는 참조가 아닌 값으로 보관
	} //n이 파괴된다.

	f();					// 이순간 foo(n) 실행

	cout << n << endl;
}
*/