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


// 1. �Ϲ� �Լ��� �ڽŸ��� Ÿ���� ����. signature�� ������ �Լ��� ���� Ÿ���̴�.
// 2. �Լ� ��ü�� �ڽŸ��� Ÿ���� �ִ�. signature�� �����ص� ��� �ٸ� Ÿ���̴�.

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


// ��å ������ �����ϰ�, ��å�� �ζ��� ġȯ�� �Ǵ� Sort
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