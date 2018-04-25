//5_SFINAE8
// SFINAE - Substitution Failure Is Not An Error

#include <iostream>
#include <type_traits>
using namespace std;

struct Test {
	//void foo() {} 
	int foo() { return 0; }

	Test(int a) {}
};

//Test xdeclval();
template<typename T> T&& xdeclval();

/*
int main()
{
	// �ӽð�ü
	//cout << sizeof( Test(0).foo() ) << endl;

	// xdeclval() : xdeclval�̶�� �Լ� ȣ��
	//cout << sizeof(xdeclval().foo()) << endl;

	// C++11 ǥ�ؿ� declval�� �ֽ��ϴ�.
	// www.cppreference.com���� declval �˻��� ������.
	cout << sizeof(declval<Test>().foo()) << endl;
}
*/


template<typename U> struct has_foo_function
{
	template<typename T>
	static char check(decltype(declval<T>().foo()) *);

	template<typename T> 
	static short check(...);

	enum { value = (sizeof(check<U>(0)) == sizeof(char)) };
};

int main()
{
	cout << has_foo_function<Test>::value << endl;
}