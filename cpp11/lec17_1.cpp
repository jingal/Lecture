#include <iostream>
#include <type_traits>
#include <typeinfo>
#include <string>
#include <chrono>
//#include <vector>
//#include <boost\\type_index.hpp>

using namespace std;
using namespace std::chrono;

///////////////////////////////////////////////////////////////////////////
//	Temporay object (�ӽ� ��ü�� ����� ������ ����)
///////////////////////////////////////////////////////////////////////////

class Point
{
	int x, y;

public:
	Point(int a = 0, int b = 0) { cout << "Point()" << endl; }
	~Point()					{ cout << "~Point()" << endl; }
};

int main()
{
	//Point(0, 0);	//	1. ��������� ����� �ӽð�ü, �̸��� ����.

	//Point p(0, 0);	// 2. ������ü, �̸��� �ִ�.

	Point(0, 0), cout << "X" << endl;

	cout << "A" << endl;
}


/*
//�ӽð�ü����
int main()
{
	int a = 20, b = 10;

	int c = (a + b) * (a - b);		// int temp1 = a+b;
									// int temp2 = a-b;
									// c = temp1 * temp2;
}
*/
