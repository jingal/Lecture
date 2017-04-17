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
//	21�� reference wrapper ����
///////////////////////////////////////////////////////////////////////////

void foo(int& r) { r = 10; }

int main()
{
	function<void()> f;

	int n = 0;

	//f = bind(&foo, n);
	f = bind(&foo, ref(n));	//n�� ������ ������ �޶�.
	f();

	cout << n << endl;
}


/*
void foo() { cout << "foo" << endl; }
void goo(int n) { cout << "goo" << n << endl; }

int main()
{
	// function : �Լ� �����Ϳ� ������ ��Ȱ�� �ϴ� ���ø�

	function<void()> f = &foo;
	f(); //foo()


	f = bind(&goo, 10);
	f();	//goo(10)
}
*/