//5_SFINAE2 - 215 내용입니다. 중요합니다.
// SFINAE - Substitution Failure Is Not An Error

#include <iostream>
using namespace std;


// 1. exactly matching
// 2. template 사용
// 3. 가변 인자

//int foo(int a) { cout << "int" << endl; return 0; }


template<typename T> 
typename T::type foo(T a) { cout << "T " << endl; return 0; }
//typename int::type foo(int a) ...

// 아래 함수 주석처리 시 함수가 없다는 에러, (치환실패 에러가 아님)
int foo(...) { cout << "..." << endl; return 0; }


int main()
{	
	foo(10);
}