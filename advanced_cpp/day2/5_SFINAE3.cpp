//5_SFINAE3
// SFINAE - Substitution Failure Is Not An Error

#include <iostream>
using namespace std;

// unevaluated expression (�򰡵��� �ʴ� ǥ����) ����

// ����ð��� ��������� �ʴ� ǥ���ĵ�.
// sizeof(foo()), decltype(foo()), typeid(foo()), 

// sizeof(�Լ�ȣ��) : � �Լ��� ȣ���ϴ��� �����Ҷ� �θ� ����ϴ� ���
//						�Լ� �����ΰ� ��� �������.

short foo(int a);	//{ return 0; }
char foo(double a); //{ return 0; }

int main()
{
	//int n = sizeof(foo(0));		// � �ǹ��ϱ��?
									// �Լ��� ����Ǿ��� �� ��ȯ���� ũ��
									// n = 2;
									// sizeof�� ������, ������ Ÿ�ӿ� ����
	int n = sizeof(foo(0.0));		// n =1

	cout << n << endl;	
}