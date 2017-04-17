#include <iostream>
#include <type_traits>
#include <vector>

using namespace std;

///////////////////////////////////////////////////////////////////////////
//	default / value initialization
///////////////////////////////////////////////////////////////////////////

int main()
{
	int n1{ 0 };			// direct initialization
	int n2 = { 0 };			// copy initialization

	int n3;					// default initialization
	int n4{};				// value initialization


	cout << n3 << endl;
	cout << n4 << endl;
}
