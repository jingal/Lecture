//2_new - 103 page. generic container idioms

#include <iostream>
using namespace std;


struct Point
{
	int x, y;
	Point(int a, int b) : x(a), y(b) {}
};

// ���� : �Ʒ� �����̳ʸ� ����Ϸ��� ����Ʈ �����ڰ� �־�� 
//			�Ѵ�. - 103 page ���� �Ʒ�
template<typename T> class Vector
{
	T*  buff;
	int size;

public:
	Vector(int sz)
	{
		size = sz;
		buff = new T[sz];		// new Point[10]
	}
};

int main() 
{
	Vector<Point> v(10);	//�ɱ�?

}