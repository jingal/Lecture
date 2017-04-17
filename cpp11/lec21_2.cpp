#include <iostream>
#include <type_traits>
#include <typeinfo>
#include <string>
#include <chrono>
#include <typeinfo>
#include <vector>
#include <boost/type_index.hpp>
#include <memory>

using namespace std;
using namespace std::chrono;
using namespace boost::typeindex;

///////////////////////////////////////////////////////////////////////////
//	21�� Perfect forwarding Ȱ�� #2
///////////////////////////////////////////////////////////////////////////

void* operator new(size_t sz)
{
	cout << "new" << endl;
	return malloc(sz);
}

void operator delete(void* p) { free(p); }


class Point
{
	int x, y;

public:
	//Point(int a = 0, int b = 0) {}
	Point(int a, int b) {}
};

int main()
{
	//shared_ptr<Point> p1(new Point(1, 1));		// new ���� �޸��Ҵ�, share_ptr �����ڿ��� �Ҵ�

	//sizeof(Point) + sizeof(������ü)�� �ѹ� �޸� �Ҵ�
	//shared_ptr<Point> p2 = make_shared<Point>();
	shared_ptr<Point> p2 = make_shared<Point>(1,1);	//�Ϻ��� �����ڷ� 
}
