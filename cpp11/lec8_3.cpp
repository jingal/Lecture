#include <iostream>
#include <type_traits>
#include <vector>

using namespace std;

///////////////////////////////////////////////////////////////////////////
//	Delegate constructor
///////////////////////////////////////////////////////////////////////////

class Point
{
public:
	int x, y;

	Point(int a, int b) : x(a), y(b) {}

	Point() : Point(0,0)	// "���� ������"
	{
		//Point(0, 0);		// �ٸ� ������ ȣ���� �ƴϰ�.. Point�� �ӽ� ��ü�� ����� ǥ��..
							// �ӽð�ü�� ����

	}
};

int main()
{
	Point p;
	cout << p.x << "," << p.y << endl;
}



