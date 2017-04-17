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


	constexpr int c3 = 10;			//ok, ������ �ð� ����� ���� ����
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

//	const int c = 10;				// ok, ������ �ð� ���
	const int c = n;				// n���� ������ �����ϱ� ������ , ����ð� ���� �Ұ�, ����ð� ���.

	check<c> c2;
}
*/