//2_int2type2 - 115 page

#include <iostream>
#include <type_traits>

using namespace std;

template<int N> struct int2type
{
	enum { value = N };
};

void foo(int a) {
	cout << "int" << endl;
}

void foo(int2type<0>) {
	cout << "0" << endl;
}

void foo(int2type<1>) {
	cout << "1" << endl;
}

int main()
{
	foo(0);
	foo(1);			//0과 1은 모두 같은 타입(int)
					// foo(0)과 foo(1)은 모두 같은 함수 호출
	int2type<0> t0;
	int2type<1> t1;

	foo(t0);
	foo(t1);		// t0, t1은 다른 타입
					// foo(t0)와 foo(t1) 다른 함수 호출
}