#include <iostream>
#include <type_traits>
#include <vector>

using namespace std;

///////////////////////////////////////////////////////////////////////////
//	initializer_list
///////////////////////////////////////////////////////////////////////////

void foo(initializer_list<int> e)
{
	for (auto n : e)
		cout << n << "";

	cout << endl;
}

int main()
{
	foo({ 1,2,3,4 });
	foo({ 1,2,3,4,5,6,7});

	foo({ });
}
