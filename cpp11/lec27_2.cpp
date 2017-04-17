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
//	27강 함수 객체의 장점 #2 - 성능
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
	Add1(1, 2);		// 호출
	Add2(1, 2);		// 치환

	int(*f)(int, int);

	f = &Add2;

	int n;
	cin >> n;
	if (n == 1) f = &Add1;

	f(1, 2);		//호출 ? 치환
					// 함수포인터에 담는 순간 치환 불가능
}
*/

