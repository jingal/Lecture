#include <iostream>
#include <type_traits>
#include <vector>

using namespace std;

///////////////////////////////////////////////////////////////////////////
//	inherit constructor
///////////////////////////////////////////////////////////////////////////

class Animal 
{
	int age;
public:
	Animal(int a) : age(a) {}
};

class Dog : public Animal
{
	public:
		Dog() : Animal(1) {}
		//Dog(int a) : Animal(a) {}		   
		using Animal::Animal;		// 부모의 생성자를 상속 받는다.
									// 생성자 상속
};

int main()
{
	Dog d;				//1살
	Dog d2(5);			
}



