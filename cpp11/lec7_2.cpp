#include <iostream>
#include <type_traits>
#include <vector>

using namespace std;

///////////////////////////////////////////////////////////////////////////
//	ranged for
///////////////////////////////////////////////////////////////////////////

int main()
{
	int x[5] = { 1,2,3,4,5 };

	for (int n : x)
	{
		cout << n << endl;
	}

	//컴파일러는 위 for문을 아래처럼 변경합니다.

	for (auto p = begin(x); p != end(x); ++p)
	{
		int n = *p;
		cout << n << endl;
	}
}



/*
int main()
{
	vector<int> v = { 1,2,3,4,5,6,7,8,9,10 };
	int x[10] = { 1,2,3,4,5,6,7,8,9,10 };

	for (int n : x) //ranged for .. java, c# : foreach
					//배열, STL 컨테이너
	{
		cout << n << endl;
	}

	for (int i = 0; i < 10; i++)
	{
		cout << x[i] << endl;
	}
s
}
*/