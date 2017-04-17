#include <iostream>
#include <type_traits>
#include <vector>

using namespace std;

///////////////////////////////////////////////////////////////////////////
//	delete function
///////////////////////////////////////////////////////////////////////////

int square(int a)
{
	return a*a;
}


//double square(double d);	//선언만
double square(double d) = delete;		//컴파일 타임 error

int main()
{
	square(3);
	square(3.3);
}
