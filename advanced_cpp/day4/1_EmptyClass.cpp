//1_EmptyClass - 73 page EBCO

#include <iostream>
using namespace std;


class EmptyClass {};		// empty class, sizeof = 1


class Test : public EmptyClass
{
	int data;
};

int main()
{
	EmptyClass ec;
	cout << sizeof(ec) << endl;			// 1
	cout << sizeof(Test) << endl;		// 4
}





