// 4_ObejctGennerator5 - 177 page

#include <iostream>
#include <functional>
using namespace std;


void log() { cout << "log" << endl; }
int goo() { cout << "goo" << endl; return 0; }

// ()를 사용해서 호출할 수 있는 것들
// 1. 함수
// 2. 함수객체
// 3. 람다 표현식.. [] (int a) { return a + b; } (1,2)
// 4. 멤버 변수
// callable object : ()로 호출가능한 모든것

template<typename T>
class ScopedExit
{
	T handler;

public:
	ScopedExit(T f) : handler(f) {}
	~ScopedExit() { handler(); }
};


int main()
{	
	//프로그램이 종료되기 전에 반드시 logging 하고 싶다.
	
	ScopedExit<void(*)()> exit1(&log);

	auto f = []() { cout << "bye" << endl; };
	ScopedExit< decltype(f) > exit2(f);
		
	cout << "다른 코드" << endl;
}


