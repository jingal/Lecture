//2_addressof2.cpp - å 7 page addressof
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
	Point p;

	//p�� �ּҸ� �ų�����.
	&p;	//1. p.operator&() �̹Ƿ� ����

	//2. �����Ϸ��� �ӿ��� �Ѵ�. p�� �ٸ� Ÿ������
	//char c = static_cast<char>(p);	//error, �������� ��� ����

	//char c = reinterpret_cast<char>(p);	//
					// 1. ��ĳ������ �ȵȴ�.
					// 2. ĳ������ �����P �ӽð�ü�̴�.
	
	char* p1 = reinterpret_cast<char*>(&p);	
					// ������ ������ &p �����Ƿ� 0

	cout << (void*)p1<< endl;					

	char* p2 = &(reinterpret_cast<char&>(p));	//
	cout << (void*)p2 << endl;

	const Point pt;

	Point* p3 = reinterpret_cast<Point*>(
				&(reinterpret_cast<char&>(
					const_cast<Point&>(pt))));	//
	cout << (void*)p3 << endl;

	Point pt2;
	Point* pp = addressof(pt2);	//c++ 11 ���� ǥ��.

	cout << pp << endl;
}
