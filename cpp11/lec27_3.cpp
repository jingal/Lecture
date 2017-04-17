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


// 1. 일반 함수는 자신만의 타입이 없다. signature가 동일한 함수는 같은 타입이다.
// 2. 함수 객체는 자신만의 타입이 있다. signature가 동일해도 모두 다른 타입이다.

struct Less
{
	inline bool operator()(int a, int b)
	{
		return a < b;
	}
};

struct Greator
{
	inline bool operator()(int a, int b)
	{
		return a > b;
	}
};


// 정책 변경이 가능하고, 정책의 인라인 치환이 되는 Sort
template<typnename T>void Sort(int* x, int sz, T cmp)
{
	for (int i = 0; i < sz; i++)
	{
		for (int j = i; j < sz; j++)
		{			
			if (cmp(x[i], x[j]))
				swap(x[i], x[j]);
		}
	}
}

Less f1; Sort(x, 10, f1);
Greator f2; Sort(x, 10, f2);

//-------------------------------
inline bool cmp1(int a, int b) { return a < b; }
inline bool cmp2(int a, int b) { return a > b; }

int main()
{
	int x[10] = { 1,3,5,7,9,2,4,6,8,10 };
	Sort(x, 10, cmp1);
}