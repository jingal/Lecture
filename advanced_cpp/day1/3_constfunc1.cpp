//3_상수함수 - 아주 기본이지만 중요한 문법

#include <iostream>
using namespace std;

struct Point
{
	int x = 0;
	int y = 0;
	
	void set(int a, int b)
	{
		x = a;
		y = b;
	}

	void print() const		//이 함수는 값을 변경하지 않는 함수이다.
	{
		//x = 10; //error
		cout << x << endl;
	}
};

int main()
{
	const Point p;

	p.x = 10;			//error, p는 상수
	p.set(10, 20);		//error, 
	p.print();			//호출되게 하려면 상수함수 이어야 한다.

	//상수 객체는 상수 멤버 함수만 호출가능.

	//p.set(10, 20);
	//p.print();
}