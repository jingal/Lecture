#include <iostream>
#include <type_traits>
//#include <vector>
//#include <boost\\type_index.hpp>

using namespace std;

///////////////////////////////////////////////////////////////////////////
//	decltype
///////////////////////////////////////////////////////////////////////////

int main()
{
	int x[3] = { 1,2,3 };

	int n = 10;
	int* p = &n;

	// 연산자를 포함한 수식이 좌변에 올 수 있는 지 여부에 따라 달라짐 --> 올 수 있으면 참조, 아니면 값
	decltype(p) d1;		// int*
	decltype(*p) d2;	// int ? int& --> int&
	decltype(x[0]) d3;	// x[0] = 10.. int &

	decltype(n + n) d4;	// n+n = 20.. error,   => int
	decltype(++n) d5;	// ++n = 20.. ok => int&, 11로 바뀐 n이 리턴됨
	decltype(n++) d6;	// n++ = 20,; error, 이전에 있던 10이 리턴됨, int
}

