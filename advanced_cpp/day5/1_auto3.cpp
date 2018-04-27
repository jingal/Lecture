//1_auto3

#include <iostream>
using namespace std;

int foo() {}
int& goo() {}

//foo() = 10;	//error
//goo() = 10;	//ok
// �ٽ� : ��ȣ�� ���ʿ� ������ (lvalue) ������ ���ϵǾ�� �Ѵ�.

int main()
{
	int	n;
	int* p = &n;

	// 1. ���� �̸��� ���� �� : ���� ������ ���ؼ� �߷�
	decltype(n) d1;		//int
	decltype(p) d2;		//int*

	// 2. ������ ������ ǥ����(expression)�� ���� ��
	//		ǥ������ lvalue�� : ����
	//					lvalue�� �� �� ������ : �� (int)
	decltype(*p) d3;		// *p = 30, int&
	decltype(n + n) d4;		// n+n �� ���ʿ� �� �� ����. int


	decltype((n)) d5;		// (n) = 10 �� �� �ִ�. int&

	decltype(n++) d6;		// �Լ��� ������ temp�� ����� n++ �� �Ŀ� temp �� ����, 
							// int : n++ = 10�� �� �� ����.
	decltype(++n) d7;		// n = n+1�� ����
							// int& : ++n = 10�� �� �� �ִ�.

	int x[3] = { 1,2,3 };		
	decltype(x[0]) d8; 		// int&
}