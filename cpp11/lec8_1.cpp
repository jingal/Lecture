#include <iostream>
#include <type_traits>
#include <vector>

using namespace std;

///////////////////////////////////////////////////////////////////////////
//	inherit constructor
///////////////////////////////////////////////////////////////////////////

class Base
{
public:
	void foo(int a) { cout << "int" << endl; }
	void foo(int, int) { cout << "int, int" << endl; }
};

class Derived : public Base
{
public:
	using Base::foo;
	// 자식이 fooㄹ르 만들면 부모의 함수를 가린다.
	void foo(double d) { cout << "double" << endl; }
};


int main()
{
	Derived d;
	d.foo(3.4);				// doubld
	d.foo(0);				// "int" --> double 
	d.foo(1, 2);			// "int, int"
}



