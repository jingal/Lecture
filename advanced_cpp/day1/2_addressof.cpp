//2_addressof.cpp - 책 7 page addressof
#include <iostream>
using namespace std;


class Point 
{
	int x = 0;
	int y = 0;
public:
	Point* operator&() const { return 0; }	// 내 주소를 알려하지 말라.
};

int main()
{
	//Point p;
	const Point p;
	cout << &p << endl;		//왜 주소가 나올까?

}
