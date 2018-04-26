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
	foo(1);			//0�� 1�� ��� ���� Ÿ��(int)
					// foo(0)�� foo(1)�� ��� ���� �Լ� ȣ��
	int2type<0> t0;
	int2type<1> t1;

	foo(t0);
	foo(t1);		// t0, t1�� �ٸ� Ÿ��
					// foo(t0)�� foo(t1) �ٸ� �Լ� ȣ��
}