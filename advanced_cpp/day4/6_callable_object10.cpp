// 6_callableobject10

#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	int x[10] = { 1,2,3,4,5,6,7,8,9,10 };
	// ����ǥ���� Ȱ��
	// 1. �Լ����ڷ� ����, ��κ� ���(���� 70% ������ ���)
	for_each(x, x + 10, [](int a) {});

	// 2. �ٷ� ȣ�� (���ǻ�� ����)
	[]() {cout << "hello" << endl; }();

	// 3. ������ ��Ƽ� �Լ�ó�� ���
	int n1 = 0;
	auto f = [n1](int a, int b) {return a + b; };
				// class xxx, xxxx();

	cout << f(1, 2) << endl;	//3

	cout << sizeof(f) << endl;
}

// �ȵ���̵��ڵ�/base/scopedguard_test.cpp