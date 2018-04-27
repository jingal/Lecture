//3_reference3

#include <iostream>

using namespace std;

struct Plus
{
	int operator()(int a, int b) const
	{
		return a + b;
	}
};


// 람다 표현식은 forwarding reference로 받아야 한다.
template<typename T> void foo(T&& f) 
{
	std::forward<T>(f(1, 2));
}

int main()
{
	Plus p;
	foo(p);

	foo([](int a, int b) {return a + b; });
}
