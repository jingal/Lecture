// 6_enable_if4 - 77 page

#include <iostream>
#include <type_traits>
using namespace std;

/*
template<typename T> void print(T a)
{
	// 아래 코드는 조건을 만족하지 못해도
	// 컴파일을 하게 된다. int a에서
	// *가 될 수 없으므로 error
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
	print(n);		// 1. 에러의 원인.
	print(&n);
}

// 왜 에러일까요??? 잘 생각해 보세요.