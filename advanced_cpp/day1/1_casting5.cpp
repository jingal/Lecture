//1_casting5.cpp - å 7 page addressof

#include <iostream>

using namespace std;


class Animal {
public:
	// �����Լ��� ������ �����Լ� ���̺��� �����ǰ�
	// ���̺��� ���������� �ڽ��� � Ŭ���������� ������ �ִ�.
	// ��� : dynamci_cast�� ����Ϸ��� �Ѱ��̻��� �����Լ��� �ʿ��ϴ�.
	// dynamic_cast�� �θ�*�� �ٽ� �ڽ�*�� �ٲٰ� �������� ����Ѵ�.
	// ��Ÿ�� ������尡 ����. ����~~
	virtual ~Animal() {}
};

class Dog : public Animal
{
public:
	int color;

};

void foo(Animal *p)
{
	//p->color = 10;
	//p�� Dog*�� ĳ�����Ѵ�.

	//Dog *pDog = p;		//error

	// static_cat : ������ �ð� ĳ��Ʈ �̹Ƿ� 
	//				p�� ���� ������ ����Ű���� �� �� ����.

	Dog *pDog = static_cast<Dog*>(p);	// Compile OK
	cout << pDog << endl;
	//pDog->color = 10;

	//����ð��� p�� ����Ű�� �޸𸮸� �����ؼ� ĳ����
	Dog *pDog2 = dynamic_cast<Dog*>(p);	// 
	cout << pDog2 << endl;
}


int main()
{
	Dog		d; foo(&d);
	Animal	a; foo(&a);
}

