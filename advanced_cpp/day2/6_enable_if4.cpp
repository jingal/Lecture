// 6_enable_if4 - 77 page

#include <iostream>
#include <type_traits>
using namespace std;

/*
template<typename T> void print(T a)
{
	// �Ʒ� �ڵ�� ������ �������� ���ص�
	// �������� �ϰ� �ȴ�. int a����
	// *�� �� �� �����Ƿ� error
	if (is_pointer<T>::value)				// if(false)
		cout << a << " : " << *a << endl;
	else
		cout << a << endl;
}
*/
/*
typename enable_if<!is_pointer<T>::value, void>::type foo(T a)
{
	//...
}
*/

template<typename T> 
typename enable_if<is_pointer<T>::value>::type 
print(T a)
{
	cout << a << " : " << *a << endl;
}

template<typename T>
typename enable_if<!is_pointer<T>::value>::type
print(T a)
{
	cout << a << endl;
}


int main()
{
	int n = 10;
	print(n);		// 1. ������ ����.
	print(&n);
}

// �� �����ϱ��??? �� ������ ������.