//4_참조계수3

#include <iostream>
#include <vector>
using namespace std;

// 참조계수를 책임지는 기반 클래스
class RefCounted
{
	int m_refCount = 0;
public:
	void ref() { m_refCount++; }
	void deref()
	{
		//RefCounted* const this
		if (--m_refCount == 0) delete this;
	}

protected:
	// 기반 클래스의 소멸자는 가상 소멸자 이어야 한다.
	virtual ~RefCounted() { cout << "~RefCounted" << endl; }
};

//Truck도 참조계수로 관리하고 싶다.
class Truck : public RefCounted
{
	~Truck() { cout << "~Truck" << endl; }
};

int main()
{
	Truck* p = new Truck;

	p->ref();
	p->deref();

	// RefCoutef* this = new Truck;
	// delete this; //메모리 조사해서 소멸자 호출
}