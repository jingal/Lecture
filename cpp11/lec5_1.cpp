#include <iostream>

using namespace std;




int main()
{
	int n1 = 3;
	int n2 = n1;

	double d1 = n2;		//implicit conversion

	double d2 = (double)n2;					// explicit conversion
	double d3 = static_cast<double>(n2);	// C++ Style
}