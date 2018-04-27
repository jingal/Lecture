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


// ���� ǥ������ forwarding reference�� �޾ƾ� �Ѵ�.
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
