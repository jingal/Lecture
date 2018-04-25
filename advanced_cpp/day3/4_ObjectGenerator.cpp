// 4_ObejctGennerator - 177 page

#include <iostream>
#include <list>
using namespace std;

// 함수 템플릿은 컴파일러가 타입 추론이 가능하지만
// 클래스 템플릿은 컴파일러가 추론할 수 없다.
template<typename T>		// 타입인자 (type parameter)
T square(T a)				// 함수인자
{
	return a * a;
}

int main()
{
	square<int>(3);				// 이 표현이 정확한 표현입니다.
	square(3);					// 함수 인자로 타입 추론
								// type deduction(inference)

	//list<int> = { 1,2,3 };
	list<int> s(10, 1);				// 10개를 1로 초기화
	list s(10, 1);					// error. int 생략 안됨
									// 단, C++17 부터 생략 가능
}


