//4_�������7

#include <iostream>
#include <vector>
using namespace std;

// 237. thintemplate
// ���ø��� ���鶧 T�� �������� ���� ����� 
// ���ø��� �ƴ� ��� Ŭ������ ���� ��������.

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


// ������ �Ŀ� ������� �����ڵ忡�� ��� �Լ��� � �������?
// 

int main()
{
	const Truck* p = new Truck;

	p->ref();
	p->deref();
}