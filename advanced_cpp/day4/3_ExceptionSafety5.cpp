// 3_ExceptionSafety5 - 197 page

#include <iostream>
#include <mutex> 
using namespace std;

mutex m;

// 동기화 객체 사용시 예외가 발생하면 dead lock 발생할 수 있음
// 생성자, 소멸자를 통해서 자원을 사용하자.

// 1. 전역변수인 mutex를 지역변수인 lg 변수로 관리
// 2. 예외 발생시 지역변수는 안전하게 파괴된다.

// RAII : Resource Acquision Is Initialize
// "자원을 획득하는 것은 자원관리객체가 초기화 될때이다."
// 안드로이드/libutils/include/utils/Singleton.h

/*
template<typename T> struct lock_guard
{
	T& sync;
	lock_guard(T& s) : sync(s) {
		sync.lock();
	}

	~lock_guard(){
		sync.unlock();
	}
};
*/

void foo()
{
	lock_guard<mutex> lg(m);	// lg의 생성자에서 m.lock
	//m.lock();
	// ---
	// 예외발생				--> stack 풀기로 인해서 소멸자가 호출됨
	//m.unlock();
								// 파괴될때 소멸자에서 m.unlock
}

int main()
{

}