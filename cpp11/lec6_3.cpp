#include <iostream>
#include <type_traits>

using namespace std;

template<typename T> T square(T a)
{
	static_assert(is_integral<T>::value || is_floating_point<T>::value, "Error T is unknown Type");
	return a*a;
}

int main()
{
	int n = 3;

	square(n);
	square(&n);
}