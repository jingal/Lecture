//2_int2type3 - 115 page

#include <iostream>
#include <type_traits>

using namespace std;

/*
// 정수개열만 가능
template<typename T, T N> struct integral_constant
{
	enum { value = N };
};

integral_constant<int, 0> n0;
integral_constant<int, 1> n1;
integral_constant<short, 0> s0;

typedef integral_constant<bool, false> false_type;
typedef integral_constant<bool, true> true_type;
// 그리고 is_pointer를 만들때
template<typename T> struct is_pointer : false_type {};
template<typename T> struct is_pointer<T*> : true_type {};
*/

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


int main()
{
	int *n = 0;
	print(n);
}