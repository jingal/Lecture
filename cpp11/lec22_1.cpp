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
//	22°­ Shallow Copy (¾èÀº º¹»ç)
///////////////////////////////////////////////////////////////////////////

class Cat
{
	char * name;
	int age;
public:
	Cat(const char* n, int a)
	{
		name = new char[strlen(n)];
		strcpy(name, n);
	}

	~Cat() { delete[] name; }
};


int main()
{
	Cat c1("nami", 5);
	Cat c2 = c1;
}
