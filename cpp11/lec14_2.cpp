#include <iostream>
#include <type_traits>
//#include <vector>

using namespace std;

///////////////////////////////////////////////////////////////////////////
//	auto
///////////////////////////////////////////////////////////////////////////

int main()
{
	int x[3] = { 1,2,3 };

	// auto�� �迭. --> �迭�� ����Ű�� �����ͷ�
	auto p1 = x;			// int p1[3] = x
							// int* p1 = x;

	auto& p2 = x;			//int (&p2)[3] = x;
							//auto : int[3] p2 : int(&)[3]

	cout << typeid(p1).name() << endl;
	cout << typeid(p2).name() << endl;
}

