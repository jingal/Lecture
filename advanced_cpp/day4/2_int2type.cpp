//2_int2type - 115 page

#include <iostream>
#include <type_traits>

using namespace std;


//����(�����Ϳ���)�� ���� �ٸ� �ڵ带 �����ϴ� ���
// 1. is_pointer<T>::value�� if������ ����
//	���� : *v���� ǥ������ ����� �� ����
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
// 2. if constexpr ��� - c++17
template<typename T> void print(T v)
{
	if constexpr (is_pointer<T>::value)
		cout << v << " : " << *v << endl;
	else
		cout << v << endl;
}
*/

/*
// 3. ���ǿ� ���� �Լ��� ������ ���� �Ŀ�
//		���õ��� ���� �Լ��� ������ ���� �ʰ� - enable_if
//	���Ϲ� : typename enable_if<����, ��ȯŸ��>::type

template<typename T> 
typename enable_if<is_pointer<T>::value, void>::type print(T v)
{
	cout << "������" << endl;	// *v ��� ����
}

template<typename T> 
typename enable_if<! is_pointer<T>::value, void>::type print(T v)
{
	cout << "������ �ƴ�" << endl;
}
*/

// 4. �Լ� overloading ���
//		�⺻ �Լ����� ���ǿ� ���� _imp ������ �Լ��� ȣ��
//	���Ϲ� : typename enable_if<����, ��ȯŸ��>::type
//	���� : *v���� ǥ������ ����� �� ����
/*
template<int N> struct int2type
{
	enum { value = N };
};

template<typename T> void print_imp(T v, int2type<1>)
{
	cout << "������" << endl;	// *v ��� ����
}

template<typename T> void print_imp(T v, int2type<0>)
{
cout << "������ �ƴ�" << endl;
}
*/

//C++11 ���ʹ� int2type��ſ� 
// true_type / false_type ���� �����ε� �մϴ�.
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


template<typename T> void print(T v)
{
	//���ǿ� ���� �ٸ� �Լ� ȣ��	
	print_imp(v, int2type<is_pointer<T>::value>());
}


int main()
{
	int *n = 0;
	print(n);
}