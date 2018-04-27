//3_reference2

#include <iostream>
using namespace std;

// int&		: int Ÿ���� lvalue�� ���� �� �ִ�. "lvalue reference"
// int&&	: int Ÿ���� rvalue�� ���� �� �ִ�. "rvalue reference"
// T&		: ��� Ÿ���� lvaule�� ���� �� �ִ�.
// T&&		: ��� Ÿ���� lvaule�� rvalue�� �� ���� �� �ִ�.	"forwarding reference"
//				lvalue�� ������ f4(int&)���� ����
//				rvalue�� ������ f4(int&&) ���� ����

void f1(int& a) {}
void f2(int&& a) {}

template<typename T> void f3(T& a) {}

/*
int main()
{
	int n = 0;

	//T�� Ÿ���� ����ڰ� ��������� �����ϴ� ���
	f3<int>(n);			//int	& => int&
	f3<int&>(n);		//int&	& => int&
	f3<int&&>(n);		//int&& & => int&

	//T Ÿ���� �������� ���� ���
	f3(n);				// T�� �� 3���� ��� ������ 
						// �����Ϸ��� int�� ����
	f3(10);				// error
}
*/

template<typename T> void f4(T&& a) {}

int main()
{
	int n = 10;

	//?�� n�Ǵ� 10�� �־� ������.
	
	f4<int>(10);		//int	&& => int&&
	f4<int&>(n);		//int&	&& => int&
	f4<int&&>(10);		//int&& && => int&&
						
	//Ÿ���� �������� ���� ���
	f4(n);				// T:int&		T&&: int&
	f4(10);				// T:int		T&&: int&&
}
