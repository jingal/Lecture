//4_default

#include <iostream>
#include <atomic>
using namespace std;

struct Point
{
	int x, y;

	//Point() {}
	Point() = default;
};

int main()
{
	int n{};
	//Point p;				// value initialization : �����Ⱚ
	Point p{};				// default initialization : ��� ����� 0���� �ʱ�ȭ
							// C++ 11����

	cout << p.x << endl;	// �����Ⱚ
	cout << p.y << endl;
}