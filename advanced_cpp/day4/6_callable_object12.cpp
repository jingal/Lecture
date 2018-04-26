// 6_callable_object12

#include <iostream>
#include <algorithm>
using namespace std;


int main()
{	

	// �ѹ� �ʱ�ȭ �� ���ٺ����� ���� �Ұ���
	auto f1 = [](int a, int b) { return a + b; };
	auto f2 = [](int a, int b) { return a + b; };

	//f1�� f2�� ����? �ٸ�? Ÿ��
	cout << typeid(f1).name() << endl;
	cout << typeid(f2).name() << endl;

	//f1 = [](int a, int b) { return a + b; };	// error, �ٸ� Ÿ���̹Ƿ� ���� �ȵ�

	int n1 = 0;
	decltype(n1) n2;		//ok... int n2;

	//decltype(f1) f3;			// error, Clouser���� Default �����ڰ� �����Ǿ� ����
	decltype(f1) f3(f1);		// ok,�����Ϸ��� ������ִ� Ŭ��� ���� �����ڰ� �ֱ� ������ OK

	int(*f)(int, int) = f1;		//ok. �Լ� �����ͷ� ��ȯ ����
								// f1.operator int(*)(int, int)�� ��ȯ�� ������ִ� ��ȯ������ �Լ� ����
}
// cppreference.com "lambda" �˻�
// https://isocpp.org/