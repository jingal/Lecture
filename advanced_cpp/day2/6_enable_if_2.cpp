// 6_enable_if2 - 77 page

#include <iostream>
#include <type_traits>
using namespace std;

// �ٽ�
// 1. static_assert : ������ �������� ���� ��� ������ error
// 2. enable_if : ������ �������� ���� ��� �ڵ� ���� ����.
//					������ �̸��� �ٸ� �Լ��� �ִٸ� ��밡��.

/*
template<typename T>
void foo(T a)
{
	//�� �Լ� a�� ���� �迭 �϶��� �����ؾ� �մϴ�.

	static_assert(is_integral<T>::value, "error");
	cout << "T" << endl;
}
*/
template<typename T> 
typename enable_if<is_integral<T>::value, T>::type foo(T a)
{
	cout << "T" << endl;
}

void foo(double d)
{	
	cout << "�Ǽ� ����" << endl;
}


int main()
{
	//foo(3);
	foo(3.3f);
}
