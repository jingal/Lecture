//2_int2type - 115 page

#include <iostream>
#include <type_traits>

using namespace std;


//조건(포인터여부)에 따라 다른 코드를 수행하는 방법
// 1. is_pointer<T>::value를 if문으로 조사
//	단점 : *v등의 표현식을 사용할 수 없다
/*
template<typename T> void print(T v)
{
	if(is_pointer<T>::value)
		cout << v << " : " << *v << endl;
	else
		cout << v << endl;
}
*/

/*
// 2. if constexpr 사용 - c++17
template<typename T> void print(T v)
{
	if constexpr (is_pointer<T>::value)
		cout << v << " : " << *v << endl;
	else
		cout << v << endl;
}
*/

/*
// 3. 조건에 따라 함수를 여러개 만든 후에
//		선택되지 않은 함수를 컴파일 되지 않게 - enable_if
//	리턴문 : typename enable_if<조건, 반환타입>::type

template<typename T> 
typename enable_if<is_pointer<T>::value, void>::type print(T v)
{
	cout << "포인터" << endl;	// *v 사용 가능
}

template<typename T> 
typename enable_if<! is_pointer<T>::value, void>::type print(T v)
{
	cout << "포인터 아님" << endl;
}
*/

// 4. 함수 overloading 사용
//		기본 함수에서 조건에 따라 _imp 버전의 함수를 호출
//	리턴문 : typename enable_if<조건, 반환타입>::type
//	단점 : *v등의 표현식을 사용할 수 없다
/*
template<int N> struct int2type
{
	enum { value = N };
};

template<typename T> void print_imp(T v, int2type<1>)
{
	cout << "포인터" << endl;	// *v 사용 가능
}

template<typename T> void print_imp(T v, int2type<0>)
{
cout << "포인터 아님" << endl;
}
*/

//C++11 부터는 int2type대신에 
// true_type / false_type 으로 오버로딩 합니다.
template<typename T> void print_imp(T v, true_type)
{
cout << "포인터" << endl;	// *v 사용 가능
}

template<typename T> void print_imp(T v, false_type)
{
cout << "포인터 아님" << endl;
}


template<typename T> void print(T v)
{
//조건에 따라 다른 함수 호출
print_imp(v, is_pointer<T>());
}


template<typename T> void print(T v)
{
	//조건에 따라 다른 함수 호출	
	print_imp(v, int2type<is_pointer<T>::value>());
}


int main()
{
	int *n = 0;
	print(n);
}