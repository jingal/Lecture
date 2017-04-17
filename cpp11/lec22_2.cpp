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
//	22강 Deep Copy (깊은 복사)
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

	//깊은 복사를 구현한 복사 생성자
	/*
	Cat(const Cat& c)
	{
		age = c.age;

		name = new char[strlen(c.name) + 1];
		strcpy(name, c.name);
	}
	*/

	//소유권 이전(Move Ownership)
	Cat(Cat& c)		//주의 const가 없다.
	{
		age = c.age;
		name = c.name; //얕은 복사..

		c.name = 0;		//원본객체의 주소를 0으로..
						//자원 복사가 아닌 자원 전달.
	}
};


int main()
{
	Cat c1("nami", 5);
	Cat c2 = c1;
}
