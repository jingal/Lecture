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


//double square(double d);	//����
double square(double d) = delete;		//������ Ÿ�� error

int main()
{
	square(3);
	square(3.3);
}
