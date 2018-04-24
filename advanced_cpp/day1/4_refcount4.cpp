//4_참조계수4

#include <iostream>
#include <vector>
using namespace std;

// CRTP (Curiosly Recurring Template Pattern
// 기반 클래스가 템플릿인데, 파생 클래스 만들때 인자로
// 자신의 이름을 전달하는 코드
// 오늘 만든 코드에서 미래에 만드어질 클래스의 이름을 
// 사용할 수 있다.
template<typename T> class RefCounted
{
	int m_refCount = 0;
public:
	void ref() { m_refCount++; }
	void deref()
	{
		// 핵심 : delete 할때 this를 파생 클래스 타입으로
		//		캐스팅해서 하자.
		if (--m_refCount == 0) 
			delete static_cast<T*>(this);
	}

protected:	
	// 가상 소멸자를 사용하지 말자.
	// 가상함수의 오버헤드가 모든 파생클래스에 있는 것이 
	// 싫다는 의도
	~RefCounted() { cout << "~RefCounted" << endl; }
};

class Truck : public RefCounted<Truck>
{
public:
	~Truck() { cout << "~Truck" << endl; }
};

int main()
{
	Truck* p = new Truck;

	p->ref();
	p->deref();
}