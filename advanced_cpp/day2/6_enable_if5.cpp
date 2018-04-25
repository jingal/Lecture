// 6_enable_if5 - 77 page

#include <iostream>
#include <type_traits>
using namespace std;


//enable_if�� ����ϴ� 3���� ���
// 1. ���� Ÿ������ Ȱ��
template<typename T> 
typename enable_if<is_pointer<T>::value>::type foo(T a) {}


// 2. �Լ� ���ڿ� Ȱ�� - �ַ� �����ڿ��� Ȱ��
// void�� ���ڷ� �ȵǱ⿡ void*�� ����
template<typename T>
������(T a, 
	typename enable_if<is_pointer<T>::value>::type* = nullptr) {}


// 3. ���ø� ���ڿ� Ȱ�� - �Լ��� ����� ������ ������ �ִ�.
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
	print(n);		// 1. ������ ����.
	print(&n);
}

// �� �����ϱ��??? �� ������ ������.