// 6_callableobject6

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
	int x[] = { 1,2,3,4,5 };

	//람다표현식에서 지역변수 사용
	//for_each(x, x + 5,
	//	[n1, n2](int n) { n1 = 0; cout << n + n1 + n2 << ","; });

	// mutalbe 람다 : () 연산자 함수를 비상수 함수로 해달라.
	for_each(x, x + 5,
		[n1, n2](int n) mutable { n1 = 0; cout << n + n1 + n2 << ","; });


	//------------------------------------
	// 위 한줄을 보고 컴파일러는 아래 코드를 생성합니다.
	// 람다 표현식은 함수객체를 자동생성하는 도구
	// 입니다.!!!

	class ClosureType
	{
		int n1, n2;
	public:
		ClosureType(int a, int b) : n1(a), n2(b) {}

		inline void operator()(int n) //const --> mutable로 할경우 const가 빠짐
		//inline void operator()(int n) const
		{
			n1 = 0;	// 상수 함수이므로 멤버변수를 수정할 수 없음
			cout << n + n1 + n2 << ",";
		}
	};

	// 람다표현식이 만드는 객체를 Closure라 부른다.
	// 아래 코드에서 n1, n2는 main의 지역변수 입니다.
	for_each(x, x + 5, ClosureType(n1,n2));
}
