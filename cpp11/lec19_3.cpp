#include <iostream>
#include <type_traits>
#include <typeinfo>
#include <string>
#include <chrono>
//#include <vector>
//#include <boost\\type_index.hpp>

using namespace std;
using namespace std::chrono;

///////////////////////////////////////////////////////////////////////////
//	19강 1. lvalue vs rvalue
///////////////////////////////////////////////////////////////////////////
//연산자와 lvalue


int main()
{
	int v1 = 10;
	int v2 = 20;
	int arr[5] = { 1,2,3,4,5 };

	int n = v1 + v2;

	v1 + v2 = 10;		// int temp = v1 + v2; return temp; error. +연산자의 결과는 rvalue
	-v1 = 20;			// error. 단항 연산자 -의 결과도 rvalue

	*arr = 10;			// ok. 단항 연산자 *의 결과는  lvalue, 
	arr[1] = 10;		// ok. [] 연산자의 결과도 lvalue
}
