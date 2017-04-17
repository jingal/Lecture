#include <iostream>
#include <type_traits>
//#include <vector>
//#include <boost\\type_index.hpp>

using namespace std;

///////////////////////////////////////////////////////////////////////////
//	nullptr #1 - 0의 문제점
///////////////////////////////////////////////////////////////////////////

int main()
{
	int n1 = 0;
	int* p1 = 0;			//0은 int, 포인터로 암시적 형변환 가능

	int n2 = 10;			// ok.
	int* p2 = 10;			// error;
}