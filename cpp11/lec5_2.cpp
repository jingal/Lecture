#include <iostream>

using namespace std;


// ��ȯ ������ : Complex => �ٸ� Ÿ�� : operator �ٸ�Ÿ��()
// ��ȯ ������ : Complex <= �ٸ� Ÿ�� : Complex (�ٸ� Ÿ��)

class Complex
{
	int re;
	int im;

public:
	Complex() : re(0), im(0) {}
	Complex(int a, int b) : re(a), im(b) {}

	//���� �ϳ��� ������ ������ : ��ȯ������.. �ٸ� Ÿ���� ��ü�� ��ȯ�ǰ� �Ѵ�.
	Complex(int a) : re(a), im(0) {}

	//��ȯ ������ : ��ü�� �ٸ� Ÿ������ ��ȯ�ǰ� �Ѵ�.
	//	Ư¡ : ���� Ÿ���� ǥ������ �ʴ´�.
	operator int() { return re; }
};


int main()
{
	int n = 0;
	Complex c1;
	Complex c2(1, 2);

	n = c2;		//c2.operator int() �Լ��� ã�´�..
	c2 = n;		//n.operator Complex()�� ������ �ȴ�... �׷���, n�� ��ü�� �ƴϴ�.

	cout << n << endl;
}