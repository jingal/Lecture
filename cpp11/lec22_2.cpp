#include <iostream>
#include <type_traits>
#include <typeinfo>
#include <string>
#include <chrono>
#include <typeinfo>
#include <vector>
#include <boost/type_index.hpp>
#include <memory>
#include <functional>
#include <thread>

using namespace std;
using namespace std::chrono;
using namespace boost::typeindex;

///////////////////////////////////////////////////////////////////////////
//	22�� Deep Copy (���� ����)
///////////////////////////////////////////////////////////////////////////

class Cat
{
	char * name;
	int age;
public:
	
	Cat(const char* n, int a)
	{
		name = new char[strlen(n) + 1];
		strcpy(name, n);
	}

	~Cat() { delete[] name; }

	//���� ���縦 ������ ���� ������
	/*
	Cat(const Cat& c)
	{
		age = c.age;

		name = new char[strlen(c.name) + 1];
		strcpy(name, c.name);
	}
	*/

	//������ ����(Move Ownership)
	Cat(Cat& c)		//���� const�� ����.
	{
		age = c.age;
		name = c.name; //���� ����..

		c.name = 0;		//������ü�� �ּҸ� 0����..
						//�ڿ� ���簡 �ƴ� �ڿ� ����.
	}
};


int main()
{
	Cat c1("nami", 5);
	Cat c2 = c1;
}
