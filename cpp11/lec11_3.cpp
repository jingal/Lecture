#include <iostream>
#include <type_traits>
#include <vector>

using namespace std;

///////////////////////////////////////////////////////////////////////////
//	default function
///////////////////////////////////////////////////////////////////////////

class Point
{
public:
	int x, y;

	Point(int a, int b) {}

	//Point() {}
	Point() = default;			// ����ڰ� �ƹ��͵� ���Ұ�쿡�� default�� ���
};


int main()
{
	Point p1;
	Point p2(1, 2);

	Point p3{};
	cout << p3.x << endl;

	Point p1 = { 1,1 };
}
