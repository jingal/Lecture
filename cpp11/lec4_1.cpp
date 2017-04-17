#include <iostream>

using namespace std;

class Point {
	int x, y;

public:
	Point() { cout << "Point()" << endl; }
	~Point() { cout << "~Point()" << endl; }
};

void * operator new(size_t sz)
{
	cout << "my new" << endl;
	return malloc(sz);
}

void operator delete(void* p)  noexcept
{
	cout << "my delete" << endl;
	free(p);
}

void * operator new(size_t sz, const char* s, int n)
{
	cout << "my new2" << endl;
	return malloc(sz);
}

int main()
{

	int* p2 = new("abc", 3) int;

	int *p1 = new int;			// 1. operator new(sizeof(int))
								// 2. ������ ȣ��.
								// 3. return static_cast<int*>(�ּ�)

	delete p1;
}

/*
int main()
{
	Point* p = static_cast<Point*>(operator new(sizeof(Point)));
	//Point *p = new Point;			//1. �޸��Ҵ�. operator new() �Լ����
									//2. ������ ȣ��
									//3. return static_cast<Point*>(�ּ�)

	cout << p << endl;

	operator delete(p);


	//delete p;						// 1.�Ҹ��� ȣ��,
									// 2. �޸� ����, operator delete() �Լ� ���.
}
*/