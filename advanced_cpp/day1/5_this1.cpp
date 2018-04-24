//5_this

#include <iostream>
#include <vector>
using namespace std;

class Point
{
	int x, y;

public:
	void set(int a, int b)		// set(Point* const this, int a, int b)
	{
		//this = (Point*p)10;
		x = a;			//this->x = a;
		y = b;			//this->y = b;
	}

	void print() const		// print(const Point* const this)
	{
		x = 10;		//error this->x = 10, 
		//static_cast<const 파생클래스*>(this);
	}
};

int main() 
{
	Point p1, p2;
	p1.set(10, 20);			//set(&p1, 10, 20)로 변경됩니다.
							// push 20
							// push 10
							// mov ecx, &p1
							// call Point::set
}