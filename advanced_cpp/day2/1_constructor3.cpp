//1_������3 25 page

#include <iostream>
using namespace std;

// �ٽ�: �޸𸮿� ���̴� ������� ������ ȣ��
// 1. ��� Ŭ������ ��� ������		- BM()
// 2. ��� Ŭ������ ������			- Base()
// 3. �ڽ��� ����� ������			- M()
// 4. �ڽ��� ������.				- Derived()

// �� ������ ����ڰ� ������ �� ����.!!
// ���� �ʱ�ȭ ����Ʈ���� ȣ���ؼ� ������ ������� �ʴ´�.

struct BM { BM() { cout << "BM()" << endl; } };
struct M { M() { cout << "M()" << endl; } };

struct Base
{
	BM bm;
	Base() : bm() { cout << "Base()" << endl; }
};

struct Derived : public Base
{
	M m;
	Derived() : Base(), m() { cout << "Derived()" << endl; } // ������ �ٲ㵵 ȣ������� �ٲ��� ����
};


int main()
{
	Derived d; //ȭ�� ��� ��� ������ ������.
}