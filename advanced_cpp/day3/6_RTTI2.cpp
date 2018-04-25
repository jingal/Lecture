//5_RTTI2 - 35 page

#include <iostream>
#include <string>
using namespace std;

// 규칙 1. 모든 클래스에는 자신의 정보를 담은 static 변수가
//			있어야 한다. (C++표준의 type_info역활)
// 규칙 2. (1)의 static 변수를 반환하는 가상함수가 있어야 한다.
//			C++표준의 typeid역활
struct Animal
{
	int age;

	virtual const string& getInterfaceDescriptior() {
		return Animal::description;
	}
	static const string description;		//자신에 대한 정보 보관	
};

const string Animal::description = "Animal";

struct Dog : public Animal
{
	virtual const string& getInterfaceDescriptior() {
		return Dog::description;
	}

	static const string description;		//자신에 대한 정보 보관	
};
const string Dog::description = "Dog";

int main()
{
	Animal a1, a2;	
	Dog d;

	Animal*p = &d;

	// p가 어느 객체를 가리키는지 조사..
	if (p->getInterfaceDescriptior() == Dog::description)
	{
		cout << p->getInterfaceDescriptior() << endl;
		cout << "Dog" << endl;
	}

}