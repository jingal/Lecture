#include <iostream>
#include <type_traits>
//#include <vector>
//#include <boost\\type_index.hpp>

using namespace std;

///////////////////////////////////////////////////////////////////////////
//	decltype
///////////////////////////////////////////////////////////////////////////

int x = 0;

int& foo(int a, int b) { return x; }

int main()
{
	//auto ret = foo(0, 0);			//int ret = 

	//decltype(foo(0, 0)) ret = foo(0, 0);		// int& ret = foo(0,0);

	decltype(auto) ret = foo(0, 0);		// �캯�� ������ Ÿ���� ���� ����, �ٸ� auto �߷б�Ģ�� �ƴ� decltype �߷б�Ģ���� �߷�

	ret = 10;

	cout << x << endl;
}

