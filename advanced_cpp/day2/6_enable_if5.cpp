// 6_enable_if5 - 77 page

#include <iostream>
#include <type_traits>
using namespace std;


//enable_if를 사용하는 3가지 방법
// 1. 리턴 타입으로 활용
template<typename T> 
typename enable_if<is_pointer<T>::value>::type foo(T a) {}


// 2. 함수 인자에 활용 - 주로 생성자에서 활용
// void는 인자로 안되기에 void*를 만듬
template<typename T>
생성자(T a, 
	typename enable_if<is_pointer<T>::value>::type* = nullptr) {}


// 3. 템플릿 인자에 활용 - 함수의 모양이 간결한 장점이 있다.
template<typename T, 
			typename U = typename enable_if<is_pointer<T>::value>::type>
void foo(T a) {}



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