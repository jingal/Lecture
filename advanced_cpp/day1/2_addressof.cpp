//2_addressof.cpp - å 7 page addressof
#include <iostream>
using namespace std;


class Point 
{
	int x = 0;
	int y = 0;
public:
	Point* operator&() const { return 0; }	// �� �ּҸ� �˷����� ����.
};

int main()
{
	//Point p;
	const Point p;
	cout << &p << endl;		//�� �ּҰ� ���ñ�?

}
