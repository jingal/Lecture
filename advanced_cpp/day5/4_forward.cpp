//4_forward 

#include <iostream>
using namespace std;

void foo(int a) {}
void goo(int& a) { a = 20; }
void hoo(int&& a) {}

//�Լ� ȣ���� �����忡 �����ϰ� �ϴ� �Լ�
// perfect forwardng : �����Լ��� ���� ���ڸ� 
//						�����Լ����� �Ϻ��ϰ� �����ϴ� ���
// 1. �����Լ������� ���纻���� ������ �ȵȴ�. - ����
// 2. ������� �߰��Ǿ �ȵȴ�.
// 3. �ذ�å => T&&�� �ؾ� �Ѵ�.
template<typename F, typename T>
void lockAndCall(F f, T&& t)
{
	f(t);
}

int main()
{
	int n = 10;

	lockAndCall(foo, 10);		//(10)
	lockAndCall(goo, n);		//goo(n)
	lockAndCall(hoo, 10);		//hoo(10) //error
}