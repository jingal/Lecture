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
//	21강 reference wrapper 개념
///////////////////////////////////////////////////////////////////////////

void foo(int& r) { r = 10; }

int main()
{
	function<void()> f;

	int n = 0;

	//f = bind(&foo, n);
	f = bind(&foo, ref(n));	//n을 참조로 고정해 달라.
	f();

	cout << n << endl;
}


/*
void foo() { cout << "foo" << endl; }
void goo(int n) { cout << "goo" << n << endl; }

int main()
{
	// function : 함수 포인터와 유사한 역활을 하는 템플릿

	function<void()> f = &foo;
	f(); //foo()


	f = bind(&goo, 10);
	f();	//goo(10)
}
*/