//1_auto2

#include <iostream>
using namespace std;

int main()
{
	int			n;	// n : �����̸�, Ÿ�� : int
	double		d;	// d :  �����̸�, Ÿ�� : double

	// �����̸� x, Ÿ�� : int[3]
	int x[3] = { 1,2,3 };

	// �Ʒ� �ڵ忡�� a�� d�� Ÿ���� ������ ������.
	auto a = x;
	// �ĺ� 1. int a[3] = x;	error
	// �ĺ� 2. int* a	= x;	�迭�� �迭�� 1��° �����
	//							�ּҷ� �Ͻ��� ����ȯ �Ǵ� �� 
	//							array to conversion

	decltype(x) d;		// int d[3]
	decltype(x) d = x;	// int d[3] = x �̹Ƿ� error
}