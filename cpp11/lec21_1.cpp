#include <iostream>
#include <type_traits>
#include <typeinfo>
#include <string>
#include <chrono>
#include <typeinfo>
#include <vector>
#include <boost/type_index.hpp>

using namespace std;
using namespace std::chrono;
using namespace boost::typeindex;

///////////////////////////////////////////////////////////////////////////
//	21�� Perfect forwarding Ȱ��
///////////////////////////////////////////////////////////////////////////

class Point
{
	int x, y;

public:
	Point(int a = 0, int b = 0) { cout << "Point()" << endl; }
	~Point()					{ cout << "~Point()" << endl; }
	Point(const Point& p) { cout << "Point(const Point& p)" << endl; }	
};

int main()
{
	vector<Point> v;

	// vector�� ��� �ֱ� 1
	//Point p(1, 2);
	//v.push_back(p);		// ���������� �����ؼ� heap�� ����, ������ �ι� �Ҹ�


	//�ӽð�ü�� �ֱ�.. 2
	//v.push_back(Point(1, 2));	//v.push_back({1,1});


	//������ ���ڸ� �����ؼ� v�� ���������� Point�� ����� �Ѵ�.
	v.emplace_back(1, 2);
}