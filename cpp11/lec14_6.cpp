#include <iostream>
#include <type_traits>
//#include <vector>
//#include <boost\\type_index.hpp>

using namespace std;

///////////////////////////////////////////////////////////////////////////
//	suffix return type, trailling return
///////////////////////////////////////////////////////////////////////////
// 후위 반환 타입 (suffix return type, trailling return)

//template<typename T, typename U> decltype(a*b) Mul(T a, U b)
template<typename T, typename U> 
//auto Mul(T a, U b) -> decltype(a*b)		// c++ 11
auto Mul(T a, U b)
{
	return a * b;
}

int main()
{
	cout << Mul(3, 4.2) << endl;
}

/*
auto square(int a) -> int
{
	return a * a;
}


int main()
{
	int n = square(3);	
}
*/
