//5_RTTI - 35 page

#include <iostream>
using namespace std;

struct Animal 
{
	int age;

	// RTTI를 사용하려면 반드시 가상함수가 한개 이상 
	// 있어야 하다.
	virtual ~Animal() {}	
};

struct Dog : public Animal
{
	int age;
	virtual void goo() {}
};

void foo(Animal* p)
{
	// p가 어떤 객체를 가리키는지 알고 싶다.
	// typeid : 타입에 정보를 담은 객체를 반환한다.
	//			반환값은 반드시 const 참조로 받아야 한다.
	const type_info& t = typeid(*p);
	cout << t.name() << endl;
}

int main()
{	
	Animal a; foo(&a);
	Dog d; foo(&d);
}