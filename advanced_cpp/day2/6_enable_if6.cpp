// 6_enable_if6 - 77 page

#include <iostream>
#include <type_traits>
using namespace std;


template<typename T> void print(T a)
{
	//if (is_pointer<T>::value)				// if(false)
	// ������ �ð� if��.. ������ ���縦 ������ �ð��� ����
	// false�� ������ ������ ����
	// c++ 17, ������ Ÿ�� ����� ��� ����
	if constexpr (is_pointer<T>::value)
		cout << a << " : " << *a << endl;
	else
		cout << a << endl;
}

typename enable_if<!is_pointer<T>::value, void>::type foo(T a)
{
	//...
}

int main()
{
	int n = 10;
	print(n);		// 1. ������ ����.
	print(&n);
}