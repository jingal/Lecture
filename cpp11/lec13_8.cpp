#include <iostream>
#include <type_traits>
//#include <vector>

using namespace std;

///////////////////////////////////////////////////////////////////////////
//	aggregate initialization
///////////////////////////////////////////////////////////////////////////

struct Point
{
	int x;
	int y;

	// �����ڰ� ���� ��� ����ü
	//	Point() {}
	//	Point(int a, int b) : x(a), y(b) { cout << "int, int" << endl; }


	//	Point() {}
	//	Point(int a, int b) : x(a), y(b) { cout << "int, int" << endl; } 
	//	p2���� ���� �߻�
	//

	//Point() = default;		: aggregate

	//virtual void foo() {}		: aggregate

	void foo() {}				//: aggregate
};

int main()
{
	Point p1;				//ok
	Point p2 = { 1,1 };		//ok


	int x[10] = { 1,2,3 };

	//aggregate : �迭, ����ü
}

