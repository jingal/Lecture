//4_참조계수1

#include <iostream>
#include <vector>
using namespace std;

class Car
{
public:
	~Car() { cout << "~Car" << endl; }
};

vector<Car*> v;

void foo()
{
	Car* p = new Car;
	v.push_back(p);

	//더 이상 p가 필요없다.
	delete p;	//지우도 될까?
}

int main()
{
	foo();
}