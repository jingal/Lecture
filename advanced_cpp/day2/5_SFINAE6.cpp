//5_SFINAE6
// SFINAE - Substitution Failure Is Not An Error

#include <iostream>
#include <type_traits>
using namespace std;

struct Shape
{
	virtual void Draw() = 0;
};

// Step 3. 

template<typename U> struct xis_abstract
{
	template<typename T> static char check(T (*)[1]);
	template<typename T> static short check(...);

	enum { value = (sizeof(check<U>(0)) == sizeof(short)) };
};

int main()
{
	cout << xis_abstract<Shape>::value << endl;
}
