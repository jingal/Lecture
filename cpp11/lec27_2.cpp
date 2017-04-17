#include <iostream>
#include <type_traits>
#include <typeinfo>
#include <string>
#include <chrono>
#include <typeinfo>
#include <vector>
#include <boost/type_index.hpp>
#include <memory>
#include <functional>
#include <thread>
#include <ctime>

using namespace std;
using namespace std::chrono;
using namespace boost::typeindex;

///////////////////////////////////////////////////////////////////////////
//	27�� �Լ� ��ü�� ���� #2 - ����
///////////////////////////////////////////////////////////////////////////

void Sort(int* x, int sz, bool(*cmp)(int, int))
{
	for (int i = 0; i < sz; i++)
	{
		for (int j = i; j < sz; j++)
		{
			//if (x[i] > x[j])
			if (cmp(x[i], x[j]))
				swap(x[i], x[j]);
		}
	}
}

//-------------------------------
inline bool cmp1(int a, int b) { return a < b; }
inline bool cmp2(int a, int b) { return a > b; }


/*
int Add1(int a, int b) { return a + b; }
inline int Add2(int a, int b) { return a + b; }

int main()
{
	Add1(1, 2);		// ȣ��
	Add2(1, 2);		// ġȯ

	int(*f)(int, int);

	f = &Add2;

	int n;
	cin >> n;
	if (n == 1) f = &Add1;

	f(1, 2);		//ȣ�� ? ġȯ
					// �Լ������Ϳ� ��� ���� ġȯ �Ұ���
}
*/

