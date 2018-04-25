//5_RTTI - 35 page

#include <iostream>
using namespace std;

struct Animal 
{
	int age;

	// RTTI�� ����Ϸ��� �ݵ�� �����Լ��� �Ѱ� �̻� 
	// �־�� �ϴ�.
	virtual ~Animal() {}	
};

struct Dog : public Animal
{
	int age;
	virtual void goo() {}
};

void foo(Animal* p)
{
	// p�� � ��ü�� ����Ű���� �˰� �ʹ�.
	// typeid : Ÿ�Կ� ������ ���� ��ü�� ��ȯ�Ѵ�.
	//			��ȯ���� �ݵ�� const ������ �޾ƾ� �Ѵ�.
	const type_info& t = typeid(*p);
	cout << t.name() << endl;
}

int main()
{	
	Animal a; foo(&a);
	Dog d; foo(&d);
}