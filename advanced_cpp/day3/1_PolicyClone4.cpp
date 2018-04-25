// 1_PolicyClone4 - 183 page

#include <iostream>
#include <vector>
using namespace std;


struct Point
{
	int x, y;

	Point() { cout << "Point()" << endl; }
	Point(int a, int b) : x(a), y(b) { cout << "Point()" << endl; }
	~Point() { cout << "~Point()" << endl; }
};


int main()
{
	allocator<Point> ax;		//C++ ǥ�� �޸� �Ҵ��

	Point* p = ax.allocate(10);

	for(int i = 0; i < 10; i++)
		ax.construct(&p[i]);

	for (int i = 0; i < 10; i++)
		ax.destroy(&p[i]);

	ax.deallocate(p, 10);

}


