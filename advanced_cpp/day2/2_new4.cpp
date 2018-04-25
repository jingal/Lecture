//2_new4 - 103 page. generic container idioms

#include <iostream>
#include <vector>
using namespace std;


struct Point
{
	int x, y;
	Point(int a, int b) : x(a), y(b)
	{
		cout << "Point()" << endl;
	}

	//Point(const Point& p) { cout << "복사생성자" << endl; }
};


int main()
{
	Point p(0, 0);
	//vector<Point> v(10, p);	//될까?
	//v.resize(20, p);

	vector<Point> v(10, p);
	v.resize(20, p);	
}