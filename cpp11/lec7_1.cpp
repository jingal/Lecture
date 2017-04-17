#include <iostream>
#include <type_traits>
#include <vector>

using namespace std;

///////////////////////////////////////////////////////////////////////////
//	non member begin/end
///////////////////////////////////////////////////////////////////////////

/*
template<typename T> void show(T &c)
{
	//typename T::iterator p = c.begin();
	auto p = begin(c);

	while (p != c.end())
	{
		cout << *p << " ";
		++p;
	}

	cout << endl;
}
*/

// 일바 함수로 만드는 begin / end
// 1. 컨테이너 버전
template<typename T> auto xbegin(T& c) { return c.begin(); }
template<typename T> auto xend(T& c) { return c.end(); }

// 2. 배열 버전의 begin
template<typename T, int N> auto xbegin(T(&r)[N]) { return r; }
template<typename T, int N> auto xend(T(&r)[N]) { return r + N; }


template<typename T> void show(T &c)
{	
	auto p = begin(c);

	while (p != end(c))
	{
		cout << *p << " ";
		++p;
	}

	cout << endl;
}

int main()
{
	vector<int> v = { 1,2,3,4,5,6,7,8,9,10 };

	show(v);


	int x[10] = { 1,2,3,4,5,6,7,8,9,10 };
	show(x);
}