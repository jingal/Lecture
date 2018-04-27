//4_forward4

#include <iostream>
using namespace std;


void hoo(int&& a) {}
void foo(int& a) {}

template<typename F, typename ... T>
decltype(auto) lockAndCall(F&& f, T&& ...t)
{
	return (std::forward<F>(f)) (std::forward<T>(t)...);
	// C++ 17
	//return invoke((std::forward<F>(f)), 
	//				(std::forward<T>(t) ...));
}

int main()
{
	int n = 10;

	lockAndCall([](int a) { cout << a << endl; }, n);		// T : int
	lockAndCall(foo, n);									// T : int
	lockAndCall(hoo, 10);									// T : int&&

	//lockAndCall(&Test::foo, &t, 1);
}

/*
class Test
{
public:
	void foo() & { cout << "LVALUE" << endl; }
	void foo() && { cout << "RVALUE" << endl; }
};

void main()
{
	Test t;
	t.foo();			//1

	Test().foo();		//2
}
*/
