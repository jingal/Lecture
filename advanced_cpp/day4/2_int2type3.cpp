//2_int2type3 - 115 page

#include <iostream>
#include <type_traits>

using namespace std;

/*
// ���������� ����
template<typename T, T N> struct integral_constant
{
	enum { value = N };
};

integral_constant<int, 0> n0;
integral_constant<int, 1> n1;
integral_constant<short, 0> s0;

typedef integral_constant<bool, false> false_type;
typedef integral_constant<bool, true> true_type;
// �׸��� is_pointer�� ���鶧
template<typename T> struct is_pointer : false_type {};
template<typename T> struct is_pointer<T*> : true_type {};
*/

template<typename T> void print_imp(T v, true_type)
{
	cout << "������" << endl;	// *v ��� ����
}

template<typename T> void print_imp(T v, false_type)
{
	cout << "������ �ƴ�" << endl;
}


template<typename T> void print(T v)
{
	//���ǿ� ���� �ٸ� �Լ� ȣ��	
	print_imp(v, is_pointer<T>());
}


int main()
{
	int *n = 0;
	print(n);
}