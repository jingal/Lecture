//5_SFINAE4
// SFINAE - Substitution Failure Is Not An Error

#include <iostream>
#include <type_traits>
using namespace std;

struct Shape
{
	virtual void Draw() {} // = 0;
};

int main()
{
	cout << is_abstract<Shape>::value << endl;

}