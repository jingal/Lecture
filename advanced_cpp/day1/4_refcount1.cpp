//4_�������1

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

	//�� �̻� p�� �ʿ����.
	delete p;	//���쵵 �ɱ�?
}

int main()
{
	foo();
}