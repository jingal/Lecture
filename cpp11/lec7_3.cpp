#include <iostream>
#include <type_traits>
#include <vector>

using namespace std;

///////////////////////////////////////////////////////////////////////////
//	ranged for
///////////////////////////////////////////////////////////////////////////

struct Point3D
{
	int x, y, z;

	Point3D(int a = 0, int b = 0, int c = 0) : x(a), y(b), z(c) {}
};

int* begin(Point3D& p) { return &(p.x); }
int* end(Point3D& p) { return &(p.z) + 1; }

int main()
{
	Point3D p3d(1, 2, 3);

	for (int n : p3d)
		cout << n << endl;
}



