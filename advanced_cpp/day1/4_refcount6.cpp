//4_참조계수7

#include <iostream>
#include <vector>
using namespace std;

// 237. thintemplate
// 템플릿을 만들때 T에 의존되지 않은 멤버는 
// 템플릿이 아닌 기반 클래스를 만들어서 제공하자.

class RefCountedBase
{
protected:
	mutable int m_refCount = 0;

public:
	void ref() const { ++m_refCount; }
	void derefBase() const 
	{ 
		
	}

	int refCount() const { return m_refCount; }
};

template<typename T> class RefCounted : public RefCountedBase
{
public:
	void deref() const 
	{ 
		deferBase();
		if (--m_refCount == 0) delete static_cast<const T*>(this);	
	}

protected:
	~RefCounted() { cout << "~RefCounted" << endl; }

};

class Truck : public RefCounted<Truck> {};
class Bike : public RefCounted<Bike> {};


// 컴파일 후에 만들어진 목적코드에는 멤버 함수가 몇개 있을까요?
// 

int main()
{
	const Truck* p = new Truck;

	p->ref();
	p->deref();
}