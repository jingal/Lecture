// 6_enable_if3 - 77 page

#include <iostream>
#include <type_traits>
using namespace std;

// type traits : Ÿ���� �Ӽ��� �����ϴ� ���̺귯��
//					<type_traits>
//					������ �Ӽ�<Ÿ��>::value
//					is_abstact<T>::value
//					

/*
template<typename T> void foo(T a)
{
	static_assert(!is_pointer<T>::value, "error");
	//...
}
*/
// ������ �������� ���Ҷ�..
// ������ �ƴ϶� �ĺ������� ���� (�ڵ���� ����)
// SFINAE ����� �ʿ��ϴ�.


template<typename T> 
typename enable_if<!is_pointer<T>::value, void>::type foo(T a)
{	
	//...
}


void foo(...) { cout << "����Ʈ ó��" << endl; }

int main()
{
	int n = 10;
	foo(&n);
}
