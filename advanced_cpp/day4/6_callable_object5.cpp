// 6_callableobject5

#include <iostream>
#include <algorithm>

using namespace std;

// callable object : ()로 호출 가능한 객체
// 일반 함수 
// 함수 객체(Function Object, Functor)
// 람다 표현식
// 

int main()
{
	int n1 = 10, n2 = 10;
	int x[] = { 1,2,3,4,5};

	for_each(x, x+5,
		[](int n) { cout << n << ","; });
	//------------------------------------
	// 위 한줄을 보고 컴파일러는 아래 코드를 생성합니다.
	// 람다 표현식은 함수객체를 자동생성하는 도구
	// 입니다.!!!

	class ClosureType
	{
	public:
		inline void operator()(int n) const
		{
			cout << n << ",";
		}
	};

	// 람다표현식이 만드는 객체를 Closure라 부른다.
	for_each(x, x + 5, ClosureType());
}
