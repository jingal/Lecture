#include <iostream>
#include <type_traits>
#include <vector>

using namespace std;

///////////////////////////////////////////////////////////////////////////
//	override
///////////////////////////////////////////////////////////////////////////

template<typename T> class Base
{
public:
	virtual void foo(const T a) { cout << "Base::foo" << endl; }
};


class Derived : public Base<int*>
{
public:
	virtual void foo(int* a) { cout << "Derived::foo" << endl; }
};



int main()
{
	Base<int*>* p = new Derived;
	p->foo(0);		// Derived::foo 나와야 한다.
}