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
//	27강 함수 객체의 장점 #1 - 상태를 가지는 함수
///////////////////////////////////////////////////////////////////////////

#include <bitset>


template<int N>
class URandom
{
	mutable bitset<N> bs;

public:
	URandom()
	{
		srand(time(0));
		bs.reset();		//모든 비트를 0으로..
	}

	int operator()() const
	{
		int v = -1;

		do {
			v = rand() % N;
		} while (bs.test(v));

		bs.set(v);		// v번째를 1로

		return v;
	}

};

int main()
{
	URandom<10> r;

	for (int i = 0; i < 10; i++)
	{
		cout << r() << ' ';
	}

	cout << endl;

}

/*
int main()
{
	srand(time(0));

	int n1 = rand() & 10;		// 0 ~ 9 난수
	int n2 = rand() & 10;		
	int n3 = rand() & 10;		

	cout << n1 << endl;
	cout << n2 << endl;
	cout << n3 << endl;
}
*/
