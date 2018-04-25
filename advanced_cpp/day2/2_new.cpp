//2_new - 103 page. generic container idioms

#include <iostream>
using namespace std;


struct Point
{
	int x, y;
	Point(int a, int b) : x(a), y(b) {}
};

// 단점 : 아래 컨테이너를 사용하려면 디폴트 생성자가 있어야 
//			한다. - 103 page 제일 아래
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
	Vector<Point> v(10);	//될까?

}