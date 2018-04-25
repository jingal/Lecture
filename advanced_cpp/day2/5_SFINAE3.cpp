//5_SFINAE3
// SFINAE - Substitution Failure Is Not An Error

#include <iostream>
using namespace std;

// unevaluated expression (평가되지 않는 표현식) 개념

// 실행시간에 실행되지는 않는 표현식들.
// sizeof(foo()), decltype(foo()), typeid(foo()), 

// sizeof(함수호출) : 어떤 함수를 호출하는지 조사할때 널리 사용하는 기술
//						함수 구현부가 없어도 상관없다.

short foo(int a);	//{ return 0; }
char foo(double a); //{ return 0; }

int main()
{
	//int n = sizeof(foo(0));		// 어떤 의미일까요?
									// 함수가 수행되었을 때 반환값의 크기
									// n = 2;
									// sizeof는 연산자, 컴파일 타임에 결정
	int n = sizeof(foo(0.0));		// n =1

	cout << n << endl;	
}