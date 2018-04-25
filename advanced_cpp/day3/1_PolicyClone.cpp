// 1_PolicyClone - 183 page
// wtf/폴더에 nolock.h


#include <iostream>
using namespace std;

// PolicyBase Design(단위 전략 디자인) - 사용자 선택에 의해서 정책 적용, 성능저하 없이
// 모든 정책 클래스에는 지켜야 하는 조건이 있다.
// 함수 이름이 정해져 있다는 의미.

template<typename T, typename ThreadModel = NoLock> class List
{
	ThreadModel tm;

public:
	void push_front(const T& a)
	{
		tm.lock();
		//....
		tm.unlock();
	}
};

// 동기화 정책을 담은 정책 클래스
class MuteLock
{
public:
	inline void lock() { cout << "mutex lock" << endl; }
	inline void unlock() { cout << "mutex unlock" << endl; }

};

class NoLock
{
public:
	inline void lock() { }
	inline void unlock() { }
};


List<int, NoLock> s;				//전역변수, 멀티스레드에 안전하지 않다.


int main()
{
	s.push_front(10);
}