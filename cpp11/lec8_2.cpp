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
		using Animal::Animal;		// �θ��� �����ڸ� ��� �޴´�.
									// ������ ���
};

int main()
{
	Dog d;				//1��
	Dog d2(5);			
}



