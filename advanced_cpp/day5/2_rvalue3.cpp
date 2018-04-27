//2_rvalue3

#include <iostream>
using namespace std;

// �� ��Ģ�� �߿��մϴ�. �� �ܿ� �μ���.
void foo(int& a) { cout << "int&" << endl; }
void foo(const int& a) { cout << "const int&" << endl; }
void foo(int&&a) { cout << "int&&" << endl; }


int main()
{
	int n = 10;
	foo(n);				//1��(int&) ȣ��, ������ 2��(const int&) ȣ��
	foo(10);			//3��(int&&)ȣ��, ������ 2�� ȣ��

	int& r = n;			
	foo(r);				//1��(int&) ȣ��, ������ 2��(const int&) ȣ��

	int&& r2 = 10;		// 10�� rvalue
						// �̸��� ����, r2 �� lvaule
						// "named rvalue reference is lvalue"
	foo(r2);			//1��(int&) ȣ��
	foo(static_cast<int&&>(r2));		//3�� ȣ��
}