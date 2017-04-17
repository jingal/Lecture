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
	int *p1 = 0;

	int n2 = nullptr;			//error
	int* p2 = nullptr;			// ok..


	//nullptr bool은 허용
	bool b1 = nullptr;			//error, ms에서만 허용
	bool b2(nullptr);			//ok
	bool b3{ nullptr };			//ok
}