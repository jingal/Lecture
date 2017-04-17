#include <iostream>
#include <set>
#include <functional>

using namespace std;

///////////////////////////////////////////////////////////////////////////
//	using
///////////////////////////////////////////////////////////////////////////

//typedef set<int, greater<int>> des_set;
//typedef set<double, greater<double>> des_set_double;

//template<typename T> typedef set<T, greater<T>> des_set;	//error. typedef는 템플릿이 될 수 없다.

// C++11 using : template의 별명이 가능하다.

template<typename T>
using des_set = set<T, greater<T>>;


int main()
{
	//set<int, greater<int>> s = { 1,3,5,7,9,2,4,6,8,10 };		//c++11의 list initialization
	//des_set s = { 1,3,5,7,9,2,4,6,8,10 };
	// des_set_double sd;

	des_set<int> s = { 1,3,5,7,9,2,4,6,8,10 };
	des_set<double> sd;

	for (auto&n : s)		//c++11의 ranged_for
	{
		cout << n << endl;
	}
}




/*
// C++ 98 style
// typedef int DWORD
// typdef void(*PF)();


// C++11 style
using DWORD = int;
using PF = void(*)();

int main()
{
	DWORD a;		//int
	PF f;			// f는 함수 포인터
}*/