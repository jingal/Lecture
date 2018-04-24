//4_참조계수5

#include <iostream>
#include <vector>
using namespace std;

template<typename T> class RefCounted
{
	// mutable : 상수 함수 안에서도 값을 변경할 수 있게 한다.
	// 상수 함수 문법을 사용하게 되면 mutable 키워드를 많이 
	// 사용하게 됩니다.
	mutable int m_refCount = 0;

public:
	void foo()
	{
		// this : RefCounted* const this
		// this->멤버데이타 = 10;
	}

	void goo() const
	{
		//this : const RefCounted* const this
		//this->멤버데이타 = 10; //error
	}
	void ref() const { m_refCount++; }
	void deref() const
	{
		if (--m_refCount == 0)
			//delete static_cast<T*>(this);		//error
			//delete static_cast<T*>(
			//	const_cast<RefCounted*>(this));		//자기자신에 한해서 const_cast 치환
			delete static_cast<const T*>(this);		//error
	}

protected:
	~RefCounted() { cout << "~RefCounted" << endl; }
};

class Truck : public RefCounted<Truck>
{
public:
	~Truck() { cout << "~Truck" << endl; }
};

int main()
{
	const Truck* p = new Truck;

	p->ref();
	p->deref();
}