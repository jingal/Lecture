#include <iostream>
#include <type_traits>
#include <vector>

using namespace std;

///////////////////////////////////////////////////////////////////////////
//	constexpr
///////////////////////////////////////////////////////////////////////////


int main()
{
	int n = 10;

	const int c1 = 10;				//ok
	const int c2 = n;				//ok


	constexpr int c3 = 10;			//ok, 컴파일 시간 상수만 저장 가능
	constexpr int c4 = n;			//error

	cout << c3 << endl;

}


/*
template<int N> struct check {};

int main()
{
	int n = 10;
	//cin >> n;

	check<10> c1;					// ok
//	check<n> c2;					// error

//	const int c = 10;				// ok, 컴파일 시간 상수
	const int c = n;				// n값은 변경이 가능하기 때문에 , 실행시간 변경 불가, 실행시간 상수.

	check<c> c2;
}
*/