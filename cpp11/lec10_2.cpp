#include <iostream>
#include <type_traits>
#include <vector>

using namespace std;

///////////////////////////////////////////////////////////////////////////
//	constexpr funciton - meta fuction
///////////////////////////////////////////////////////////////////////////


constexpr int Factorial(int n)
{
	//if (n == 1) return 1;					//c++11에서는 return문 1개만 사용 가능
	//return n * Factorial(n - 1);

	return n == 1 ? 1 : n * Factorial(n - 1);
}

template<int N> struct check {};
//int Add(int a, int b) { return a + b;  }		//error
constexpr int Add(int a, int b) { return a + b; }

int main()
{
	int a1 = 1, b = 2;

	check<Factorial(5)> c3;

	//check<Add(1, 2)> c;
	//check<Add(a, b)> c2;
}
