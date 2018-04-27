//2_rvalue2

#include <iostream>
using namespace std;


struct Point {
	int x, y;
};

int main()
{
	int n = 10;
	
	// ��Ģ 1. ���� lvalue reference�� lvalue�� ����Ų��.
	//int& r1 = n;		//ok
	//int& r2 = 10;		//error


	// ��Ģ 2. ��� lvalue reference�� lvalue/rvalue ��� ����Ų��.
	// ���� : ����ų���� ������ ������� �߰��ȴ�.	
	//const int& r1 = n;		//ok
	//const int& r2 = 10;		//ok
	//const Point& r3 = Point();		//ok

	// ��Ģ 3. C++11 rvalue reference�� ������� 
	//			���� rvalue�� ����ų �� �ִ�.
	//			lvalue�� ����ų �� ����.
	// ���� : 
	//int&& r1 = n;				//error
	int&& r2 = 10;				//ok
	Point&& r3 = Point();		//ok

	r2 = 30;
	r3.x = 10;

}