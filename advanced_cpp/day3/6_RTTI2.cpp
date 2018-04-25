//5_RTTI2 - 35 page

#include <iostream>
#include <string>
using namespace std;

// ��Ģ 1. ��� Ŭ�������� �ڽ��� ������ ���� static ������
//			�־�� �Ѵ�. (C++ǥ���� type_info��Ȱ)
// ��Ģ 2. (1)�� static ������ ��ȯ�ϴ� �����Լ��� �־�� �Ѵ�.
//			C++ǥ���� typeid��Ȱ
struct Animal
{
	int age;

	virtual const string& getInterfaceDescriptior() {
		return Animal::description;
	}
	static const string description;		//�ڽſ� ���� ���� ����	
};

const string Animal::description = "Animal";

struct Dog : public Animal
{
	virtual const string& getInterfaceDescriptior() {
		return Dog::description;
	}

	static const string description;		//�ڽſ� ���� ���� ����	
};
const string Dog::description = "Dog";

int main()
{
	Animal a1, a2;	
	Dog d;

	Animal*p = &d;

	// p�� ��� ��ü�� ����Ű���� ����..
	if (p->getInterfaceDescriptior() == Dog::description)
	{
		cout << p->getInterfaceDescriptior() << endl;
		cout << "Dog" << endl;
	}

}