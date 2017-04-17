#include <iostream>
#include <type_traits>
//#include <vector>

using namespace std;

///////////////////////////////////////////////////////////////////////////
//	auto
///////////////////////////////////////////////////////////////////////////

int main() 
{
	int n = 10;
	int& r = n;

	const int c = 10;
	const int& cr = c;


	//규칙 1. 값 타입 일때 : 우변 수식의 reference, const, volatile 속성을 제거하고 auto 타입 결정
	auto a1 = n;			// int
	auto a2 = r;			// int
	auto a3 = c;			// int 
	auto a4 = cr;			// int


	//규칙 2. 참조 타입 일때 : const, volatile 속성 유지, 레퍼런스 속성만 제거하고 auto 결정
	auto& a5 = n;			// auto : int		a5 : int&
	auto& a6 = r;			// auto : int		a6 : int&
	auto& a7 = c;			// auto : const int a7 : const int&
	auto& a8 = cr;			// auto : const int	a8 : const int&

	//규칙 3. forwading reference
	auto&& a9 = n;	
}


/*
int main()
{
	int n = 10;
	auto a1 = n;		//a1은 int

	int& r = n;
	auto a2 = r;		//int ? int&

	a2 = 20;

	cout << n << endl;
}

*/
