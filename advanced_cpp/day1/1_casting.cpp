//1_casting.cpp - å 7 page addressof

#include <iostream>

using namespace std;

// C ĳ������ ������1
/*
int main()
{
	int n = 4;
	//double* p = &n;			// error. ���� �ٸ� Ÿ���� �ּҴ� ���� �� ����.
	double* p = (double*)&n;	// compile OK, 
	
	*p = 3.4;
}
*/

// Cĳ������ ������ 2
int main()
{
	//const int c = 10;	// ������ �ð� ���
						// ��ũ�� ó�� ��� �ȴ�.
						// �����Ϸ��� ������ �߿� �ϴܿ� �ִ� c�� 10�� ġȯ��Ŵ

	int n = 10;			// 
	const int c = n;	// ����ð� ���.
						// �ʱⰪ�� ������ �ð��� �� �� ����.

	//int *p = &c;		// �� ������ ������ ���ô�.
						//error
	int *p = (int*)&c;

	*p = 20;

	cout << c << endl;		//10	20
	cout << *p << endl;		//20	20
}